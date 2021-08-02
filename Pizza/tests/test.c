#include "../pizza1.h"
#include "unity.h"

void test_longest_empty(){
    TEST_ASSERT_EQUAL(0,max_len(NULL,0));
}

void test_one_member_array(){
    char input[LINESIZE][LISTSIZE]= {""};
    TEST_ASSERT_EQUAL(0,max_len(input,1));
}

void test_two_member_array(){
    char input[LINESIZE][LISTSIZE]= {"","zzzz"};
    TEST_ASSERT_EQUAL_MESSAGE(1,max_len(input,2),"input: {\"\",\"zzzz\" }, max_len(input,2)");
}

void test_three_member_array(){
    char input[LINESIZE][LISTSIZE]= {"","zzzz","zz"};
    TEST_ASSERT_EQUAL_MESSAGE(1,max_len(input,3),"input: {\"\",\"zzzz\",\"zz\" }, max_len(input,3)");
}

int main(){
    UNITY_BEGIN();
    RUN_TEST(test_longest_empty);
    RUN_TEST(test_one_member_array);
    RUN_TEST(test_two_member_array);
    RUN_TEST(test_three_member_array);
    return UNITY_END();
}
