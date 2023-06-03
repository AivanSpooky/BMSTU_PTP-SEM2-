#!/bin/bash

files="./dataset/*.txt"
for file in $files; do
	rm -f "$file" 
done