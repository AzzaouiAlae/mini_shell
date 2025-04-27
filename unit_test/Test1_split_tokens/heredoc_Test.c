#include "../Tests.h"

void heredoc_Test1()
{
    data()->s = "cat <<HERE | ls";
    t_token exp[] = {
        {"cat", e_args | e_cmd},
        {"<<", e_heredoc},
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
        {"<<", e_heredoc},
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
        {"<<", e_heredoc},
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
        {"<<", e_heredoc},
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
        {"<<", e_heredoc},
        {"HERE", e_delimiter},
        {"<<", e_heredoc},
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
        {"<<", e_heredoc},
        {"HERE", e_delimiter},
        {"<", e_redir_in},
        {"missing", e_file_name},
        {"<<", e_heredoc},
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
        {"<<", e_heredoc},
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
        {"<<", e_heredoc},
        {"echo", e_delimiter},
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
}