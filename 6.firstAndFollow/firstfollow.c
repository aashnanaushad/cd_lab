#include <stdio.h>
#include <string.h>
#include <ctype.h>
char a[10][10], f[10];
int n, m = 0, p, i = 0, j = 0;
void first(char c);
void follow(char c);

void first(char c)
{
    if (!isupper(c))
    {
        f[m++] = c;
    }
    for (int k = 0; k < n; k++)
    {
        if (a[k][0] == c)
        {
            if (a[k][2] == '$')
                follow(a[k][0]);
            else if (islower(a[k][2]))
                f[m++] = a[k][2];
            else
                first(a[k][2]);
        }
    }
}
void follow(char c)
{
    if (a[0][0] == c)
    {
        f[m++] = '$';
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 2; j < strlen(a[i]); j++)
        {
            if (a[i][j] == c)
            {
                if (a[i][j + 1] != '\0')
                    first(a[i][j + 1]);
                if (a[i][j + 1] == '\0' && c != a[i][0])
                    follow(a[i][0]);
            }
        }
    }
}
int main()
{
    int i, z;
    char c, ch;
    printf("\nEnter the number of productions: ");
    scanf("%d", &n);
    printf("\nEnter the productions\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%s%c", a[i], &ch);
    }
    do
    {
        m = 0;
        printf("Enter the element whose first and follow is to be calculated:");
        scanf("%c", &c);
        first(c);
        printf("First of %c is ", c);
        for (int i = 0; i < m; i++)
            printf("%c", f[i]);
        printf("\n");
        strcpy(f, " ");
        m = 0;
        follow(c);
        printf("Follow of %c is ", c);
        for (int i = 0; i < m; i++)
            printf("%c", f[i]);
        printf("\n");
        strcpy(f, " ");
        printf("Continue(0/1)?");
        scanf("%d%c", &z, &ch);
    } while (z == 1);
    return 0;
}