#!/bin/bash

for i in $(ls *.c);
do
    mv "$i" "${i%.c}.cpp"
done
