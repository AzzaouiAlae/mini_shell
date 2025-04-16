#include "../Tests.h"


void Test_syntax_error1()
{
    //arrange
    t_token tokens[] = {
        {"echo", e_args | e_cmd},
        {"hello", e_args},
        {"world", e_args}
    };
    cs_list_clear(g_all.tokens);
    for(int i = 0; i < 3; i++)
        cs_list_add(g_all.tokens, (long)&(tokens[i]));
    int exp = 1;

    //act
    ft_check_syntax_error();

    //assert
    TEST_ASSERT_EQUAL_INT32(exp, g_all.cmd_error_status);
}

// Test 1: Consecutive pipes "echo hello | |"
void Test_consecutive_pipes()
{
    // Arrange
    t_token tokens[] = {
        {"echo", e_cmd | e_args},
        {"hello", e_args},
        {"|", e_pipe},
        {"|", e_pipe}
    };
    cs_list_clear(g_all.tokens);
    for(int i = 0; i < 4; i++)
        cs_list_add(g_all.tokens,(long)&(tokens[i]));
    int exp = 1;

    // Act
    ft_check_syntax_error();

    // Assert
    TEST_ASSERT_EQUAL_INT32(exp, g_all.cmd_error_status);
}

// Test 2: Double output redirection "cat > > file"
void Test_double_output_redirect()
{
    // Arrange
    t_token tokens[] = {
        {"cat", e_cmd | e_args},
        {">", e_redir_out_trun},
        {">", e_redir_out_trun},
        {"file", e_file_name}
    };
    cs_list_clear(g_all.tokens);
    for(int i = 0; i < 4; i++)
        cs_list_add(g_all.tokens,(long)&(tokens[i]));
    int exp = 1;

    // Act
    ft_check_syntax_error();

    // Assert
    TEST_ASSERT_EQUAL_INT32(exp, g_all.cmd_error_status);
}

// Test 3: Unterminated quote "echo \"hello"
void Test_unterminated_quote()
{
    // Arrange
    t_token tokens[] = {
        {"echo", e_cmd | e_args},
        {"\"hello", e_double_quote | e_args}  // Assume tokenizer captures unterminated quote
    };
    cs_list_clear(g_all.tokens);
    for(int i = 0; i < 2; i++)
        cs_list_add(g_all.tokens,(long)&(tokens[i]));
    int exp = 1;

    // Act
    ft_check_syntax_error();

    // Assert
    TEST_ASSERT_EQUAL_INT32(exp, g_all.cmd_error_status);
}

// Test 4: Redirection without target "echo hello >"
void Test_missing_redirect_target()
{
    // Arrange
    t_token tokens[] = {
        {"echo", e_cmd | e_args},
        {"hello", e_args},
        {">", e_redir_out_trun}
    };
    cs_list_clear(g_all.tokens);
    for(int i = 0; i < 3; i++)
        cs_list_add(g_all.tokens,(long)&(tokens[i]));
    int exp = 1;

    // Act
    ft_check_syntax_error();

    // Assert
    TEST_ASSERT_EQUAL_INT32(exp, g_all.cmd_error_status);
}

// Test 5: Pipe at end "echo hello |"
void Test_pipe_at_end()
{
    // Arrange
    t_token tokens[] = {
        {"echo", e_cmd | e_args},
        {"hello", e_args},
        {"|", e_pipe}
    };
    cs_list_clear(g_all.tokens);
    for(int i = 0; i < 3; i++)
        cs_list_add(g_all.tokens,(long)&(tokens[i]));
    int exp = 1;

    // Act
    ft_check_syntax_error();

    // Assert
    TEST_ASSERT_EQUAL_INT32(exp, g_all.cmd_error_status);
}

void Test_syntax_error()
{
    RUN_TEST(Test_syntax_error1);
    RUN_TEST(Test_consecutive_pipes);
    RUN_TEST(Test_double_output_redirect);
    RUN_TEST(Test_unterminated_quote);
    RUN_TEST(Test_missing_redirect_target);
    RUN_TEST(Test_pipe_at_end);
    // Add more RUN_TEST() calls here for each new test
}