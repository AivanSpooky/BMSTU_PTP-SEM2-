#!/bin/bash

TXT="./graph/*.txt"

PREFIX="./gnuplot/gnuplot_"

./scripts/clean_scripts/clean_gnuplot.sh

# Графики из задания
# Общий кусочно-линейный график
for file in $TXT; do
    basename=$(basename "${file}")
    name=$PREFIX$basename".gpi"
    {
        echo "set output \"./gnuplot/${basename}.svg\""
        cat "./gnuplot/tmpl.txt"
        echo "set terminal svg size 1080, 720"
        echo "plot \"$file\" using 8:2 with lines title \"$basename\""
    } >> "$name"
done

# ЗАПУСТИТЬ ГРАФИК
#gnuplot $PATH$NAME".gpi" -persist