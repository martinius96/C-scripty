#include "../pizza2.h"
#include "unity.h"
#include <string.h>

void test_compare(){
    struct pizza pizza1 = {.name="Hubova",.prize=2.8};
    struct pizza pizza2 = {.name="Zmrzlinova",.prize=1.3};
    char msg[90] = "INPUT: pizza1 = {.name=\"Hubova\",.prize=2.8},pizza2 = {.name=\"Zmrzlinova\",.prize=1.3}";
    TEST_ASSERT_GREATER_THAN_MESSAGE(0,compare_pizza(&pizza1,&pizza2),msg);
    TEST_ASSERT_LESS_THAN_MESSAGE(0,compare_pizza(&pizza2,&pizza1),msg);
    TEST_ASSERT_EQUAL_INT_MESSAGE(0,compare_pizza(&pizza2,&pizza2),msg);
    TEST_ASSERT_EQUAL_INT_MESSAGE(0,compare_pizza(&pizza1,&pizza1),msg);
}


void test_sort_two(){
    struct pizza pizza_input_list[2] ={ {.name="Hubova",.prize=2.8}, {.name="Zmrzlinova",.prize=1.3}};
    struct pizza pizza_output_list[2] ={ {.name="Zmrzlinova",.prize=1.3},{.name="Hubova",.prize=2.8}};

    struct pizza pizza_actual[2];
    memcpy(pizza_actual,pizza_input_list,sizeof(struct pizza) * 2);
    sort_pizza(pizza_actual,2);
    TEST_ASSERT_EQUAL_MEMORY_ARRAY_MESSAGE(pizza_output_list,pizza_actual,sizeof(struct pizza),2,"Test zlyhal, lebo Lacnejsia pizza z dvoch by mala byt na prvom mieste");
}

int main(){
    UNITY_BEGIN();
    RUN_TEST(test_compare);
    RUN_TEST(test_sort_two);
    return UNITY_END();
}
