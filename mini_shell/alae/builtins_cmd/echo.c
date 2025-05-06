#include "builtins.h"

int is_char(char *str, char ch)
{
    int i;

    i = 0;
    while (str[i])
    {
        if(str[i] != ch)
            return 0;
        i++;
    }
    return i;
}

void print_str(char *str, int *first_args)
{
    if (str)
        write(1, str, ft_strlen(str));
    else
        write(1, " ", 1);
    *first_args = 0;
}

void print_arg(t_cmd *cmd, int i, int *first_args, int *new_line)
{
    if (i > 1 && !(*first_args))
        write(1, " ", 1);
    if (*first_args && cmd->args[i][0] == '-')
    {
        if (is_char(cmd->args[i] + 1, 'n'))
            *new_line = 0;
        else
        {
            *first_args = 0;
            print_str(cmd->args[i], first_args);
        }
    }
    else
        print_str(cmd->args[i], first_args);
}

void echo(t_cmd *cmd)
{
    int i;
    int first_args;
    int new_line;

    i = 1;
    new_line = 1;
    first_args = 1;
    if (cmd->input_fd == -1 || cmd->output_fd == -1)
            ft_exit(g_all.cmd_error_status);
    g_all.cmd_error_status = 0;
    while(cmd->args && cmd->args[i])
    {
        print_arg(cmd, i, &first_args, &new_line);
        i++;
    }
    if (new_line)
        write(1, "\n", 1);
}
