#include "../lib/dynamic_arrays.h"

Int_List init_list_int()
{

    Int_List list = { 0 };
    list._list_type = INT;

    return list;

}