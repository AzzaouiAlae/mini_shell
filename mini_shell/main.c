//#include "mini_shell.h"
#include "debug.h"
#include "alae/builtins_cmd/builtins.h"
#include <signal.h>
/*
export mesage error
export 'a'='a b c d e f'
export "a b"="a c"
echo $PWD-$-"$$"'$-dlks'
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
<<<<<<< HEAD
    signal(SIGINT, clear_read_line);
=======
>>>>>>> f4bc0d2 (auto commit)
    while(1)
    {
        g_all.i++;
        g_all.current_cmd_file = NULL;
        input = readline("$>: ");
        if (is_input_to_skip1(input))
            continue;
<<<<<<< HEAD
=======
        // add histor
>>>>>>> f4bc0d2 (auto commit)
        add_new_cmd_history(input, 1);
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
