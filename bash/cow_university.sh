#!/bin/bash

for i in $(seq 2 $1); do
	n=$(factor $i | awk 'NF==2{print $2}')
	if [ "$n" != "" ]; then
		clear
		cowsay -b $n
		sleep 1
	fi
done
