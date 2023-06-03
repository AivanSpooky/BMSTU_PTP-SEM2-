#!/bin/bash

files="./graph/*.txt"
for file in $files; do
	rm -f "$file" 
done