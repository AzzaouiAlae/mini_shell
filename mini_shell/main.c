#include "mini_shell.h"

t_global g_all;

void init_g_all(char *env[])
{
    ft_bzero(&g_all, sizeof(t_global));
    g_all.env = env;
    init_env_map();
}

char *get_enum_str(int type)
{
    t_cs_list *list = cs_list_new(1);
    int i = 0;
    char *strs[] = {"e_none", "e_args", "e_pipe", "e_heredoc",
 		"e_redir_out_app", "e_redir_out_trun", "e_redir_in", "e_var_to_get",
 		"e_quote", "e_double_quote", "e_file_name", "e_cmd", "e_path", 
        "e_set_var", "e_var_to_set" ,"e_delimiter", "e_error_status", 0};
    for(int i = 1, j = 1; strs[j]; i *= 2, j++)
    {
        if((type & i) == i)
        {
            cs_list_add_range(list, strlen(strs[j]), strs[j]);
            cs_list_add(list, (long)' ');
        }
    }
    return list->content;
}

void print_tokens(char *s)
{
    int i;
    t_token **t;
    
    split_tokens(s, " |<>\t$\n", "\"'");
    i = 0;
    t = g_all.tokens->content;
    while(i < g_all.tokens->count)
    {   
        printf("%15s = %s\n", t[i]->s, get_enum_str(t[i]->type));
        i++;
    }
}

// int main(int argc, char *argv[], char *env[])
// {
//     char *input;

//     init_g_all(env);
//     while(1)
//     {
//         input = readline("$>: ");
//         if(input && *input)
//             add_history(input);
//         if(input && !ft_strcmp(input, "exit"))
//             break;
//         print_tokens(input);
//         free(input);
//     }
//     free(input);
//     rl_clear_history();
//     return 1;
// }
