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
    t_token exp[] = {{"grep", e_args | e_cmd}, {"hi", e_args},
     {"\"<infile\"", e_double_quote | e_args}, {"<", e_redir_in}, 
     {"./test_files/infile", e_file_name}};
    data()->exp = (t_token *)exp;
    data()->count = 5;
    split_tokens_test();
}

void redirects_Test3()
{
    data()->s = "echo <\"./test_files/infile\" <missing <\"./test_files/infile\"";
    t_token exp[] = {{"echo", e_args | e_cmd}, {"<", e_redir_in}, 
        {"\"./test_files/infile\"", e_double_quote | e_file_name}, {"<", e_redir_in}
        , {"missing", e_file_name}, {"<", e_redir_in}, {"\"./test_files/infile\"", e_double_quote | e_file_name}};
    data()->exp = (t_token *)exp;
    data()->count = 7;
    split_tokens_test();
}

void redirects_Test4()
{
    data()->s = "echo <missing <\"./test_files/infile\" <missing";
    t_token exp[] = {{"echo", e_args | e_cmd}, {"<", e_redir_in}, 
        {"missing", e_file_name}, {"<", e_redir_in}
        , {"\"./test_files/infile\"", e_double_quote | e_file_name}, 
        {"<", e_redir_in}, {"missing", e_file_name}};
    data()->exp = (t_token *)exp;
    data()->count = 7;
    split_tokens_test();
}

void redirects_Test5()
{
    data()->s = "cat <\"./test_files/infile\"";
    t_token exp[] = {{"cat", e_args | e_cmd}, {"<", e_redir_in}, 
        {"\"./test_files/infile\"", e_double_quote | e_file_name}};
    data()->exp = (t_token *)exp;
    data()->count = 3;
    split_tokens_test();
}

void redirects_Test6()
{
    data()->s = "echo <\"./test_files/infile_big\" | cat <\"./test_files/infile\"";
    t_token exp[] = {{"echo", e_args | e_cmd}, {"<", e_redir_in}, 
        {"\"./test_files/infile_big\"", e_double_quote | e_file_name}, 
        {"|", e_pipe}, {"cat", e_cmd | e_args}, {"<", e_redir_in}, 
        {"\"./test_files/infile\"", e_double_quote | e_file_name}};
    data()->exp = (t_token *)exp;
    data()->count = 7;
    split_tokens_test();
}

void redirects_Test7()
{
    data()->s = "echo hi | cat <\"./test_files/infile\"";
    t_token exp[] = {{"echo", e_args | e_cmd}, {"hi", e_args}, 
        {"|", e_pipe}, {"cat", e_args | e_cmd}, {"<", e_redir_in},
        {"\"./test_files/infile\"", e_double_quote | e_file_name}};
    data()->exp = (t_token *)exp;
    data()->count = 6;
    split_tokens_test();
}

void redirects_Test8()
{
    data()->s = "echo hi | cat \"./test_files/infile\"";
    t_token exp[] = {{"echo", e_args | e_cmd}, {"hi", e_args}, 
        {"|", e_pipe}, {"cat", e_args | e_cmd}, 
        {"\"./test_files/infile\"", e_double_quote | e_args | e_path}};
    data()->exp = (t_token *)exp;
    data()->count = 5;
    split_tokens_test();
}

void redirects_Test9()
{
    data()->s = "cat <\"./test_files/infile\" | echo hi";
    t_token exp[] = {{"cat", e_args | e_cmd}, {"<", e_redir_in}, 
        {"\"./test_files/infile\"", e_double_quote | e_file_name}, 
        {"|", e_pipe}, {"echo", e_cmd | e_args}, {"hi", e_args}};
    data()->exp = (t_token *)exp;
    data()->count = 6;
    split_tokens_test();
}

void redirects_Test10()
{
    data()->s = "ls >./outfiles/outfile01";
    t_token exp[] = {{"ls", e_args | e_cmd}, {">", e_redir_out_trun}, 
        {"./outfiles/outfile01", e_file_name}};
    data()->exp = (t_token *)exp;
    data()->count = 3;
    split_tokens_test();
}

void redirects_Test11()
{
    data()->s = "ls >         ./outfiles/outfile01";
    t_token exp[] = {{"ls", e_args | e_cmd}, {">", e_redir_out_trun}, 
        {"./outfiles/outfile01", e_file_name}};
    data()->exp = (t_token *)exp;
    data()->count = 3;
    split_tokens_test();
}

void redirects_Test12()
{
    data()->s = "echo hi >         ./outfiles/outfile01 bye";
    t_token exp[] = {{"echo", e_args | e_cmd}, {"hi", e_args}, 
    {">", e_redir_out_trun},{"./outfiles/outfile01", e_file_name},
    {"bye", e_args}};
    data()->exp = (t_token *)exp;
    data()->count = 5;
    split_tokens_test();
}

void redirects_Test13()
{
    data()->s = "ls >./outfiles/outfile01 >./outfiles/outfile02";
    t_token exp[] = {{"ls", e_args | e_cmd}, {">", e_redir_out_trun}, 
    {"./outfiles/outfile01", e_file_name},{">", e_redir_out_trun},
    {"./outfiles/outfile02", e_file_name}};
    data()->exp = (t_token *)exp;
    data()->count = 5;
    split_tokens_test();
}

void redirects_Test14()
{
    data()->s = "ls >\"./outfiles/outfile with spaces\"";
    t_token exp[] = {{"ls", e_args | e_cmd}, {">", e_redir_out_trun}, 
    {"\"./outfiles/outfile with spaces\"", e_double_quote | e_file_name}};
    data()->exp = (t_token *)exp;
    data()->count = 3;
    split_tokens_test();
}

void redirects_Test15()
{
    data()->s = "ls >\"./outfiles/outfile\"\"1\"\"2\"\"3\"\"4\"\"5\"";
    t_token exp[] = {{"ls", e_args | e_cmd}, {">", e_redir_out_trun}, 
    {"\"./outfiles/outfile\"\"1\"\"2\"\"3\"\"4\"\"5\"", e_double_quote | e_file_name}};
    data()->exp = (t_token *)exp;
    data()->count = 3;
    split_tokens_test();
}

void redirects_Test16()
{
    data()->s = "ls >\"./outfiles/outfile01\" >./test_files/invalid_permission >\"./outfiles/outfile02\"";
    t_token exp[] = {{"ls", e_args | e_cmd}, {">", e_redir_out_trun}, 
    {"\"./outfiles/outfile01\"", e_double_quote | e_file_name},
    {">", e_redir_out_trun}, {"./test_files/invalid_permission", e_file_name},
    {">", e_redir_out_trun}, {"\"./outfiles/outfile02\"", e_double_quote | e_file_name}};
    data()->exp = (t_token *)exp;
    data()->count = 7;
    split_tokens_test();
}

void redirects_Test17()
{
    data()->s = "ls >./test_files/invalid_permission >\"./outfiles/outfile01\" >./test_files/invalid_permission";
    t_token exp[] = {{"ls", e_args | e_cmd}, {">", e_redir_out_trun}, 
    {"./test_files/invalid_permission", e_file_name}, {">", e_redir_out_trun}, 
    {"\"./outfiles/outfile01\"", e_double_quote | e_file_name}, {">", e_redir_out_trun}, 
    {"./test_files/invalid_permission", e_file_name}};
    data()->exp = (t_token *)exp;
    data()->count = 7;
    split_tokens_test();
}

void redirects_Test18()
{
    data()->s = "cat <\"./test_files/infile\" >\"./outfiles/outfile01\"";
    t_token exp[] = {{"cat", e_args | e_cmd}, {"<", e_redir_in}, {"\"./test_files/infile\"", e_double_quote | e_file_name},
        {">", e_redir_out_trun}, {"\"./outfiles/outfile01\"", e_double_quote | e_file_name}};
    data()->exp = (t_token *)exp;
    data()->count = 5;
    split_tokens_test();
}

void redirects_Test19()
{
    data()->s = "echo hi >./outfiles/outfile01 | echo bye";
    t_token exp[] = {{"echo", e_args | e_cmd}, {"hi", e_args}, {">", e_redir_out_trun},
    {"./outfiles/outfile01", e_file_name}, {"|", e_pipe}, {"echo", e_args | e_cmd}, {"bye", e_args}};
    data()->exp = (t_token *)exp;
    data()->count = 7;
    split_tokens_test();
}

void redirects_Test20()
{
    data()->s = "echo hi >./outfiles/outfile01 >./outfiles/outfile02 | echo bye";
    t_token exp[] = {{"echo", e_args | e_cmd}, {"hi", e_args}, {">", e_redir_out_trun}, 
        {"./outfiles/outfile01", e_file_name}, {">", e_redir_out_trun}, {"./outfiles/outfile02", e_file_name},
        {"|", e_pipe}, {"echo", e_cmd | e_args}, {"bye", e_args}};
    data()->exp = (t_token *)exp;
    data()->count = 9;
    split_tokens_test();
}

void redirects_Test21()
{
    data()->s = "echo hi | echo >./outfiles/outfile01 bye";
    t_token exp[] = {{"echo", e_args | e_cmd}, {"hi", e_args}, {"|", e_pipe}, {"echo", e_args | e_cmd},
    {">", e_redir_out_trun}, {"./outfiles/outfile01", e_file_name}, {"bye", e_args}};
    data()->exp = (t_token *)exp;
    data()->count = 7;
    split_tokens_test();
}

void redirects_Test22()
{
    data()->s = "echo hi | echo bye >./outfiles/outfile01 >./outfiles/outfile02";
    t_token exp[] = {{"echo", e_args | e_cmd}, {"hi", e_args}, {"|", e_pipe}, {"echo", e_args | e_cmd},
        {"bye", e_args}, {">", e_redir_out_trun}, {"./outfiles/outfile01", e_file_name}, {">", e_redir_out_trun},
        {"./outfiles/outfile02", e_file_name}};
    data()->exp = (t_token *)exp;
    data()->count = 9;
    split_tokens_test();
}

void redirects_Test23()
{
    data()->s = "echo hi >./outfiles/outfile01 | echo bye >./outfiles/outfile02";
    t_token exp[] = {{"echo", e_args | e_cmd}, {"hi", e_args}, {">", e_redir_out_trun},
    {"./outfiles/outfile01", e_file_name}, {"|", e_pipe}, {"echo", e_args | e_cmd},
    {"bye", e_args}, {">", e_redir_out_trun}, {"./outfiles/outfile02", e_file_name}};
    data()->exp = (t_token *)exp;
    data()->count = 9;
    split_tokens_test();
}

void redirects_Test24()
{
    data()->s = "echo hi >./outfiles/outfile01 | echo bye >./outfiles/outfile02";
    t_token exp[] = {{"echo", e_args | e_cmd}, {"hi", e_args}, {">", e_redir_out_trun},
    {"./outfiles/outfile01", e_file_name}, {"|", e_pipe}, {"echo", e_args | e_cmd}, 
    {"bye", e_args}, {">", e_redir_out_trun}, {"./outfiles/outfile02", e_file_name}};
    data()->exp = (t_token *)exp;
    data()->count = 9;
    split_tokens_test();
}

void redirects_Test25()
{
    data()->s = "echo hi >./test_files/invalid_permission | echo bye";
    t_token exp[] = {{"echo", e_args | e_cmd}, {"hi", e_args}, {">", e_redir_out_trun},
    {"./test_files/invalid_permission", e_file_name}, {"|", e_pipe}, {"echo", e_args | e_cmd},
    {"bye", e_args}};
    data()->exp = (t_token *)exp;
    data()->count = 7;
    split_tokens_test();
}

void redirects_Test26()
{
    data()->s = "echo hi >./test_files/invalid_permission >./outfiles/outfile01 | echo bye";
    t_token exp[] = {{"echo", e_args | e_cmd}, {"hi", e_args}, {">", e_redir_out_trun},
    {"./test_files/invalid_permission", e_file_name}, {">", e_redir_out_trun}, {"./outfiles/outfile01", e_file_name},
    {"|", e_pipe}, {"echo", e_args | e_cmd}, {"bye", e_args}};
    data()->exp = (t_token *)exp;
    data()->count = 9;
    split_tokens_test();
}

void redirects_Test27()
{
    data()->s = "echo hi | echo bye >./test_files/invalid_permission";
    t_token exp[] = {{"echo", e_args | e_cmd}, {"hi", e_args}, {"|", e_pipe},
    {"echo", e_cmd | e_args}, {"bye", e_args}, {">", e_redir_out_trun},
    {"./test_files/invalid_permission", e_file_name}};
    data()->exp = (t_token *)exp;
    data()->count = 7;
    split_tokens_test();
}

void redirects_Test28()
{
    data()->s = "echo hi | >./outfiles/outfile01 echo bye >./test_files/invalid_permission";
    t_token exp[] = {{"echo", e_args | e_cmd}, {"hi", e_args}, {"|", e_pipe}, {">", e_redir_out_trun}, 
    {"./outfiles/outfile01", e_file_name}, {"echo", e_args | e_cmd}, {"bye", e_args}, {">", e_redir_out_trun},
    {"./test_files/invalid_permission", e_file_name}};
    data()->exp = (t_token *)exp;
    data()->count = 9;
    split_tokens_test();
}

void redirects_Test29()
{
    data()->s = "echo hi | echo bye >./test_files/invalid_permission >./outfiles/outfile01";
    t_token exp[] = {
        {"echo", e_args | e_cmd},
        {"hi", e_args},
        {"|", e_pipe},
        {"echo", e_args | e_cmd},
        {"bye", e_args},
        {">", e_redir_out_trun},
        {"./test_files/invalid_permission", e_file_name},
        {">", e_redir_out_trun},
        {"./outfiles/outfile01", e_file_name}
    };
    data()->exp = (t_token *)exp;
    data()->count = 9;
    split_tokens_test();
}

void redirects_Test30()
{
    data()->s = "cat <\"./test_files/infile\" >./test_files/invalid_permission";
    t_token exp[] = {
        {"cat", e_args | e_cmd},
        {"<", e_redir_in},
        {"\"./test_files/infile\"", e_double_quote | e_file_name},
        {">", e_redir_out_trun},
        {"./test_files/invalid_permission", e_file_name}
    };
    data()->exp = (t_token *)exp;
    data()->count = 5;
    split_tokens_test();
}

void redirects_Test31()
{
    data()->s = "cat >./test_files/invalid_permission <\"./test_files/infile\"";
    t_token exp[] = {
        {"cat", e_args | e_cmd},
        {">", e_redir_out_trun},
        {"./test_files/invalid_permission", e_file_name},
        {"<", e_redir_in},
        {"\"./test_files/infile\"", e_double_quote | e_file_name}
    };
    data()->exp = (t_token *)exp;
    data()->count = 5;
    split_tokens_test();
}

void redirects_Test32()
{
    data()->s = "cat <missing >./outfiles/outfile01";
    t_token exp[] = {
        {"cat", e_args | e_cmd},
        {"<", e_redir_in},
        {"missing", e_file_name},
        {">", e_redir_out_trun},
        {"./outfiles/outfile01", e_file_name}
    };
    data()->exp = (t_token *)exp;
    data()->count = 5;
    split_tokens_test();
}

void redirects_Test33()
{
    data()->s = "cat >./outfiles/outfile01 <missing";
    t_token exp[] = {
        {"cat", e_args | e_cmd},
        {">", e_redir_out_trun},
        {"./outfiles/outfile01", e_file_name},
        {"<", e_redir_in},
        {"missing", e_file_name}
    };
    data()->exp = (t_token *)exp;
    data()->count = 5;
    split_tokens_test();
}

void redirects_Test34()
{
    data()->s = "cat <missing >./test_files/invalid_permission";
    t_token exp[] = {
        {"cat", e_args | e_cmd},
        {"<", e_redir_in},
        {"missing", e_file_name},
        {">", e_redir_out_trun},
        {"./test_files/invalid_permission", e_file_name}
    };
    data()->exp = (t_token *)exp;
    data()->count = 5;
    split_tokens_test();
}

void redirects_Test35()
{
    data()->s = "cat >./outfiles/outfile01 <missing >./test_files/invalid_permission";
    t_token exp[] = {
        {"cat", e_args | e_cmd},
        {">", e_redir_out_trun},
        {"./outfiles/outfile01", e_file_name},
        {"<", e_redir_in},
        {"missing", e_file_name},
        {">", e_redir_out_trun},
        {"./test_files/invalid_permission", e_file_name}
    };
    data()->exp = (t_token *)exp;
    data()->count = 7;
    split_tokens_test();
}

void redirects_Test36()
{
    data()->s = "ls >>./outfiles/outfile01";
    t_token exp[] = {
        {"ls", e_args | e_cmd},
        {">>", e_redir_out_app},
        {"./outfiles/outfile01", e_file_name}
    };
    data()->exp = (t_token *)exp;
    data()->count = 3;
    split_tokens_test();
}

void redirects_Test37()
{
    data()->s = "ls >>      ./outfiles/outfile01";
    t_token exp[] = {
        {"ls", e_args | e_cmd},
        {">>", e_redir_out_app},
        {"./outfiles/outfile01", e_file_name}
    };
    data()->exp = (t_token *)exp;
    data()->count = 3;
    split_tokens_test();
}

void redirects_Test38()
{
    data()->s = "ls >>./outfiles/outfile01 >./outfiles/outfile01";
    t_token exp[] = {
        {"ls", e_args | e_cmd},
        {">>", e_redir_out_app},
        {"./outfiles/outfile01", e_file_name},
        {">", e_redir_out_trun},
        {"./outfiles/outfile01", e_file_name}
    };
    data()->exp = (t_token *)exp;
    data()->count = 5;
    split_tokens_test();
}

void redirects_Test39()
{
    data()->s = "ls >./outfiles/outfile01 >>./outfiles/outfile01";
    t_token exp[] = {
        {"ls", e_args | e_cmd},
        {">", e_redir_out_trun},
        {"./outfiles/outfile01", e_file_name},
        {">>", e_redir_out_app},
        {"./outfiles/outfile01", e_file_name}
    };
    data()->exp = (t_token *)exp;
    data()->count = 5;
    split_tokens_test();
}

void redirects_Test40()
{
    data()->s = "ls >./outfiles/outfile01 >>./outfiles/outfile01 >./outfiles/outfile02";
    t_token exp[] = {
        {"ls", e_args | e_cmd},
        {">", e_redir_out_trun},
        {"./outfiles/outfile01", e_file_name},
        {">>", e_redir_out_app},
        {"./outfiles/outfile01", e_file_name},
        {">", e_redir_out_trun},
        {"./outfiles/outfile02", e_file_name}
    };
    data()->exp = (t_token *)exp;
    data()->count = 7;
    split_tokens_test();
}

void redirects_Test41()
{
    data()->s = "ls >>./outfiles/outfile01 >>./outfiles/outfile02";
    t_token exp[] = {
        {"ls", e_args | e_cmd},
        {">>", e_redir_out_app},
        {"./outfiles/outfile01", e_file_name},
        {">>", e_redir_out_app},
        {"./outfiles/outfile02", e_file_name}
    };
    data()->exp = (t_token *)exp;
    data()->count = 5;
    split_tokens_test();
}

void redirects_Test42()
{
    data()->s = "ls >>./test_files/invalid_permission";
    t_token exp[] = {
        {"ls", e_args | e_cmd},
        {">>", e_redir_out_app},
        {"./test_files/invalid_permission", e_file_name}
    };
    data()->exp = (t_token *)exp;
    data()->count = 3;
    split_tokens_test();
}

void redirects_Test43()
{
    data()->s = "ls >>./test_files/invalid_permission >>./outfiles/outfile01";
    t_token exp[] = {
        {"ls", e_args | e_cmd},
        {">>", e_redir_out_app},
        {"./test_files/invalid_permission", e_file_name},
        {">>", e_redir_out_app},
        {"./outfiles/outfile01", e_file_name}
    };
    data()->exp = (t_token *)exp;
    data()->count = 5;
    split_tokens_test();
}

void redirects_Test44()
{
    data()->s = "ls >>./outfiles/outfile01 >>./test_files/invalid_permission";
    t_token exp[] = {
        {"ls", e_args | e_cmd},
        {">>", e_redir_out_app},
        {"./outfiles/outfile01", e_file_name},
        {">>", e_redir_out_app},
        {"./test_files/invalid_permission", e_file_name}
    };
    data()->exp = (t_token *)exp;
    data()->count = 5;
    split_tokens_test();
}

void redirects_Test45()
{
    data()->s = "ls >./outfiles/outfile01 >>./test_files/invalid_permission >>./outfiles/outfile02";
    t_token exp[] = {
        {"ls", e_args | e_cmd},
        {">", e_redir_out_trun},
        {"./outfiles/outfile01", e_file_name},
        {">>", e_redir_out_app},
        {"./test_files/invalid_permission", e_file_name},
        {">>", e_redir_out_app},
        {"./outfiles/outfile02", e_file_name}
    };
    data()->exp = (t_token *)exp;
    data()->count = 7;
    split_tokens_test();
}


void redirects_Test46()
{
    data()->s = "ls <missing >>./test_files/invalid_permission >>./outfiles/outfile02";
    t_token exp[] = {
        {"ls", e_args | e_cmd},
        {"<", e_redir_in},
        {"missing", e_file_name},
        {">>", e_redir_out_app},
        {"./test_files/invalid_permission", e_file_name},
        {">>", e_redir_out_app},
        {"./outfiles/outfile02", e_file_name}
    };
    data()->exp = (t_token *)exp;
    data()->count = 7;
    split_tokens_test();
}

void redirects_Test47()
{
    data()->s = "ls >>./test_files/invalid_permission >>./outfiles/outfile02 <missing";
    t_token exp[] = {
        {"ls", e_args | e_cmd},
        {">>", e_redir_out_app},
        {"./test_files/invalid_permission", e_file_name},
        {">>", e_redir_out_app},
        {"./outfiles/outfile02", e_file_name},
        {"<", e_redir_in},
        {"missing", e_file_name}
    };
    data()->exp = (t_token *)exp;
    data()->count = 7;
    split_tokens_test();
}

void redirects_Test48()
{
    data()->s = "echo hi >>./outfiles/outfile01 | echo bye";
    t_token exp[] = {
        {"echo", e_args | e_cmd},
        {"hi", e_args},
        {">>", e_redir_out_app},
        {"./outfiles/outfile01", e_file_name},
        {"|", e_pipe},
        {"echo", e_args | e_cmd},
        {"bye", e_args}
    };
    data()->exp = (t_token *)exp;
    data()->count = 7;
    split_tokens_test();
}

void redirects_Test49()
{
    data()->s = "echo hi >>./outfiles/outfile01 >>./outfiles/outfile02 | echo bye";
    t_token exp[] = {
        {"echo", e_args | e_cmd},
        {"hi", e_args},
        {">>", e_redir_out_app},
        {"./outfiles/outfile01", e_file_name},
        {">>", e_redir_out_app},
        {"./outfiles/outfile02", e_file_name},
        {"|", e_pipe},
        {"echo", e_args | e_cmd},
        {"bye", e_args}
    };
    data()->exp = (t_token *)exp;
    data()->count = 9;
    split_tokens_test();
}

void redirects_Test50()
{
    data()->s = "echo hi | echo >>./outfiles/outfile01 bye";
    t_token exp[] = {
        {"echo", e_args | e_cmd},
        {"hi", e_args},
        {"|", e_pipe},
        {"echo", e_args | e_cmd},
        {">>", e_redir_out_app},
        {"./outfiles/outfile01", e_file_name},
        {"bye", e_args}
    };
    data()->exp = (t_token *)exp;
    data()->count = 7;
    split_tokens_test();
}

void redirects_Test51()
{
    data()->s = "echo hi | echo bye >>./outfiles/outfile01 >>./outfiles/outfile02";
    t_token exp[] = {
        {"echo", e_args | e_cmd},
        {"hi", e_args},
        {"|", e_pipe},
        {"echo", e_args | e_cmd},
        {"bye", e_args},
        {">>", e_redir_out_app},
        {"./outfiles/outfile01", e_file_name},
        {">>", e_redir_out_app},
        {"./outfiles/outfile02", e_file_name}
    };
    data()->exp = (t_token *)exp;
    data()->count = 9;
    split_tokens_test();
}

void redirects_Test52()
{
    data()->s = "echo hi >>./outfiles/outfile01 | echo bye >>./outfiles/outfile02";
    t_token exp[] = {
        {"echo", e_args | e_cmd},
        {"hi", e_args},
        {">>", e_redir_out_app},
        {"./outfiles/outfile01", e_file_name},
        {"|", e_pipe},
        {"echo", e_args | e_cmd},
        {"bye", e_args},
        {">>", e_redir_out_app},
        {"./outfiles/outfile02", e_file_name}
    };
    data()->exp = (t_token *)exp;
    data()->count = 9;
    split_tokens_test();
}

void redirects_Test53()
{
    data()->s = "echo hi >>./test_files/invalid_permission | echo bye";
    t_token exp[] = {
        {"echo", e_args | e_cmd},
        {"hi", e_args},
        {">>", e_redir_out_app},
        {"./test_files/invalid_permission", e_file_name},
        {"|", e_pipe},
        {"echo", e_args | e_cmd},
        {"bye", e_args}
    };
    data()->exp = (t_token *)exp;
    data()->count = 7;
    split_tokens_test();
}

void redirects_Test54()
{
    data()->s = "echo hi >>./test_files/invalid_permission >./outfiles/outfile01 | echo bye";
    t_token exp[] = {
        {"echo", e_args | e_cmd},
        {"hi", e_args},
        {">>", e_redir_out_app},
        {"./test_files/invalid_permission", e_file_name},
        {">", e_redir_out_trun},
        {"./outfiles/outfile01", e_file_name},
        {"|", e_pipe},
        {"echo", e_args | e_cmd},
        {"bye", e_args}
    };
    data()->exp = (t_token *)exp;
    data()->count = 9;
    split_tokens_test();
}

void redirects_Test55()
{
    data()->s = "echo hi | echo bye >>./test_files/invalid_permission";
    t_token exp[] = {
        {"echo", e_args | e_cmd},
        {"hi", e_args},
        {"|", e_pipe},
        {"echo", e_args | e_cmd},
        {"bye", e_args},
        {">>", e_redir_out_app},
        {"./test_files/invalid_permission", e_file_name}
    };
    data()->exp = (t_token *)exp;
    data()->count = 7;
    split_tokens_test();
}

void redirects_Test56()
{
    data()->s = "echo hi | echo >>./outfiles/outfile01 bye >./test_files/invalid_permission";
    t_token exp[] = {
        {"echo", e_args | e_cmd},
        {"hi", e_args},
        {"|", e_pipe},
        {"echo", e_args | e_cmd},
        {">>", e_redir_out_app},
        {"./outfiles/outfile01", e_file_name},
        {"bye", e_args},
        {">", e_redir_out_trun},
        {"./test_files/invalid_permission", e_file_name}
    };
    data()->exp = (t_token *)exp;
    data()->count = 9;
    split_tokens_test();
}

void redirects_Test57()
{
    data()->s = "cat <minishell.h>./outfiles/outfile";
    t_token exp[] = {
        {"cat", e_args | e_cmd},
        {"<", e_redir_in},
        {"minishell.h", e_file_name},
        {">", e_redir_out_trun},
        {"./outfiles/outfile", e_file_name}
    };
    data()->exp = (t_token *)exp;
    data()->count = 5;
    split_tokens_test();
}

void redirects_Test58()
{
    data()->s = "cat <minishell.h|ls";
    t_token exp[] = {
        {"cat", e_args | e_cmd},
        {"<", e_redir_in},
        {"minishell.h", e_file_name},
        {"|", e_pipe},
        {"ls", e_args | e_cmd}
    };
    data()->exp = (t_token *)exp;
    data()->count = 5;
    split_tokens_test();
}

void redirects_Tests()
{
    RUN_TEST(redirects_Test1);
    RUN_TEST(redirects_Test2);
    RUN_TEST(redirects_Test3);
    RUN_TEST(redirects_Test4);
    RUN_TEST(redirects_Test5);
    RUN_TEST(redirects_Test6);
    RUN_TEST(redirects_Test7);
    RUN_TEST(redirects_Test8);
    RUN_TEST(redirects_Test9);
    RUN_TEST(redirects_Test10);
    RUN_TEST(redirects_Test11);
    RUN_TEST(redirects_Test12);
    RUN_TEST(redirects_Test13);
    RUN_TEST(redirects_Test14);
    RUN_TEST(redirects_Test15);
    RUN_TEST(redirects_Test16);
    RUN_TEST(redirects_Test17);
    RUN_TEST(redirects_Test18);
    RUN_TEST(redirects_Test19);
    RUN_TEST(redirects_Test20);
    RUN_TEST(redirects_Test21);
    RUN_TEST(redirects_Test22);
    RUN_TEST(redirects_Test23);
    RUN_TEST(redirects_Test24);
    RUN_TEST(redirects_Test25);
    RUN_TEST(redirects_Test26);
    RUN_TEST(redirects_Test27);
    RUN_TEST(redirects_Test28);
    RUN_TEST(redirects_Test29);
    RUN_TEST(redirects_Test30);
    RUN_TEST(redirects_Test31);
    RUN_TEST(redirects_Test32);
    RUN_TEST(redirects_Test33);
    RUN_TEST(redirects_Test34);
    RUN_TEST(redirects_Test35);
    RUN_TEST(redirects_Test36);
    RUN_TEST(redirects_Test37);
    RUN_TEST(redirects_Test38);
    RUN_TEST(redirects_Test39);
    RUN_TEST(redirects_Test40);
    RUN_TEST(redirects_Test41);
    RUN_TEST(redirects_Test42);
    RUN_TEST(redirects_Test43);
    RUN_TEST(redirects_Test44);
    RUN_TEST(redirects_Test45);
    RUN_TEST(redirects_Test46);
    RUN_TEST(redirects_Test47);
    RUN_TEST(redirects_Test48);
    RUN_TEST(redirects_Test49);
    RUN_TEST(redirects_Test50);
    RUN_TEST(redirects_Test51);
    RUN_TEST(redirects_Test52);
    RUN_TEST(redirects_Test53);
    RUN_TEST(redirects_Test54);
    RUN_TEST(redirects_Test55);
    RUN_TEST(redirects_Test56);
    RUN_TEST(redirects_Test57);
    RUN_TEST(redirects_Test58);
}
