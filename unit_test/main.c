
#include "Tests.h"

void setUp(void)
{
  
}
void tearDown(void)
{
    
}

void init_Tests(char **env)
{
    data()->sep = " |<>\t$";
    data()->special_sep = "\"'";
    init_g_all(env);
}

int main(int argc, char **argv, char **env)
{
    init_Tests(env);
    simple_tests();
    redirects_Tests();
    pipe_Test();
    builtins_Test();
    Test_syntax_error();
    heredoc_Test();
    mandatory_Tests();
    Test_cpp_map();
    ft_free_all();
    return (UnityEnd());
}
