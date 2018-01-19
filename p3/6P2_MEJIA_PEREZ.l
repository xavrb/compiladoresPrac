%{
#include "6P2_MEJIA.tab.h"
#include <stdlib.h>

%}

digito [0-9]
 
 

%%

[-{1}|+?]*[0-9]+"."[-{1}|+?]*[0-9]+ { yylval.real = atof(yytext); return REAL;}
[-{1}|+?]*[0-9]+ { yylval.entero = atoi(yytext); return ENTERO;}

"+" return SUMA;
"-" return RESTA;
"*" return MULT;
"/" return DIVISION;
"^" return POTENCIA;
"(" return ABRE_P;
")" return CIERRA_P;
"," return COMA;
"\n" return SALTO_LINEA;
"MOD"|"mod" return MODULO;

%%
