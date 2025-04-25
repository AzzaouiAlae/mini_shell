#include "../Tests.h"

void set_vars_Test1()
{
    //arrange
    char *input = "echo $SHELL\"   $  \"  $  $USER  ' $a'$a ";
}

void set_vars_Tests()
{
    RUN_TEST(set_vars_Test1);
}