%{
#include<stdio.h>
#include<stdlib.h>
int yylex();
int yyerror();
int valid=1;
%}
%token NUMBER LETTER
%%
start: LETTER s;
s: LETTER s
  | NUMBER s 
  |
  ;
%%
int main()
{
printf("Enter the Variable: \n");
yyparse();
if(valid)
{
printf("This variable is Valid. \n");
}
return 0;
}
int yyerror()
{
printf("This Variable is Invalid! \n");
valid=0;
exit(0);
} 
