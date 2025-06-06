#include "../Tests.h"

void heredoc_Test1()
{
    data()->s = "cat <<HERE | ls";
    t_token exp[] = {
        {"cat", e_args | e_cmd},
        {"<<", e_heredoc | e_var_to_get},
        {"HERE", e_delimiter},
        {"|", e_pipe},
        {"ls", e_args | e_cmd}
    };
    data()->exp = (t_token *)exp;
    data()->count = 5;
    split_tokens_test();
}

void heredoc_Test2()
{
    data()->s = "cat <<HERE";
    t_token exp[] = {
        {"cat", e_args | e_cmd},
        {"<<", e_heredoc | e_var_to_get},
        {"HERE", e_delimiter}
    };
    data()->exp = (t_token *)exp;
    data()->count = 3;
    split_tokens_test();
}

void heredoc_Test3()
{
    data()->s = "cat <minishell.h <<HERE <missing | ls";
    t_token exp[] = {
        {"cat", e_args | e_cmd},
        {"<", e_redir_in},
        {"minishell.h", e_file_name},
        {"<<", e_heredoc | e_var_to_get},
        {"HERE", e_delimiter},
        {"<", e_redir_in},
        {"missing", e_file_name},
        {"|", e_pipe},
        {"ls", e_args | e_cmd}
    };
    data()->exp = (t_token *)exp;
    data()->count = 9;
    split_tokens_test();
}

void heredoc_Test4()
{
    data()->s = "cat <minishell.h <<HERE | cat";
    t_token exp[] = {
        {"cat", e_args | e_cmd},
        {"<", e_redir_in},
        {"minishell.h", e_file_name},
        {"<<", e_heredoc | e_var_to_get},
        {"HERE", e_delimiter},
        {"|", e_pipe},
        {"cat", e_args | e_cmd}
    };
    data()->exp = (t_token *)exp;
    data()->count = 7;
    split_tokens_test();
}

void heredoc_Test5()
{
    data()->s = "cat <<HERE <<DOC";
    t_token exp[] = {
        {"cat", e_args | e_cmd},
        {"<<", e_heredoc | e_var_to_get},
        {"HERE", e_delimiter},
        {"<<", e_heredoc | e_var_to_get},
        {"DOC", e_delimiter}
    };
    data()->exp = (t_token *)exp;
    data()->count = 5;
    split_tokens_test();
}

void heredoc_Test6()
{
    data()->s = "cat <minishell.h <<HERE <missing <<DOC | echo oi";
    t_token exp[] = {
        {"cat", e_args | e_cmd},
        {"<", e_redir_in},
        {"minishell.h", e_file_name},
        {"<<", e_heredoc | e_var_to_get},
        {"HERE", e_delimiter},
        {"<", e_redir_in},
        {"missing", e_file_name},
        {"<<", e_heredoc | e_var_to_get},
        {"DOC", e_delimiter},
        {"|", e_pipe},
        {"echo", e_args | e_cmd},
        {"oi", e_args}
    };
    data()->exp = (t_token *)exp;
    data()->count = 11;
    split_tokens_test();
}

void heredoc_Test7()
{
    data()->s = "cat << $";
    t_token exp[] = {
        {"cat", e_args | e_cmd},
        {"<<", e_heredoc | e_var_to_get},
        {"$", e_delimiter}
    };
    data()->exp = (t_token *)exp;
    data()->count = 3;
    split_tokens_test();
}

void heredoc_Test8()
{
    data()->s = "<< echo oi";
    t_token exp[] = {
        {"<<", e_heredoc | e_var_to_get},
        {"echo", e_delimiter},
        {"oi", e_args | e_cmd}
    };
    data()->exp = (t_token *)exp;
    data()->count = 3;
    split_tokens_test();
}

void heredoc_Test9()
{
    data()->s = "<< $$a oi";
    t_token exp[] = {
        {"<<", e_heredoc | e_var_to_get},
        {"$$a", e_delimiter},
        {"oi", e_args | e_cmd}
    };
    data()->exp = (t_token *)exp;
    data()->count = 3;
    split_tokens_test();
}

void heredoc_Test10()
{
    data()->s = "<< $$$a oi";
    t_token exp[] = {
        {"<<", e_heredoc | e_var_to_get},
        {"$$$a", e_delimiter},
        {"oi", e_args | e_cmd}
    };
    data()->exp = (t_token *)exp;
    data()->count = 3;
    split_tokens_test();
}

void heredoc_Test11()
{
    data()->s = "<< $$$$a oi";
    t_token exp[] = {
        {"<<", e_heredoc | e_var_to_get},
        {"$$$$a", e_delimiter},
        {"oi", e_args | e_cmd}
    };
    data()->exp = (t_token *)exp;
    data()->count = 3;
    split_tokens_test();
}

void heredoc_Test12()
{
    data()->s = "<< $\"$$$a\" oi";
    t_token exp[] = {
        {"<<", e_heredoc},
        {"$$$a", e_delimiter},
        {"oi", e_args | e_cmd}
    };
    data()->exp = (t_token *)exp;
    data()->count = 3;
    split_tokens_test();
}

void heredoc_Test13()
{
    data()->s = "<< $\"$$a\" oi";
    t_token exp[] = {
        {"<<", e_heredoc},
        {"$$a", e_delimiter},
        {"oi", e_args | e_cmd}
    };
    data()->exp = (t_token *)exp;
    data()->count = 3;
    split_tokens_test();
}

void heredoc_Test14()
{
    data()->s = "<< $\"$a\" oi";
    t_token exp[] = {
        {"<<", e_heredoc},
        {"$a", e_delimiter},
        {"oi", e_args | e_cmd}
    };
    data()->exp = (t_token *)exp;
    data()->count = 3;
    split_tokens_test();
}

void heredoc_Test15()
{
    data()->s = "<< $\"a\" oi";
    t_token exp[] = {
        {"<<", e_heredoc},
        {"a", e_delimiter},
        {"oi", e_args | e_cmd}
    };
    data()->exp = (t_token *)exp;
    data()->count = 3;
    split_tokens_test();
}

void heredoc_Test16()
{
    data()->s = "<< $'$$$a' oi";
    t_token exp[] = {
        {"<<", e_heredoc},
        {"$$$a", e_delimiter},
        {"oi", e_args | e_cmd}
    };
    data()->exp = (t_token *)exp;
    data()->count = 3;
    split_tokens_test();
}

void heredoc_Test17()
{
    data()->s = "<< $'$$a' oi";
    t_token exp[] = {
        {"<<", e_heredoc},
        {"$$a", e_delimiter},
        {"oi", e_args | e_cmd}
    };
    data()->exp = (t_token *)exp;
    data()->count = 3;
    split_tokens_test();
}

void heredoc_Test18()
{
    data()->s = "<< $'$a' oi";
    t_token exp[] = {
        {"<<", e_heredoc},
        {"$a", e_delimiter},
        {"oi", e_args | e_cmd}
    };
    data()->exp = (t_token *)exp;
    data()->count = 3;
    split_tokens_test();
}

void heredoc_Test19()
{
    data()->s = "<< $'a' oi";
    t_token exp[] = {
        {"<<", e_heredoc},
        {"a", e_delimiter},
        {"oi", e_args | e_cmd}
    };
    data()->exp = (t_token *)exp;
    data()->count = 3;
    split_tokens_test();
}

void heredoc_Test20()
{
    data()->s = "<< $$'a' oi";
    t_token exp[] = {
        {"<<", e_heredoc},
        {"$$a", e_delimiter},
        {"oi", e_args | e_cmd}
    };
    data()->exp = (t_token *)exp;
    data()->count = 3;
    split_tokens_test();
}

void heredoc_Test21()
{
    data()->s = "<< $$$'a' oi";
    t_token exp[] = {
        {"<<", e_heredoc},
        {"$$a", e_delimiter},
        {"oi", e_args | e_cmd}
    };
    data()->exp = (t_token *)exp;
    data()->count = 3;
    split_tokens_test();
}

void heredoc_Test()
{
    RUN_TEST(heredoc_Test1);
    RUN_TEST(heredoc_Test2);
    RUN_TEST(heredoc_Test3);
    RUN_TEST(heredoc_Test4);
    RUN_TEST(heredoc_Test5);
    RUN_TEST(heredoc_Test6);
    RUN_TEST(heredoc_Test7);
    RUN_TEST(heredoc_Test8);
    RUN_TEST(heredoc_Test9);
    RUN_TEST(heredoc_Test10);
    RUN_TEST(heredoc_Test11);
    RUN_TEST(heredoc_Test12);
    RUN_TEST(heredoc_Test13);
    RUN_TEST(heredoc_Test14);
    RUN_TEST(heredoc_Test15);
    RUN_TEST(heredoc_Test16);
    RUN_TEST(heredoc_Test17);
    RUN_TEST(heredoc_Test18);
    RUN_TEST(heredoc_Test19);
    RUN_TEST(heredoc_Test20);
    RUN_TEST(heredoc_Test21);
}