#include "Tests.h"

char *get_enum_str(int type)
{
    t_cs_list *list = cs_list_new(1);
    int i = 0;
    char *strs[] = {"e_none", "e_args", "e_pipe", "e_heredoc",
 		"e_redir_out_app", "e_redir_out_trun", "e_redir_in", "e_var",
 		"e_quote", "e_double_quote", "e_file_name", "e_cmd", "e_path", "e_set_var", 0};
    for(int i = 1, j = 1; strs[j]; i *= 2, j++)
    {
        if((type & i) == i)
        {
            cs_list_add_range(list, strlen(strs[j]), strs[j]);
            cs_list_add(list, (long)' ');
        }
    }
    return list->content;
}

t_split_tokens_data *data()
{
    static t_split_tokens_data strs;

    return (&strs);
}

void simple_test1()
{
    data()->s = "env | sort";
    t_token exp[] = { {"env", e_args | e_cmd}, {"|", e_pipe}, {"sort", e_args | e_cmd}};
    data()->exp = (t_token *)exp;
    data()->count = 3;
    split_tokens_test();
}

void simple_test2()
{
    data()->s = "env | sort | grep -v SHLVL | grep -v ^_ |echo \" hfh  $saaj\" ' dhdf $test'";

    t_token exp[] = { {"env", e_args | e_cmd}, {"|", e_pipe}, {"sort", e_args | e_cmd}, {"|", e_pipe},{"grep", e_args | e_cmd},{"-v", e_args},{"SHLVL", e_args},
            {"|", e_pipe},{"grep", e_args | e_cmd},{"-v", e_args},{"^_", e_args},{"|", e_pipe},{"echo", e_args | e_cmd}, {"\" hfh  $saaj\"", e_double_quote | e_var_to_get | e_args},
            {"' dhdf $test'", e_quote}};
    data()->exp = (t_token *)exp;
    data()->count = 15;
    split_tokens_test();
}

void simple_test3()
{
    data()->s = "echo \" hfh  $saaj\" ' dhdf $test'";

    t_token exp[] = { {"echo", e_args | e_cmd}, {"\" hfh  $saaj\"", e_args | e_double_quote | e_var_to_get}, {"' dhdf $test'", e_quote},};
    data()->exp = (t_token *)exp;
    data()->count = 3;
    split_tokens_test();
}

void simple_test4()
{
    data()->s = "$PWD";

    t_token exp[] = { {"$PWD", e_var_to_get | e_args | e_cmd}};
    data()->exp = (t_token *)exp;
    data()->count = 1;
    split_tokens_test();
}

void simple_test5()
{
    data()->s = "$EMPTY echo hi";

    t_token exp[] = { {"$EMPTY", e_var_to_get | e_args | e_cmd}, {"echo", e_args}, {"hi", e_args}};
    data()->exp = (t_token *)exp;
    data()->count = 1;
    split_tokens_test();
}

void simple_test6()
{
    data()->s = "./test_files/invalid_permission";

    t_token exp[] = { {"./test_files/invalid_permission", e_args | e_cmd | e_path}};
    data()->exp = (t_token *)exp;
    data()->count = 1;
    split_tokens_test();
}

void simple_test7()
{
    data()->s = "cat ./test_files/infile_big | grep oi";

    t_token exp[] = { {"cat", e_args | e_cmd}, {"./test_files/infile_big", e_args}, 
    {"|", e_pipe}, {"grep", e_args | e_cmd}, {"oi", e_args}};
    data()->exp = (t_token *)exp;
    data()->count = 5;
    split_tokens_test();
}

void simple_test8()
{
    data()->s = "cat minishell.h | grep \");\"$";

    t_token exp[] = { {"cat", e_args | e_cmd}, {"minishell.h", e_args}, 
    {"|", e_pipe}, {"grep", e_args | e_cmd}, {"\");\"", e_double_quote}, 
    {"$", e_var_to_get}};
    data()->exp = (t_token *)exp;
    data()->count = 5;
    split_tokens_test();
}

void simple_test9()
{
    data()->s = "export GHOST=123 | env | grep GHOST";
    t_token exp[] = { {"export", e_set_var}, {"GHOST=123", e_var_to_set}, {"|", e_pipe}, {"env", e_args | e_cmd}, {"|", e_pipe}, {"grep", e_args | e_cmd}, {"GHOST", e_args}};
    data()->exp = (t_token *)exp;
    data()->count = 6;
    split_tokens_test();
}

void simple_test10()
{
    data()->s = "grep hi <./test_files/infile";

    t_token exp[] = { {"grep", e_args | e_cmd}, {"hi", e_args}, {"<", e_redir_in}, {"./test_files/infile", e_file_name}};
    data()->exp = (t_token *)exp;
    data()->count = 4;
    split_tokens_test();
}

void simple_test11()
{
    data()->s = "grep hi \"<infile\" <         ./test_files/infile";

    t_token exp[] = { {"grep", e_args | e_cmd}, {"hi", e_args}, {"\"<infile\"", e_double_quote}, {"<", e_redir_in}, {"./test_files/infile", e_file_name}};
    data()->exp = (t_token *)exp;
    data()->count = 5;
    split_tokens_test();
}

void simple_test12()
{
    data()->s = "echo hi < ./test_files/infile bye bye";

    t_token exp[] = { {"echo", e_args | e_cmd}, {"hi", e_args}, {"<", e_redir_in}, {"./test_files/infile", e_file_name}, {"bye", e_args}, {"bye", e_args}};
    data()->exp = (t_token *)exp;
    data()->count = 6;
    split_tokens_test();
}

void simple_test13()
{
    data()->s = "grep hi <./test_files/infile_big <./test_files/infile";

    t_token exp[] = { {"grep", e_args | e_cmd}, {"hi", e_args}, {"<", e_redir_in}, {"./test_files/infile_big", e_file_name}, {"<", e_redir_in}, {"./test_files/infile", e_args}};
    data()->exp = (t_token *)exp;
    data()->count = 6;
    split_tokens_test();
}

void simple_test14()
{
    data()->s = "echo <\"./test_files/infile\" \"bonjour       42\"";

    t_token exp[] = { {"echo", e_args | e_cmd}, {"<", e_redir_in}, 
    {"\"./test_files/infile\"", e_double_quote}, 
    {"\"bonjour       42\"", e_double_quote}};
    data()->exp = (t_token *)exp;
    data()->count = 4;
    split_tokens_test();
}

void simple_test15()
{
    data()->s = "cat <\"1\"\"2\"\"3\"\"4\"\"5\"";

    t_token exp[] = { {"cat", e_args | e_cmd}, {"<", e_redir_in}, 
    {"\"1\"\"2\"\"3\"\"4\"\"5\"", e_double_quote}};
    data()->exp = (t_token *)exp;
    data()->count = 3;
    split_tokens_test();
}

void simple_test16()
{
    data()->s = "cat hello\" this is a test $test\"";

    t_token exp[] = { {"cat", e_args | e_cmd}, {"hello\" this is a test $test\"", e_args | e_var_to_get}, 
    };
    data()->exp = (t_token *)exp;
    data()->count = 2;
    split_tokens_test();
}

void simple_test17()
{
    data()->s = "echo hh$test";

    t_token exp[] = { {"echo", e_args | e_cmd}, {"hh", e_args}, {"$test", e_var_to_get} 
    };
    data()->exp = (t_token *)exp;
    data()->count = 3;
    split_tokens_test();
}

void simple_test18()
{
    data()->s = "echo hh $test";

    t_token exp[] = { {"echo", e_args | e_cmd}, {"hh", e_args}, {" $test", e_var_to_get} 
    };
    data()->exp = (t_token *)exp;
    data()->count = 3;
    split_tokens_test();
}

void simple_test19()
{
    data()->s = "echo GHOST=123 | env | grep GHOST";

    t_token exp[] = { {"echo", e_args | e_cmd}, {"GHOST=123", e_args}};
    data()->exp = (t_token *)exp;
    data()->count = 2;
    split_tokens_test();
}

//aa=ee not work but echo work
void simple_test20() 
{
    data()->s = "aa=ee echo sdffsgfjfg";

    t_token exp[] = { {"echo", e_args | e_cmd}, {"GHOST=123", e_args}};
    data()->exp = (t_token *)exp;
    data()->count = 2;
    split_tokens_test();
}

void simple_test21()
{
    data()->s = "echo hh \"$test\"";

    t_token exp[] = { 
        {"echo", e_args | e_cmd}, {"hh", e_args}, 
        {"\"$test\"", e_args | e_double_quote | e_var_to_get} 
    };
    data()->exp = (t_token *)exp;
    data()->count = 3;
    split_tokens_test();
}

void simple_test22()
{
    data()->s = "echo hh \"$ test\"";

    t_token exp[] = { 
        {"echo", e_args | e_cmd}, {"hh", e_args}, 
        {"\"$ test\"", e_double_quote} 
    };
    data()->exp = (t_token *)exp;
    data()->count = 3;
    split_tokens_test();
}

void simple_test23()
{
    data()->s = "echo $ test";

    t_token exp[] = { 
        {"echo", e_args | e_cmd}, {"$", e_args}, 
        {"test", e_args}
    };
    data()->exp = (t_token *)exp;
    data()->count = 3;
    split_tokens_test();
}

void simple_test24()
{
    data()->s = "$write hello";

    t_token exp[] = { 
        {"$write", e_var_to_get | e_cmd | e_args},
        {"hello", e_args} 
    };
    data()->exp = (t_token *)exp;
    data()->count = 2;
    split_tokens_test();
}

void simple_test25()
{
    data()->s = "echo export GHOST=123";
    t_token exp[] = {{"echo", e_args | e_cmd}, {"export", e_args}, {"GHOST=123", e_args}};
    data()->exp = (t_token *)exp;
    data()->count = 3;
    split_tokens_test();
}

void split_tokens_test()
{
    //arrange
    t_token **tokens;

    //act
    split_tokens(data()->s, data()->sep, data()->special_sep);
    tokens = g_all.tokens->content;

    //asert
    for(int i = 0; i < data()->count; i++)
    {
        //printf("%s == %s\n", data()->exp[i].s, tokens[i]->s);
        TEST_ASSERT_EQUAL_INT32(strlen(data()->exp[i].s), strlen(tokens[i]->s));
        TEST_ASSERT_EQUAL_CHAR_ARRAY(data()->exp[i].s, tokens[i]->s, strlen(data()->exp[i].s));
        //printf("%s == %s\n", get_enum_str(data()->exp[i].type), get_enum_str(tokens[i]->type));
        TEST_ASSERT_EQUAL_INT32(data()->exp[i].type, tokens[i]->type);
    }
}

void simple_tests()
{
    RUN_TEST(simple_test1);
    RUN_TEST(simple_test2);
    RUN_TEST(simple_test3);
    RUN_TEST(simple_test4);
    RUN_TEST(simple_test5);
    RUN_TEST(simple_test6);
    RUN_TEST(simple_test7);
    RUN_TEST(simple_test8);
    RUN_TEST(simple_test9);
    RUN_TEST(simple_test10);
    RUN_TEST(simple_test11);
    RUN_TEST(simple_test12);
    RUN_TEST(simple_test13);
    RUN_TEST(simple_test14);
    RUN_TEST(simple_test15);
    RUN_TEST(simple_test16);
    RUN_TEST(simple_test17);
    RUN_TEST(simple_test18);
    RUN_TEST(simple_test19);
    RUN_TEST(simple_test21);
    RUN_TEST(simple_test22);
    RUN_TEST(simple_test23);
    RUN_TEST(simple_test24);
    RUN_TEST(simple_test25);
}
