
#include "Tests.h"

void setUp(void)
{
  
}
void tearDown(void)
{
    
}

void init_Tests(int argc, char **argv,char **env)
{
    data()->sep = " |<>\t$";
    data()->special_sep = "\"'";
    init_g_all(argc, argv, env);
}

int main(int argc, char **argv, char **env)
{
    init_Tests(argc, argv, env);
    // simple_tests();
    // redirects_Tests();
    // pipe_Test();
    // builtins_Test();
    // Test_syntax_error();
    heredoc_Test();
    // mandatory_Tests();
    // Test_cpp_map();
    // Test_env_vars();
    // more_Tests();
    // mini_shell_map_Tests();
    // set_vars_Tests();
    // get_vars_Tests();
    complete_cmd_Tests();
    ft_free_all();
    return (UnityEnd());
}
