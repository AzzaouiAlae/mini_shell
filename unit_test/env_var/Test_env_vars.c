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
    TEST_ASSERT_EQUAL(74, map->count);
}

void env_vars_Test2()
{
    
}

void Test_env_vars()
{
    RUN_TEST(env_vars_Test1);
    RUN_TEST(env_vars_Test2);
}