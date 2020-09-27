#include <stdio.h>
#include <stdlib.h>
static int mat[20][20], n, c, r;
int ans[20];
void calc(int x)
{
    int i;
    ans[c++] = x;
    for (i = 0; i <= n; i++)
        if (mat[x][i])
            calc(i);
}
void main()
{
    int i, j, k;
    char s;
    FILE *fp;
    fp = fopen("input.txt", "r");
    fscanf(fp, "%d", &n);
    printf("\ntotal number of transitions is %d", n);
    printf("\n the transitions are\n");
    while (!feof(fp))
    {
        fscanf(fp, "%d %c %d", &r, &s, &c);
        printf("\n%d %c %d", r, s, c);
        if (s == 'e')
            mat[r][c] = 1;
    }
    for (j = 0; j <= r; j++)
    {
        c = 0;
        calc(j);
        printf("\n e-closure of state %d is {", j);
        for (i = 0; i < c - 1; i++)
            printf(" %d ", ans[i]);
        printf("%d }\n\n", ans[i]);
    }
    fclose(fp);
}