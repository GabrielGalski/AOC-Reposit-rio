#include <stdio.h>

int main()
{
    FILE *arq;
    char caractere;

    arq = fopen("arq.txt", "w");
    printf("\n- digite '0' para sair -\n");

    while (1)
    {

        printf("digite um caractere:");
        caractere = getchar();
        getchar();

        if (caractere == '0')
        {
            break;
        }

        fputc(caractere, arq);
    }

    fclose(arq);
    printf("fechando...\n");

    FILE *arq_open;
    arq_open = fopen("arq.txt", "r");

    printf("caracteres:\n");

    while ((caractere = fgetc(arq_open)) != EOF)
    {
        putchar(caractere);
    }

    fclose(arq_open);
    printf("\nfechando...\n");

    return 0;
}
