#!/bin/bash
OUTPUT_FILE=$(echo $1 | sed 's/\.c/\.o/g')
cc -Wall -o $OUTPUT_FILE $1
