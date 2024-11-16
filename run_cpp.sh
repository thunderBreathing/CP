#!/bin/bash

if [ -z "$1" ]; then
  echo "Usage: $0 <filename.cpp>"
  exit 1
fi

filename="$1"
output="${filename%.*}"

# Compile with warnings and optimization
g++ -std=c++23 -Wall -Wextra -o "$output" "$filename"

if [ $? -eq 0 ]; then
  # Measure time and memory usage
  /usr/bin/time -v "./$output"
else
  echo "Compilation failed!"
fi

