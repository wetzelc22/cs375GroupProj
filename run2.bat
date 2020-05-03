#!/bin/bash

A=0
B=15
trials=1000

rm timings.txt

for((j=3;j<=$trials;j++));
do
	./floyd $j.txt
	rm $j.txt
done

