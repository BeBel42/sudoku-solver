#!/bin/bash

if [ $# -eq "1" ]
then
    LIST="123456789"
    GRID=$1
elif [ $# -eq "2" ]
then
    LIST=$1
    GRID=$2
else
    echo "Error: invalid number of arguments."
    exit 1
fi

./Sources/a.out "$LIST" "$GRID"
