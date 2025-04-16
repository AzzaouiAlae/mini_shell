#!/bin/bash

#../auto_git_push
clear
gcc -g Unity-master/src/*.c ../mini_shell/*.c ../mini_shell/*/*.c *.c */*.c *.h && valgrind --track-origins=yes -s --leak-check=full ./a.out
#gcc -fsanitize=address  Unity-master/src/*.c ../mini_shell/*.c ../mini_shell/*/*.c *.c  && ./a.out
