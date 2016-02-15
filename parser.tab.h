/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NUM = 258,
    ID = 259,
    CARACTER = 260,
    TOKEN_TRUE = 261,
    TOKEN_FALSE = 262,
    TOKEN_PUNTO = 263,
    TOKEN_DOSPUNT = 264,
    TOKEN_PARABRE = 265,
    TOKEN_PARCIERRA = 266,
    TOKEN_SUMA = 267,
    TOKEN_RESTA = 268,
    TOKEN_MULT = 269,
    TOKEN_DIV = 270,
    TOKEN_MOD = 271,
    TOKEN_CONJ = 272,
    TOKEN_DISY = 273,
    TOKEN_NEG = 274,
    TOKEN_MENOR = 275,
    TOKEN_MAYOR = 276,
    TOKEN_MENORIG = 277,
    TOKEN_MAYORIG = 278,
    TOKEN_CREATE = 279,
    TOKEN_WHILE = 280,
    TOKEN_BOOL = 281,
    TOKEN_INT = 282,
    TOKEN_CHAR = 283,
    TOKEN_IF = 284,
    TOKEN_ELSE = 285,
    TOKEN_SEND = 286,
    TOKEN_EXECUTE = 287,
    TOKEN_ON = 288,
    TOKEN_STORE = 289,
    TOKEN_BOT = 290,
    TOKEN_DESIGUAL = 291,
    TOKEN_IGUAL = 292,
    TOKEN_COMA = 293,
    TOKEN_DEFAULT = 294,
    TOKEN_COLLECT = 295,
    TOKEN_DROP = 296,
    TOKEN_UP = 297,
    TOKEN_DOWN = 298,
    TOKEN_RIGHT = 299,
    TOKEN_LEFT = 300,
    TOKEN_READ = 301,
    TOKEN_AS = 302,
    TOKEN_RECEIVE = 303,
    TOKEN_ADVANCE = 304,
    TOKEN_ACTIVATE = 305,
    TOKEN_ACTIVATION = 306,
    TOKEN_DEACTIVATE = 307,
    TOKEN_DEACTIVATION = 308,
    TOKEN_END = 309
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 24 "parser.y" /* yacc.c:1909  */

	int value;
	char name[200];
	char carac;
	algExpression *algExp;
	boolExpression *boolExp;
	Expression *exp;
	instruccion *inst;
	declaracion *decl;
	listaIDs *idl;

#line 121 "parser.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
