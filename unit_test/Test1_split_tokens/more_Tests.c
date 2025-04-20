#include "../Tests.h"

void more_Test1()
{
    data()->s = "echo $\"test\"";
    t_token exp[] = {
        {"echo", e_args | e_cmd},
        {"\"test\"", e_args | e_double_quote}
    };
    data()->exp = (t_token *)exp;
    data()->count = 2;
    split_tokens_test();
}

void more_Test2()
{
    data()->s = "echo $\"$test$\"";
    t_token exp[] = {
        {"echo", e_args | e_cmd},
        {"\"$test$\"", e_args | e_double_quote | e_var_to_get}
    };
    data()->exp = (t_token *)exp;
    data()->count = 2;
    split_tokens_test();
}

void more_Tests()
{
    RUN_TEST(more_Test1);
    RUN_TEST(more_Test2);
}
