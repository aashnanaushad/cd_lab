%{
#include "y.tab.h"
%}
%%
[a-zA-Z_][a-zA-Z_0-9]* {return LETTER;}
[0-9] {return NUMBER;}
[\n] {return 0;}
. {return yytext[0];}
%%
