#include "tests.h"

void test_list_strings()
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

    printf("\n");

    free_string_arr(&strs);

}

void test_list_integers()
{

    Int_List list = init_list_int();

    for (size_t i = 0; i < 10; i++) { list_append(list, i); };

    printf("Before delete : \n");
    for (size_t i = 0; i < list.count; i++) printf("%d\n", list.items[i]);

    printf("\n");

    list_free(list);

}