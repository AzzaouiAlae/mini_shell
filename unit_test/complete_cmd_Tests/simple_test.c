#include "complete_Tests.h"

void SimpleTest1()
{
    //Arrange
    char *input = "env | sort";
    char *args[] = {"env", 0};
    char *args2[] = {"sort", 0};
    t_cmd cmd[] = {
        { "env", args, 0, 0, 0}, 
        { "/usr/bin/sort", args2, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 2);
}

void SimpleTest2()
{
    //Arrange
    char *input = "env | sort | grep -v SHLVL | grep -v ^_ |echo \" hfh  $saaj\" ' dhdf $test'";
    char *args[] = {"env", 0};
    char *args2[] = {"sort", 0};
    char *args3[] = {"grep", "-v", "SHLVL", 0};
    char *args4[] = {"grep", "-v", "^_", 0};
    char *args5[] = {"echo", " hfh  ", " dhdf $test", 0};
    t_cmd cmd[] = {
        { "env", args, 0, 0, 0}, 
        { "/usr/bin/sort", args2, 0, 0, 0},
        { "/usr/bin/grep", args3, 0, 0, 0},
        { "/usr/bin/grep", args4, 0, 0, 0},
        { "echo", args4, 0, 0, 0},
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 5);
}

void SimpleTests()
{
    RUN_TEST(SimpleTest1);
    RUN_TEST(SimpleTest2);
}