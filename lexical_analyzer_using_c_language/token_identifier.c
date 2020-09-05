#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
void keywordOrIdentifier(char word[])
{
    FILE *fp1;
    char word2[30], type[30];
    int pos = 0, flag = 0;
    fp1 = fopen("keyword_identifier.txt", "r+");
    if (fp1 != NULL)
    {
        while (!feof(fp1))
        {
            fscanf(fp1, "%s %s", &word2, &type);
            pos++;
            if (strcmp(word, word2) == 0)
            {
                if (strcmp(type, "keyword") == 0)
                    printf("%s - keyword \n", word);
                else
                    printf("%s - identifier ( %d ) \n", word, pos);
                flag = 1;
            }
        }
        if (flag == 0)
        {
            pos++;
            fprintf(fp1, "\n%s %s", word, "identifier");
            printf("%s - identifier ( %d )\n", word, pos);
        }
    }
    fclose(fp1);
}
int main()
{
    FILE *fp;
    char ch, word[30], word1[30];
    int state = 0;
    fp = fopen("add.c", "r");
    if (fp != NULL)
    {
        while ((ch = fgetc(fp)) != EOF)
        {
            switch (state)
            {
            case 0:
                if (isalpha(ch) != 0)
                {
                    strncat(word, &ch, 1);
                    state = 1;
                }
                else if (isdigit(ch) != 0)
                {
                    printf("%c", ch);
                    state = 3;
                }
                else
                {
                    state = 0;
                    strcpy(word, word1);
                }
                break;
            case 1:
                if (isalpha(ch) != 0 || isdigit(ch) != 0)
                {
                    strncat(word, &ch, 1);
                    state = 1;
                    break;
                }
                else
                    state = 2;
            case 2:
                keywordOrIdentifier(word);
                state = 0;
                strcpy(word, word1);
                break;
            case 3:
                if (isdigit(ch) != 0)
                {
                    printf("%c", ch);
                    state = 3;
                    break;
                }
                else
                    state = 4;
            case 4:
                printf(" - number \n");
                state = 0;
                break;
            default:
                break;
            }
        }
    }
    else
    {
        printf("The file is missing!");
    }
    fclose(fp);
    return 0;
}