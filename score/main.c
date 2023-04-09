// main.c

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "fonction.h"

int main(int argc, char *argv[]) {
  SDL_Surface *ecran = NULL;
  SDL_Init(SDL_INIT_VIDEO);
  TTF_Init();

  // Initialisation de la fenêtre d'affichage
  ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  SDL_WM_SetCaption("Meilleurs scores", NULL);

  ScoreInfo scores[3];

  // Chargement des scores depuis le fichier
  bestScore("scores.txt", scores);

  // Affichage des scores
  // Affichage des scores
  afficherBest(ecran, scores);
  SDL_Flip(ecran);

  

  // Sauvegarde d'un nouveau score
  ScoreInfo s;
  s.score = 1000;
  s.temps = 60;
  strcpy(s.playerName, "Joueur1");
  saveScore(s, "scores.txt");

  // Rechargement des scores depuis le fichier
  bestScore("scores.txt", scores);

  // Affichage des nouveaux scores
  afficherBest(ecran, scores);
  SDL_Flip(ecran);

  

  SDL_Quit();
  return 0;
}


