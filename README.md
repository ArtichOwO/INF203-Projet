# INF203 - Projet Cowsay
> Arthur Lepley, Léo Grange

## Build

Targets:
- `newcow.exe`
- `wildcow.exe`
- `reading_cow.exe`
- `tamagotchi_cow.exe`

```bash
cd cowsay && make
```

## Usage

### `newcow.exe`

```sh
Usage: newcow.exe [-e EYES] [-T TONGUE] [-d] [-g] [-p] [-s] [-t] [-w] [-y] [-h] INPUT 

`cowsay' rewritten with less options lolwut

	-e	EYES	Define eyes to use (use 2 chars)
	-T	TONGUE	Define tongue to use (use 1 char)
	-d			Dead cow
	-g			Greedy cow
	-p			Paranoïd cow
	-s			Stoned cow
	-t			Tired cow
	-w			Wired cow
	-y			Young cow
	-h			Show this help
		INPUT	Input text to say
```

### `wildcow.exe`

```sh
Usage: wildcow.exe [-r] [-T LENGTH] [-e] [-h] INPUT 

Animated `cowsay'

	-r			Running cow
	-T	LENGTH	Make the cow's tail grow
	-e			oO
	-h			Show this help
		INPUT	Input text to say
```

### `reading_cow.exe`

```sh
Usage: reading_cow.exe [-h] [FILE] 

File-eater `cowsay'

	-h			Show this help
		FILE	Input file (defaults to stdin)
```

### `tamagotchi_cow.exe`

Run the game.
