#include "create_cmd.h"

void print_error_cmd_not_found(char *cmd, t_create_cmd *data, int status)
{
    t_cpp_str *str;

    str = cpp_str_new();
    cpp_str_add(str, "mini-shell: ");
	cpp_str_add(str, cmd);
	cpp_str_add(str, ": ");
    cpp_str_add(str, data->error);
	write(2, str->content, str->count);
    data->cmd_not_found = 1;
    g_all.cmd_error_status = status;
}

int is_dir(char *cmd)
{
    DIR *dir;
    
    dir = opendir(cmd);
    if (dir)
        return 1;
    return 0;
}

int path_error(char *cmd, t_create_cmd *data)
{
    if (access(cmd, F_OK))
    {
        data->error = "No such file or directory\n";
        print_error_cmd_not_found(data->tkn->s, data, 127);
        return 1;
    }
    return 0;
}

int check_path(char *cmd, t_create_cmd *data)
{
    if (cpp_map_get(g_all.builtins, cmd))
        return (1);
    if (cmd && is_dir(cmd))
    {
        data->error = "Is a directory\n";
        print_error_cmd_not_found(data->tkn->s, data, 126);
        return 0;
    }
    else if (is_path(cmd) && path_error(cmd, data))
        return 0;
    else if (!cmd || access(cmd, F_OK))
    {
        data->error = "command not found\n";
        print_error_cmd_not_found(data->tkn->s, data, 127);
        return 0;
    }
    else if (!cmd || access(cmd, X_OK))
    {
        data->error = "Permission denied\n";
        print_error_cmd_not_found(data->tkn->s, data, 126);
        return 0;
    }
    return 1;
}
