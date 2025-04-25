#include "complete_Tests.h"

void execute_cmd_input(char *input)
{
    split_tokens(input, data()->sep, data()->special_sep);
    ft_check_syntax_error();
    get_variables_value();
    add_vars_to_env();
    rm_single_double_qoute();
    open_redirection_files();
    create_cmd();
}

void assert_env_var(char *input, char *key, char *exp, int len)
{
    //Arrange
    t_cs_list *var;

    //act
    execute_cmd_input(input);

    //ASSERT
    var = cpp_map_get(g_all.custom_env, "HELLO");
    TEST_ASSERT_EQUAL_CHAR_ARRAY(exp, var->content, 4);
}

void builtins_complete(char *input, t_cmd *exp, int cmds_count)
{
    //arrange
    t_cmd **act_cmd;

    //act
    execute_cmd_input(input);

    //assert
    act_cmd = g_all.cmds->content;
    if (cmds_count != g_all.cmds->count)
        printf("cmds_count exp=%d  but was=%d\n", cmds_count, g_all.cmds->count);
    TEST_ASSERT_EQUAL_INT32(cmds_count, g_all.cmds->count);
    for(int i = 0; cmds_count > i; i++)
    {
        if (strlen(exp[i].cmd_path) != strlen(act_cmd[i]->cmd_path))
            printf("exp=%s  but was=%s\n", exp[i].cmd_path, act_cmd[i]->cmd_path);
        TEST_ASSERT_EQUAL_INT32(strlen(exp[i].cmd_path), strlen(act_cmd[i]->cmd_path));
        TEST_ASSERT_EQUAL_CHAR_ARRAY(exp[i].cmd_path, act_cmd[i]->cmd_path,  strlen(act_cmd[i]->cmd_path) + 1);
        if (ft_strslen(exp[i].args) != ft_strslen(act_cmd[i]->args))
            printf("args exp=%d  but was=%d\n", ft_strslen(exp[i].args), ft_strslen(act_cmd[i]->args));
        for (int j = 0; exp[i].args[j]; j++)
        {
            if (strlen(exp[i].args[j]) != strlen(act_cmd[i]->args[j]))
                printf("exp=%s  but was=%s\n", exp[i].args[j], act_cmd[i]->args[j]);
            TEST_ASSERT_EQUAL_INT32(strlen(exp[i].args[j]), strlen(act_cmd[i]->args[j]));
            TEST_ASSERT_EQUAL_CHAR_ARRAY(exp[i].args[j], act_cmd[i]->args[j],  strlen(act_cmd[i]->args[j]) + 1);
        }
        TEST_ASSERT_EQUAL_INT32(exp[i].heredoc_fd, act_cmd[i]->heredoc_fd);
        TEST_ASSERT_EQUAL_INT32(exp[i].redir_out_app_fd, act_cmd[i]->redir_out_app_fd);
        TEST_ASSERT_EQUAL_INT32(exp[i].redir_out_trun_fd, act_cmd[i]->redir_out_trun_fd);
        TEST_ASSERT_EQUAL_INT32(exp[i].redir_in_fd, act_cmd[i]->redir_in_fd);
    }
}

void builtins_complete_Test1()
{
    //Arrange
    char *input = "echo hello world";
    char *args[] = {"echo", "hello", "world", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0, 0, 0 }, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test2()
{
    //Arrange
    char *input = "echo \"hello world\"";
    char *args[] = {"echo", "hello world", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0, 0, 0 }, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test3()
{
    //Arrange
    char *input = "echo 'hello world'";
    char *args[] = {"echo", "hello world", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0, 0, 0 }, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test4()
{
    //Arrange
    char *input = "echo hello'world'";
    char *args[] = {"echo", "helloworld", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0, 0, 0 }, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test5()
{
    //Arrange
    char *input = "echo hello\"\"world";
    char *args[] = {"echo", "helloworld", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0, 0, 0 }, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test6()
{
    //Arrange
    char *input = "echo ''";
    char *args[] = {"echo", "", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0, 0, 0 }, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test7()
{
    //Arrange
    char *input = "echo \"$PWD\"";
    char *args[] = {"echo", "/home/aazzaoui/Desktop/projects/mini_shell_All/mini_shell_Repo2/unit_test", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0, 0, 0 }, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test8()
{
    //Arrange
    char *input = "echo '$PWD'";
    char *args[] = {"echo", "$PWD", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0, 0, 0 }, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test9()
{
    //Arrange
    char *input = "echo \"aspas ->'\"";
    char *args[] = {"echo", "aspas ->'", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0, 0, 0 }, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test10()
{
    //Arrange
    char *input = "echo \"aspas -> ' \"";
    char *args[] = {"echo", "aspas -> ' ", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0, 0, 0 }, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test11()
{
    //Arrange
    char *input = "echo 'aspas ->\"'";
    char *args[] = {"echo", "aspas ->\"", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0, 0, 0 }, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test12()
{
    //Arrange
    char *input = "echo 'aspas -> \" '";
    char *args[] = {"echo", "aspas -> \" ", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0, 0, 0 }, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test13()
{
    //Arrange
    char *input = "echo \"> >> < * ? [ ] | ; [ ] || && ( ) & # $ \\ <<\"";
    char *args[] = {"echo", "> >> < * ? [ ] | ; [ ] || && ( ) & # $ \\ <<", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0, 0, 0 }, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test14()
{
    //Arrange
    char *input = "echo '> >> < * ? [ ] | ; [ ] || && ( ) & # $ \\ <<'";
    char *args[] = {"echo", "> >> < * ? [ ] | ; [ ] || && ( ) & # $ \\ <<", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0, 0, 0 }, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test15()
{
    //Arrange
    char *input = "echo \"exit_code ->$? user ->$USER home -> $HOME\"";
    char *args[] = {"echo", "exit_code ->0 user ->aazzaoui home -> /home/aazzaoui", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0, 0, 0 }, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test16()
{
    //Arrange
    char *input = "echo 'exit_code ->$? user ->$USER home -> $HOME'";
    char *args[] = {"echo", "exit_code ->$? user ->$USER home -> $HOME", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0, 0, 0 }, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test17()
{
    //Arrange
    char *input = "echo \"$\"";
    char *args[] = {"echo", "$", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0, 0, 0 }, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test18()
{
    //Arrange
    char *input = "echo '$'";
    char *args[] = {"echo", "$", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0, 0, 0 }, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test19()
{
    //Arrange
    char *input = "echo $";
    char *args[] = {"echo", "$", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0, 0, 0 }, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test20()
{
    //Arrange
    char *input = "echo $?";
    char *args[] = {"echo", "0", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0, 0, 0 }, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test21()
{
    //Arrange
    char *input = "echo $?HELLO";
    char *args[] = {"echo", "0HELLO", 0};
    t_cmd cmd[] = {
        { "echo", args, 0, 0, 0, 0, 0 }, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test22()
{
    //Arrange
    char *input = "pwd";
    char *args[] = {"pwd", 0};
    t_cmd cmd[] = {
        { "pwd", args, 0, 0, 0, 0, 0 }, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test23()
{
    //Arrange
    char *input = "pwd oi";
    char *args[] = {"pwd", "oi", 0};
    t_cmd cmd[] = {
        { "pwd", args, 0, 0, 0, 0, 0 }, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test24()
{
    //Arrange
    char *input = "export hello";
    char *args[] = {"export", "hello", 0};
    t_cmd cmd[] = {
        { "export", args, 0, 0, 0, 0, 0 }, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test25()
{
    //Arrange
    char *input = "export HELLO=123";
    char *exp = "123";
    char *key = "HELLO";
    int str_len = 4;

    //act  //ASSERT
    assert_env_var(input, key, exp, str_len);
}

void builtins_complete_Test26()
{
    //Arrange
    char *input = "export A-";
    char *args[] = {"export", "A-", 0};
    t_cmd cmd[] = {
        { "export", args, 0, 0, 0, 0, 0 }, 
        0
    };

    //act  //ASSERT
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test27()
{
    //Arrange
    char *input = "export HELLO=1234 A";
    char *exp = "1234";
    char *key = "HELLO";
    int str_len = strlen(exp) + 1;

    //act  //ASSERT
    assert_env_var(input, key, exp, str_len);
    TEST_ASSERT_EQUAL_INT32(0, g_all.cmds->count);
}

void builtins_complete_Test28()
{
    //Arrange
    char *input = "export HELLO=\"123 A-\"";
    char *exp = "123 A-";
    char *key = "HELLO";
    int str_len = strlen(exp) + 1;

    //act  //ASSERT
    assert_env_var(input, key, exp, str_len);
    TEST_ASSERT_EQUAL_INT32(0, g_all.cmds->count);
}

void builtins_complete_Test29()
{
    //Arrange
    char *input = "export HELLO   HELLO";
    char *exp = "123 A-";
    char *key = "HELLO";
    int str_len = strlen(exp) + 1;
    char *args[] = {"export", "HELLO", "HELLO", 0};
    t_cmd cmd[] = {
        { "export", args, 0, 0, 0, 0, 0 }, 
        0
    };

    //act  //ASSERT
    assert_env_var(input, key, exp, str_len);
    builtins_complete(input, cmd, 1);
}

void builtins_complete_Test30()
{
    //Arrange
    char *input = "export HELLO=123";
    char *exp = "123";
    char *key = "HELLO";
    int str_len = 4;

    //act  //ASSERT
    assert_env_var(input, key, exp, str_len);
}

void builtins_complete_Test31()
{
    //Arrange
    char *input = "export HELLO=123";
    char *exp = "123";
    char *key = "HELLO";
    int str_len = 4;

    //act  //ASSERT
    assert_env_var(input, key, exp, str_len);
}

void builtins_complete_Test32()
{
    //Arrange
    char *input = "export HELLO=123";
    char *exp = "123";
    char *key = "HELLO";
    int str_len = 4;

    //act  //ASSERT
    assert_env_var(input, key, exp, str_len);
}

void builtins_complete_Tests()
{
    RUN_TEST(builtins_complete_Test1);
    RUN_TEST(builtins_complete_Test2);
    RUN_TEST(builtins_complete_Test3);
    RUN_TEST(builtins_complete_Test4);
    RUN_TEST(builtins_complete_Test5);
    RUN_TEST(builtins_complete_Test6);
    RUN_TEST(builtins_complete_Test7);
    RUN_TEST(builtins_complete_Test8);
    RUN_TEST(builtins_complete_Test9);
    RUN_TEST(builtins_complete_Test10);
    RUN_TEST(builtins_complete_Test11);
    RUN_TEST(builtins_complete_Test12);
    RUN_TEST(builtins_complete_Test13);
    RUN_TEST(builtins_complete_Test14);
    RUN_TEST(builtins_complete_Test15);
    RUN_TEST(builtins_complete_Test16);
    RUN_TEST(builtins_complete_Test17);
    RUN_TEST(builtins_complete_Test18);
    RUN_TEST(builtins_complete_Test19);
    RUN_TEST(builtins_complete_Test20);
    RUN_TEST(builtins_complete_Test21);
    RUN_TEST(builtins_complete_Test22);
    RUN_TEST(builtins_complete_Test23);
    RUN_TEST(builtins_complete_Test24);
    RUN_TEST(builtins_complete_Test25);
    RUN_TEST(builtins_complete_Test26);
    RUN_TEST(builtins_complete_Test27);
    RUN_TEST(builtins_complete_Test28);
    RUN_TEST(builtins_complete_Test29);
}