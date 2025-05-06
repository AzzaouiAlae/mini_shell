

//#include "mini_shell.h"
#include "debug.h"
#include "alae/builtins_cmd/builtins.h"
t_global g_all;

void init_g_all(int argc, char *argv[], char *env_vars[])
{
    t_cs_list *paths;
    ft_bzero(&g_all, sizeof(t_global));
    g_all.env = env_vars;
    g_all.argc = argc;
    g_all.argv = argv;
    init_env_map();
    init_builtins_map();
    g_all.ch_i = cs_list_new(sizeof(int));
    g_all.files_to_remove = cs_list_new(sizeof(char *));
    g_all.variables_name = cs_list_new(sizeof(char *));
    paths = cpp_map_get(g_all.custom_env, "PATH");
	if (!paths)
	{
		paths = cs_list_new(sizeof(char));
		cs_list_add_range(paths, 60,
			"/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin");
        cpp_map_add(g_all.custom_env, "PATH", paths);
	}
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
    if(!input)
        ft_exit(g_all.cmd_error_status);
    if(!(*input))
        return 1;
    if (!ft_strcmp(input, "\n"))
    {
        free(input);
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
    {
        if (str_find_char(input, "!"))
        {
            g_all.cmd_error_status = 1;
            set_exit_status();
        }
        return 1;
    }
    return 0;
}
