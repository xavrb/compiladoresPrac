%{
#include <stdio.h>
#include<stdlib.h>
%}


%option noyywrap
string [_]*[a-zA-Z]+[0-9]*
number [-{1}|+?]*[0-9]+
numberf [-{1}|+?]*[0-9]+\.[0-9]+

%%
{string}"="{number} {printf("VARIABLE\t");
                      ECHO;
}
{string} {printf("\nVARIABLE "); ECHO;}
{string}"="{numberf} {printf("\nVARIABLE "); ECHO;}
{numberf} {printf("\nFloat "); ECHO;}
{number} {printf("\nInteger "); ECHO;}
({numberf}|{number})"^"({numberf}|{number}) {printf("\nReal Exponential "); ECHO;}
({numberf}|{number})"+"({numberf}|{number}) {printf("\nSUM "); ECHO;}
({numberf}|{number})"-"({numberf}|{number}) {printf("\nSUBS "); ECHO;}
({numberf}|{number})"*"({numberf}|{number}) {printf("\nMULT "); ECHO;}
({numberf}|{number})"/"({numberf}|{number}) {printf("\nDIV "); ECHO;}
({numberf}|{number})("MOD"|"mod")({numberf}|{number}) {printf("\nMOD ");  ECHO;}

%%
int main(void){
    /* Ejecuta el ''lexer'', y después termina. */
 
    printf("COMPILADORES\n");
    printf("Mejía  Javier\n\n");
    printf("Ingrese cadena a evaluar:\n>>");
    yylex();
    return 0;
}
