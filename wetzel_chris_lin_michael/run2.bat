#!/bin/bash

trials=98

rm timings.txt

for((j=1;j<=$trials;j++));
do
	./floyd $j.txt $j
	rm $j.txt
done

