#!/bin/bash

A=0
B=15
trials=98

for((j=1;j<=$trials;j++));
do
	python3 data_gen.py  100 $j $A $B
done
