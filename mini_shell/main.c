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

char *get_prompt()
{
    char *prompt;
    char buf[4097];

    ft_bzero(buf, 4097);
    prompt = getcwd(buf, 4097);
    if (!prompt)
    {
        prompt = get_from_env("PWD")->content;
    }
    prompt = ft_strrchr(prompt, '/') + 1;
    prompt = my_ft_strjoin("➜ ", prompt);
    prompt = my_ft_strjoin(prompt, " $>: ");
    return prompt;
}

void augment_shell_level()
{
    t_cpp_str *str;
    t_cs_list *value;
    int shlvl;
    int error;

    shlvl = 0;
    str = cpp_str_new();
    value = cpp_map_get(g_all.custom_env, "SHLVL");
    if (!value)
        cpp_str_add(str, ft_strdup("1"));
    shlvl = ft_atoi(value->content, &error) + 1;
    cpp_str_add(str, ft_itoa(shlvl)->content);
    add_to_env(str, NULL, "SHLVL");
}

int main(int argc, char *argv[], char *env[])
{
    char *input;
    
    init_g_all(argc, argv, env);
    add_the_past_history();
    signal(SIGINT, clear_read_line);
    augment_shell_level();
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
