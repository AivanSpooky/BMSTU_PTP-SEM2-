#!/bin/bash

files="./gnuplot/*.gpi ./gnuplot/*.svg"
for file in $files; do
	rm -f "$file" 
done