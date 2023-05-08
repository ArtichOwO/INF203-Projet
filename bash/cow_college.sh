#!/bin/bash

a=0
b=1

for i in $(seq 0 $1); do
	clear
	cowsay " $a "
	c=$(expr $a + $b)
	a=$b
	b=$c
	sleep 1
done
