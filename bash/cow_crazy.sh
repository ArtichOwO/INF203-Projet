#!/bin/bash

lookandsay() {
    n=$1

    [ $n -eq 1 ] && echo 1
    [ $n -eq 2 ] && echo 11

    s=11

    for i in $(seq 3 $(expr $n + 1)); do
        s+="#"
        l=$(expr $(echo $s | wc -c) - 1)

        cnt=1
        tmp=""

        for j in $(seq 1 $(expr $l - 1)); do
            sjm1=${s:$(expr $j - 1):1}

            if [ ${s:$j:1} != $sjm1 ]; then
                tmp+="$cnt$sjm1"
                cnt=1
            else
                cnt=$(expr $cnt + 1)
            fi
        done

        s=$tmp
    done

    echo $s
}

sequence=1
for i in $(seq 2 $1); do sequence+=" $(lookandsay $i)"; done

cowsay -e "°°" "Look-and-say: $sequence!"
