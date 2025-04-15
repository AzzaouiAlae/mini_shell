#include "../Tests.h"
#include <string.h>


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
        if(strcmp(data()->exp[i].s, tokens[i]->s))
            printf("%s == %s\n", data()->exp[i].s, tokens[i]->s);
        TEST_ASSERT_EQUAL_INT32(strlen(data()->exp[i].s), strlen(tokens[i]->s));
        TEST_ASSERT_EQUAL_CHAR_ARRAY(data()->exp[i].s, tokens[i]->s, strlen(data()->exp[i].s));
        if(data()->exp[i].type != tokens[i]->type)
            printf("%s == %s\n", get_enum_str(data()->exp[i].type), get_enum_str(tokens[i]->type));
        TEST_ASSERT_EQUAL_INT32(data()->exp[i].type, tokens[i]->type);
    }
}

