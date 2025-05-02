//#include "mini_shell.h"
#include "debug.h"
#include "alae/builtins_cmd/builtins.h"
#include <signal.h>
/*
bash: $gg: ambiguous redirect
*/

void clear_read_line(int signo)
{
    printf("\n");
    rl_on_new_line();
    rl_replace_line("", 0);
    rl_redisplay();
}

int main(int argc, char *argv[], char *env[])
{
    char *input;
    
    init_g_all(argc, argv, env);
    add_the_past_history();
    signal(SIGINT, clear_read_line);
    while(1)
    {
        g_all.i++;
        g_all.current_cmd_file = NULL;
        input = readline("$>: ");
        if (is_input_to_skip1(input))
            continue;
        add_new_cmd_history(input, 1);
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
