/* Filter a LISTSERV PUNCH format message into normal text */

#include <stdio.h>
#include <string.h>

int
main()
{
    char	buffer[81];
    char	*p;
    int		len, n, k;

    k = 0;
    while (gets(buffer) != (char*)NULL)
    {
	k++;
	if (strcmp(buffer,"END/") == 0)
	    break;
	p = strchr(buffer,'/');
	if (p != (char*)NULL) p = strchr(p+1,'/');
	if (p != (char*)NULL) ++p;
	if ( (sscanf(buffer,"%d/%d/",&len,&n) != 2) || (p == (char*)NULL) )
	{
	    fprintf(stderr,"Conversion error on line %d = [%s]\n",k,buffer);
#if 0
	    exit(1);
#endif
	    n = 1;
	}

	if (p != (char*)NULL)
	    fputs(p,stdout);
	else
	{
	    fputs("????",stdout);
	    fputs(buffer,stdout);
	}

	for (; n > 1; --n)		/* copy continuation lines */
	{
	    if (gets(buffer) == (char*)NULL)
		break;
	    k++;
	    fputs(buffer,stdout);
	}
	fputc('\n',stdout);
    }
    exit (0);
}
