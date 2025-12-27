#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef enum 
{

    INT,
    FLOAT,
    DOUBLE,
    CHAR

} _List_Type ;

typedef struct 
{

    int *items;
    size_t count;
    size_t capacity;
    _List_Type _list_type;

} Int_List;

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
    if (List._list_type == INT) \
    { \
        _list_delete_int(&List, index); \
    }; 

#define list_free(List) \
    free(List.items);

Int_List init_list();
void _list_delete_int(Int_List *List, size_t index);
