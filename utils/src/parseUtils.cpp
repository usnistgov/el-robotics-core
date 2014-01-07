#include <string.h>		// strcmp
#include <stdio.h>		/// sscanf
#include <ctype.h>		// isspace
#include "parseUtils.hh"

/*
  \param msg Pointer to message string
  \param key Key returned
  \return new location of pointer
*/
const char *getKey(const char *msg, char *key)
{
  const char *ptr = msg;
  while ((*ptr != 0) && (*ptr != '{'))
    ptr++;			/* find the { */
  if (*ptr == 0)
    return msg;		/* didn't find the { */
  ptr++;			/* skip over the { */
  while (isspace(*ptr))
    ptr++;			/* skip over any space */

  /* copy everything until we hit space */
  while (1) 
    {
      if ((*ptr == 0) || (*ptr == ',') || (*ptr == '{') || (*ptr == '}')) 
	{

	  /* unexpected delimiter -- return the original pointer */
	  return msg;
	}
      if (isspace(*ptr)) 
	{

	  /* expected delimiter -- break to return current pointer */
	  break;
	}

      /* else copy it */
      *key++ = *ptr++;
    }
  *key = 0;			/* null terminate */
  return ptr;
}


/*
  \param msg Pointer to message string
  \param value Value read
  \return new location of pointer
*/
const char *getValue(const char *msg, char *value)
{
  const char *ptr = msg;
  while ((isspace(*ptr)) || (*ptr == ','))
    ptr++;			/* skip over delimiters */

  /* copy everything until we hit a delimiter */
  while (!isspace(*ptr)) 
    {
      if (*ptr == 0)
	return ptr;		/* didn't finish cleanly */
      if ((*ptr == ',') || (*ptr == '}')) 
	{
	  break;
	}

      /* ok to copy */
      *value++ = *ptr++;
    }
  *value = 0;			/* null terminate */
  return ptr;
}


/*
  \param expectString String to search for
  \param msg Pointer to message string
  \return updated pointer on success
  \return original pointer on failure
*/
const char *expect(const char *expectString, const char *msg)
{
  const char *ptr = msg;
  const char *nextptr;
  char token[MAX_TOKEN_LEN];
  nextptr = getValue(ptr, token);
  if (nextptr == ptr)
    return msg;
  if (strcmp(token, expectString))
    {

      //printf( "Expect found: %s looking for %s\n", token, expectString );
      return msg;
    }
  ptr = nextptr;
  return ptr;
}


/*
  \param msg Pointer to message string
  \param intValue Place holder for returned value
  \return updated pointer on success
  \return original pointer on failure
*/
const char *getInteger(const char *msg, int *intValue)
{
  const char *ptr = msg;
  const char *nextptr;
  char token[MAX_TOKEN_LEN];
  nextptr = getValue(ptr, token);
  if (nextptr == msg)
    return msg;
  if (1 != sscanf(token, "%i", intValue))
    return msg;
  ptr = nextptr;
  return ptr;
}


/*
  \param ptr Pointer to message string
  \param dblValue Place holder for returned value
  \return updated pointer on success
  \return original pointer on failure
*/
const char *getDouble(const char *msg, double *dblValue)
{
  const char *ptr = msg;
  const char *nextptr;
  char token[MAX_TOKEN_LEN];
  nextptr = getValue(ptr, token);
  if (nextptr == ptr)
    return msg;
  if (1 != sscanf(token, "%lf", dblValue))
    return msg;
  ptr = nextptr;
  return ptr;
}


/*
  \param ptr Pointer to message string
  \param dblArray Place holder for returned values
  \param length Number of items to return
  \return updated pointer on success
  \return original pointer on failure
*/
const char *getVector(const char *msg, double *dblArray, int length)
{
  const char *ptr = msg;
  const char *nextptr;
  int count;
  for (count = 0; count < length; count++)
    {
      nextptr = getDouble(ptr, &dblArray[count]);
      if (nextptr == ptr)
	return msg;
      ptr = nextptr;
    }
  return ptr;
}


/*
  \param ptr Pointer to message string
  \param dblArray Place holder for returned values
  \return updated pointer on success
  \return original pointer on failure
*/
const char *getBone(const char *msg, double *dblArray)
{
  const char *ptr = msg;
  const char *nextptr;
  int foundLoc = 0;
  int foundRot = 0;
  int foundParent = 0;
  char token[MAX_TOKEN_LEN];
  while (1)
    {
      nextptr = getKey(ptr, token);
      if (nextptr == ptr)
	break;
      ptr = nextptr;
      if (!strcmp(token, "Parent"))
	{
	  nextptr = getValue(ptr, token);
	  if (nextptr == ptr)
	    break;
	  ptr = nextptr;
	  foundParent = 1;

	  // printf( "getBone found parent\n");
	  if (foundParent && foundLoc && foundRot)
	    return ptr;
	}

      else if (!strcmp(token, "Location"))
	{
	  nextptr = getVector(ptr, dblArray, 3);
	  if (nextptr == ptr)
	    break;
	  ptr = nextptr;
	  foundLoc = 1;

	  // printf( "getBone found location\n");
	  if (foundParent && foundLoc && foundRot)
	    return ptr;
	}

      else if (!strcmp(token, "Orientation"))
	{
	  nextptr = getVector(ptr, &dblArray[3], 3);
	  if (nextptr == ptr)
	    break;
	  ptr = nextptr;
	  foundRot = 1;

	  // printf( "getBone found orientation\n");
	  if (foundParent && foundLoc && foundRot)
	    return ptr;
	}

      else
	{
	  printf("getBone found bad token %s\n", token);
	  return msg;
	}
    }
  return msg;
}
