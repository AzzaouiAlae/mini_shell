#include "../Tests.h"

void mini_shell_map_Test1() {
    data()->s = "\n";
    t_token *exp = NULL;
    data()->exp = (t_token *)exp;
    data()->count = 0;
    split_tokens_test();
}

void mini_shell_map_Test2() {
    data()->s = "    ";
    t_token *exp = NULL;
    data()->exp = (t_token *)exp;
    data()->count = 0;
    split_tokens_test();
}

void mini_shell_map_Test3() {
    data()->s = ":";
    t_token *exp = NULL;
    data()->exp = (t_token *)exp;
    data()->count = 0;
    split_tokens_test();
}

void mini_shell_map_Test4() {
    data()->s = "!";
    t_token *exp = NULL;
    data()->exp = (t_token *)exp;
    data()->count = 0;
    split_tokens_test();
}

void mini_shell_map_Test5() {
    data()->s = ">";
    t_token *exp = NULL;
    data()->exp = (t_token *)exp;
    data()->count = 0;
    split_tokens_test();
}

void mini_shell_map_Test6() {
    data()->s = "<";
    t_token *exp = NULL;
    data()->exp = (t_token *)exp;
    data()->count = 0;
    split_tokens_test();
}

void mini_shell_map_Test7() {
    data()->s = ">>";
    t_token *exp = NULL;
    data()->exp = (t_token *)exp;
    data()->count = 0;
    split_tokens_test();
}

void mini_shell_map_Test8() {
    data()->s = "<<";
    t_token *exp = NULL;
    data()->exp = (t_token *)exp;
    data()->count = 0;
    split_tokens_test();
}

void mini_shell_map_Test9() {
    data()->s = "<>";
    t_token *exp = NULL;
    data()->exp = (t_token *)exp;
    data()->count = 0;
    split_tokens_test();
}

void mini_shell_map_Test11() {
    data()->s = ">>>>>";
    t_token *exp = NULL;
    data()->exp = (t_token *)exp;
    data()->count = 0;
    split_tokens_test();
}

void mini_shell_map_Test12() {
    data()->s = ">>>>>>>>>>>>>>>";
    t_token *exp = NULL;
    data()->exp = (t_token *)exp;
    data()->count = 0;
    split_tokens_test();
}

void mini_shell_map_Test13() {
    data()->s = "<<<<<";
    t_token *exp = NULL;
    data()->exp = 0;
    data()->count = 0;
    split_tokens_test();
}

void mini_shell_map_Test14() {
    data()->s = "<<<<<<<<<<<<<<<<";
    t_token *exp = NULL;
    data()->exp = (t_token *)exp;
    data()->count = 0;
    split_tokens_test();
}

void mini_shell_map_Test15() {
    data()->s = "> > > >";
    t_token exp[] = {
        { 0, 0 }
    };
    data()->exp   = exp;
    data()->count = 0;
    split_tokens_test();
}

void mini_shell_map_Test16() {
    data()->s = ">> >> >> >>";
    t_token exp[] = {
        { 0, 0 }
    };
    data()->exp   = exp;
    data()->count = 0;
    split_tokens_test();
}

void mini_shell_map_Test17() {
    data()->s = ">>>> >> >> >>";
    t_token exp[] = {
        { 0, 0 }
    };
    data()->exp   = exp;
    data()->count = 0;
    split_tokens_test();
}

/*
  “Is a directory” errors should likewise produce a single token with the
  exact message. We’ll flag them as e_args | e_error here.
*/

void mini_shell_map_Test18() {
    data()->s = "/";
    t_token exp[] = {
        { 0, 0 }
    };
    data()->exp   = exp;
    data()->count = 0;
    split_tokens_test();
}

void mini_shell_map_Test19() {
    data()->s = "//";
    t_token exp[] = {
        { 0, 0 }
    };
    data()->exp   = exp;
    data()->count = 0;
    split_tokens_test();
}

void mini_shell_map_Test20() {
    data()->s = "/.";
    t_token exp[] = {
        { 0, 0 }
    };
    data()->exp   = exp;
    data()->count = 0;
    split_tokens_test();
}

void mini_shell_map_Test21() {
    data()->s = "/./../../../../..";
    t_token exp[] = {
        { 0, 0 }
    };
    data()->exp   = exp;
    data()->count = 0;
    split_tokens_test();
}

void mini_shell_map_Test22() {
    data()->s = "///////";
    t_token exp[] = {
        { 0, 0 }
    };
    data()->exp   = exp;
    data()->count = 0;
    split_tokens_test();
}

/*
  Unrecognized backslashes should produce a “command not found” style message.
  Flagged here as e_args | e_error as well.
*/

void mini_shell_map_Test23() {
    data()->s = "\\";
    t_token exp[] = {
        { 0, 0 }
    };
    data()->exp   = exp;
    data()->count = 0;
    split_tokens_test();
}

void mini_shell_map_Test24() {
    data()->s = "\\\\";
    t_token exp[] = {
        { 0, 0 }
    };
    data()->exp   = exp;
    data()->count = 0;
    split_tokens_test();
}

void mini_shell_map_Test25() {
    data()->s = "\\\\\\\\\\\\";
    t_token exp[] = {
        { 0, 0 }
    };
    data()->exp   = exp;
    data()->count = 0;
    split_tokens_test();
}

void mini_shell_map_Test26() {
    data()->s = "-";
    t_token exp[] = {
        { 0, 0 }
    };
    data()->exp   = exp;
    data()->count = 0;
    split_tokens_test();
}

void mini_shell_map_Test28() {
    data()->s = "| hola";
    t_token exp[] = {
        { "|", e_pipe },
        { "hola", e_args | e_cmd }
    };
    data()->exp   = exp;
    data()->count = 2;
    split_tokens_test();
}

void mini_shell_map_Test29() {
    data()->s = "| | |";
    t_token exp[] = {
        { "|", e_pipe },
        { "|", e_pipe },
        { "|", e_pipe }
    };
    data()->exp   = exp;
    data()->count = 3;
    split_tokens_test();
}

void mini_shell_map_Test30() {
    data()->s = "||";
    t_token exp[] = {
        { "|", e_pipe }, 
        { "|", e_pipe }
    };
    data()->exp   = exp;
    data()->count = 2;
    split_tokens_test();
}

void mini_shell_map_Test32() {
    data()->s = "|||||||||||||";
    t_token exp[] = {
        { "|", e_pipe }, { "|", e_pipe }, { "|", e_pipe },
        { "|", e_pipe }, { "|", e_pipe }, { "|", e_pipe },
        { "|", e_pipe }, { "|", e_pipe }, { "|", e_pipe },
        { "|", e_pipe }, { "|", e_pipe }, { "|", e_pipe },
        { "|", e_pipe }
    };
    data()->exp   = exp;
    data()->count = 13;
    split_tokens_test();
}

void mini_shell_map_Test33() {
    data()->s = ">>|><";
    t_token exp[] = {
        { ">>", e_redir_out_app },
        { "|",  e_pipe },
        { ">",  e_redir_out_trun },
        { "<",  e_redir_in }
    };
    data()->exp   = exp;
    data()->count = 4;
    split_tokens_test();
}

void mini_shell_map_Test34() {
    data()->s = "&&";
    t_token exp[] = {
        { "&&", e_args | e_cmd }
    };
    data()->exp   = exp;
    data()->count = 1;
    split_tokens_test();
}

void mini_shell_map_Test35() {
    data()->s = "&&&&&";
    t_token exp[] = { 
        { "&&&&&", e_args | e_cmd } 
    };
    data()->exp   = exp;
    data()->count = 1;
    split_tokens_test();
}

void mini_shell_map_Test36() {
    data()->s = "&&&&&&&&&&&&&&";
    t_token exp[] = { { "&&&&&&&&&&&&&&", e_args  | e_cmd} };
    data()->exp   = exp;
    data()->count = 1;
    split_tokens_test();
}

void mini_shell_map_Test37() {
    data()->s = ";;";
    t_token exp[] = { { ";;", e_args | e_cmd} };
    data()->exp   = exp;
    data()->count = 1;
    split_tokens_test();
}

void mini_shell_map_Test38() {
    data()->s = ";;;;;";
    t_token exp[] = { { ";;;;;", e_args | e_cmd } };
    data()->exp   = exp;
    data()->count = 1;
    split_tokens_test();
}

void mini_shell_map_Test39() {
    data()->s = ";;;;;;;;;;;;;;;";
    t_token exp[] = { { ";;;;;;;;;;;;;;;", e_args | e_cmd } };
    data()->exp   = exp;
    data()->count = 1;
    split_tokens_test();
}

void mini_shell_map_Test40() {
    data()->s = "()";
    t_token exp[] = { { "()", e_args | e_cmd } };
    data()->exp   = exp;
    data()->count = 1;
    split_tokens_test();
}

void mini_shell_map_Test41() {
    data()->s = "( ( ) )";
    t_token exp[] = { { "(", e_args | e_cmd }, 
    { "(", e_args },
    { ")", e_args }, 
    { ")", e_args }, };
    data()->exp   = exp;
    data()->count = 4;
    split_tokens_test();
}

void mini_shell_map_Test42() {
    data()->s = "( ( ( ( ) ) ) )";
    t_token exp[] = { 
        { "(", e_args | e_cmd }, 
        { "(", e_args }, 
        { "(", e_args }, 
        { "(", e_args }, 
        { ")", e_args }, 
        { ")", e_args }, 
        { ")", e_args }, 
        { ")", e_args }, 
    };
    data()->exp   = exp;
    data()->count = 8;
    split_tokens_test();
}

void mini_shell_map_Test43() {
    data()->s = "\"\"";
    t_token exp[] = { { "\"\"", e_args | e_cmd | e_double_quote } };
    data()->exp   = exp;
    data()->count = 1;
    split_tokens_test();
}

void mini_shell_map_Test44() {
    data()->s = "\"hola\"";
    t_token exp[] = { { "\"hola\"", e_double_quote | e_args | e_cmd} };
    data()->exp   = exp;
    data()->count = 1;
    split_tokens_test();
}

void mini_shell_map_Test45() {
    data()->s = "'hola'";
    t_token exp[] = { { "'hola'", e_quote | e_args | e_cmd } };
    data()->exp   = exp;
    data()->count = 1;
    split_tokens_test();
}

void mini_shell_map_Test46() {
    data()->s = "''";
    t_token exp[] = { { "''", e_quote | e_cmd | e_args } };
    data()->exp   = exp;
    data()->count = 1;
    split_tokens_test();
}

void mini_shell_map_Test47() {
    data()->s = "*";
    t_token exp[] = { { "*", e_args | e_cmd} };
    data()->exp   = exp;
    data()->count = 1;
    split_tokens_test();
}

void mini_shell_map_Test48() {
    data()->s = "*/ *";
    t_token exp[] = { { "*/", e_args | e_cmd | e_path } };
    data()->exp   = exp;
    data()->count = 1;
    split_tokens_test();
}

void mini_shell_map_Test49() {
    data()->s = "*/ *";
    t_token exp[] = { { "*/", e_args | e_cmd | e_path }, { "*", e_cmd } };
    data()->exp   = exp;
    data()->count = 1;
    split_tokens_test();
}

void mini_shell_map_Test50() {
    data()->s = ".";
    t_token exp[] = { { ".", e_args | e_cmd } };
    data()->exp   = exp;
    data()->count = 1;
    split_tokens_test();
}

void mini_shell_map_Test51() {
    data()->s = "..";
    t_token exp[] = { { "..", e_args | e_cmd } };
    data()->exp   = exp;
    data()->count = 1;
    split_tokens_test();
}

void mini_shell_map_Test52() {
    data()->s = "~";
    t_token exp[] = { { "~", e_args | e_cmd } };
    data()->exp   = exp;
    data()->count = 1;
    split_tokens_test();
}

void mini_shell_map_Test53() {
    data()->s = "echo $";
    t_token exp[] = {
        { "echo", e_cmd | e_args },
        { "$", e_args }
    };
    data()->exp   = exp;
    data()->count = 2;
    split_tokens_test();
}

void mini_shell_map_Test54() {
    data()->s = "echo $HOME";
    t_token exp[] = {
        { "echo", e_cmd | e_args },
        { "$HOME", e_args | e_var_to_get}
    };
    data()->exp   = exp;
    data()->count = 2;
    split_tokens_test();
}

void mini_shell_map_Test55() {
    data()->s = "echo $HOME9";
    t_token exp[] = {
        { "echo", e_cmd | e_args },
        { "$HOME9", e_args | e_var_to_get}
    };
    data()->exp   = exp;
    data()->count = 2;
    split_tokens_test();
}

void mini_shell_map_Test56() {
    data()->s = "echo $9HOME";
    t_token exp[] = {
        { "echo", e_cmd | e_args },
        { "$9HOME", e_args | e_var_to_get}
    };
    data()->exp   = exp;
    data()->count = 2;
    split_tokens_test();
}

void mini_shell_map_Test57() {
    data()->s = "echo $HOME%";
    t_token exp[] = {
        { "echo", e_cmd | e_args },
        { "$HOME%", e_args | e_var_to_get}
    };
    data()->exp   = exp;
    data()->count = 2;
    split_tokens_test();
}

void mini_shell_map_Test58() {
    data()->s = "echo $UID$HOME";
    t_token exp[] = {
        { "echo", e_cmd | e_args },
        { "$UID$HOME", e_args | e_var_to_get}
    };
    data()->exp   = exp;
    data()->count = 2;
    split_tokens_test();
}

void mini_shell_map_Test59() {
    data()->s = "echo Le path de mon HOME est $HOME";
    t_token exp[] = {
        { "echo", e_cmd | e_args },
        { "Le", e_args },
        { "path", e_args },
        { "de", e_args },
        { "mon", e_args },
        { "HOME", e_args },
        { "est", e_args },
        { "$HOME", e_args | e_var_to_get}
    };
    data()->exp   = exp;
    data()->count = 8;
    split_tokens_test();
}

void mini_shell_map_Test60() {
    data()->s = "echo $USER$var\\$USER$USER\\$USERtest$USER";
    t_token exp[] = {
        { "echo", e_cmd | e_args },
        { "$USER$var\\$USER$USER\\$USERtest$USER", e_args | e_var_to_get}
    };
    data()->exp   = exp;
    data()->count = 2;
    split_tokens_test();
}

void mini_shell_map_Test61() {
    data()->s = "echo $hola*";
    t_token exp[] = {
        { "echo", e_cmd | e_args },
        { "$hola*", e_args | e_var_to_get}
    };
    data()->exp   = exp;
    data()->count = 2;
    split_tokens_test();
}

void mini_shell_map_Test62() {
    data()->s = "echo -nnnn $hola";
    t_token exp[] = {
        { "echo", e_cmd | e_args },
        { "-nnnn", e_args },
        { "$hola", e_args | e_var_to_get}
    };
    data()->exp   = exp;
    data()->count = 3;
    split_tokens_test();
}

void mini_shell_map_Test63() {
    data()->s = "echo > <";
    t_token exp[] = {
        { "echo", e_cmd | e_args },
        { ">", e_redir_out_trun },
        { "<", e_redir_in }
    };
    data()->exp   = exp;
    data()->count = 3;
    split_tokens_test();
}

void mini_shell_map_Test64() {
    data()->s = "echo | |";
    t_token exp[] = {
        { "echo", e_cmd | e_args },
        { "|", e_pipe },
        { "|", e_pipe }
    };
    data()->exp   = exp;
    data()->count = 3;
    split_tokens_test();
}

void mini_shell_map_Test65() {
    data()->s = "EechoE";
    t_token exp[] = {
        { "EechoE", e_cmd | e_args }
    };
    data()->exp   = exp;
    data()->count = 1;
    split_tokens_test();
}

void mini_shell_map_Test66() {
    data()->s = ".echo.";
    t_token exp[] = {
        { ".echo.", e_cmd | e_args }
    };
    data()->exp   = exp;
    data()->count = 1;
    split_tokens_test();
}

void mini_shell_map_Test67() {
    data()->s = ">echo>";
    t_token exp[] = {
        { ">",  e_redir_out_trun},
        { "echo", e_cmd | e_args },
        { ">",  e_redir_out_trun},
    };
    data()->exp   = exp;
    data()->count = 1;
    split_tokens_test();
}

void mini_shell_map_Test68() {
    data()->s = "<echo<";
    t_token exp[] = {
        { "<", e_redir_in },
        { "echo", e_file_name },
        { "<", e_redir_in },
    };
    data()->exp   = exp;
    data()->count = 3;
    split_tokens_test();
}

void mini_shell_map_Test69() {
    data()->s = ">>echo>>";
    t_token exp[] = {
        { ">>",  e_redir_out_app},
        { "echo>>", e_file_name },
        { ">>",  e_redir_out_app},
    };
    data()->exp   = exp;
    data()->count = 1;
    split_tokens_test();
}

void mini_shell_map_Test70() {
    data()->s = "|echo|";
    t_token exp[] = {
        { "|", e_pipe },
        { "echo", e_cmd | e_args },
        { "|", e_pipe },
    };
    data()->exp   = exp;
    data()->count = 3;
    split_tokens_test();
}

void mini_shell_map_Test71() {
    data()->s = "|echo -n hola";
    t_token exp[] = {
        { "|", e_pipe },
        { "echo", e_cmd | e_args },
        { "-n", e_args },
        { "hola", e_args }
    };
    data()->exp   = exp;
    data()->count = 4;
    split_tokens_test();
}

void mini_shell_map_Test72() {
    data()->s = "echo *";
    t_token exp[] = {
        { "echo", e_cmd | e_args },
        { "*", e_args }
    };
    data()->exp   = exp;
    data()->count = 2;
    split_tokens_test();
}

void mini_shell_map_Test73() {
    data()->s = "echo";
    t_token exp[] = {
        { "echo", e_cmd | e_args }
    };
    data()->exp = exp;
    data()->count = 1;
    split_tokens_test();
}

void mini_shell_map_Test74() {
    data()->s = "echo -n";
    t_token exp[] = {
        { "echo", e_cmd | e_args },
        { "-n", e_args }
    };
    data()->exp = exp;
    data()->count = 2;
    split_tokens_test();
}

void mini_shell_map_Test75() {
    data()->s = "echo Hola";
    t_token exp[] = {
        { "echo", e_cmd | e_args },
        { "Hola", e_args }
    };
    data()->exp = exp;
    data()->count = 2;
    split_tokens_test();
}

void mini_shell_map_Test76() {
    data()->s = "echoHola";
    t_token exp[] = {
        { "echoHola", e_cmd | e_args }
    };
    data()->exp = exp;
    data()->count = 1;
    split_tokens_test();
}

void mini_shell_map_Test77() {
    data()->s = "echo-nHola";
    t_token exp[] = {
        { "echo-nHola", e_cmd | e_args }
    };
    data()->exp = exp;
    data()->count = 1;
    split_tokens_test();
}

void mini_shell_map_Test78() {
    data()->s = "echo -n Hola";
    t_token exp[] = {
        { "echo", e_cmd | e_args },
        { "-n", e_args },
        { "Hola", e_args }
    };
    data()->exp = exp;
    data()->count = 3;
    split_tokens_test();
}

void mini_shell_map_Test79() {
    data()->s = "echo \"-n\" Hola";
    t_token exp[] = {
        { "echo", e_cmd | e_args },
        { "\"-n\"", e_args },
        { "Hola", e_args }
    };
    data()->exp = exp;
    data()->count = 3;
    split_tokens_test();
}

void mini_shell_map_Test80() {
    data()->s = "echo -nHola";
    t_token exp[] = {
        { "echo", e_cmd | e_args },
        { "-nHola", e_args }
    };
    data()->exp = exp;
    data()->count = 2;
    split_tokens_test();
}

void mini_shell_map_Test81() {
    data()->s = "echo Hola -n";
    t_token exp[] = {
        { "echo", e_cmd | e_args },
        { "Hola", e_args },
        { "-n", e_args }
    };
    data()->exp = exp;
    data()->count = 3;
    split_tokens_test();
}

void mini_shell_map_Test82() {
    data()->s = "echo Hola Que Tal";
    t_token exp[] = {
        { "echo", e_cmd | e_args },
        { "Hola", e_args },
        { "Que", e_args },
        { "Tal", e_args }
    };
    data()->exp = exp;
    data()->count = 4;
    split_tokens_test();
}

void mini_shell_map_Test83() {
    data()->s = "echo         Hola";
    t_token exp[] = {
        { "echo", e_cmd | e_args },
        { "Hola", e_args }
    };
    data()->exp = exp;
    data()->count = 2;
    split_tokens_test();
}

void mini_shell_map_Test84() {
    data()->s = "echo    Hola     Que    Tal";
    t_token exp[] = {
        { "echo", e_cmd | e_args },
        { "Hola", e_args },
        { "Que", e_args },
        { "Tal", e_args }
    };
    data()->exp = exp;
    data()->count = 4;
    split_tokens_test();
}

void mini_shell_map_Test85() {
    data()->s = "echo      \\n hola";
    t_token exp[] = {
        { "echo", e_cmd | e_args },
        { "\\n", e_args },
        { "hola", e_args }
    };
    data()->exp = exp;
    data()->count = 3;
    split_tokens_test();
}

void mini_shell_map_Test86() {
    data()->s = "echo \"         \" | cat -e";
    t_token exp[] = {
        { "echo", e_cmd | e_args },
        { "\"         \"", e_args },
        { "|", e_pipe },
        { "cat", e_cmd | e_args },
        { "-e", e_args }
    };
    data()->exp = exp;
    data()->count = 5;
    split_tokens_test();
}

void mini_shell_map_Test87() {
    data()->s = "echo           | cat -e";
    t_token exp[] = {
        { "echo", e_cmd | e_args },
        { "|", e_pipe },
        { "cat", e_cmd | e_args },
        { "-e", e_args }
    };
    data()->exp = exp;
    data()->count = 4;
    split_tokens_test();
}

void mini_shell_map_Test88() {
    data()->s = "\"\"''echo hola\"\"'''' que\"\"'' tal\"\"";
    t_token exp[] = {
        { "\"\"''echo", e_cmd | e_args },
        { "hola\"\"''''", e_args },
        { "que\"\"''", e_args },
        { "tal\"\"", e_args }
    };
    data()->exp = exp;
    data()->count = 4;
    split_tokens_test();
}

void mini_shell_map_Test89() {
    data()->s = "echo -n -n";
    t_token exp[] = {
        { "echo", e_cmd | e_args },
        { "-n", e_args },
        { "-n", e_args }
    };
    data()->exp = exp;
    data()->count = 3;
    split_tokens_test();
}

void mini_shell_map_Test90() {
    data()->s = "echo -n -n Hola Que";
    t_token exp[] = {
        { "echo", e_cmd | e_args },
        { "-n", e_args },
        { "-n", e_args },
        { "Hola", e_args },
        { "Que", e_args }
    };
    data()->exp = exp;
    data()->count = 5;
    split_tokens_test();
}

void mini_shell_map_Tests()
{
    RUN_TEST(mini_shell_map_Test1);
    RUN_TEST(mini_shell_map_Test2);
    RUN_TEST(mini_shell_map_Test3);
    RUN_TEST(mini_shell_map_Test4);
    RUN_TEST(mini_shell_map_Test5);
    RUN_TEST(mini_shell_map_Test6);
    RUN_TEST(mini_shell_map_Test7);
    RUN_TEST(mini_shell_map_Test8);
    RUN_TEST(mini_shell_map_Test9);
    RUN_TEST(mini_shell_map_Test11);
    RUN_TEST(mini_shell_map_Test12);
    RUN_TEST(mini_shell_map_Test13);
    RUN_TEST(mini_shell_map_Test14);
    RUN_TEST(mini_shell_map_Test15);
    RUN_TEST(mini_shell_map_Test16);
    RUN_TEST(mini_shell_map_Test17);
    RUN_TEST(mini_shell_map_Test18);
    RUN_TEST(mini_shell_map_Test19);
    RUN_TEST(mini_shell_map_Test20);
    RUN_TEST(mini_shell_map_Test21);
    RUN_TEST(mini_shell_map_Test22);
    RUN_TEST(mini_shell_map_Test23);
    RUN_TEST(mini_shell_map_Test24);
    RUN_TEST(mini_shell_map_Test25);
    RUN_TEST(mini_shell_map_Test26);
    // RUN_TEST(mini_shell_map_Test27);
    RUN_TEST(mini_shell_map_Test28);
    RUN_TEST(mini_shell_map_Test29);
    RUN_TEST(mini_shell_map_Test30);
    // RUN_TEST(mini_shell_map_Test31);
    RUN_TEST(mini_shell_map_Test32);
    RUN_TEST(mini_shell_map_Test33);
    RUN_TEST(mini_shell_map_Test34);
    // RUN_TEST(mini_shell_map_Test35);
    RUN_TEST(mini_shell_map_Test36);
    RUN_TEST(mini_shell_map_Test37);
    RUN_TEST(mini_shell_map_Test38);
    RUN_TEST(mini_shell_map_Test39);
    RUN_TEST(mini_shell_map_Test40);
    RUN_TEST(mini_shell_map_Test41);
    RUN_TEST(mini_shell_map_Test42);
    RUN_TEST(mini_shell_map_Test43);
    RUN_TEST(mini_shell_map_Test44);
    RUN_TEST(mini_shell_map_Test45);
    RUN_TEST(mini_shell_map_Test46);
    RUN_TEST(mini_shell_map_Test47);
    RUN_TEST(mini_shell_map_Test48);
    RUN_TEST(mini_shell_map_Test49);
    RUN_TEST(mini_shell_map_Test50);
    RUN_TEST(mini_shell_map_Test51);
    RUN_TEST(mini_shell_map_Test52);
    RUN_TEST(mini_shell_map_Test53);
    RUN_TEST(mini_shell_map_Test54);
    RUN_TEST(mini_shell_map_Test55);
    RUN_TEST(mini_shell_map_Test56);
    RUN_TEST(mini_shell_map_Test57);
    RUN_TEST(mini_shell_map_Test58);
    RUN_TEST(mini_shell_map_Test59);
    RUN_TEST(mini_shell_map_Test60);
    RUN_TEST(mini_shell_map_Test61);
    RUN_TEST(mini_shell_map_Test62);
    RUN_TEST(mini_shell_map_Test63);
    RUN_TEST(mini_shell_map_Test64);
    RUN_TEST(mini_shell_map_Test65);
    RUN_TEST(mini_shell_map_Test66);
    RUN_TEST(mini_shell_map_Test67);
    RUN_TEST(mini_shell_map_Test68);
    RUN_TEST(mini_shell_map_Test69);
    RUN_TEST(mini_shell_map_Test70);
    RUN_TEST(mini_shell_map_Test71);
    RUN_TEST(mini_shell_map_Test72);
}