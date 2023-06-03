#!/bin/bash

con="-"
if [ -z "$1" ]
then
    key=""
else
    key="${con}$1"
fi

gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -Wvla -c main"$key".c
gcc main"$key".o -o app.exe -lm 