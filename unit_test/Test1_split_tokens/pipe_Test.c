#include "../Tests.h"

void pipe_test1()
{
    data()->s = "env | sort | grep -v SHLVL | grep -v ^_";
    t_token exp[] = {
        {"env", e_args | e_cmd},
        {"|", e_pipe},
        {"sort", e_args | e_cmd},
        {"|", e_pipe},
        {"grep", e_args | e_cmd},
        {"-v", e_args},
        {"SHLVL", e_args},
        {"|", e_pipe},
        {"grep", e_args | e_cmd},
        {"-v", e_args},
        {"^_", e_args}
    };
    data()->exp = (t_token *)exp;
    data()->count = 11;
    split_tokens_test();
}

void pipe_test2()
{
    data()->s = "cat ./test_files/infile_big | grep oi";
    t_token exp[] = {
        {"cat", e_args | e_cmd},
        {"./test_files/infile_big", e_args},
        {"|", e_pipe},
        {"grep", e_args | e_cmd},
        {"oi", e_args}
    };
    data()->exp = (t_token *)exp;
    data()->count = 5;
    split_tokens_test();
}

void pipe_test3()
{
    data()->s = "cat minishell.h | grep \");\"$";
    t_token exp[] = {
        {"cat", e_args | e_cmd},
        {"minishell.h", e_args},
        {"|", e_pipe},
        {"grep", e_args | e_cmd},
        {"\");\"$", e_args | e_double_quote | e_var_to_get}
    };
    data()->exp = (t_token *)exp;
    data()->count = 5;
    split_tokens_test();
}

void pipe_test4()
{
    data()->s = "export GHOST=123 | env | grep GHOST";
    t_token exp[] = {
        {"export", e_set_var | e_cmd},
        {"GHOST=123", e_var_to_set},
        {"|", e_pipe},
        {"env", e_args | e_cmd},
        {"|", e_pipe},
        {"grep", e_args | e_cmd},
        {"GHOST", e_args}
    };
    data()->exp = (t_token *)exp;
    data()->count = 7;
    split_tokens_test();
}

void pipe_Test()
{
    RUN_TEST(pipe_test1);
    RUN_TEST(pipe_test2);
    RUN_TEST(pipe_test3);
    RUN_TEST(pipe_test4);
}