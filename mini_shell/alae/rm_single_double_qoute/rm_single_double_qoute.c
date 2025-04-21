#include "../../mini_shell.h"
#include "../../ft_func/ft_func.h"

int rm_type(int type)
{
    if(type & e_double_quote)
        type -= e_double_quote;
    if(type & e_quote)
        type -= e_quote;
    return type;
}

void delete_sigle_double_qoute(t_token *tokens)
{
    t_cpp_str *str;
    char ch;
    int j;

    str = cpp_str_new_substitute(tokens->s);
    ch = '\0';
    j = 0;
    while(str->content[j])
    {
        if (!ch && ft_strchr("\"'", str->content[j]))
        {
            ch = str->content[j];
            cpp_delete_char(str, j);
        }
        else if (ch == str->content[j])
        {
            ch = '\0';
            cpp_delete_char(str, j);
        }
        else
            j++;
    }
}

void rm_single_double_qoute()
{
    t_token **tokens;
    int i;
    int res;

    tokens = g_all.tokens->content;
    i = 0;
    while(g_all.tokens->count > i)
    {
        if(tokens[i]->type & (e_double_quote | e_quote))
        {
            delete_sigle_double_qoute(tokens[i]);
            tokens[i]->type = rm_type(tokens[i]->type);
        }
        i++;
    }
}
