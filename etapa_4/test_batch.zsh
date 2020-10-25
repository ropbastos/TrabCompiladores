#!/bin/zsh

for ((i = 0; i < 71; i++)); do 
  echo  'test' $i
  head -1 tests/t$i
  code=$(head -1 tests/t$i | grep -Eo '[0-9]{1,4}')
  ./etapa4 < tests/t$i >> /dev/null
  echo $?
  echo ; done
