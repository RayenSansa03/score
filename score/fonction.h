// fonction.h

#ifndef FONCTION_H
#define FONCTION_H

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

typedef struct {
  int score;
  int temps;
  char playerName[20];
} ScoreInfo;

void saveScore(ScoreInfo s, char *fileName);
void bestScore(char *filename, ScoreInfo trois[]);
void afficherBest(SDL_Surface *ecran, ScoreInfo t[]);

#endif // FONCTION_H

