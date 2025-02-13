#!/bin/bash
# ./compile_and_run.sh main.cpp

# Check if a filename is provided
if [ $# -eq 0 ]; then
    echo "Usage: $0 <source_file.cpp>"
    exit 1
fi

# Get the filename without the extension
FILENAME=$(basename "$1" .cpp)

# Compile the C++ file
g++ "$1" -o "$FILENAME"

# Check if the compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful. Running the program..."
    # Run the executable
    ./"$FILENAME"
else
    echo "Compilation failed."
fi

