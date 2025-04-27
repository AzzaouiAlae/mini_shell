#include "complete_Tests.h"

void heredoc_Test1()
{
    //Arrange
    char *input = "cat <<HERE | ls";
    char *args[] = {"cat", 0};
    char *args2[] = {"ls", 0};
    t_cmd cmd[] = {
        { "cat", args, 0, 3, 0, 0, 0 }, 
        { "ls", args2, 0, 0, 0, 0, 0 }, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 2);
    close(3);
}

void heredoc_Test2()
{
    //Arrange
    char *input = "cat <<HERE";
    char *args[] = {"cat", 0};
    t_cmd cmd[] = {
        { "cat", args, 0, 3, 0, 0, 0 }, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 2);
    close(3);
}

void heredoc_Test3()
{
    //Arrange
    char *input = "cat <minishell.h <<HERE <missing | ls";
    char *args[] = {"cat",  0};
    t_cmd cmd[] = {
        { "cat", args, 0, 4, 0, 0, 4 }, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 2);
    close(3);
}

void heredoc_Tests()
{
    RUN_TEST(heredoc_Test1);
}