#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{

    int *items;
    size_t count;
    size_t capacity;

} Numbers;

typedef struct 
{

    char **items;
    size_t count;
    size_t capacity;

} List_Strings;


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

    list_append(strs, "gsldhgsdhgjsdghsldk;gjpiogow");
    list_append(strs, "fou9317yrhoeng/v");
    list_append(strs, "azxcgwe4asfadf");

    for (size_t i = 0; i < strs.count; i++) printf("%s\n", strs.items[i]);

    free(strs.items);

    return 0;

}