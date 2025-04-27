//#include "mini_shell.h"
#include "debug.h"
#include "alae/builtins_cmd/builtins.h"

int main(int argc, char *argv[], char *env[])
{
    char *input;

    init_g_all(argc, argv, env);
    while(1)
    {
        g_all.i++;
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
