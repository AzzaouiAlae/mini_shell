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
    int exp = 0;

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
    int exp = 2;

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
    int exp = 2;

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
    int exp = 0;

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
    int exp = 2;

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
    int exp = 2;

    // Act
    ft_check_syntax_error();

    // Assert
    TEST_ASSERT_EQUAL_INT32(exp, g_all.cmd_error_status);
}


void Test_redirect_append_without_target()
{
    t_token tokens[] = {
        {">", e_redir_out_trun},
        {">", e_redir_out_trun}
    };
    cs_list_clear(g_all.tokens);
    for(int i = 0; i < 2; i++)
        cs_list_add(g_all.tokens, (long)&(tokens[i]));
    int exp = 2;
    ft_check_syntax_error();
    TEST_ASSERT_EQUAL_INT32(exp, g_all.cmd_error_status);
}

void Test_heredoc_standalone()
{
    t_token tokens[] = {
        {"<<", e_heredoc},
        {"<", e_redir_in},
        {"hello", e_args}
    };
    cs_list_clear(g_all.tokens);
    for(int i = 0; i < 3; i++)
        cs_list_add(g_all.tokens, (long)&(tokens[i]));
    int exp = 2;
    ft_check_syntax_error();
    TEST_ASSERT_EQUAL_INT32(exp, g_all.cmd_error_status);
}


void Test_double_append_redirect()
{
    t_token tokens[] = {
        {">>", e_redir_out_app},
        {">>", e_redir_out_app},
        {"log", e_file_name}
    };
    cs_list_clear(g_all.tokens);
    for(int i = 0; i < 3; i++)
        cs_list_add(g_all.tokens, (long)&(tokens[i]));
    int exp = 2;
    ft_check_syntax_error();
    TEST_ASSERT_EQUAL_INT32(exp, g_all.cmd_error_status);
}

void Test_triple_redirect()
{
    t_token tokens[] = {
        {">", e_redir_out_trun},
        {">", e_redir_out_trun},
        {">", e_redir_out_trun},
        {"file", e_file_name}
    };
    cs_list_clear(g_all.tokens);
    for (int i = 0; i < 4; i++)
        cs_list_add(g_all.tokens, (long)&(tokens[i]));
    int exp = 2;
    ft_check_syntax_error();
    TEST_ASSERT_EQUAL_INT32(exp, g_all.cmd_error_status);
}

void Test_pipe_with_double_pipe_and_grep()
{
    t_token tokens[] = {
        {"echo", e_cmd | e_args},
        {"hello", e_args},
        {"|", e_pipe},
        {"|", e_pipe},
        {"grep", e_cmd},
        {"hi", e_args}
    };
    cs_list_clear(g_all.tokens);
    for (int i = 0; i < 6; i++)
        cs_list_add(g_all.tokens, (long)&(tokens[i]));
    int exp = 2;
    ft_check_syntax_error();
    TEST_ASSERT_EQUAL_INT32(exp, g_all.cmd_error_status);
}

void Test_invalid_redirection_without_target()
{
    t_token tokens[] = {
        {"echo", e_cmd | e_args},
        {"hello", e_args},
        {">", e_redir_out_trun}
    };
    cs_list_clear(g_all.tokens);
    for(int i = 0; i < 3; i++)
        cs_list_add(g_all.tokens, (long)&(tokens[i]));
    int exp = 2;
    ft_check_syntax_error();
    TEST_ASSERT_EQUAL_INT32(exp, g_all.cmd_error_status);
}

void Test_invalid_io_redirection()
{
    t_token tokens[] = {
        {"echo", e_cmd | e_args},
        {"hello", e_args},
        {"|", e_pipe},
        {"<", e_redir_out_trun},
        {">", e_redir_in}
    };
    cs_list_clear(g_all.tokens);
    for(int i = 0; i < 5; i++)
        cs_list_add(g_all.tokens, (long)&(tokens[i]));
    int exp = 2;
    ft_check_syntax_error();
    TEST_ASSERT_EQUAL_INT32(exp, g_all.cmd_error_status);
}

void Test_invalid_redirection_combination()
{
    t_token tokens[] = {
        {"echo", e_cmd | e_args},
        {"hello", e_args},
        {"|", e_pipe},
        {">", e_redir_out_trun},
        {">", e_redir_out_trun}
    };
    cs_list_clear(g_all.tokens);
    for(int i = 0; i < 5; i++)
        cs_list_add(g_all.tokens, (long)&(tokens[i]));
    int exp = 2;
    ft_check_syntax_error();
    TEST_ASSERT_EQUAL_INT32(exp, g_all.cmd_error_status);
}

void Test_pipe_followed_by_pipe()
{
    t_token tokens[] = {
        {"ls", e_cmd | e_args},
        {"|", e_pipe},
        {"|", e_pipe}
    };
    cs_list_clear(g_all.tokens);
    for(int i = 0; i < 3; i++)
        cs_list_add(g_all.tokens, (long)&(tokens[i]));
    int exp = 2;
    ft_check_syntax_error();
    TEST_ASSERT_EQUAL_INT32(exp, g_all.cmd_error_status);
}

void Test_redir_in_at_start()
{
    t_token tokens[] = {
        {"<", e_redir_in},
        {"ls", e_cmd | e_args}
    };
    cs_list_clear(g_all.tokens);
    for(int i = 0; i < 2; i++)
        cs_list_add(g_all.tokens, (long)&(tokens[i]));
    int exp = 2;
    ft_check_syntax_error();
    TEST_ASSERT_EQUAL_INT32(exp, g_all.cmd_error_status);
}

void Test_redir_out_at_end()
{
    t_token tokens[] = {
        {"echo", e_cmd | e_args},
        {">", e_redir_out_trun}
    };
    cs_list_clear(g_all.tokens);
    for(int i = 0; i < 2; i++)
        cs_list_add(g_all.tokens, (long)&(tokens[i]));
    int exp = 2;
    ft_check_syntax_error();
    TEST_ASSERT_EQUAL_INT32(exp, g_all.cmd_error_status);
}

void Test_redir_in_followed_by_pipe()
{
    t_token tokens[] = {
        {"cat", e_cmd | e_args},
        {"<", e_redir_in},
        {"|", e_pipe}
    };
    cs_list_clear(g_all.tokens);
    for(int i = 0; i < 3; i++)
        cs_list_add(g_all.tokens, (long)&(tokens[i]));
    int exp = 2;
    ft_check_syntax_error();
    TEST_ASSERT_EQUAL_INT32(exp, g_all.cmd_error_status);
}

void Test_pipe_followed_by_redir_out()
{
    t_token tokens[] = {
        {"ls", e_cmd | e_args},
        {"|", e_pipe},
        {">", e_redir_out_trun}
    };
    cs_list_clear(g_all.tokens);
    for(int i = 0; i < 3; i++)
        cs_list_add(g_all.tokens, (long)&(tokens[i]));
    int exp = 2;
    ft_check_syntax_error();
    TEST_ASSERT_EQUAL_INT32(exp, g_all.cmd_error_status);
}

void Test_double_redir_in()
{
    t_token tokens[] = {
        {"cat", e_cmd | e_args},
        {"<", e_redir_in},
        {"<", e_redir_in},
        {"file", e_args}
    };
    cs_list_clear(g_all.tokens);
    for(int i = 0; i < 4; i++)
        cs_list_add(g_all.tokens, (long)&(tokens[i]));
    int exp = 2;
    ft_check_syntax_error();
    TEST_ASSERT_EQUAL_INT32(exp, g_all.cmd_error_status);
}

void Test_redir_in_without_file()
{
    t_token tokens[] = {
        {"cat", e_cmd | e_args},
        {"<", e_redir_in}
    };
    cs_list_clear(g_all.tokens);
    for(int i = 0; i < 2; i++)
        cs_list_add(g_all.tokens, (long)&(tokens[i]));
    int exp = 2;
    ft_check_syntax_error();
    TEST_ASSERT_EQUAL_INT32(exp, g_all.cmd_error_status);
}

void Test_redir_append_without_file()
{
    t_token tokens[] = {
        {"ls", e_cmd | e_args},
        {">>", e_redir_out_app}
    };
    cs_list_clear(g_all.tokens);
    for(int i = 0; i < 2; i++)
        cs_list_add(g_all.tokens, (long)&(tokens[i]));
    int exp = 2;
    ft_check_syntax_error();
    TEST_ASSERT_EQUAL_INT32(exp, g_all.cmd_error_status);
}

void Test_double_redir_append()
{
    t_token tokens[] = {
        {"ls", e_cmd | e_args},
        {">>", e_redir_out_app},
        {">>", e_redir_out_app},
        {"file", e_args}
    };
    cs_list_clear(g_all.tokens);
    for(int i = 0; i < 4; i++)
        cs_list_add(g_all.tokens, (long)&(tokens[i]));
    int exp = 2;
    ft_check_syntax_error();
    TEST_ASSERT_EQUAL_INT32(exp, g_all.cmd_error_status);
}

void Test_heredoc_without_delim()
{
    t_token tokens[] = {
        {"cat", e_cmd | e_args},
        {"<<", e_heredoc}
    };
    cs_list_clear(g_all.tokens);
    for(int i = 0; i < 2; i++)
        cs_list_add(g_all.tokens, (long)&(tokens[i]));
    int exp = 2;
    ft_check_syntax_error();
    TEST_ASSERT_EQUAL_INT32(exp, g_all.cmd_error_status);
}

void Test_only_pipe()
{
    t_token tokens[] = {
        {"|", e_pipe}
    };
    cs_list_clear(g_all.tokens);
    cs_list_add(g_all.tokens, (long)&(tokens[0]));
    int exp = 2;
    ft_check_syntax_error();
    TEST_ASSERT_EQUAL_INT32(exp, g_all.cmd_error_status);
}

void Test_only_redir()
{
    t_token tokens[] = {
        {">", e_redir_out_trun}
    };
    cs_list_clear(g_all.tokens);
    cs_list_add(g_all.tokens, (long)&(tokens[0]));
    int exp = 2;
    ft_check_syntax_error();
    TEST_ASSERT_EQUAL_INT32(exp, g_all.cmd_error_status);
}

void Test_pipe_multiple_times()
{
    t_token tokens[] = {
        {"ls", e_cmd | e_args},
        {"|", e_pipe},
        {"|", e_pipe},
        {"|", e_pipe},
        {"wc", e_cmd | e_args}
    };
    cs_list_clear(g_all.tokens);
    for(int i = 0; i < 5; i++)
        cs_list_add(g_all.tokens, (long)&(tokens[i]));
    int exp = 2;
    ft_check_syntax_error();
    TEST_ASSERT_EQUAL_INT32(exp, g_all.cmd_error_status);
}

void Test_redir_in_after_redir_out()
{
    t_token tokens[] = {
        {"echo", e_cmd | e_args},
        {">", e_redir_out_trun},
        {"<", e_redir_in},
        {"file", e_args}
    };
    cs_list_clear(g_all.tokens);
    for(int i = 0; i < 4; i++)
        cs_list_add(g_all.tokens, (long)&(tokens[i]));
    int exp = 2;
    ft_check_syntax_error();
    TEST_ASSERT_EQUAL_INT32(exp, g_all.cmd_error_status);
}

void Test_pipe_between_redirs()
{
    t_token tokens[] = {
        {"cat", e_cmd | e_args},
        {"<", e_redir_in},
        {"|", e_pipe},
        {">", e_redir_out_trun}
    };
    cs_list_clear(g_all.tokens);
    for(int i = 0; i < 4; i++)
        cs_list_add(g_all.tokens, (long)&(tokens[i]));
    int exp = 2;
    ft_check_syntax_error();
    TEST_ASSERT_EQUAL_INT32(exp, g_all.cmd_error_status);
}

void Test_redir_in_with_pipe_at_end()
{
    t_token tokens[] = {
        {"cat", e_cmd | e_args},
        {"<", e_redir_in},
        {"file", e_args},
        {"|", e_pipe}
    };
    cs_list_clear(g_all.tokens);
    for(int i = 0; i < 4; i++)
        cs_list_add(g_all.tokens, (long)&(tokens[i]));
    int exp = 2;
    ft_check_syntax_error();
    TEST_ASSERT_EQUAL_INT32(exp, g_all.cmd_error_status);
}

void Test_pipe_at_start_and_end()
{
    t_token tokens[] = {
        {"|", e_pipe},
        {"echo", e_cmd | e_args},
        {"|", e_pipe}
    };
    cs_list_clear(g_all.tokens);
    for(int i = 0; i < 3; i++)
        cs_list_add(g_all.tokens, (long)&(tokens[i]));
    int exp = 2;
    ft_check_syntax_error();
    TEST_ASSERT_EQUAL_INT32(exp, g_all.cmd_error_status);
}

void Test_redir_with_quote_error()
{
    t_token tokens[] = {
        {"echo", e_cmd | e_args},
        {"\"", e_quote},
        {">", e_redir_out_trun}
    };
    cs_list_clear(g_all.tokens);
    for(int i = 0; i < 3; i++)
        cs_list_add(g_all.tokens, (long)&(tokens[i]));
    int exp = 2;
    ft_check_syntax_error();
    TEST_ASSERT_EQUAL_INT32(exp, g_all.cmd_error_status);
}

void Test_heredoc_followed_by_pipe()
{
    t_token tokens[] = {
        {"cat", e_cmd | e_args},
        {"<<", e_heredoc},
        {"|", e_pipe}
    };
    cs_list_clear(g_all.tokens);
    for(int i = 0; i < 3; i++)
        cs_list_add(g_all.tokens, (long)&(tokens[i]));
    int exp = 2;
    ft_check_syntax_error();
    TEST_ASSERT_EQUAL_INT32(exp, g_all.cmd_error_status);
}

void Test_redir_append_followed_by_redir_in()
{
    t_token tokens[] = {
        {"ls", e_cmd | e_args},
        {">>", e_redir_out_app},
        {"<", e_redir_in},
        {"file", e_args}
    };
    cs_list_clear(g_all.tokens);
    for(int i = 0; i < 4; i++)
        cs_list_add(g_all.tokens, (long)&(tokens[i]));
    int exp = 2;
    ft_check_syntax_error();
    TEST_ASSERT_EQUAL_INT32(exp, g_all.cmd_error_status);
}

void Test_double_heredoc()
{
    t_token tokens[] = {
        {"cat", e_cmd | e_args},
        {"<<", e_heredoc},
        {"<<", e_heredoc},
        {"END", e_args}
    };
    cs_list_clear(g_all.tokens);
    for(int i = 0; i < 4; i++)
        cs_list_add(g_all.tokens, (long)&(tokens[i]));
    int exp = 2;
    ft_check_syntax_error();
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
    RUN_TEST(Test_redirect_append_without_target);
    RUN_TEST(Test_heredoc_standalone);
    RUN_TEST(Test_double_append_redirect);
    RUN_TEST(Test_triple_redirect);
    RUN_TEST(Test_pipe_with_double_pipe_and_grep);
    RUN_TEST(Test_invalid_redirection_without_target);
    RUN_TEST(Test_invalid_redirection_combination);
    RUN_TEST(Test_invalid_redirection_combination);
    RUN_TEST(Test_pipe_followed_by_pipe);
    RUN_TEST(Test_redir_in_at_start);
    RUN_TEST(Test_redir_out_at_end);
    RUN_TEST(Test_redir_in_followed_by_pipe);
    RUN_TEST(Test_pipe_followed_by_redir_out);
    RUN_TEST(Test_double_redir_in);
    RUN_TEST(Test_redir_in_without_file);
    RUN_TEST(Test_redir_append_without_file);
    RUN_TEST(Test_double_redir_append);
    RUN_TEST(Test_heredoc_without_delim);
    RUN_TEST(Test_only_pipe);
    RUN_TEST(Test_only_redir);
    RUN_TEST(Test_pipe_multiple_times);
    RUN_TEST(Test_redir_in_after_redir_out);
    RUN_TEST(Test_pipe_between_redirs);
    RUN_TEST(Test_redir_in_with_pipe_at_end);
    RUN_TEST(Test_pipe_at_start_and_end);
    RUN_TEST(Test_redir_with_quote_error);
    RUN_TEST(Test_heredoc_followed_by_pipe);
    RUN_TEST(Test_redir_append_followed_by_redir_in);
    RUN_TEST(Test_double_heredoc);
    // Add more RUN_TEST() calls here for each new test
}