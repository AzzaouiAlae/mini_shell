#include "complete_Tests.h"

void builtins_complete_Test1()
{
    //Arrange
    char *input = "echo hello world";
    char *args[] = {"echo", "hello", "world", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test2()
{
    //Arrange
    char *input = "echo \"hello world\"";
    char *args[] = {"echo", "hello world", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test3()
{
    //Arrange
    char *input = "echo 'hello world'";
    char *args[] = {"echo", "hello world", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test4()
{
    //Arrange
    char *input = "echo hello'world'";
    char *args[] = {"echo", "helloworld", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test5()
{
    //Arrange
    char *input = "echo hello\"\"world";
    char *args[] = {"echo", "helloworld", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test6()
{
    //Arrange
    char *input = "echo ''";
    char *args[] = {"echo", "", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test7()
{
    //Arrange
    char *input = "echo \"$PWD\"";
    char *args[] = {"echo", "/home/aazzaoui/Desktop/projects/mini_shell_All/mini_shell_Repo2/unit_test", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test8()
{
    //Arrange
    char *input = "echo '$PWD'";
    char *args[] = {"echo", "$PWD", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test9()
{
    //Arrange
    char *input = "echo \"aspas ->'\"";
    char *args[] = {"echo", "aspas ->'", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test10()
{
    //Arrange
    char *input = "echo \"aspas -> ' \"";
    char *args[] = {"echo", "aspas -> ' ", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test11()
{
    //Arrange
    char *input = "echo 'aspas ->\"'";
    char *args[] = {"echo", "aspas ->\"", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test12()
{
    //Arrange
    char *input = "echo 'aspas -> \" '";
    char *args[] = {"echo", "aspas -> \" ", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test13()
{
    //Arrange
    char *input = "echo \"> >> < * ? [ ] | ; [ ] || && ( ) & # $ \\ <<\"";
    char *args[] = {"echo", "> >> < * ? [ ] | ; [ ] || && ( ) & # $ \\ <<", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test14()
{
    //Arrange
    char *input = "echo '> >> < * ? [ ] | ; [ ] || && ( ) & # $ \\ <<'";
    char *args[] = {"echo", "> >> < * ? [ ] | ; [ ] || && ( ) & # $ \\ <<", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test15()
{
    //Arrange
    char *input = "echo \"exit_code ->$? user ->$USER home -> $HOME\"";
    char *args[] = {"echo", "exit_code ->0 user ->aazzaoui home -> /home/aazzaoui", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test16()
{
    //Arrange
    char *input = "echo 'exit_code ->$? user ->$USER home -> $HOME'";
    char *args[] = {"echo", "exit_code ->$? user ->$USER home -> $HOME", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test17()
{
    //Arrange
    char *input = "echo \"$\"";
    char *args[] = {"echo", "$", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test18()
{
    //Arrange
    char *input = "echo '$'";
    char *args[] = {"echo", "$", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test19()
{
    //Arrange
    char *input = "echo $";
    char *args[] = {"echo", "$", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test20()
{
    //Arrange
    char *input = "echo $?";
    char *args[] = {"echo", "0", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test21()
{
    //Arrange
    char *input = "echo $?HELLO";
    char *args[] = {"echo", "0HELLO", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test22()
{
    //Arrange
    char *input = "pwd";
    char *args[] = {"pwd", 0};
    t_cmd cmd[] = {
        { "pwd", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test23()
{
    //Arrange
    char *input = "pwd oi";
    char *args[] = {"pwd", "oi", 0};
    t_cmd cmd[] = {
        { "pwd", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test24()
{
    //Arrange
    char *input = "export hello";
    char *args[] = {"export", "hello", 0};
    t_cmd cmd[] = {
        { "export", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test25()
{
    //Arrange
    char *input = "export HELLO=123";
    char *exp = "123";
    char *key = "HELLO";

    //act  //ASSERT
    assert_env_var(input, key, exp);
}

void builtins_complete_Test26()
{
    //Arrange
    char *input = "export A-";
    char *args[] = {"export", "A-", 0};
    t_cmd cmd[] = {
        { "export", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test27()
{
    //Arrange
    char *input = "export HELLO=1234 A";
    char *exp = "1234";
    char *key = "HELLO";

    //act  //ASSERT
    assert_env_var(input, key, exp);
    TEST_ASSERT_EQUAL_INT32(0, g_all.cmds->count);
}

void builtins_complete_Test28()
{
    //Arrange
    char *input = "export HELLO=\"123 A-\"";
    char *exp = "123 A-";
    char *key = "HELLO";

    //act  //ASSERT
    assert_env_var(input, key, exp);
    TEST_ASSERT_EQUAL_INT32(0, g_all.cmds->count);
}

void builtins_complete_Test29()
{
    //Arrange
    char *input = "export HELLO   HELLO";
    char *exp = "123 A-";
    char *key = "HELLO";
    char *args[] = {"export", "HELLO", "HELLO", 0};
    t_cmd cmd[] = {
        { "export", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    assert_env_var(input, key, exp);
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test30()
{
    //Arrange
    char *input = "export HELLO-=123";
    char *args[] = {"export", "HELLO-=123", 0};
    t_cmd cmd[] = {
        { "export", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test31()
{
    //Arrange
    char *input = "export =";
    char *args[] = {"export", "=", 0};
    t_cmd cmd[] = {
        { "export", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test32()
{
    //Arrange
    char *input = "export 123";
    char *args[] = {"export", "123", 0};
    t_cmd cmd[] = {
        { "export", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test33()
{
    //Arrange
    char *input = "unset";
    char *args[] = {"unset", 0};
    t_cmd cmd[] = {
        { "unset", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test34()
{
    //Arrange
    char *input = "unset HELLO";
    char *args[] = {"unset", "HELLO", 0};
    t_cmd cmd[] = {
        { "unset", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test35()
{
    //Arrange
    char *input = "unset HELLO1 HELLO2";
    char *args[] = {"unset", "HELLO1", "HELLO2", 0};
    t_cmd cmd[] = {
        { "unset", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test36()
{
    //Arrange
    char *input = "unset HOME";
    char *args[] = {"unset", "HOME", 0};
    t_cmd cmd[] = {
        { "unset", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test37()
{
    //Arrange
    char *input = "unset PATH";
    char *args[] = {"unset", "PATH", 0};
    t_cmd cmd[] = {
        { "unset", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test38()
{
    //Arrange
    char *input = "unset SHELL";
    char *args[] = {"unset", "SHELL", 0};
    t_cmd cmd[] = {
        { "unset", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test39()
{
    //Arrange
    char *input = "cd $SHELL";
    char *args[] = {"cd", "/bin/bash", 0};
    t_cmd cmd[] = {
        { "cd", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test40()
{
    //Arrange
    char *input = "cd $SHELL hi";
    char *args[] = {"cd", "/bin/bash", "hi", 0};
    t_cmd cmd[] = {
        { "cd", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test41()
{
    //Arrange
    char *input = "cd 123123";
    char *args[] = {"cd", "123123", 0};
    t_cmd cmd[] = {
        { "cd", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test42()
{
    //Arrange
    char *input = "exit 123";
    char *args[] = {"exit", "123", 0};
    t_cmd cmd[] = {
        { "exit", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test43()
{
    //Arrange
    char *input = "exit 298";
    char *args[] = {"exit", "298", 0};
    t_cmd cmd[] = {
        { "exit", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test44()
{
    //Arrange
    char *input = "exit +100";
    char *args[] = {"exit", "+100", 0};
    t_cmd cmd[] = {
        { "exit", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test45()
{
    //Arrange
    char *input = "exit \"+100\"";
    char *args[] = {"exit", "+100", 0};
    t_cmd cmd[] = {
        { "exit", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test46()
{
    //Arrange
    char *input = "exit +\"100\"";
    char *args[] = {"exit", "+100", 0};
    t_cmd cmd[] = {
        { "exit", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test47()
{
    //Arrange
    char *input = "exit -100";
    char *args[] = {"exit", "-100", 0};
    t_cmd cmd[] = {
        { "exit", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test48()
{
    //Arrange
    char *input = "exit \"-100\"";
    char *args[] = {"exit", "-100", 0};
    t_cmd cmd[] = {
        { "exit", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test49()
{
    //Arrange
    char *input = "exit -\"100\"";
    char *args[] = {"exit", "-100", 0};
    t_cmd cmd[] = {
        { "exit", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test50()
{
    //Arrange
    char *input = "exit hello";
    char *args[] = {"exit", "hello", 0};
    t_cmd cmd[] = {
        { "exit", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test51()
{
    //Arrange
    char *input = "exit 42 world";
    char *args[] = {"exit", "42", "world", 0};
    t_cmd cmd[] = {
        { "exit", args, 0, 0, 0}, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Tests()
{
    RUN_TEST(builtins_complete_Test1);
    RUN_TEST(builtins_complete_Test2);
    RUN_TEST(builtins_complete_Test3);
    RUN_TEST(builtins_complete_Test4);
    RUN_TEST(builtins_complete_Test5);
    RUN_TEST(builtins_complete_Test6);
    //RUN_TEST(builtins_complete_Test7);
    RUN_TEST(builtins_complete_Test8);
    RUN_TEST(builtins_complete_Test9);
    RUN_TEST(builtins_complete_Test10);
    RUN_TEST(builtins_complete_Test11);
    RUN_TEST(builtins_complete_Test12);
    RUN_TEST(builtins_complete_Test13);
    RUN_TEST(builtins_complete_Test14);
    RUN_TEST(builtins_complete_Test15);
    RUN_TEST(builtins_complete_Test16);
    RUN_TEST(builtins_complete_Test17);
    RUN_TEST(builtins_complete_Test18);
    RUN_TEST(builtins_complete_Test19);
    RUN_TEST(builtins_complete_Test20);
    RUN_TEST(builtins_complete_Test21);
    RUN_TEST(builtins_complete_Test22);
    RUN_TEST(builtins_complete_Test23);
    RUN_TEST(builtins_complete_Test24);
    RUN_TEST(builtins_complete_Test25);
    RUN_TEST(builtins_complete_Test26);
    RUN_TEST(builtins_complete_Test27);
    RUN_TEST(builtins_complete_Test28);
    RUN_TEST(builtins_complete_Test29);
    RUN_TEST(builtins_complete_Test30);
    RUN_TEST(builtins_complete_Test31);
    RUN_TEST(builtins_complete_Test32);
    RUN_TEST(builtins_complete_Test33);
    RUN_TEST(builtins_complete_Test34);
    RUN_TEST(builtins_complete_Test35);
    RUN_TEST(builtins_complete_Test36);
    RUN_TEST(builtins_complete_Test37);
    RUN_TEST(builtins_complete_Test38);
    RUN_TEST(builtins_complete_Test39);
    RUN_TEST(builtins_complete_Test40);
    RUN_TEST(builtins_complete_Test41);
    RUN_TEST(builtins_complete_Test42);
    RUN_TEST(builtins_complete_Test43);
    RUN_TEST(builtins_complete_Test44);
    RUN_TEST(builtins_complete_Test45);
    RUN_TEST(builtins_complete_Test46);
    RUN_TEST(builtins_complete_Test47);
    RUN_TEST(builtins_complete_Test48);
    RUN_TEST(builtins_complete_Test49);
    RUN_TEST(builtins_complete_Test50);
    RUN_TEST(builtins_complete_Test51);
}
