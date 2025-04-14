#include "../Tests.h"

char *get_enum_str(int type)
{
    t_cs_list *list = cs_list_new(1);
    int i = 0;
    char *strs[] = {"e_none", "e_args", "e_pipe", "e_heredoc",
 		"e_redir_out_app", "e_redir_out_trun", "e_redir_in", "e_var_to_get",
 		"e_quote", "e_double_quote", "e_file_name", "e_cmd", "e_path", "e_set_var", "e_var_to_set" ,"e_delimiter", 0};
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

t_split_tokens_data *data()
{
    static t_split_tokens_data strs;

    return (&strs);
}

void split_tokens_test()
{
    //arrange
    t_token **tokens;

    //act
    split_tokens(data()->s, data()->sep, data()->special_sep);
    tokens = g_all.tokens->content;

    //asert
    for(int i = 0; i < data()->count; i++)
    {
        //printf("%s == %s\n", data()->exp[i].s, tokens[i]->s);
        TEST_ASSERT_EQUAL_INT32(strlen(data()->exp[i].s), strlen(tokens[i]->s));
        TEST_ASSERT_EQUAL_CHAR_ARRAY(data()->exp[i].s, tokens[i]->s, strlen(data()->exp[i].s));
        //printf("%s == %s\n", get_enum_str(data()->exp[i].type), get_enum_str(tokens[i]->type));
        TEST_ASSERT_EQUAL_INT32(data()->exp[i].type, tokens[i]->type);
    }
}

