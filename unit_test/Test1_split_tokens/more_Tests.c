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

void more_Test3()
{
    data()->s = "<< $\"\"";
    t_token exp[] = {
        {"<<", e_heredoc},
        {"", e_delimiter}
    };
    data()->exp = (t_token *)exp;
    data()->count = 2;
    split_tokens_test();
}

void more_Test4()
{
    data()->s = "<< $\"aa\"";
    t_token exp[] = {
        {"<<", e_heredoc},
        {"aa", e_delimiter}
    };
    data()->exp = (t_token *)exp;
    data()->count = 2;
    split_tokens_test();
}

void more_Test5()
{
    data()->s = "<< $a\"aa\"";
    t_token exp[] = {
        {"<<", e_heredoc},
        {"$aaa", e_delimiter}
    };
    data()->exp = (t_token *)exp;
    data()->count = 2;
    split_tokens_test();
}

void more_Test6()
{
    data()->s = "<< $a\"aa$\"";
    t_token exp[] = {
        {"<<", e_heredoc},
        {"$aaa$", e_delimiter}
    };
    data()->exp = (t_token *)exp;
    data()->count = 2;
    split_tokens_test();
}

void more_Test7()
{
    data()->s = "<< $a$\"aa$\"";
    t_token exp[] = {
        {"<<", e_heredoc},
        {"$aaa$", e_delimiter}
    };
    data()->exp = (t_token *)exp;
    data()->count = 2;
    split_tokens_test();
}

void more_Test8()
{
    data()->s = "<< $'a'$\"aa$\"";
    t_token exp[] = {
        {"<<", e_heredoc},
        {"aaa$", e_delimiter}
    };
    data()->exp = (t_token *)exp;
    data()->count = 2;
    split_tokens_test();
}

void more_Test9()
{
    data()->s = "\n";
    data()->exp = NULL;
    data()->count = 0;
    split_tokens_test();
}

void more_Test10()
{
    data()->s = "            ";
    data()->exp = NULL;
    data()->count = 0;
    split_tokens_test();
}
void more_Test11()
{
    data()->s = "\t\t\t\t\t\t\t\t\t\t";
    data()->exp = NULL;
    data()->count = 0;
    split_tokens_test();
}

void more_Test12()
{
    data()->s = ":";
    data()->exp = NULL;
    data()->count = 0;
    split_tokens_test();
}

void more_Test13()
{
    data()->s = "!";
    data()->exp = NULL;
    data()->count = 0;
    split_tokens_test();
}

void more_Tests()
{
    RUN_TEST(more_Test1);
    RUN_TEST(more_Test2);
    RUN_TEST(more_Test3);
    RUN_TEST(more_Test4);
    RUN_TEST(more_Test5);
    RUN_TEST(more_Test6);
    RUN_TEST(more_Test7);
    RUN_TEST(more_Test8);
    RUN_TEST(more_Test9);
    RUN_TEST(more_Test10);
    RUN_TEST(more_Test11);
    RUN_TEST(more_Test12);
    RUN_TEST(more_Test13);
}
