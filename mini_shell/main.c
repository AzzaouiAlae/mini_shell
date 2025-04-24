//#include "mini_shell.h"
#include "debug.h"

t_global g_all;

void init_g_all(int argc, char *argv[], char *env[])
{
    ft_bzero(&g_all, sizeof(t_global));
    g_all.env = env;
    g_all.argc = argc;
    g_all.argv = argv;
    init_env_map();
}

void set_exit_status()
{
    t_cs_list *str;
    t_cpp_str *exit_str;

    str = cs_list_new(sizeof(char));
    exit_str = ft_itoa(g_all.cmd_error_status);
    cs_list_add_range(str, exit_str->count, exit_str->content);
    cpp_map_add(g_all.custom_env, "?", str);
}

int is_input_to_skip1(char *input)
{
    if(!input || !(*input))
        return 1;
    if (!ft_strcmp(input, "\n"))
    {
        printf("\n");
        return 1;
    }
    return 0;
}

int is_space(char *input)
{
    int i;

    i = 0;
    while (input[i])
    {
        if(input[i] != ' ' && input[i] != '\t')
            return 0;
        i++;
    }
    return 1;
}

int is_input_to_skip2(char *input)
{
    if(is_space(input))
        return 1;
    if (ft_strlen(input) == 1 && str_find_char(input, ":!#"))
        return 1;
    return 0;
}

int main(int argc, char *argv[], char *env[])
{
    char *input;

    init_g_all(argc, argv, env);
    while(1)
    {
        input = readline("$>: ");
        if (is_input_to_skip1(input))
            continue;
        add_history(input);
        if(input && !ft_strcmp(input, "exit"))
            break;
        if (is_input_to_skip2(input))
            continue;
        process_cmd(input);
        free(input);
        g_all.line_count++;
    }
    free(input);
    ft_free_all();
    rl_clear_history();
    return 1;
}
