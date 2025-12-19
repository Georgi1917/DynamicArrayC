#include <stdio.h>
#include <stdlib.h>

int main()
{

    int initial_size = 10;
    int *a = (int *)malloc(initial_size * sizeof(int));

    for (int i = 0; i < 100; i++)
    {
        a[i] = i + 1;
    }

    for (int i = 0; i < 100; i++)
    {
        printf("a : %d\n", a[i]);
    }

    return 0;

}