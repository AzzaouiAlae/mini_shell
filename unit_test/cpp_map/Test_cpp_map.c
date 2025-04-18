#include "../Tests.h"

t_cpp_map *map;

void Test_cpp_map1()
{
    //arrange
    map = cpp_map_new();

    //act
    cpp_map_add(map, "", (void *)10);

    //assert
    TEST_ASSERT_EQUAL(10, cpp_map_get(map, ""));
    TEST_ASSERT_EQUAL(1, map->count);
}

void Test_cpp_map2()
{
    //arrange

    //act
    cpp_map_add(map, "a", (void *)15);

    //assert
    TEST_ASSERT_EQUAL(15, cpp_map_get(map, "a"));
    TEST_ASSERT_EQUAL(2, map->count);
}

void Test_cpp_map3()
{
    //arrange

    //act
    cpp_map_add(map, "abc", (void *)15);

    //assert
    TEST_ASSERT_EQUAL(15, cpp_map_get(map, "a"));
    TEST_ASSERT_EQUAL(3, map->count);
}

void Test_cpp_map4()
{
    //arrange

    //act
    cpp_map_add(map, "Below is a comprehensive suite of test cases designed to validate every aspect of your cpp_map implementation in C. The tests are organized by function, covering normal operation, edge cases, error handling", (void *)15);

    //assert
    TEST_ASSERT_EQUAL(15, cpp_map_get(map, "Below is a comprehensive suite of test cases designed to validate every aspect of your cpp_map implementation in C. The tests are organized by function, covering normal operation, edge cases, error handling"));
    TEST_ASSERT_EQUAL(4, map->count);
}

void Test_cpp_map5()
{
    //arrange

    //act
    cpp_map_add(map, "abc\1", (void *)200);

    //assert
    TEST_ASSERT_EQUAL(200, cpp_map_get(map, "abc\1"));
    TEST_ASSERT_EQUAL(5, map->count);
}

void Test_cpp_map6()
{
    //arrange

    //act
    cpp_map_add(map, "cba\1", (void *)300);

    //assert
    TEST_ASSERT_EQUAL(300, cpp_map_get(map, "cba\1"));
    TEST_ASSERT_EQUAL(6, map->count);
}

void Test_cpp_map7()
{
    //arrange

    //act
    cpp_map_delete(map, "");

    //assert
    TEST_ASSERT_EQUAL(0, cpp_map_get(map, ""));
    TEST_ASSERT_EQUAL(5, map->count);
}

void Test_cpp_map8()
{
    //arrange

    //act
    cpp_map_delete(map, "a");

    //assert
    TEST_ASSERT_EQUAL(0, cpp_map_get(map, "a"));
    TEST_ASSERT_EQUAL(4, map->count);
}

void Test_cpp_map9()
{
    //arrange

    //act
    cpp_map_delete(map, "9");

    //assert
    TEST_ASSERT_EQUAL(0, cpp_map_get(map, "9"));
    TEST_ASSERT_EQUAL(4, map->count);
}

void Test_cpp_map10()
{
    //arrange
    t_cs_list *str = cs_list_new(sizeof(char));
    cs_list_add_range(str, 20, "hello this is a test");

    //act
    cpp_map_add(map, "test1", (void *)str);

    //assert
    TEST_ASSERT_EQUAL_CHAR_ARRAY("hello this is a test", ((t_cs_list *)(cpp_map_get(map, "test1")))->content, 20);
    TEST_ASSERT_EQUAL(5, map->count);
}

void Test_cpp_map()
{
    RUN_TEST(Test_cpp_map1);
    RUN_TEST(Test_cpp_map2);
    RUN_TEST(Test_cpp_map3);
    RUN_TEST(Test_cpp_map4);
    RUN_TEST(Test_cpp_map5);
    RUN_TEST(Test_cpp_map6);
    RUN_TEST(Test_cpp_map7);
    RUN_TEST(Test_cpp_map8);
    RUN_TEST(Test_cpp_map9);
    RUN_TEST(Test_cpp_map10);
}