#!/bin/bash

if [ -z "$1" ]
then
    echo "please, enter programm key!"
else
    ./build_release.sh "$1"
    for (( i=1; i <= 500; i++ ))
    do
        echo "test-'$i'"
        rm -f ./dataset/t_"$1"_"$i".txt
        ./app.exe >> ./dataset/t_"$1"_"$i".txt
    done
    echo "dataset done!"
fi
