#include "complete_Tests.h"

void OthetTest1()
{
    //Arrange
    char *input = "echo hello world";
    char *args[] = {"echo", "hello", "world", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0, 0, 0 }, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void OthetTests()
{

}