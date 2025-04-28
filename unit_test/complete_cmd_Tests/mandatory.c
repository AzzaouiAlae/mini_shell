#include "complete_Tests.h"

void MandatoryTest1()
{
    //Arrange
    char *input = "echo -n hello";
    char *args[] = {"echo", "-n", "hello", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void MandatoryTest2()
{
    //Arrange
    char *input = "export HELLO=123";
    char *exp = "123";
    char *key = "HELLO";

    //act   //ASSERT
    assert_env_var(input, key, exp);
    TEST_ASSERT_EQUAL_INT32(0, g_all.cmds->count);
}

void MandatoryTest3()
{
     //Arrange
     char *input = "export HELLO=\"beautiful world\"";
     char *exp = "beautiful world";
     char *key = "HELLO";
 
     //act   //ASSERT
     assert_env_var(input, key, exp);
     TEST_ASSERT_EQUAL_INT32(0, g_all.cmds->count);
}

void MandatoryTest4()
{
    //Arrange
    char *input = "echo $HOSTNAME $USER";
    char *args[] = {"echo", "c3r8p3", "aazzaoui", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void MandatoryTest5()
{
    //Arrange
    char *input = "doesntexist";

    //act
    execute_cmd_input(input);

    //ASSERT
    TEST_ASSERT_EQUAL_INT32(0, g_all.cmds->count);
    TEST_ASSERT_EQUAL_INT32(127, g_all.cmd_error_status);
}

void MandatoryTest6()
{
    //Arrange
    char *input = "echo $?";
    char *args[] = {"echo", "127", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void MandatoryTest7()
{
    //Arrange
    char *input = "$EMPTY";

    //act  //ASSERT
    TEST_ASSERT_EQUAL_INT32(0, g_all.cmds->count);
}

void MandatoryTest8()
{
    //Arrange
    char *input = "echo \"hi\" | cat | cat | cat | cat | cat | cat | cat";
    char *args[] = {"echo", "hi", 0};
    char *args2[] = {"cat", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0}, 
        { "/usr/bin/cat", args2, 0, 0, 0}, 
        { "/usr/bin/cat", args2, 0, 0, 0}, 
        { "/usr/bin/cat", args2, 0, 0, 0}, 
        { "/usr/bin/cat", args2, 0, 0, 0}, 
        { "/usr/bin/cat", args2, 0, 0, 0}, 
        { "/usr/bin/cat", args2, 0, 0, 0}, 
        { "/usr/bin/cat", args2, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 8);
}

void MandatoryTest9()
{
    //Arrange
    char *input = "echo -n hello";
    char *args[] = {"echo", "-n", "hello", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void MandatoryTest10()
{
    //Arrange
    char *input = "echo -n hello";
    char *args[] = {"echo", "-n", "hello", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void MandatoryTest11()
{
    //Arrange
    char *input = "echo -n hello";
    char *args[] = {"echo", "-n", "hello", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}
void MandatoryTest12()
{
    //Arrange
    char *input = "echo -n hello";
    char *args[] = {"echo", "-n", "hello", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void MandatoryTest13()
{
    //Arrange
    char *input = "echo -n hello";
    char *args[] = {"echo", "-n", "hello", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void MandatoryTest14()
{
    //Arrange
    char *input = "echo -n hello";
    char *args[] = {"echo", "-n", "hello", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void MandatoryTest15()
{
    //Arrange
    char *input = "echo -n hello";
    char *args[] = {"echo", "-n", "hello", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void MandatoryTest16()
{
    //Arrange
    char *input = "echo -n hello";
    char *args[] = {"echo", "-n", "hello", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void MandatoryTest17()
{
    //Arrange
    char *input = "echo -n hello";
    char *args[] = {"echo", "-n", "hello", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void MandatoryTest18()
{
    //Arrange
    char *input = "echo -n hello";
    char *args[] = {"echo", "-n", "hello", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void MandatoryTest19()
{
    //Arrange
    char *input = "echo -n hello";
    char *args[] = {"echo", "-n", "hello", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void MandatoryTest20()
{
    //Arrange
    char *input = "echo -n hello";
    char *args[] = {"echo", "-n", "hello", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void MandatoryTest21()
{
    //Arrange
    char *input = "echo -n hello";
    char *args[] = {"echo", "-n", "hello", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void MandatoryTest22()
{
    //Arrange
    char *input = "ps -a";
    char *args[] = {"ps", "-a", 0};
    t_cmd cmd[] = {
        { "/usr/bin/ps", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void MandatoryTest23()
{
    //Arrange
    char *input = "echo - \"\" \"  \" hello";
    char *args[] = {"echo", "-", "", "  " ,"hello", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void MandatoryTest24()
{
    //Arrange
    char *input = "unset USER";
    char *args[] = {"unset", "USER", 0};
    t_cmd cmd[] = {
        { "unset", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void MandatoryTest25()        ///////////////bin/ls
{
    //Arrange
    char *input = "/bin/ls";
    char *args[] = {"/bin/ls", 0};
    t_cmd cmd[] = {
        { "/bin/ls", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void MandatoryTest26()
{
    //Arrange
    char *input = "cd .. hi";
    char *args[] = {"cd", "..", "hi", 0};
    t_cmd cmd[] = {
        { "cd", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void MandatoryTests()
{
    RUN_TEST(MandatoryTest1);
    RUN_TEST(MandatoryTest2);
    RUN_TEST(MandatoryTest3);
    RUN_TEST(MandatoryTest4);
    RUN_TEST(MandatoryTest5);
    RUN_TEST(MandatoryTest6);
    RUN_TEST(MandatoryTest8);
    RUN_TEST(MandatoryTest9);
    RUN_TEST(MandatoryTest10);
    RUN_TEST(MandatoryTest11);
    RUN_TEST(MandatoryTest12);
    RUN_TEST(MandatoryTest13);
    RUN_TEST(MandatoryTest14);
    RUN_TEST(MandatoryTest15);
    RUN_TEST(MandatoryTest16);
    RUN_TEST(MandatoryTest17);
    RUN_TEST(MandatoryTest18);
    RUN_TEST(MandatoryTest19);
    RUN_TEST(MandatoryTest20);
    RUN_TEST(MandatoryTest21);
    RUN_TEST(MandatoryTest22);
    RUN_TEST(MandatoryTest23);
    RUN_TEST(MandatoryTest24);
    RUN_TEST(MandatoryTest25);
    RUN_TEST(MandatoryTest26);
}