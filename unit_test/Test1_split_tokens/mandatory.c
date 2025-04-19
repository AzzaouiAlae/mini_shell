#include "../Tests.h"

void mandatory_Tests1()
{
    data()->s = "echo -n hello";
    t_token exp[] = {
        {"echo", e_args | e_cmd},
        {"-n", e_args},
        {"hello", e_args}
    };
    data()->exp = (t_token *)exp;
    data()->count = 3;
    split_tokens_test();
}

void mandatory_Tests2()
{
    data()->s = "export HELLO=123";
    t_token exp[] = {
        {"export", e_set_var | e_cmd},
        {"HELLO=123", e_var_to_set}
    };
    data()->exp = (t_token *)exp;
    data()->count = 2;
    split_tokens_test();
}

void mandatory_Tests3()
{
    data()->s = "export HELLO=\"beautiful world\"";
    t_token exp[] = {
        {"export", e_set_var | e_cmd},
        {"HELLO=\"beautiful world\"", e_var_to_set | e_double_quote}
    };
    data()->exp = (t_token *)exp;
    data()->count = 2;
    split_tokens_test();
}
void mandatory_Test4()
{
    data()->s = "echo $PWD $OLDPWD";
    t_token exp[] = {
        {"echo", e_args | e_cmd},
        {"$PWD", e_var_to_get | e_args},
        {"$OLDPWD", e_var_to_get | e_args}
    };
    data()->exp = (t_token *)exp;
    data()->count = 3;
    split_tokens_test();
}

void mandatory_Test5()
{
    data()->s = "doesntexist";
    t_token exp[] = {
        {"doesntexist", e_args | e_cmd}
    };
    data()->exp = (t_token *)exp;
    data()->count = 1;
    split_tokens_test();
}

void mandatory_Test6()
{
    data()->s = "echo $?";
    t_token exp[] = {
        {"echo", e_args | e_cmd},
        {"$?", e_error_status | e_args}
    };
    data()->exp = (t_token *)exp;
    data()->count = 2;
    split_tokens_test();
}

void mandatory_Test7()
{
    data()->s = "$EMPTY";
    t_token exp[] = {
        {"$EMPTY", e_var_to_get | e_args | e_cmd}
    };
    data()->exp = (t_token *)exp;
    data()->count = 1;
    split_tokens_test();
}

void mandatory_Test8()
{
    data()->s = "echo \"hi\" | cat | cat | cat | cat | cat | cat | cat";
    t_token exp[] = {
        {"echo", e_args | e_cmd},
        {"\"hi\"", e_args | e_double_quote},
        {"|", e_pipe},
        {"cat", e_args | e_cmd},
        {"|", e_pipe},
        {"cat", e_args | e_cmd},
        {"|", e_pipe},
        {"cat", e_args | e_cmd},
        {"|", e_pipe},
        {"cat", e_args | e_cmd},
        {"|", e_pipe},
        {"cat", e_args | e_cmd},
        {"|", e_pipe},
        {"cat", e_args | e_cmd}
    };
    data()->exp = (t_token *)exp;
    data()->count = 14;
    split_tokens_test();
}

void mandatory_Test9()
{
    data()->s = "ps -a";
    t_token exp[] = {
        {"ps", e_args | e_cmd},
        {"-a", e_args}
    };
    data()->exp = (t_token *)exp;
    data()->count = 2;
    split_tokens_test();
}

void mandatory_Test10()
{
    data()->s = "echo - \"\" \"  \" hello";
    t_token exp[] = {
        {"echo", e_args | e_cmd},
        {"-", e_args},
        {"\"\"", e_args | e_double_quote},
        {"\"  \"", e_args | e_double_quote},
        {"hello", e_args}
    };
    data()->exp = (t_token *)exp;
    data()->count = 5;
    split_tokens_test();
}

void mandatory_Test11()
{
    data()->s = "unset USER";
    t_token exp[] = {
        {"unset", e_args | e_cmd},
        {"USER", e_args}
    };
    data()->exp = (t_token *)exp;
    data()->count = 2;
    split_tokens_test();
}

void mandatory_Test12()
{
    data()->s = "/bin/ls";
    t_token exp[] = {
        {"/bin/ls", e_args | e_cmd | e_path}
    };
    data()->exp = (t_token *)exp;
    data()->count = 1;
    split_tokens_test();
}

void mandatory_Test13()
{
    data()->s = "cd .. hi";
    t_token exp[] = {
        {"cd", e_args | e_cmd},
        {"..", e_args},
        {"hi", e_args}
    };
    data()->exp = (t_token *)exp;
    data()->count = 3;
    split_tokens_test();
}


void mandatory_Tests()
{
    RUN_TEST(mandatory_Tests1);
    RUN_TEST(mandatory_Tests2);
    RUN_TEST(mandatory_Tests3);
    RUN_TEST(mandatory_Test4);
    RUN_TEST(mandatory_Test5);
    RUN_TEST(mandatory_Test6);
    RUN_TEST(mandatory_Test7);
    RUN_TEST(mandatory_Test8);
    RUN_TEST(mandatory_Test9);
    RUN_TEST(mandatory_Test10);
    RUN_TEST(mandatory_Test11);
    RUN_TEST(mandatory_Test12);
    RUN_TEST(mandatory_Test13);
}