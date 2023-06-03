#!/bin/bash

files="./*.sh"
for file_in in $files; do
	chmod +x "$file_in"
done
