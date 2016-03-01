/*
  inifile.c
*/

#include <stdio.h>		/* FILE *, fopen(), fclose(), NULL */
#include <string.h>		/* strlen(), etc. */
#include <stddef.h>
#include <ctype.h>		/* isspace() */
#include "ulapi.h"
#include "inifile.h"

/* if the next non-whitespace character in string is '=', returns
   ptr to next non-whitespace after that, or NULL. */
static const char *afterequal(const char *string)
{
  const char *spot = string;

  while (1) {
    if (*spot == '=') {
      /* = is there-- return next non-white, or NULL if not there */
      for (;;) {
	spot++;
	if (0 == *spot) {
	  /* ran out, so return this empty string */
	  return spot;
	} else if (*spot != ' ' && *spot != '\t' && *spot != '\r'
		   && *spot != '\n') {
	  /* matched! */
	  return spot;
	} else {
	  /* keep going for the text */
	  continue;
	}
      }
    } else if (*spot == 0) {
      /* end of string */
      return NULL;
    } else {
      /* haven't seen '=' yet-- keep going */
      spot++;
      continue;
    }
  }
}

/* returns ptr to first non-white in string, or NULL if it's all white */
static char *skipwhite(char *string)
{
  for (;;) {
    if (*string == 0) {
      return NULL;
    }

    if (*string == COMMENT_CHAR) {
      return NULL;
    }

    if (*string != ' ' && *string != '\t' && *string != '\r'
	&& *string != '\n') {
      return string;
    }

    string++;
  }
}

/*
   Positions file at line after section tag. Returns 0 if section found;
   -1 if not.
   */
static int find_section(FILE *fp, const char *section)
{
  static char line[INIFILE_MAX_LINELEN + 2];	/* 1 for newline, 1 for NULL */
  char bracketsection[INIFILE_MAX_LINELEN + 2];
  char *nonwhite;

  /* check valid file */
  if (NULL == fp) {
    return -1;
  }

  /* start from beginning */
  rewind(fp);

  /* if section is NULL, we're already positioned */
  if (NULL == section) {
    return 0;
  }

  /* wrap section in brackets, so it matches */
  ulapi_snprintf(bracketsection, sizeof(bracketsection) - 1, "[%s]", section);

  /* find [section], and position fp just after it */
  while (!feof(fp)) {

    if (NULL == fgets(line, INIFILE_MAX_LINELEN + 1, fp)) {
      /* got to end of file without finding it */
      return -1;
    }

    /* got a line-- check it for real data, not comment or blank line */
    if (NULL == (nonwhite = skipwhite(line))) {
      /* blank line-- skip it */
      continue;
    }

    /* not a blank line-- compare with section tag */
    if (0 != strncmp(bracketsection, nonwhite, strlen(bracketsection))) {
      /* not on this line */
      continue;
    }

    /* else it matches-- fp is now set up for search on tag */
    return 0;
  }

  /* didn't find it */
  return -1;
}

int ini_match(const char * match, const char * me)
{
  while (*me != 0) if (toupper(*match++) != toupper(*me++)) return 0;

  if (isspace(*match) || *match == 0) return 1;

  return 0;
}

/* Returns string in file associated with tag, e.g., in a file that
   contains

   PRINTER=fred

   ini_find("PRINTER");

   would return "fred", and

   ini_find("printer");

   would return NULL.

   The FILE * needs to have been opened; its position after the call
   to ini_find is undefined.
 */

const char *ini_find(FILE *fp, const char *tag, const char *section)
{
  static char line[INIFILE_MAX_LINELEN + 2];	/* 1 for newline, 1 for NULL */
  char bracketsection[INIFILE_MAX_LINELEN + 2];
  char *nonwhite;
  int newlinepos;		/* position of newline to strip */
  int len;
  char tagend;
  char *value_string;
  char *end_value_string;

  /* check valid file */
  if (NULL == fp)
    return NULL;

  /* start from beginning */
  rewind(fp);

  /* check for section first-- if it's non-NULL, then position file at line
     after [section] */
  if (NULL != section) {
    ulapi_snprintf(bracketsection, sizeof(bracketsection) - 1, "[%s]", section);

    /* find [section], and position fp just after it */
    while (!feof(fp)) {
      if (NULL == fgets(line, INIFILE_MAX_LINELEN + 1, fp)) {
	/* got to end of file without finding it */
	return NULL;
      }
      /* got a line */

      /* strip off newline */
      newlinepos = strlen(line) - 1;	/* newline is on back from 0 */
      if (newlinepos < 0) {
	newlinepos = 0;
      }
      if (line[newlinepos] == '\n') {
	line[newlinepos] = 0;	/* make the newline 0 */
      }

      if (NULL == (nonwhite = skipwhite(line))) {
	/* blank line-- skip */
	continue;
      }

      /* not a blank line, and nonwhite is first char */
      if (0 != strncmp(bracketsection, nonwhite, strlen(bracketsection))) {
	/* not on this line */
	continue;
      }

      /* it matches-- fp is now set up for search on tag */
      break;
    }
  }

  while (!feof(fp)) {
    /* check for end of file */
    if (NULL == fgets(line, INIFILE_MAX_LINELEN + 1, fp)) {
      /* got to end of file without finding it */
      return NULL;
    }

    /* got a line */

    /* strip off newline */
    newlinepos = strlen(line) - 1;	/* newline is on back from 0 */
    if (newlinepos < 0) {
      newlinepos = 0;
    }
    if (line[newlinepos] == '\n') {
      line[newlinepos] = 0;	/* make the newline 0 */
    }

    /* skip leading whitespace */
    if (NULL == (nonwhite = skipwhite(line))) {
      /* blank line-- skip */
      continue;
    }

    /* check for '[' char-- if so, it's a section tag, and we're out of
       our section */
    if (NULL != section && nonwhite[0] == '[') {
      return NULL;
    }

    len = strlen(tag);

    if (0 != strncmp(tag, nonwhite, len)) {
      /* not on this line */
      continue;
    }

    /* it matches the first part of the string-- if whitespace or =
       is next char then call it a match */
    tagend = nonwhite[len];
    if (tagend == ' ' || tagend == '\r' || tagend == '\t' || tagend == '\n'
	|| tagend == '=') {
      /* it matches-- return string after =, or NULL */
      nonwhite += len;
      value_string = (char *) afterequal(nonwhite); /* cast is needed because we are discarding the const */
      /* eliminate white space at the end of a line also */
      if (NULL == value_string) {
	return NULL;
      }
      end_value_string = value_string + strlen(value_string) - 1;
      while (*end_value_string == ' ' || *end_value_string == '\t'
	     || *end_value_string == '\r') {
	*end_value_string = 0;
	end_value_string--;
      }
      return value_string;
    }
    /* else continue */
  }

  return NULL;
}

/*
   given 'section' and array of strings, fills strings with what was
   found in the section, one line per string. Comments and blank lines
   are omitted. 'array' is assumed to be allocated, of 'max' entries
   of size INIFILE_MAX_LINELEN.

   Returns number of entries found; 0 if section is there but no entries
   in it, or -1 if section is not there.
*/

int ini_section(FILE *fp, const char *section, INIFILE_ENTRY array[], int max)
{
  static char line[INIFILE_MAX_LINELEN + 2];	/* 1 for newline, 1 for NULL */
  int count = 0;
  char *nonwhite;
  int newlinepos;
  const char *entry;

  if (NULL == fp) {
    return -1;
  }

  /*  position at section */
  if (-1 == find_section(fp, section)) {
    /* didn't find it */
    return -1;
  }

  /* found section-- start loading lines */

  while (!feof(fp) &&
	 count < max) {
    if (NULL == fgets(line, INIFILE_MAX_LINELEN + 1, fp)) {
      /* got to end of file without finding it */
      return count;
    }

    /* got a line-- check for blank */
    if (NULL == (nonwhite = skipwhite(line))) {
      continue;
    }

    /* check for new section-- if so, we're done */
    if ('[' == *nonwhite) {
      return count;
    }

    /* strip off newline  */
    newlinepos = strlen(line) - 1;	/* newline is one back from 0 */
    if (newlinepos < 0) {
      newlinepos = 0;
    }
    if (line[newlinepos] == '\n') {
      line[newlinepos] = 0;	/* make the newline 0 */
    }

    /* it's a valid line-- copy into entry struct */

    /* read first tag */
    sscanf(line, "%s", array[count].tag);

    /* copy everything after equal to the rest */

    entry = afterequal(line);
    if (NULL != entry) {
      strncpy(array[count].rest, afterequal(line), sizeof(array[count].rest) - 1);
    } else {
      array[count].rest[0] = 0;	/* make it the empty string */
    }
    count++;
  }

  /* got to end of file */
  return count;
}

#ifdef INIFILE_MAIN

int main(int argc, char *argv[])
{
  FILE *fp;
  const char *inistring;

  if (4 != argc) {
    fprintf(stderr, "inifind: usage: <variable> <section> <inifile>\n");
    return 1;
  }

  /* open the inifile */
  if (NULL == (fp = fopen(argv[3], "r"))) {
    fprintf(stderr, "inifind: can't open %s\n", argv[3]);
    return 1;
  }

  inistring = ini_find(fp, argv[1], argv[2]);

  fclose(fp);

  if (NULL == inistring) {
    return 1;
  }

  printf("%s\n", inistring);

  return 0;
}

#endif
