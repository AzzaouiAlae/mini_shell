#include "../Tests.h"

void builtins_Test1() {
    data()->s = "echo hello world";
    t_token exp[] = {
        {"echo", e_args | e_cmd},
        {"hello", e_args},
        {"world", e_args}
    };
    data()->exp = (t_token *)exp;
    data()->count = 3;
    split_tokens_test();
}

void builtins_Test2() {
    data()->s = "echo \"hello world\"";
    t_token exp[] = {
        {"echo", e_args | e_cmd},
        {"\"hello world\"", e_args | e_double_quote}
    };
    data()->exp = (t_token *)exp;
    data()->count = 2;
    split_tokens_test();
}

void builtins_Test3() {
    data()->s = "echo 'hello world'";
    t_token exp[] = {
        {"echo", e_args | e_cmd},
        {"'hello world'", e_args | e_quote}
    };
    data()->exp = (t_token *)exp;
    data()->count = 2;
    split_tokens_test();
}

void builtins_Test4() {
    data()->s = "echo hello'world'";
    t_token exp[] = {
        {"echo", e_args | e_cmd},
        {"hello'world'", e_args | e_quote}
    };
    data()->exp = (t_token *)exp;
    data()->count = 2;
    split_tokens_test();
}

void builtins_Test5() {
    data()->s = "echo hello\"\"world";
    t_token exp[] = {
        {"echo", e_args | e_cmd},
        {"hello\"\"world", e_args | e_double_quote}
    };
    data()->exp = (t_token *)exp;
    data()->count = 2;
    split_tokens_test();
}

void builtins_Test6() {
    data()->s = "echo ''";
    t_token exp[] = {
        {"echo", e_args | e_cmd},
        {"''", e_args | e_quote}
    };
    data()->exp = (t_token *)exp;
    data()->count = 2;
    split_tokens_test();
}

void builtins_Test7() {
    data()->s = "echo \"$PWD\"";
    t_token exp[] = {
        {"echo", e_args | e_cmd},
        {"\"$PWD\"", e_args | e_double_quote | e_var_to_get}
    };
    data()->exp = (t_token *)exp;
    data()->count = 2;
    split_tokens_test();
}

void builtins_Test8() {
    data()->s = "echo '$PWD'";
    t_token exp[] = {
        {"echo", e_args | e_cmd},
        {"'$PWD'", e_args | e_quote}
    };
    data()->exp = (t_token *)exp;
    data()->count = 2;
    split_tokens_test();
}

void builtins_Test9() {
    data()->s = "echo \"aspas ->'\"";
    t_token exp[] = {
        {"echo", e_args | e_cmd},
        {"\"aspas ->'\"", e_args | e_double_quote}
    };
    data()->exp = (t_token *)exp;
    data()->count = 2;
    split_tokens_test();
}

void builtins_Test10() {
    data()->s = "echo \"aspas -> ' \"";
    t_token exp[] = {
        {"echo", e_args | e_cmd},
        {"\"aspas -> ' \"", e_args | e_double_quote}
    };
    data()->exp = (t_token *)exp;
    data()->count = 2;
    split_tokens_test();
}

void builtins_Test11() {
    data()->s = "echo 'aspas ->\"'";
    t_token exp[] = {
        {"echo", e_args | e_cmd},
        {"'aspas ->\"'", e_args | e_quote}
    };
    data()->exp = (t_token *)exp;
    data()->count = 2;
    split_tokens_test();
}

void builtins_Test12() {
    data()->s = "echo 'aspas -> \" '";
    t_token exp[] = {
        {"echo", e_args | e_cmd},
        {"'aspas -> \" '", e_args | e_quote}
    };
    data()->exp = (t_token *)exp;
    data()->count = 2;
    split_tokens_test();
}

void builtins_Test13() {
    data()->s = "echo \"> >> < * ? [ ] | ; [ ] || && ( ) & # $ \\ <<\"";
    t_token exp[] = {
        {"echo", e_args | e_cmd},
        {"\"> >> < * ? [ ] | ; [ ] || && ( ) & # $ \\ <<\"", e_args | e_double_quote}
    };
    data()->exp = (t_token *)exp;
    data()->count = 2;
    split_tokens_test();
}

void builtins_Test14() {
    data()->s = "echo '> >> < * ? [ ] | ; [ ] || && ( ) & # $ \\ <<'";
    t_token exp[] = {
        {"echo", e_args | e_cmd},
        {"'> >> < * ? [ ] | ; [ ] || && ( ) & # $ \\ <<'", e_args | e_quote}
    };
    data()->exp = (t_token *)exp;
    data()->count = 2;
    split_tokens_test();
}

void builtins_Test15() {
    data()->s = "echo \"exit_code ->$? user ->$USER home -> $HOME\"";
    t_token exp[] = {
        {"echo", e_args | e_cmd},
        {"\"exit_code ->$? user ->$USER home -> $HOME\"", e_args | e_double_quote | e_var_to_get}
    };
    data()->exp = (t_token *)exp;
    data()->count = 2;
    split_tokens_test();
}

void builtins_Test16() {
    data()->s = "echo 'exit_code ->$? user ->$USER home -> $HOME'";
    t_token exp[] = {
        {"echo", e_args | e_cmd},
        {"'exit_code ->$? user ->$USER home -> $HOME'", e_args | e_quote}
    };
    data()->exp = (t_token *)exp;
    data()->count = 2;
    split_tokens_test();
}

void builtins_Test17() {
    data()->s = "echo \"$\"";
    t_token exp[] = {
        {"echo", e_args | e_cmd},
        {"\"$\"", e_args | e_double_quote}
    };
    data()->exp = (t_token *)exp;
    data()->count = 2;
    split_tokens_test();
}

void builtins_Test18() {
    data()->s = "echo '$'";
    t_token exp[] = {
        {"echo", e_args | e_cmd},
        {"'$'", e_args | e_quote}
    };
    data()->exp = (t_token *)exp;
    data()->count = 2;
    split_tokens_test();
}

void builtins_Test19() {
    data()->s = "echo $";
    t_token exp[] = {
        {"echo", e_args | e_cmd},
        {"$", e_args}
    };
    data()->exp = (t_token *)exp;
    data()->count = 2;
    split_tokens_test();
}

void builtins_Test20() {
    data()->s = "echo $?";
    t_token exp[] = {
        {"echo", e_args | e_cmd},
        {"$?", e_var_to_get | e_args}
    };
    data()->exp = (t_token *)exp;
    data()->count = 2;
    split_tokens_test();
}

void builtins_Test21() {
    data()->s = "echo $?HELLO";
    t_token exp[] = {
        {"echo", e_args | e_cmd},
        {"$?HELLO", e_args | e_var_to_get},
    };
    data()->exp = (t_token *)exp;
    data()->count = 2;
    split_tokens_test();
}

void builtins_Test22() {
    data()->s = "pwd";
    t_token exp[] = {
        {"pwd", e_args | e_cmd}
    };
    data()->exp = (t_token *)exp;
    data()->count = 1;
    split_tokens_test();
}

void builtins_Test23() {
    data()->s = "pwd oi";
    t_token exp[] = {
        {"pwd", e_args | e_cmd},
        {"oi", e_args}
    };
    data()->exp = (t_token *)exp;
    data()->count = 2;
    split_tokens_test();
}

void builtins_Test24() {
    data()->s = "export hello";
    t_token exp[] = {
        {"export", e_set_var | e_cmd},
        {"hello", e_args}
    };
    data()->exp = (t_token *)exp;
    data()->count = 2;
    split_tokens_test();
}

void builtins_Test25() {
    data()->s = "export HELLO=123";
    t_token exp[] = {
        {"export", e_set_var | e_cmd},
        {"HELLO=123", e_var_to_set}
    };
    data()->exp = (t_token *)exp;
    data()->count = 2;
    split_tokens_test();
}

void builtins_Test26() {
    data()->s = "export A-";
    t_token exp[] = {
        {"export", e_set_var | e_cmd},
        {"A-", e_args}
    };
    data()->exp = (t_token *)exp;
    data()->count = 2;
    split_tokens_test();
}

void builtins_Test27() {
    data()->s = "export HELLO=123 A";
    t_token exp[] = {
        {"export", e_set_var | e_cmd},
        {"HELLO=123", e_var_to_set},
        {"A", e_args}
    };
    data()->exp = (t_token *)exp;
    data()->count = 3;
    split_tokens_test();
}

void builtins_Test28() {
    data()->s = "export HELLO=\"123 A-\"";
    t_token exp[] = {
        {"export", e_set_var | e_cmd},
        {"HELLO=\"123 A-\"", e_var_to_set | e_double_quote}
    };
    data()->exp = (t_token *)exp;
    data()->count = 2;
    split_tokens_test();
}

void builtins_Test29() {
    data()->s = "export hello world";
    t_token exp[] = {
        {"export", e_set_var | e_cmd},
        {"hello", e_args},
        {"world", e_args}
    };
    data()->exp = (t_token *)exp;
    data()->count = 3;
    split_tokens_test();
}

void builtins_Test30() {
    data()->s = "export HELLO-=123";
    t_token exp[] = {
        {"export", e_set_var | e_cmd},
        {"HELLO-=123", e_args}
    };
    data()->exp = (t_token *)exp;
    data()->count = 2;
    split_tokens_test();
}

void builtins_Test31() {
    data()->s = "export =";
    t_token exp[] = {
        {"export", e_set_var | e_cmd},
        {"=", e_var_to_set}
    };
    data()->exp = (t_token *)exp;
    data()->count = 2;
    split_tokens_test();
}

void builtins_Test32() {
    data()->s = "export 123";
    t_token exp[] = {
        {"export", e_set_var | e_cmd},
        {"123", e_args}
    };
    data()->exp = (t_token *)exp;
    data()->count = 2;
    split_tokens_test();
}

void builtins_Test33() {
    data()->s = "unset";
    t_token exp[] = {
        {"unset", e_args | e_cmd}
    };
    data()->exp = (t_token *)exp;
    data()->count = 1;
    split_tokens_test();
}

void builtins_Test34() {
    data()->s = "unset HELLO";
    t_token exp[] = {
        {"unset", e_args | e_cmd},
        {"HELLO", e_args}
    };
    data()->exp = (t_token *)exp;
    data()->count = 2;
    split_tokens_test();
}

void builtins_Test35() {
    data()->s = "unset HELLO1 HELLO2";
    t_token exp[] = {
        {"unset", e_args | e_cmd},
        {"HELLO1", e_args},
        {"HELLO2", e_args}
    };
    data()->exp = (t_token *)exp;
    data()->count = 3;
    split_tokens_test();
}

void builtins_Test36() {
    data()->s = "unset HOME";
    t_token exp[] = {
        {"unset", e_args | e_cmd},
        {"HOME", e_args}
    };
    data()->exp = (t_token *)exp;
    data()->count = 2;
    split_tokens_test();
}

void builtins_Test37() {
    data()->s = "unset PATH";
    t_token exp[] = {
        {"unset", e_args | e_cmd},
        {"PATH", e_args}
    };
    data()->exp = (t_token *)exp;
    data()->count = 2;
    split_tokens_test();
}

void builtins_Test38() {
    data()->s = "unset SHELL";
    t_token exp[] = {
        {"unset", e_args | e_cmd},
        {"SHELL", e_args}
    };
    data()->exp = (t_token *)exp;
    data()->count = 2;
    split_tokens_test();
}

void builtins_Test39() {
    data()->s = "cd $PWD";
    t_token exp[] = {
        {"cd", e_args | e_cmd},
        {"$PWD", e_var_to_get | e_args}
    };
    data()->exp = (t_token *)exp;
    data()->count = 2;
    split_tokens_test();
}

void builtins_Test40() {
    data()->s = "cd $PWD hi";
    t_token exp[] = {
        {"cd", e_args | e_cmd},
        {"$PWD", e_var_to_get | e_args},
        {"hi", e_args}
    };
    data()->exp = (t_token *)exp;
    data()->count = 3;
    split_tokens_test();
}

void builtins_Test41() {
    data()->s = "cd 123123";
    t_token exp[] = {
        {"cd", e_args | e_cmd},
        {"123123", e_args}
    };
    data()->exp = (t_token *)exp;
    data()->count = 2;
    split_tokens_test();
}

void builtins_Test42() {
    data()->s = "exit 123";
    t_token exp[] = {
        {"exit", e_args | e_cmd},
        {"123", e_args}
    };
    data()->exp = (t_token *)exp;
    data()->count = 2;
    split_tokens_test();
}

void builtins_Test43() {
    data()->s = "exit 298";
    t_token exp[] = {
        {"exit", e_args | e_cmd},
        {"298", e_args}
    };
    data()->exp = (t_token *)exp;
    data()->count = 2;
    split_tokens_test();
}

void builtins_Test44() {
    data()->s = "exit +100";
    t_token exp[] = {
        {"exit", e_args | e_cmd},
        {"+100", e_args}
    };
    data()->exp = (t_token *)exp;
    data()->count = 2;
    split_tokens_test();
}

void builtins_Test45() {
    data()->s = "exit \"+100\"";
    t_token exp[] = {
        {"exit", e_args | e_cmd},
        {"\"+100\"", e_args | e_double_quote}
    };
    data()->exp = (t_token *)exp;
    data()->count = 2;
    split_tokens_test();
}

void builtins_Test46() {
    data()->s = "exit +\"100\"";
    t_token exp[] = {
        {"exit", e_args | e_cmd},
        {"+\"100\"", e_args | e_double_quote}
    };
    data()->exp = (t_token *)exp;
    data()->count = 2;
    split_tokens_test();
}

void builtins_Test47() {
    data()->s = "exit -100";
    t_token exp[] = {
        {"exit", e_args | e_cmd},
        {"-100", e_args}
    };
    data()->exp = (t_token *)exp;
    data()->count = 2;
    split_tokens_test();
}

void builtins_Test48() {
    data()->s = "exit \"-100\"";
    t_token exp[] = {
        {"exit", e_args | e_cmd},
        {"\"-100\"", e_args | e_double_quote}
    };
    data()->exp = (t_token *)exp;
    data()->count = 2;
    split_tokens_test();
}

void builtins_Test49() {
    data()->s = "exit -\"100\"";
    t_token exp[] = {
        {"exit", e_args | e_cmd},
        {"-\"100\"", e_args | e_double_quote}
    };
    data()->exp = (t_token *)exp;
    data()->count = 2;
    split_tokens_test();
}

void builtins_Test50() {
    data()->s = "exit hello";
    t_token exp[] = {
        {"exit", e_args | e_cmd},
        {"hello", e_args}
    };
    data()->exp = (t_token *)exp;
    data()->count = 2;
    split_tokens_test();
}

void builtins_Test51() {
    data()->s = "exit 42 world";
    t_token exp[] = {
        {"exit", e_args | e_cmd},
        {"42", e_args},
        {"world", e_args}
    };
    data()->exp = (t_token *)exp;
    data()->count = 3;
    split_tokens_test();
}



void builtins_Test()
{
    RUN_TEST(builtins_Test1);
    RUN_TEST(builtins_Test2);
    RUN_TEST(builtins_Test3);
    RUN_TEST(builtins_Test4);
    RUN_TEST(builtins_Test5);
    RUN_TEST(builtins_Test6);
    RUN_TEST(builtins_Test7);
    RUN_TEST(builtins_Test8);
    RUN_TEST(builtins_Test9);
    RUN_TEST(builtins_Test10);
    RUN_TEST(builtins_Test11);
    RUN_TEST(builtins_Test12);
    RUN_TEST(builtins_Test13);
    RUN_TEST(builtins_Test14);
    RUN_TEST(builtins_Test15);
    RUN_TEST(builtins_Test16);
    RUN_TEST(builtins_Test17);
    RUN_TEST(builtins_Test18);
    RUN_TEST(builtins_Test19);
    RUN_TEST(builtins_Test20);
    RUN_TEST(builtins_Test21);
    RUN_TEST(builtins_Test22);
    RUN_TEST(builtins_Test23);
    RUN_TEST(builtins_Test24);
    RUN_TEST(builtins_Test25);
    RUN_TEST(builtins_Test26);
    RUN_TEST(builtins_Test27);
    RUN_TEST(builtins_Test28);
    RUN_TEST(builtins_Test29);
    RUN_TEST(builtins_Test30);
    RUN_TEST(builtins_Test31);
    RUN_TEST(builtins_Test32);
    RUN_TEST(builtins_Test33);
    RUN_TEST(builtins_Test34);
    RUN_TEST(builtins_Test35);
    RUN_TEST(builtins_Test36);
    RUN_TEST(builtins_Test37);
    RUN_TEST(builtins_Test38);
    RUN_TEST(builtins_Test39);
    RUN_TEST(builtins_Test40);
    RUN_TEST(builtins_Test41);
    RUN_TEST(builtins_Test42);
    RUN_TEST(builtins_Test43);
    RUN_TEST(builtins_Test44);
    RUN_TEST(builtins_Test45);
    RUN_TEST(builtins_Test46);
    RUN_TEST(builtins_Test47);
    RUN_TEST(builtins_Test48);
    RUN_TEST(builtins_Test49);
    RUN_TEST(builtins_Test50);
    RUN_TEST(builtins_Test51);
}
