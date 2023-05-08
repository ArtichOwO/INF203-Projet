#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

#include <print_msg.h>
#include <show_cow.h>
#include <animation.h>

// Yeux dans différents états
#define E_LIFEROCKS "^^"
#define E_LIFESUCKS "@@"
#define E_BYEBYELIFE "xx"

// Langue dans différents états
#define T_LIFEROCKS " "
#define T_LIFESUCKS " "
#define T_BYEBYELIFE "U"

// Impression de la vache dans différents états
void show_cow_state(int fitness) {
	if (4 <= fitness && fitness <= 6) {
		show_cow(E_LIFEROCKS, T_LIFEROCKS);
	} else if ((1 <= fitness && fitness <= 3) 
			|| (7 <= fitness && fitness <= 9)) {
		show_cow(E_LIFESUCKS, T_LIFESUCKS);
	} else {
		show_cow(E_BYEBYELIFE, T_BYEBYELIFE);
	}
}

// Mettre à jour le stock de nourriture
void stock_update(int * stock, int lunchfood) {
	int crop = rand()%6 - 3;
	*stock -= lunchfood - crop;
	if (*stock < 0)
		*stock = 0;
}

// Mettre à jour la santé de la vache
void fitness_update(int * fitness, int lunchfood) {
	int digestion = rand()%3;
	*fitness += lunchfood - digestion;
}

int main(int argc, char const *argv[]) {
	unsigned int lunchfood;
	unsigned int ctime;
	int stock = 5;
	int fitness = 5;
	char * time_msg = malloc(17);

	time_t t;
	srand ((unsigned)time(&t));

	for (ctime = 0; 0 < fitness && fitness < 10; ctime++) {
		update();
		sprintf(time_msg, "Time: %i", ctime);
		print_msg_str(time_msg);
		show_cow_state(fitness);

		printf("Current stock: %i\n"
			   "Give how much food: ", stock);
		/* `lunchfood` pourrait être
		 * plus élevé que `stock`
		 * mais ça n'a pas d'importance
		 * puisque `stock_update` remet à zéro
		 * `stock` si elle est négative
		 */
		scanf("%i", &lunchfood);

		if (lunchfood == 713705) {
			gotoxy(5, 10);
			printf("☀☀");
			fflush(stdout);
			sleep(2);
			lunchfood = 0;
		}

		if (lunchfood == 0xDEADBEEF) {
			char * phrases[][3] = { 
				{ "HA HA HA!", "OO", " " },
				{ "Oh, wow...", "óò", " " },
				{ "im die", "@@", " " },
				{ "thank u 4evah", "@@", "U" }
			};

			for (int i = 0; i < 4; i++) {
				update();
				print_msg_str(phrases[i][0]);
				show_cow(phrases[i][1], phrases[i][2]);
				sleep(2);
			}

			fitness = -1000;
		}

		stock_update(&stock, lunchfood);
		fitness_update(&fitness, lunchfood);
	}

	update();
	sprintf(time_msg, "Score = %i", ctime);
	print_msg_str(time_msg);
	show_cow_state(fitness);

	return 0;
}
