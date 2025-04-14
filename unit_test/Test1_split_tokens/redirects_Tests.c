#include "../Tests.h"

void redirects_Test1()
{
    data()->s = "grep hi <./test_files/infile";
    t_token exp[] = {{"grep", e_args | e_cmd}, {"hi", e_args}, 
        {"<", e_redir_in}, {"./test_files/infile", e_file_name}};
    data()->exp = (t_token *)exp;
    data()->count = 4;
    split_tokens_test();
}

void redirects_Test2()
{
    data()->s = "grep hi \"<infile\" <         ./test_files/infile";
    t_token exp[] = {{"grep", e_args | e_cmd}, {"\"<infile\"", e_args}, 
        {"<", e_redir_in}, {"./test_files/infile", e_file_name}};
    data()->exp = (t_token *)exp;
    data()->count = 4;
    split_tokens_test();
}

void redirects_Test3()
{
    data()->s = "echo <\"./test_files/infile\" <missing <\"./test_files/infile\"";
    t_token exp[] = {{"echo", e_args | e_cmd}, {"<", e_redir_in}, 
        {"\"./test_files/infile\"", e_double_quote | e_file_name}, {"<", e_redir_in}
        , {"missing", e_file_name}, {"<", e_redir_in}, {"\"./test_files/infile\"", e_double_quote | e_file_name}};
    data()->exp = (t_token *)exp;
    data()->count = 4;
    split_tokens_test();
}

void redirects_Tests()
{
    RUN_TEST(redirects_Test1);
    RUN_TEST(redirects_Test2);
    RUN_TEST(redirects_Test3);
}
