%{
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
extern char *yytext;

%}
%union{
	int entero;
	double real;
};
%token <real> REAL
%token <entero> ENTERO
%type <entero> integerExp
%type <real> realExp

%token SUMA RESTA MULT DIVISION POTENCIA MODULO
%token ABRE_P CIERRA_P COMA 
%token SALTO_LINEA


%left SUMA RESTA
%left MULT DIVISION
%left NEGATIVO
%left POTENCIA

%start input
%%

input:
    
     | input line
;

line:
     SALTO_LINEA
     | realExp SALTO_LINEA { printf("Resultado: %.2f\n", $1); }
     | integerExp SALTO_LINEA { printf("Resultado: %d\n", $1); }
;

realExp:
 		
		REAL { $$=$1; }
			|		realExp SUMA realExp { $$ = $1 + $3; }
			| 	realExp RESTA realExp { $$ = $1 - $3; }
			| 	realExp MULT realExp { $$ = $1 * $3; }
			| 	realExp DIVISION realExp { $$ = $1 / $3; }
			| 	RESTA realExp %prec NEGATIVO { $$ = -$2; }
			| 	realExp POTENCIA realExp { $$ = pow($1, $3); }
			| 	ABRE_P realExp CIERRA_P { $$ = $2; }
			| 	MODULO ABRE_P realExp COMA realExp CIERRA_P { $$ = fmod($3,$5); }
;

integerExp:
		ENTERO { $$=$1; }
			|		integerExp SUMA integerExp { $$ = $1 + $3; }
			| 	integerExp RESTA integerExp { $$ = $1 - $3; }
			| 	integerExp MULT integerExp { $$ = $1 * $3; }
			| 	integerExp DIVISION integerExp { $$ = $1 / $3; }
			| 	RESTA integerExp %prec NEGATIVO { $$ = -$2; }
			| 	integerExp POTENCIA integerExp { $$ = pow($1, $3); }
			| 	ABRE_P integerExp CIERRA_P { $$ = $2; }
			| 	MODULO ABRE_P integerExp COMA integerExp CIERRA_P { $$ = fmod($3,$5); }
;

%%

int main(){
 
	printf("Escuela Superior de Cómputo\n");
	printf("COMPILADORES\n Práctica 3\n");
	printf("Mejía Pérez Javier\n\n");
	printf("Ingrese cadena a evaluar:\n>>");
	yyparse();
}
             
yyerror (char *s){
	printf ("%s\n", s);
}

             
int yywrap(){  
	return 1;  
}  
