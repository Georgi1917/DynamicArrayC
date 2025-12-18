#include <stdio.h>
#include <stdlib.h>

int main()
{

    int *a = (int *)malloc(100 * sizeof(int));

    if (a == NULL)
    {
        printf("Init failed");
        exit(0);
    }
    
    for (int i = 0; i < 100; i++)
    {
        a[i] = i;
    }

    for (int j = 0; j < 100; j++)
    {
        printf("%d\n", a[j]);
    }

    return 0;

}