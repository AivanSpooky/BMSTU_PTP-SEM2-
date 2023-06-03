#!/bin/bash

TXT="./graph/*.txt"

PREFIX="./gnuplot/gnuplot_"

./scripts/clean_scripts/clean_gnuplot.sh

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

# # График с ошибкой
# for file in $TXT; do
#     basename=$(basename "${file}")
#     name=$PREFIX$basename"_error.gpi"
#     {
#         echo "set output \"./gnuplot/${basename}_Error.svg\""
#         cat "./gnuplot/tmpl.txt"
#         echo "set terminal svg size 1080, 720"
#         echo "plot \"$file\" using 8:2:3:7 with yerror title \"$basename Error\", \"$file\" using 8:2 with lines title \"$basename\""
#     } >> "$name"
# done

# # График с усами
# for file in $TXT; do
#     basename=$(basename "${file}")
#     name=$PREFIX$basename"_Moustache.gpi"
#     {
#         cat "./gnuplot/tmpl.txt"
#         echo "set terminal svg size 1080, 720"
#         echo "set output \"./gnuplot/${basename}Moustache.svg\""
#         echo "plot \"$file\" using 8:4:3:7:6 with candlesticks title \"$basename Moustache\", \"$file\" using 8:2 with lines title \"$basename\""
#     } >> "$name"
# done

# Графики из задания
cd ./scripts || exit
./clean_scripts/clean_dataset.sh
i=0
while read -r line; do
    if [ $i -eq 0 ]; then
        opt=$line
    fi
    if [ $i -eq 2 ]; then
        sort_types=$line
    fi
    if [ $i -eq 4 ]; then
        arr_types="${line}"
    fi
    i=$((i + 1))
done < ./cfg.txt
cd ..

# # График
# name=$PREFIX"comp_1.gpi"
# cat "./gnuplot/tmpl.txt" > "$name"
# echo "set terminal svg size 1080, 720" >> "$name"
# echo "set output \"./gnuplot/Comparative_Graph.svg\"" >> "$name"

# count=0
# for option in $opt; do
#     for sort_type in $sort_types; do
#         for arr_type in $arr_types; do
#             file=./graph/"${option}"_s"${sort_type}"_a"${arr_type}".txt
#             if [ "$arr_type" -eq 2 ]; then
#                 basename=$(basename "${file}")
#                 if [ $count -eq 0 ]; then
#                     echo "plot \"$file\" using 8:2 with lines title \"$basename\", \\" >> "$name"
#                 else
#                     echo "\"$file\" using 8:2 with lines title \"$basename\", \\" >> "$name"
#                 fi
#                 count=$((count + 1))
#             fi
#         done
#     done
# done

# # График-2
# name=$PREFIX"comp_2.gpi"
# cat "./gnuplot/tmpl.txt" > "$name"
# echo "set terminal svg size 1080, 720" >> "$name"
# echo "set output \"./gnuplot/Comparative_Graph.svg\"" >> "$name"

# count=0
# for option in $opt; do
#     for sort_type in $sort_types; do
#         for arr_type in $arr_types; do
#             file=./graph/"${option}"_s"${sort_type}"_a"${arr_type}".txt
#             if [ "$arr_type" -eq 1 ]; then
#                 basename=$(basename "${file}")
#                 if [ $count -eq 0 ]; then
#                     echo "plot \"$file\" using 8:2 with lines title \"$basename\", \\" >> "$name"
#                 else
#                     echo "\"$file\" using 8:2 with lines title \"$basename\", \\" >> "$name"
#                 fi
#                 count=$((count + 1))
#             fi
#         done
#     done
# done

# # График-3
# name=$PREFIX"comp_3.gpi"
# cat "./gnuplot/tmpl.txt" > "$name"
# echo "set terminal svg size 1080, 720" >> "$name"
# echo "set output \"./gnuplot/Comparative_Graph.svg\"" >> "$name"

# count=0
# for option in $opt; do
#     for sort_type in $sort_types; do
#         for arr_type in $arr_types; do
#             file=./graph/"${option}"_s"${sort_type}"_a"${arr_type}".txt
#             if [ "$option" == "O2"  ]; then
#                 basename=$(basename "${file}")
#                 if [ $count -eq 0 ]; then
#                     echo "plot \"$file\" using 8:2:3:7 with yerror title \"$basename Error\", \"$file\" using 8:2 with lines title \"$basename\"" >> "$name"
#                 else
#                     echo "\"$file\" using 8:2:3:7 with yerror title \"$basename Error\", \"$file\" using 8:2 with lines title \"$basename\"" >> "$name"
#                 fi
#                 count=$((count + 1))
#             fi
#         done
#     done
# done

# # График-4
# name=$PREFIX"comp_4.gpi"
# cat "./gnuplot/tmpl.txt" > "$name"
# echo "set terminal svg size 1080, 720" >> "$name"
# echo "set output \"./gnuplot/Comparative_Graph.svg\"" >> "$name"

# count=0
# for option in $opt; do
#     for sort_type in $sort_types; do
#         for arr_type in $arr_types; do
#             file=./graph/"${option}"_s"${sort_type}"_a"${arr_type}".txt
#             if [ "$option" == "O2"  ]; then
#                 basename=$(basename "${file}")
#                 if [ $count -eq 0 ]; then
#                     echo "plot \"$file\" using 8:4:3:7:6 with candlesticks title \"$basename Moustache\", \"$file\" using 8:2 with lines title \"$basename\"" >> "$name"
#                 else
#                     echo "\"$file\" using 8:4:3:7:6 with candlesticks title \"$basename Moustache\", \"$file\" using 8:2 with lines title \"$basename\"" >> "$name"
#                 fi
#                 count=$((count + 1))
#             fi
#         done
#     done
# done
# ЗАПУСТИТЬ ГРАФИК
#gnuplot $PATH$NAME".gpi" -persist