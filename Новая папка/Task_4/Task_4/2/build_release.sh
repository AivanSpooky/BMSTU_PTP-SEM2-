#!/bin/bash

gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -Wvla -"${1}" -DSORT_TYPE="${2}" -DARR_TYPE="${3}" -DNMAX="${4}" -c main.c
gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -Wvla -c array_t.c
gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -Wvla -c sort.c
gcc -o ./apps/app_"$1"_s"$2"_a"$3"_n"$4".exe main.o array_t.o sort.o -lm 