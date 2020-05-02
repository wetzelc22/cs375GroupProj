#!/bin/bash

A=0
B=15
trials=6

for((j=3;j<=$trials;j++));
do
	time python data_gen.py  $j $A $B
done
