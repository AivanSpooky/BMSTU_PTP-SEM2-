#!/bin/bash

files="./scripts/*.sh ./scripts/clean_scripts/*.sh  ./*.sh"
for file_in in $files; do
	chmod +x "$file_in"
done
