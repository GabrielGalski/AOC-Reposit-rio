#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char **nomes = NULL;
    int numNomes = 0;
    int op;

    do
    {
        printf("\nselecione:\n1. adicionar nome\n2. remover nome\n3. listar\n4. sair\n");
        scanf("%d", &op);
        getchar();

        switch (op)
        {
        case 1:
        {
            char buffer[100];
            printf("digite o nome que deseja adicionar:\n");
            scanf(" %[^\n]", buffer);

            char **temp = realloc(nomes, (numNomes + 1) * sizeof(char *));

            nomes = temp;

            nomes[numNomes] = malloc((strlen(buffer) + 1) * sizeof(char));

            strcpy(nomes[numNomes], buffer);

            numNomes++;
            printf("Nome adicionado com sucesso.\n");
            break;
        }

        case 2:
        {
            if (numNomes == 0)
            {
                printf("a lista está vazia.\n");
                break;
            }

            char buffer[100];
            printf("digite o nome que deseja remover:\n");
            scanf(" %[^\n]", buffer);

            int encontrado = -1;
            for (int i = 0; i < numNomes; i++)
            {
                if (strcmp(nomes[i], buffer) == 0)
                {
                    encontrado = i;
                    break;
                }
            }

            if (encontrado == -1)
            {
                printf("nome não encontrado\n");
            }
            else
            {
                free(nomes[encontrado]);
                for (int i = encontrado; i < numNomes - 1; i++)
                {
                    nomes[i] = nomes[i + 1];
                }

                numNomes--;
                char **temp = realloc(nomes, numNomes * sizeof(char *));
                if (temp != NULL || numNomes == 0)
                {
                    nomes = temp;
                }
                printf("nome removido\n");
            }
            break;
        }

        case 3:
        {
            if (numNomes == 0)
            {
                printf("lista vazia.\n");
            }
            else
            {
                printf("nomes:\n");
                for (int i = 0; i < numNomes; i++)
                {
                    printf("%s", nomes[i]);
                }
            }

            break;
        }

        case 4:
            printf("saindo...\n");
            return 0;
            break;

        default:
            printf("erro\n");
            break;
        }

    } while (op != 4);

    for (int i = 0; i < numNomes; i++)
    {
        free(nomes[i]);
    }
    free(nomes);

    return 0;
}
