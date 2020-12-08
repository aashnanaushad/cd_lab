//S->(S')
//S'->[a-zA-Z]-a
#include <stdio.h>
#include <ctype.h>
char *ip, expression[50];
int Sdash();
int S()
{
    if (*ip == '(')
    {
        printf("\n%s", ip);
        ip++;
        if (Sdash())
        {
            if (*ip == ')')
                return 1;
            else
            {
                return 0;
            }
        }
        else
            return 0;
    }
    else
    {
        return 0;
    }
}
int Sdash()
{
    if (isalpha(*ip))
    {
        printf("\n%s", ip);
        ip++;
        if (*ip == '-')
        {
            printf("\n%s", ip);
            ip++;
            if (*ip == 'a')
            {
                printf("\n%s", ip);
                ip++;
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}
int main()
{
    printf("\nEnter the expresssion to be evaluated:");
    scanf("%s", expression);
    ip = expression;
    if (S())
    {
        printf("\nExpression is Valid");
    }
    else
    {
        printf("\nExpression is Invalid");
    }
}