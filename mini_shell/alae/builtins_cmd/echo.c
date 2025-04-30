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
    return 1;
}

void print_str(char *str)
{
    if (str)
        printf("%s ", str);
    else
        printf(" ");
}

void echo(t_cmd *cmd)
{
    int i;
    int first_args;
    int new_line;

    i = 1;
    new_line = 1;
    first_args = 1;
    while(cmd->args && cmd->args[i])
    {
        if (first_args && cmd->args[i][0] == '-')
        {
            if (is_char(cmd->args[i] + 1, 'n'))
                new_line = 0;
            else
            {
                first_args = 0;
                print_str(cmd->args[i]);
            }
        }
        else
            print_str(cmd->args[i]);
        i++;
    }
    if (new_line)
        printf("\n");
}
