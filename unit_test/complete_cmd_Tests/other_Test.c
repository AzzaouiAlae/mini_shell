#include "complete_Tests.h"

/*
echo $HOME$ '$'$'$'
echo $HOME$ $hey $hey '$'

echo $HOME$ $P $ $P  $P '$'
echo $HOME$ "$P'$' $PWD $USER $ P $P
echo $<b "'$'$'$'" '$PWD'
echo $$b
echo '$USER '$USER" hello $USER you are using  "$SHELL
*/

void OthetTest1()
{
    //Arrange
    char *input = "echo $HOME$ '$'$'$'";
    char *args[] = {"echo", "/home/aazzaoui$", "$$", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0, 0, 0 }, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void OthetTest2()
{
    //Arrange
    char *input = "echo $HOME$ $hey $hey '$'";
    char *args[] = {"echo", "/home/aazzaoui$", "$", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0, 0, 0 }, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void OthetTest3()
{
    //Arrange
    char *input = "echo $HOME$ $hey $hey '$'";
    char *args[] = {"echo", "/home/aazzaoui$", "$", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0, 0, 0 }, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void OthetTest4()
{
    //Arrange
    char *input = "echo $H $H $H $H hhhh";
    char *args[] = {"echo", "hhhh", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0, 0, 0 }, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void OthetTest5()
{
    //Arrange
    char *input = "echo \"$H\" \"$H\" \"$H\" \"$H\" hhhh";
    char *args[] = {"echo", "", "", "", "", "hhhh", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0, 0, 0 }, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void OthetTest6()
{
    //Arrange
    char *input = "echo \"$H\"  hhhh";
    char *args[] = {"echo", "", "hhhh", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0, 0, 0 }, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void OthetTest7()
{
    //Arrange
    char *input = "echo \"$H\" \"$H\" hhhh";
    char *args[] = {"echo", "", "", "hhhh", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0, 0, 0 }, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void OthetTest8()
{
    //Arrange
    char *input = "echo \"$H\" \"$H\" \"$H\" hhhh";
    char *args[] = {"echo", "", "", "", "hhhh", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0, 0, 0 }, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void OthetTest9()
{
    //Arrange
    char *input = "echo \"$H\" \"$H\" \"$H\" \"$H\" hhhh";
    char *args[] = {"echo", "", "", "", "", "hhhh", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0, 0, 0 }, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void OthetTest10()
{
    //Arrange
    char *input = "echo $HOME$ $P $ $P  $P '$'";
    char *args[] = {"echo", "/home/aazzaoui$", "$", "$", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0, 0, 0 }, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void OthetTest11()
{
    //Arrange
    char *input = "echo $ \"'$'$'$'\" '$PWD'";
    char *args[] = {"echo", "$", "'$'$'$'", "$PWD", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0, 0, 0 }, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void OthetTest12()
{
    //Arrange
    char *input = "echo $$b";
    char *args[] = {"echo", "$$b", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0, 0, 0 },
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void OthetTest13()
{
    //Arrange
    char *input = "echo '$USER '$USER\" hello $USER you are using  \"$SHELL";
    char *args[] = {"echo", "'$USER '$USER\" hello $USER you are using  \"$SHELL", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0, 0, 0 },
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void OthetTests()
{
    RUN_TEST(OthetTest1);
    RUN_TEST(OthetTest2);
    RUN_TEST(OthetTest3);
    RUN_TEST(OthetTest4);
    RUN_TEST(OthetTest5);
    RUN_TEST(OthetTest6);
    RUN_TEST(OthetTest7);
    RUN_TEST(OthetTest8);
    RUN_TEST(OthetTest9);
    RUN_TEST(OthetTest10);
    RUN_TEST(OthetTest11);
    RUN_TEST(OthetTest12);
    RUN_TEST(OthetTest13);
}
