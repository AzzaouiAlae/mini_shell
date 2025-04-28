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
    //execute_cmd();
    set_exit_status();
    delete_files();
}

void assert_env_var(char *input, char *key, char *exp)
{
    //Arrange
    t_cs_list *var;

    //act
    execute_cmd_input(input);

    //ASSERT
    var = cpp_map_get(g_all.custom_env, key);
    TEST_ASSERT_EQUAL_CHAR_ARRAY(exp, var->content, strlen(exp) + 1);
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
        TEST_ASSERT_EQUAL_INT32(exp[i].redir_input_fd, act_cmd[i]->redir_input_fd);
        TEST_ASSERT_EQUAL_INT32(exp[i].redir_output_fd, act_cmd[i]->redir_output_fd);
    }
}

void complete_cmd_Tests()
{
    builtins_complete_Tests();
    OthetTests();
    MandatoryTests();
    SimpleTests();
}