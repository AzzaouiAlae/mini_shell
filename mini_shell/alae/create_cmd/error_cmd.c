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

int get_error_status(char *s)
{
    if (s == "Is a directory\n")
        return 126;
    if (s == "filename argument required\n")
        return 2;
    if (s == "No such file or directory\n")
        return 127;
    if (s == "command not found\n")
        return 127;
    if (s == "Permission denied\n")
        return 126;
}

void check_path(char *cmd, t_create_cmd *data)
{
    data->error = NULL;
    if (cpp_map_get(g_all.builtins, cmd))
        return ;
    if (cmd && is_dir(cmd))
        data->error = "Is a directory\n";
    else if (data->tkn->s[0] == '.' && ft_strlen(data->tkn->s) == 1)
        data->error = "filename argument required\n";
    else if (is_path(data->tkn->s) && access(cmd, F_OK))
        data->error = "No such file or directory\n";
    else if (!cmd || access(cmd, F_OK))
        data->error = "command not found\n";
    else if (!cmd || access(cmd, X_OK))
            data->error = "Permission denied\n";
    if (!g_all.is_error_printed && data->error)
    {
        print_error_cmd_not_found(data->tkn->s, data, 
            get_error_status(data->error));
        g_all.is_error_printed = 1;
    }
}
