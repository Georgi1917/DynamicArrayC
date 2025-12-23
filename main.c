#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib/d_string_arr.h"

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

    List_Strings strs = { 0 };

    append_string(&strs, "Pesho1");
    append_string(&strs, "Pesho2");
    append_string(&strs, "Pesho3");
    append_string(&strs, "Pesho4");
    append_string(&strs, "Pesho5");

    printf("Before Delete : \n");
    for (size_t i = 0; i < strs.count; i++) printf("%s\n", strs.items[i]);
    
    printf("After Delete : \n");
    delete_string(&strs, 1);
    delete_string(&strs, 1);
    delete_string(&strs, 0);    
    for (size_t i = 0; i < strs.count; i++) printf("%s\n", strs.items[i]);

    free_string_arr(&strs);

    return 0;

}