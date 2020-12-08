#include <stdio.h>
#include <ctype.h>

char stack[100], result[100];
int top = -1, resultTop = -1;
char s = 65;
void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if (top == -1)
        return -1;
    else
        return stack[top--];
}
void printStack()
{
    for (int i = 0; i < top; i++)
    {
        printf("\n%c ", stack[i]);
    }
}
int priority(char x)
{
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return 0;
}

int main()
{
    char exp[100];
    char *e, x;
    int a, b;
    printf("Enter the expression : ");
    scanf("%s", exp);
    printf("\n");
    e = exp;
    printf("Three address code for the expression is:");
    while (*e != '\0')
    {
        if (isalnum(*e))
        {
            result[++resultTop] = *e;
        }
        else if (*e == '(')
            push(*e);
        else if (*e == ')')
        {
            while ((x = pop()) != '(')
            {
                b = result[resultTop--];
                a = result[resultTop--];
                printf("\n%c = %c %c %c", s, a, x, b);
                result[++resultTop] = s;
                s++;
            }
        }
        else
        {
            //printStack();
            //printf("%c",*e);
            while (priority(stack[top]) >= priority(*e))
            {
                x = pop();
                b = result[resultTop--];
                a = result[resultTop--];
                printf("\n%c = %c %c %c", s, a, x, b);
                result[++resultTop] = s;
                s++;
            }
            push(*e);
        }
        e++;
    }
    while (top != -1)
    {
        x = pop();
        if (x != '(')
        {
            b = result[resultTop--];
            a = result[resultTop--];
            printf("\n%c = %c %c %c", s, a, x, b);
            result[++resultTop] = s;
            s++;
        }
    }
    return 0;
}