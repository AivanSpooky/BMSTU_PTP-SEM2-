#!/bin/bash

cd ./scripts || exit
./clean_scripts/clean_apps.sh
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
    i=$((i + 1))
done < ./cfg.txt
# opt - Os; O0; O2
# sort_type: 1 - с кешированием суммы; 2 - без кеширования
cd ..
for option in $opt; do
    for sort_type in $sort_types; do
        ./build_release.sh "$option" "$sort_type" "$nmax"
    done
done
