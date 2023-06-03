#!/bin/bash

cd ./scripts || exit
./clean_scripts/clean_apps.sh
i=0
while read -r line; do
    if [ $i -eq 0 ]; then
        opt=$line
    fi
    # if [ $i -eq 1 ]; then
    #     tests=$line
    # fi
    if [ $i -eq 2 ]; then
        sort_types=$line
    fi
    if [ $i -eq 3 ]; then
        nmax=$line
    fi
    if [ $i -eq 4 ]; then
        array_types="${line}"
    fi
    i=$((i + 1))
done < ./cfg.txt
# opt - O0; O2
# sort_type: 1 - индексация; 2 - *(a + i); 3 - указатели
# array_type: 1 - случайный; 2 - отсортированный
cd ..
for option in $opt; do
    for sort_type in $sort_types; do
        for array_type in $array_types; do
            ./build_release.sh "$option" "$sort_type" "$array_type" "$nmax"
        done
    done
done
