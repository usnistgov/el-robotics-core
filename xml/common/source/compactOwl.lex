%{

/*

This compacts an OWL file by:
1. removing all occurrences of one or two blank lines. The blank lines
   must not contain spaces or tabs.
2. removing comments. The comments must have // as the first two
   characters on the line.
3. combining each OWL statement written on two or more lines so it is
   all on one line. The first non-space character on the second line
   must be a colon (:) or a double quote (").
4. rewriting numbers with decimal points so there are exactly six decimal
   places. Such numbers must have at least one digit on each side of the
   decimal point in the input file.
5. putting the DifferentIndividuals inside DifferentIndividuals statements
   into alphabetical order.

To make C++ code from this, in the parent directory of source use the command:
flex -L -t source/compactOwl.lex > source/compactOwl.cc

To run the executable use the command

compactOwl < [owl file in] > [owl file out]

where [owl file in] and [owl file out] are replaced by file names.

*/

#include <math.h>
#include <string>            // for string
#include <set>

char buffer[200];
std::set<std::string> sett;
std::set<std::string>::iterator iter;

%}

%x ANNOT
%x DIF

%%

"Annotation(rdfs:comment"   {BEGIN ANNOT; /* delete annotation start */}
<ANNOT>.                    { /* delete annotation middle */}
<ANNOT>\n                   { /* delete annotation middle */}
<ANNOT>"\")"\n\n\n          {BEGIN(INITIAL); /* delete annotation end */ }
<ANNOT>"\")"\n\n            {BEGIN(INITIAL); /* delete annotation end */ }
<ANNOT>"\")"\n              {BEGIN(INITIAL); /* delete annotation end */ }

^"DifferentIndividuals("    {ECHO; BEGIN(DIF);}
<DIF>")"                    { /* print stored DifferentIndividuals */
                              printf("\n");
                              for (iter = sett.begin(); iter != sett.end(); )
				{
				  printf((*iter).c_str());
				  iter++;
				  if (iter == sett.end())
				    {
				      printf(")");
				      sett.clear();
				      break;
				    }
				  else
				    printf("\n");
				}
                             BEGIN(INITIAL);
                            }
<DIF>\n\n                   { }
<DIF>\n                     { }
<DIF>" :"[^)\n]*            { /* store DifferentIndividuals in alpha order */
			      if (yytext[0] != 0)
				sett.insert(yytext+1);
                            }
<DIF>.                      {ECHO;}

^"//".*\n                   { /* delete comment line with one endline*/}
^"//".*\n\n                 { /* delete comment line with two endlines */}
^"//".*\n\n\n               { /* delete comment line with three endlines */}
\n" "*:                     {printf(" :"); /* join lines, colon starts 2nd */}
\n" "*"\""                  {printf(" \""); /* join lines, quote starts 2nd */}
\n\n\n                      {printf("\n"); /* reduce 3 newlines to one */ }
\n\n                        {printf("\n"); /* reduce 2 newlines to one */}

[0-9]"."[0-9]+              {printf("%f", atof(yytext)); /* print numbers */}
.                           {ECHO; /* echo everything else */}

%%

int yywrap()
{
  return 1;
}

int main()
{
  yylex();
  return 1;
}
