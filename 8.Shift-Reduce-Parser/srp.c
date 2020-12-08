#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int z = 0, i = 0, j = 0, c = 0;
char a[16], ac[20], stk[15], act[10];

void check()
{
    strcpy(ac, "REDUCE TO S -> ");
    for (z = 0; z < c; z++)
    {

        if (stk[z] == 'i')
        {
            printf("%si", ac);
            stk[z] = 'S';
            stk[z + 1] = '\0';
            printf("\n$%s\t\t%s$\t\t", stk, a);
        }
    }

    for (z = 0; z < c - 2; z++)
    {
        if (stk[z] == 'S' && stk[z + 1] == '+' && stk[z + 2] == 'S')
        {
            printf("%sS+S", ac);
            stk[z] = 'S';
            stk[z + 1] = '\0';
            stk[z + 2] = '\0';
            printf("\n$%s\t\t%s$\t\t", stk, a);
            i = i - 2;
        }
    }

    for (z = 0; z < c - 2; z++)
    {
        if (stk[z] == 'S' && stk[z + 1] == '*' && stk[z + 2] == 'S')
        {
            printf("%sS*S", ac);
            stk[z] = 'S';
            stk[z + 1] = '\0';
            stk[z + 1] = '\0';
            printf("\n$%s\t\t%s$\t\t", stk, a);
            i = i - 2;
        }
    }
    return;
}

int main()
{
    printf("GRAMMAR is -\nS->S+S \nE->S*S \nS->i\n");
    printf("Enter the input string:");
    scanf("%s", a);
    c = strlen(a);
    strcpy(act, "SHIFT");
    printf("\nstack \t\t input \t\t action\n");
    printf("\n$\t\t%s$\t\t", a);

    for (i = 0; j < c; i++, j++)
    {
        printf("%s", act);
        stk[i] = a[j];
        stk[i + 1] = '\0';
        a[j] = ' ';
        printf("\n$%s\t\t%s$\t\t", stk, a);
        check();
    }
    check();
    if (stk[0] == 'S' && stk[1] == '\0')
        printf("Accept\n");
    else
        printf("Reject\n");
}