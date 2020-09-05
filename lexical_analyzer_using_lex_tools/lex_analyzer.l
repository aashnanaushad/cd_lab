%{
#include <stdio.h>
int main();

%}

numbers ([0-9])+
keywords auto|break|case|char|continue|do|default|const|double|else|enum|extern|for|if|goto|float|int|long|register|return|signed|static|sizeof|short|struct|switch|typedef|union|void|while|volatile|unsigned
identifiers [a-z|A-Z]([a-z|A-Z|0-9])*
operators "+"|"-"|"*"|"/"|"%"|"++"|"--"|"="|">"|"<"|">="|"<="|"!="|"=="|"&&"|"||"|"!"|"&"|"|"
delimiter ";"
sc "@"|"$"|"#"
other "("|")"|"{"|"}"|"'"|"\n"|"\t"|" "|","

%%
{numbers} {printf("%s - number\n",yytext);}
{keywords} {printf("%s - keyword\n",yytext);}
{identifiers} {printf("%s - identifier\n",yytext);}
{operators} {printf("%s - operator\n",yytext);}
{delimiter} {printf("%s - delimiter\n",yytext);}
{sc} {printf("%s - special characters\n",yytext);}
{other} {}
%%

int main(){

	FILE *fp;
	fp=fopen("input.c","r");
	yyin=fp;
	yylex();
	fclose(fp);
	return 0;
}
