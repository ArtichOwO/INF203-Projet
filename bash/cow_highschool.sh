#!/bin/bash

for i in $(seq 1 $1); do
	clear
	cowsay -y $(echo $i^2 | bc)
	sleep 1
done
