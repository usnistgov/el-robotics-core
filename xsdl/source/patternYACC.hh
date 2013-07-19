/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
     ANYCLASS = 258,
     ASTERISKCHAR = 259,
     BACKSLASHCHAR = 260,
     BAD = 261,
     CARRIAGERETURN = 262,
     COLONCHAR = 263,
     COMMA = 264,
     DASHCHAR = 265,
     DIGIT = 266,
     DIGITCLASS = 267,
     HATCHAR = 268,
     INITIALCLASS = 269,
     LBRACKET = 270,
     LBRACKETCHAR = 271,
     LCURLY = 272,
     LCURLYCHAR = 273,
     LETTER = 274,
     LPAREN = 275,
     LPARENCHAR = 276,
     NAMECLASS = 277,
     NEGATE = 278,
     NEWLINE = 279,
     NOTDIGITCLASS = 280,
     NOTINITIALCLASS = 281,
     NOTNAMECLASS = 282,
     NOTWEIRDCLASS = 283,
     NOTWHITESPACECLASS = 284,
     ONETOMANY = 285,
     ORBAR = 286,
     PERIODCHAR = 287,
     PLUSCHAR = 288,
     QUESTIONCHAR = 289,
     QUOTE = 290,
     RANGER = 291,
     RBRACKET = 292,
     RBRACKETCHAR = 293,
     RCURLY = 294,
     RCURLYCHAR = 295,
     RPAREN = 296,
     RPARENCHAR = 297,
     SUBTRACTER = 298,
     TAB = 299,
     UNDERSCORECHAR = 300,
     VERTICALBARCHAR = 301,
     WEIRDCLASS = 302,
     WHITESPACECLASS = 303,
     ZEROORONE = 304,
     ZEROTOMANY = 305
   };
#endif
/* Tokens.  */
#define ANYCLASS 258
#define ASTERISKCHAR 259
#define BACKSLASHCHAR 260
#define BAD 261
#define CARRIAGERETURN 262
#define COLONCHAR 263
#define COMMA 264
#define DASHCHAR 265
#define DIGIT 266
#define DIGITCLASS 267
#define HATCHAR 268
#define INITIALCLASS 269
#define LBRACKET 270
#define LBRACKETCHAR 271
#define LCURLY 272
#define LCURLYCHAR 273
#define LETTER 274
#define LPAREN 275
#define LPARENCHAR 276
#define NAMECLASS 277
#define NEGATE 278
#define NEWLINE 279
#define NOTDIGITCLASS 280
#define NOTINITIALCLASS 281
#define NOTNAMECLASS 282
#define NOTWEIRDCLASS 283
#define NOTWHITESPACECLASS 284
#define ONETOMANY 285
#define ORBAR 286
#define PERIODCHAR 287
#define PLUSCHAR 288
#define QUESTIONCHAR 289
#define QUOTE 290
#define RANGER 291
#define RBRACKET 292
#define RBRACKETCHAR 293
#define RCURLY 294
#define RCURLYCHAR 295
#define RPAREN 296
#define RPARENCHAR 297
#define SUBTRACTER 298
#define TAB 299
#define UNDERSCORECHAR 300
#define VERTICALBARCHAR 301
#define WEIRDCLASS 302
#define WHITESPACECLASS 303
#define ZEROORONE 304
#define ZEROTOMANY 305




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yyrelval;

