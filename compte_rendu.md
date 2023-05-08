# INF203 - Projet Cowsay
> Léo Grange, Arthur Lepley

Les sources sont disponibles à [cette adresse](https://github.com/ArtichOwO/INF203-Projet).

## Préliminaires

|Argument|Description|
|:-:|:-|
|`-n`|Désactiver le retour à la ligne automatique.|

```
$ figlet "AMIRITE?" | cowsay -n
________________________________________________
/     _    __  __ ___ ____  ___ _____ _____ ___  \
|    / \  |  \/  |_ _|  _ \|_ _|_   _| ____|__ \ |
|   / _ \ | |\/| || || |_) || |  | | |  _|   / / |
|  / ___ \| |  | || ||  _ < | |  | | | |___ |_|  |
| /_/   \_\_|  |_|___|_| \_\___| |_| |_____|(_)  |
\                                                /
------------------------------------------------
    \   ^__^
     \  (oo)\_______
        (__)\       )\/\
            ||----w |
            ||     ||
```

|Argument|Description|
|:-:|:-|
|`-W`|Définir la colonne à laquelle faire un retour à la ligne.|

```
$ cowsay -W 10 "CAPS LOCK IS CRUISE CONTROL FOR COOL"
 ___________
/ CAPS LOCK \
| IS CRUISE |
| CONTROL   |
\ FOR COOL  /
 -----------
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
                ||----w |
                ||     ||
```

|Argument|Description|Yeux|Langue|
|:-:|:-|:-:|:-:|
|`-b`|Vache robot.|`(==)`|Pas d'effet.|
|`-d`|Vache morte.|`(xx)`|`U`|
|`-g`|Vache avare.|`($$)`|Pas d'effet.|
|`-p`|Vache paranoïaque.|`(@@)`|Pas d'effet.|
|`-s`|Vache complètement défoncée.|`(**)`|`U`|
|`-t`|Vache fatiguée.|`(--)`|Pas d'effet.|
|`-w`|Vache en mode cablé.|`(OO)`|Pas d'effet.|
|`-y`|Vache rajeunie.|`(..)`|Pas d'effet.|

|Argument|Description|
|:-:|:-|
|`-e YEUX`|Définir de nouveaux yeux.|
|`-T LANGUE`|Définir une nouvelle langue.|

```
$ cowsay -e "♥♥" -T U "Let's All Love Lain"
 _____________________
< Let's All Love Lain >
 ---------------------
        \   ^__^
         \  (♥♥)\_______
            (__)\       )\/\
             U  ||----w |
                ||     ||
```

|Argument|Description|
|:-:|:-|
|`-l`|Lister les cowfiles dans `$COWPATH`.|
|`-f FICHIER`|Choisir un cowfile différent.|

```
$ cowsay -f vader "DO NOT WANT"
 _____________
< DO NOT WANT >
 -------------
        \    ,-^-.
         \   !oYo!
          \ /./=\.\______
               ##        )\/\
                ||-----w||
                ||      ||

               Cowth Vader
```

## Bash

### Kindergarten cow

```bash
#!/bin/bash

for i in $(seq 1 10); do
    clear
    cowsay -y $i
    sleep 1
done
```

### Primary school cow

```bash
#!/bin/bash

for i in $(seq 1 $1); do
    clear
    cowsay -y $i
    sleep 1
done
```

### Highscool cow

```bash
#!/bin/bash

for i in $(seq 1 $1); do
    clear
    cowsay -y $(echo $i^2 | bc)
    sleep 1
done
```

### College cow

```bash
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
```

### University cow

```bash
#!/bin/bash

for i in $(seq 2 $1); do
    n=$(factor $i | awk 'NF==2{print $2}')
    if [ "$n" != "" ]; then
        clear
        cowsay -b $n
        sleep 1
    fi
done
```

### Smart cow

```bash
#!/bin/bash

cowsay -e $(printf "%02i" $(echo "$1" | bc)) "$1"
```

### Crazy cow

```bash
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
```

## C

Les fichiers se trouvent dans le dossier [/cowsay/](https://github.com/ArtichOwO/INF203-Projet/tree/master/cowsay).

**Makefile**

### `newcow`

**newcow.c**
```c
```
