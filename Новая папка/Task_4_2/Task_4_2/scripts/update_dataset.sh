#!/bin/bash

cd ./scripts || exit
./clean_scripts/clean_dataset.sh
i=0
while read -r line; do
    if [ $i -eq 0 ]; then
        opt=$line
    fi
    if [ $i -eq 1 ]; then
        sort_types=$line
    fi
    if [ $i -eq 2 ]; then
        nmax=$line
    fi
    if [ $i -eq 3 ]; then
        tests=$line
    fi
    if [ $i -eq 4 ]; then
        sizes=$line
    fi
    i=$((i + 1))
done < ./cfg.txt
cd ..

for option in $opt; do
    for sort_type in $sort_types; do
        echo "app_'${option}'_s'${sort_type}'_n'${nmax}'.exe - done"
        for size in $sizes; do
            for (( i = 0; i < "$tests"; i++ )); do
                cmd="$(./apps/app_"${option}"_s"${sort_type}"_n"${nmax}".exe "${size}")"
                # echo ../applications/main"${option}".exe "${type}" "${size}" "${type_of_sort}"
                echo "$cmd" >> ./dataset/"${option}"_s"${sort_type}"_n"${size}".txt
            done
        done
    done
done
