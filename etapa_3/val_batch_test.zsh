#!/bin/zsh

for ((i = 0; i < 10; i++)); do valgrind -q --leak-check=full --error-exitcode=99 ./etapa3 < w0$i >> /dev/null && echo valgrind 'exit' code: $?; done

for ((i = 10; i < 77; i++)); do valgrind -q --leak-check=full --error-exitcode=99 ./etapa3 < w$i >> /dev/null && echo valgrind 'exit' code: $?; done