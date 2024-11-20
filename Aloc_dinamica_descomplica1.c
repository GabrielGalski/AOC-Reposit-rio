#include <stdio.h>
#include <stdlib.h>

int main()
{

    int *num = malloc(5 * sizeof(int));

    for (int i = 0; i < 5; i++)
    {

        printf("digite o numero %d:\n", i + 1);
        scanf("%d", &num[i]);
    }

    for (int i = 0; i < 5; i++)
    {

        printf("%d ", num[i]);
    }

    free(num);

    return 0;
}
