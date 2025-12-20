#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

#define list_delete(List, index) \
    if (index > List.count) \
    { \
        printf("error while deleting..."); \
    } \
    \
    int *temp = malloc((List.count - 1) * sizeof(*List.items)); \
    \
    memmove(temp, List.items, (index + 1) * sizeof(*List.items)); \
    memmove(temp + index, (List.items) + (index + 1), (List.count - index) * sizeof(*List.items)); \
    \
    free(List.items); \
    List.count--; \
    List.items = temp; 


int main()
{

    Numbers nums = { 0 };
    
    for (int i = 0; i < 10; i++) { list_append(nums, i); }

    printf("Before Delete: \n");
    for (size_t i = 0; i < nums.count; i++) printf("%d ", nums.items[i]);
    
    list_delete(nums, 7);
    printf("\nAfter Delete: \n");
    for (size_t i = 0; i < nums.count; i++) printf("%d ", nums.items[i]);

    free(nums.items);

    return 0;

}