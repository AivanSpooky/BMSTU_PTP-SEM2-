#!/bin/bash

gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -Wvla -"${1}" -DSORT_TYPE="${2}" -DNMAX="${3}" -c main.c
gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -Wvla -DNMAX="${3}" -c matrix.c
gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -Wvla -DNMAX="${3}" -c sort.c
gcc -o ./apps/app_"$1"_s"$2"_n"$3".exe main.o matrix.o sort.o -lm 