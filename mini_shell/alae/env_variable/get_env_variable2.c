#include "env_var.h"

int get_type_without_set_var(int type)
{
    if(type & e_var_to_get)
        return type - e_var_to_get;
    return type;
}

char *get_key_in_token(t_cpp_str *str, t_cpp_str *new_str_token)
{
    t_cpp_str *key;
    char ch;

    ch = '\0';
    key = cpp_str_new();
    while(str->content[0] && ( ch == '\'' || str->content[0] != '$'))
    {
        if(!ch && (str->content[0] == '\'' || str->content[0] == '"'))
            ch = str->content[0];
        else if (ch == str->content[0])
            ch = '\0';
        cpp_str_add_char(new_str_token, str->content[0]);
        cpp_delete_char(str, 0);
    }
    if(str->content[0] == '$')
        cpp_delete_char(str, 0);
    while (str->content[0] && !ft_strchr(" |<>\t$\"'", str->content[0]))
    {
        cpp_str_add_char(key, str->content[0]);
        cpp_delete_char(str, 0);
    }
    return key->content;
}
