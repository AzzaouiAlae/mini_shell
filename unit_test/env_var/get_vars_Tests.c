#include "../Tests.h"

void get_vars(char *input, char **exp)
{
    //arrange
    t_token **tkns;

    //act
    split_tokens(input, data()->sep, data()->special_sep);
    ft_check_syntax_error();
    get_variables_value();
    add_vars_to_env();
    rm_single_double_qoute();

    //assert
    tkns = g_all.tokens->content;
    for(int i = 0; exp[i]; i++)
    {
        if (strlen(exp[i]) != strlen(tkns[i]->s))
            printf("exp=%s but=%s\n", exp[i], tkns[i]->s);
        TEST_ASSERT_EQUAL_INT32(strlen(exp[i]), strlen(tkns[i]->s));
        TEST_ASSERT_EQUAL_CHAR_ARRAY(exp[i], tkns[i]->s, strlen(exp[i]) + 1);
    }
}

void get_vars_Test1()
{
    //arrange
    char *input = "echo $SHELL\"   $  \"  $  $USER  ' $a'$a ";
    char *exp[] = { 
        "echo", 
        "/bin/bash   $  ", 
        "$", 
        "aazzaoui", 
        " $a", 0
    };
    
    //act //assert
    get_vars(input, exp);
}

void get_vars_Test2()
{
    //arrange
    char *input = "echo $$";
    char *exp[] = { 
        "echo", 
        "$$", 0
    };

    //act //assert
    get_vars(input, exp);
}

void get_vars_Test3()
{
    //arrange
    char *input = "echo \"$PWD\"";
    char *exp[] = { 
        "echo", 
        "/home/aazzaoui/Desktop/projects/mini_shell_All/mini_shell_Repo2/unit_test/env_var", 0
    };

    //act //assert
    get_vars(input, exp);
}

void get_vars_Test4()
{
    //arrange
    char *input = "echo '$PWD'";
    char *exp[] = { 
        "echo", 
        "$PWD", 0
    };

    //act //assert
    get_vars(input, exp);
}

void get_vars_Test5()
{
    //arrange
    char *input = "echo \"> >> < * ? [ ] | ; [ ] || && ( ) & # $ \\ <<\"";
    char *exp[] = { 
        "echo", 
        "> >> < * ? [ ] | ; [ ] || && ( ) & # $ \\ <<", 0
    };

    //act //assert
    get_vars(input, exp);
}

void get_vars_Test6()
{
    //arrange
    char *input = "echo \"exit_code ->$? user ->$USER home -> $HOME\"";
    char *exp[] = { 
        "echo", 
        "exit_code ->0 user ->aazzaoui home -> /home/aazzaoui", 0
    };

    //act //assert
    get_vars(input, exp);
}

void get_vars_Test7()
{
    //arrange
    char *input = "echo 'exit_code ->$? user ->$USER home -> $HOME'";
    char *exp[] = { 
        "echo", 
        "exit_code ->$? user ->$USER home -> $HOME", 0
    };

    //act //assert
    get_vars(input, exp);
}

void get_vars_Test8()
{
    //arrange
    char *input = "echo \"$\"";
    char *exp[] = { 
        "echo", 
        "$", 0
    };

    //act //assert
    get_vars(input, exp);
}

void get_vars_Test9()
{
    //arrange
    char *input = "echo '$'";
    char *exp[] = { 
        "echo", 
        "$", 0
    };

    //act //assert
    get_vars(input, exp);
}

void get_vars_Test10()
{
    //arrange
    char *input = "echo $";
    char *exp[] = { 
        "echo", 
        "$", 0
    };

    //act //assert
    get_vars(input, exp);
}

void get_vars_Test11()
{
    //arrange
    char *input = "echo $?";
    char *exp[] = { 
        "echo", 
        "0", 0
    };

    //act //assert
    get_vars(input, exp);
}

void get_vars_Test12()
{
    //arrange
    char *input = "echo $?HELLO";
    char *exp[] = { 
        "echo", 
        "0HELLO", 0
    };

    //act //assert
    get_vars(input, exp);
}

void get_vars_Tests()
{
    RUN_TEST(get_vars_Test1);
    RUN_TEST(get_vars_Test2);
    //RUN_TEST(get_vars_Test3);
    RUN_TEST(get_vars_Test4);
    RUN_TEST(get_vars_Test5);
    RUN_TEST(get_vars_Test6);
    RUN_TEST(get_vars_Test7);
    RUN_TEST(get_vars_Test8);
    RUN_TEST(get_vars_Test9);
    RUN_TEST(get_vars_Test10);
    RUN_TEST(get_vars_Test11);
    RUN_TEST(get_vars_Test12);
}
