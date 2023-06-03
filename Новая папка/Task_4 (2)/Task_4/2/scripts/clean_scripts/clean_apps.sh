#!/bin/bash

files="./apps/*.exe"
for file in $files; do
	rm -f "$file" 
done