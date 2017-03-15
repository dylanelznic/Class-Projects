/* 
   Dylan Elznic
   CS 3500 Homework 2
   Prof. Gosnell, Sec. A
*/

		               /* ---- PROLOGUE ---- */
%{
#include <iostream>
using namespace std;

int no_lines = 0;
int count = 0;
%}
		              /* ---- DEFINITIONS ---- */
%option noyywrap
DIGIT		[0-9]

%%  		          /* ---- REGULAR EXPRESSIONS ---- */

[ \t]          					  												;
\n              				  												{ no_lines++; }

"if"|"then"|"else"|"while"|"end"|"banana"										{ cout << "#" << count << ": TOKEN: KEYWORD    LEXEME: " << yytext << endl; count++;}

[+-]?[0-9]+  																    { cout << "#" << count << ": TOKEN: INTCONST   LEXEME: " << yytext << endl; count++;}
[+-]?[0-9]+[.][0-9]+  											  			    { cout << "#" << count << ": TOKEN: DECCONST   LEXEME: " << yytext << endl; count++;}
[+-]?[0-9]+[.][0-9]+[E][-]?[0-9]+ 								 			    { cout << "#" << count << ": TOKEN: SCICONST   LEXEME: " << yytext << endl; count++;}
([A-F]+|[0-9]+)[H]												   			    { cout << "#" << count << ": TOKEN: HEXCONST   LEXEME: " << yytext << endl; count++;}
[0-1]+[B]						 											    { cout << "#" << count << ": TOKEN: BINCONST   LEXEME: " << yytext << endl; count++;}

([A-Za-z][A-Za-z0-9]*[.]?)+[@]([A-Za-z][A-Za-z0-9]*[.]?)+(".com"|".edu"|".net")	{ cout << "#" << count << ": TOKEN: EMCONST    LEXEME: " << yytext << endl; count++;}
[A-Za-z][A-Za-z0-9]*												 			{ cout << "#" << count << ": TOKEN: IDENT      LEXEME: " << yytext << endl; count++;}
["][A-Za-z0-9 ]*["]													 			{ cout << "#" << count << ": TOKEN: STRCONST   LEXEME: " << yytext << endl; count++;}
"+"|"-"|"*"|"/"|"<"|">"|"&"	  										 			{ cout << "#" << count << ": TOKEN: OPERATOR   LEXEME: " << yytext << endl; count++;}

\%(.)*$							 									 			{}
.																	 			{ cout << "#" << count << ": TOKEN: ?          LEXEME: " << yytext << endl; count++;}

%%  		          /* ---- EPILOGUE ---- */

int main()
{
    yylex();
	cout<< no_lines << " lines processed." << endl;
    return 0;
}