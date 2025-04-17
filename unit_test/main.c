
#include "Tests.h"

void setUp(void)
{
  
}
void tearDown(void)
{
    
}

void init_Tests()
{
    data()->sep = " |<>\t$";
    data()->special_sep = "\"'";
    init_g_all();
}

int main()
{
    init_Tests();
    simple_tests();
    redirects_Tests();
    pipe_Test();
    builtins_Test();
    // Test_syntax_error();
    heredoc_Test();
    ft_free_all();
    return (UnityEnd());
}
