#!/bin/bash

A=0
B=15
trials=11

for((j=3;j<=$trials;j++));
do
	time ./floyd $j.txt
done
