#include <stdio.h>
#include <stdlib.h>

typedef struct 
{

    int *items;
    size_t count;
    size_t capacity;

} Numbers;

#define list_append(List, item) \
    if (List.count >= List.capacity) \
        { \
            \
            if (List.capacity == 0) List.capacity = 20; \
            else List.capacity *= 2; \
            List.items = realloc(List.items, List.capacity * sizeof(*List.items)); \
            \
        } \
        List.items[List.count++] = item; \


int main()
{

    Numbers nums = { 0 };
    
    for (int i = 0; i < 50; i++)
    {
        
        list_append(nums, i);

    }

    for (size_t i = 0; i < nums.count; i++)
    {
        
        printf("%d\n", nums.items[i]);

    }

    free(nums.items);

    return 0;

}