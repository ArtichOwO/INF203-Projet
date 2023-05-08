#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

#include <print_msg.h>
#include <show_cow.h>
#include <animation.h>

#define E_LIFEROCKS "^^"
#define E_LIFESUCKS "@@"
#define E_BYEBYELIFE "xx"

#define T_LIFEROCKS " "
#define T_LIFESUCKS " "
#define T_BYEBYELIFE "U"

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

void stock_update(int * stock, int lunchfood) {
	int crop = rand()%6 - 3;
	*stock -= lunchfood - crop;
	if (*stock < 0)
		*stock = 0;

	#ifdef DEBUG
	printf("crop=%i\n", crop);
	#endif // DEBUG
}

void fitness_update(int * fitness, int lunchfood) {
	int digestion = rand()%3;
	*fitness += lunchfood - digestion;

	#ifdef DEBUG
	printf("digestion=%i\n", digestion);
	#endif // DEBUG
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
		#ifndef DEBUG
		update();
		#endif // DEBUG
		sprintf(time_msg, "Time: %i", ctime);
		print_msg_str(time_msg);
		show_cow_state(fitness);

		#ifdef DEBUG
		printf("fitness=%i\n", fitness);
		#endif // DEBUG

		printf("Current stock: %i\n"
			   "Give how much food: ", stock);
		scanf("%i", &lunchfood);

		stock_update(&stock, lunchfood);
		fitness_update(&fitness, lunchfood);
	}

	#ifndef DEBUG
	update();
	#endif // DEBUG
	sprintf(time_msg, "Score = %i", ctime);
	print_msg_str(time_msg);
	show_cow_state(fitness);

	return 0;
}
