%{
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int yylex();
int yyerror();
%}
%token NUMBER
%left '+' '-'
%left '*' '/' '%'
%left '(' ')'
%%
expression:e {printf("Result=%d \n",$$); return 0;};
e:e'+'e{$$=$1+$3;}
  | e'-'e{$$=$1-$3;}
  | e'*'e{$$=$1*$3;}
  | e'/'e{$$=$1/$3;}
  | e'%'e{$$=$1%$3;}
  | '('e')'{$$=$2;}
  | NUMBER{$$=$1;}
  ;
%%
int main()
{
printf("Enter the arithmetic expression: \n");
yyparse();
return 0;
}
int yyerror()
{
printf("This Expression can't be evaluated! \n");
exit(0);
}
