#!/bin/bash

lookandsay() {
    n=$1

    # Si n = 1 ou 2, directement donner la valeur
    [ $n -eq 1 ] && echo 1
    [ $n -eq 2 ] && echo 11

    s=11

    # De 3 à n+1
    for i in $(seq 3 $(expr $n + 1)); do
        # Ajouter un caractère temporaire
        # pour être sûr de faire
        # une itération supplémentaire
        s+="#"
        # Longueur de s - 1
        l=$(expr $(echo $s | wc -c) - 1)

        cnt=1
        tmp=""

        # Traitement du terme précédent
        # pour trouver le suivant (de 1 à l-1)
        for j in $(seq 1 $(expr $l - 1)); do
            # s[j-1]
            sjm1=${s:$(expr $j - 1):1}

            # Si s[j] != s[j-1]
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

# Calculer d'un seul coup la suite avant d'appeler cowsay
sequence=1
for i in $(seq 2 $1); do sequence+=" $(lookandsay $i)"; done

cowsay -e "°°" "Look-and-say: $sequence!"
