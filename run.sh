#!/usr/bin/env zsh

base="$1"
infile=`find . -name "$1.cpp"`
outfile="bin/$1"
shift 1

g++ "$infile" -o "$outfile" -Wextra -Wall -pedantic
$outfile $@
