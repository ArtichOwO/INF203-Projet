#!/bin/bash

for i in $(seq 1 10); do
	clear
	cowsay -y $i
	sleep 1
done
