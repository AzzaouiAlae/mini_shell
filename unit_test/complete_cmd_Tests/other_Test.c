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
    char *args[] = {"echo", "/home/aazzaoui$", "", "", "$", 0};
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
}