# INF203 - Projet Cowsay
> Léo Grange, Arthur Lepley

Les sources sont disponibles à [cette adresse](https://github.com/ArtichOwO/INF203-Projet).

## Préliminaires

|Argument|Description|
|:-:|:-|
|`-n`|Désactiver le retour à la ligne automatique.|

```sh
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

```sh
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

```sh
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

```sh
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
