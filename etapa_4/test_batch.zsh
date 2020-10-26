#!/bin/zsh

for ((i = 0; i < 76; i++)); do 
  echo  'test' $i
  head -1 tests/t$i
  ./etapa4 < tests/t$i >> /dev/null
  echo $?
  echo ; done
