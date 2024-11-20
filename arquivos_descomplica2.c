#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *arq = fopen("arq.txt", "r");

    int linha = 0;
    char c;

    while ((c = fgetc(arq)) != EOF)
    {
        if (c == '\n')
        {
        }
    }

    fclose(arq);

    printf("o arquivo tem %d linhas\n", linha);

    return 0;
}
