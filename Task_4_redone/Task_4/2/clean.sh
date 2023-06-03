#!/bin/bash

files="*.exe *.o *.out *.gcno *.gcda *.gcov"
for file in $files; do
	rm -f "$file" 
done