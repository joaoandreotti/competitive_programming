#!/bin/bash
for (( i = 1; ;++i ))
do
  echo $i
  ./gen $i > in
  diff <(./a.out < in) <(./brute < in) || break
done

