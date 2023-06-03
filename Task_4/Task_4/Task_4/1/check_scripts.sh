#!/bin/bash

scripts="./*.sh"

for file in $scripts ; do
	shellcheck "$file"
done
