#include "../calculator.h"
#include "unity.h"
#include <string.h>

void test_push_stack_size(){
    struct stack* s = create_stack();
    TEST_ASSERT_EQUAL_INT_MESSAGE(0,s->size,"Prazdny stack musi mat velkost 0");
    push_stack_value(s,0);
    TEST_ASSERT_EQUAL_INT_MESSAGE(1,s->size,"Pridanie hodnoty do prazdneho stacku musi zvysit jeho velkost na 1");
    delete_stack(s);
}

void test_push_stack_value(){
    struct stack* s = create_stack();
    push_stack_value(s,1.0);
    TEST_ASSERT_EQUAL_FLOAT_MESSAGE(1.0,s->array[0],"Pridana hodnota sa ma zapisat do pola");
    delete_stack(s);
}

void test_pop_stack_value(){
    struct stack* s = create_stack();
    s->size = 2;
    s->array[0] = 1.0;
    s->array[1] = 2.0;
    float res = pop_stack_value(s);
    TEST_ASSERT_EQUAL_FLOAT_MESSAGE(2.0,res,"Odobrata a vratena hodnota nesuvisi s povodnym obsahom");
    delete_stack(s);
}

void test_pop_stack_size(){
    struct stack* s = create_stack();
    s->size = 2;
    s->array[0] = 1.0;
    s->array[1] = 2.0;
    pop_stack_value(s);
    TEST_ASSERT_EQUAL_INT_MESSAGE(1,s->size,"Odobratie hodnoty ma sposobit o jednu mensiu velkost.");
    delete_stack(s);
}

int main(){
    UNITY_BEGIN();
    RUN_TEST(test_push_stack_size);
    RUN_TEST(test_push_stack_value);
    RUN_TEST(test_pop_stack_size);
    RUN_TEST(test_pop_stack_value);
    return UNITY_END();
}
