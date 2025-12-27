#include "../lib/dynamic_arrays.h"

Int_List init_list()
{

    Int_List list = { 0 };
    list._list_type = INT;

    return list;

}

void _list_delete_int(Int_List *List, size_t index)
{

    if (index > List->count) 
    { 
        printf("error while deleting..."); 
    } 
    
    int *temp = malloc((List->count - 1) * sizeof(*List->items)); 
    
    memmove(temp, List->items, (index + 1) * sizeof(*List->items)); 
    memmove(temp + index, (List->items) + (index + 1), (List->count - index) * sizeof(*List->items)); 
    
    free(List->items); 
    List->count--; 
    List->items = temp;

}