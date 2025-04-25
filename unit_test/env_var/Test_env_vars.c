#include "../Tests.h"

void env_vars_Test1()
{
    //arrange
    t_cpp_map *map = g_all.custom_env;
    t_cs_list *str;

    //act
    str = cpp_map_get(map, "BASH_FUNC_which%%");

    //assert
    TEST_ASSERT_EQUAL_CHAR_ARRAY("() {  ( alias;\n eval ${which_declare} ) | /usr/bin/which --tty-only --read-alias --read-functions --show-tilde --show-dot $@", str->content, 124);
    //TEST_ASSERT_EQUAL(74, map->count);
}

void env_vars_Test2()
{
    //arrange
    t_cpp_map *map = g_all.custom_env;

    //act
    add_env_var("TEST=123456789", 1);
    add_env_var("TEST2=123456789", 1);
    add_env_var("TEST3=123456789", 1);

    //assert
    //TEST_ASSERT_EQUAL(77, map->count);
    TEST_ASSERT_EQUAL_CHAR_ARRAY("123456789", ((t_cs_list *)cpp_map_get(map, "TEST"))->content, 10);
    TEST_ASSERT_EQUAL_CHAR_ARRAY("123456789", ((t_cs_list *)cpp_map_get(map, "TEST2"))->content, 10);
    TEST_ASSERT_EQUAL_CHAR_ARRAY("123456789", ((t_cs_list *)cpp_map_get(map, "TEST3"))->content, 10);
}

void env_vars_Tests3()
{
    
}

void Test_env_vars()
{
    RUN_TEST(env_vars_Test1);
    RUN_TEST(env_vars_Test2);
}
