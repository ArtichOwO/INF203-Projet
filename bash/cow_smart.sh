#!/bin/bash

cowsay -e $(printf "%02i" $(echo "$1" | bc)) "$1"
