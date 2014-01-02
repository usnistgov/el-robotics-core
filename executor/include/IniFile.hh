/*
 * IniFile.h
 *
 *  Created on: Sep 18, 2012
 *      Author: zeid
 */

#ifndef INIFILE_H_
#define INIFILE_H_

#define COMMENT_CHAR ';'	/* signifies a comment */
#define INIFILE_MAX_LINELEN 256	/* max number of chars in a line */
#define INI_OK      0
#define INI_DEFAULT 1
#define INI_INVALID 2


#include <stdio.h>		/* FILE *, fopen(), fclose(), NULL */
#include <string.h>		/* strlen(), etc. */
#include <ctype.h>		/* isspace() */

typedef struct {
  char tag[INIFILE_MAX_LINELEN];
  char rest[INIFILE_MAX_LINELEN];
} INIFILE_ENTRY;

class IniFile {
public:
	IniFile();
	IniFile(const char *path);
	virtual ~IniFile();

	int open (const char *path);
	  int close ();
	  int isSection(const char * section);
	  const char *find (const char *tag, const char *section_to_find = 0);
	  int findSection (void *fp, const char *section);
	  const char *iniFind (void *fp,	/* already opened file ptr */
	  			    const char *tag,	/* string to find */
	  			    const char *section);	/* section it's in */
	  int iniSection (void *fp,	/* already opened file ptr */
	  		       const char *section,	/* section you want */
	  		       INIFILE_ENTRY array[],	/* entries to fill */
	  		       int max);	/* how many you can hold */
	  int section (const char *section_to_load, INIFILE_ENTRY array[], int max);
	  int valid ();

 /* prevent copying. */
 IniFile(const IniFile &);
 IniFile &operator=(const IniFile &);
};

#endif /* INIFILE_H_ */
