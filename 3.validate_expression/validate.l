%{
#include "y.tab.h"
%}
%%
[a-zA-Z] {return VARIABLE;}
[0-9] {return NUMBER;}
[\t]+ ;
[\n] {return '\n';}
. {return yytext[0];}
%%

