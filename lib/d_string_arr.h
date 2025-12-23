#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#pragma once

typedef struct 
{

    char **items;
    size_t count;
    size_t capacity;

} List_Strings;

void append_string(List_Strings *List, char* item);
void free_string_arr(List_Strings *List);
void delete_string(List_Strings *List, size_t index);