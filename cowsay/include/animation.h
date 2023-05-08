#ifndef ANIMATION_H
#define ANIMATION_H

// Macros pour réduire le nombre d'appels
#define update() printf("\033[H\033[J")
#define gotoxy(X, Y) printf("\033[%d;%dH", X, Y)

#endif // ANIMATION_H
