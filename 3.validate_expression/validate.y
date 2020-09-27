%{
#include<stdio.h>
#include<stdlib.h>
int yylex();
int yyerror();
%}
%token NUMBER VARIABLE
%left '+' '-'
%left '*' '/'
%%
grammar:e '\n' {printf("This Arithmetic Expression is Valid. \n"); exit(0);};
e:e'+'e
  | e'-'e
  | e'*'e
  | e'/'e
  | '('e')'
  | NUMBER
  | VARIABLE ;
%%
int main()
{
printf("Enter the arithmetic expression: \n");
yyparse();
return 0;
}
int yyerror()
{
printf("This Arithmetic Expression is Invalid! \n");
exit(0);
} 
