/* A Bison parser, made by GNU Bison 2.4.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006,
   2009, 2010 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     BAD = 258,
     DATASTRING = 259,
     ENCODING = 260,
     ENDITEM = 261,
     ENDVERSION = 262,
     SCHEMALOCATION = 263,
     STARTVERSION = 264,
     TERMINALSTRING = 265,
     XMLNSPREFIX = 266,
     XMLNSTARGET = 267,
     XMLVERSION = 268,
     CENTEREND = 269,
     CENTERSTART = 270,
     CIRCLEINSTANCEEND = 271,
     CIRCLEINSTANCESTART = 272,
     CIRCLESANDSPHERESEND = 273,
     CIRCLESANDSPHERESSTART = 274,
     IEND = 275,
     ISTART = 276,
     JEND = 277,
     JSTART = 278,
     KEND = 279,
     KSTART = 280,
     NAMEEND = 281,
     NAMESTART = 282,
     NORMALEND = 283,
     NORMALSTART = 284,
     RADIUSEND = 285,
     RADIUSSTART = 286,
     SPHEREINSTANCEEND = 287,
     SPHEREINSTANCESTART = 288,
     XEND = 289,
     XSTART = 290,
     YEND = 291,
     YSTART = 292,
     ZEND = 293,
     ZSTART = 294,
     CIRCLETYPEDECL = 295,
     SPHERETYPEDECL = 296
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{


  SchemaLocation *                    SchemaLocationVal;
  XmlHeaderForCirclesAndSpheres *     XmlHeaderForCirclesAndSpheresVal;
  XmlVersion *                        XmlVersionVal;
  int *                               iVal;
  char *                              sVal;
  XmlDouble *                         XmlDoubleVal;
  XmlID *                             XmlIDVal;

  CirclesAndSpheresFile *             CirclesAndSpheresFileVal;

  CircleType *                        CircleTypeVal;
  CirclesAndSpheresType *             CirclesAndSpheresTypeVal;
  std::list<CircleType *> *           ListCircleTypeVal;
  std::list<SphereType *> *           ListSphereTypeVal;
  PointType *                         PointTypeVal;
  SphereType *                        SphereTypeVal;
  VectorType *                        VectorTypeVal;



} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


