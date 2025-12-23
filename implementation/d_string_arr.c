#include "../lib/d_string_arr.h"

void append_string(List_Strings *List, char* item)
{

    if (List->count >= List->capacity)
    {
        if (List->capacity == 0) List->capacity = 20;
        else List->capacity *= 2;
        List->items = realloc(List->items, List->capacity * sizeof(char *));
    }

    List->items[List->count] = malloc((strlen(item) + 1) * sizeof(char));
    strcpy(List->items[List->count], item);
    List->count++;

}

void free_string_arr(List_Strings *List)
{

    for (size_t i = 0; i < List->count; i++) free(List->items[i]);

    free(List->items);

}

void delete_string(List_Strings *List, size_t index)
{

    if (index < 0 || index > List->count) return;

    List_Strings new = { 0 };

    for (size_t i = 0; i < index; i++) 
        append_string(&new, List->items[i]);
    for (size_t i = (index + 1); i < List->count; i++) 
        append_string(&new, List->items[i]);

    free_string_arr(List);

    List->count--;
    List->items = new.items;

}