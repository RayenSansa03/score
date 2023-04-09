// fonction.c

#include "fonction.h"

void saveScore(ScoreInfo s, char *fileName) {
  FILE *f = fopen(fileName, "a");
  if (f == NULL) {
    printf("Impossible d'ouvrir le fichier %s\n", fileName);
    return;
  }
  fprintf(f, "%d %d %s\n", s.score, s.temps, s.playerName);
  fclose(f);
}

void bestScore(char *filename, ScoreInfo trois[]) {
  FILE *f = fopen(filename, "r");
  if (f == NULL) {
    printf("Impossible d'ouvrir le fichier %s\n", filename);
    return;
  }
  int count = 0;
  while (fscanf(f, "%d %d %s\n", &trois[count].score, &trois[count].temps, trois[count].playerName) != EOF) {
    count++;
    if (count == 3) break; // On ne charge que les trois meilleurs scores
  }
  fclose(f);
  // On trie le tableau selon le score et le temps
  for (int i = 0; i < 2; i++) {
    for (int j = i + 1; j < 3; j++) {
      if (trois[i].score < trois[j].score || (trois[i].score == trois[j].score && trois[i].temps > trois[j].temps)) {
        ScoreInfo tmp = trois[i];
        trois[i] = trois[j];
        trois[j] = tmp;
      }
    }
  }
}

void afficherBest(SDL_Surface *ecran, ScoreInfo t[]) {
  SDL_Color textColor = {255, 255, 255};
  TTF_Font *font = TTF_OpenFont("arial.ttf", 20);
  SDL_Surface *surf[3];
  char ch[100];
  for (int i = 0; i < 3; i++) {
    sprintf(ch, "%s %d %d", t[i].playerName, t[i].score, t[i].temps);
    surf[i] = TTF_RenderText_Solid(font, ch, textColor);
  }
  // Affichage des surfaces
  for (int i = 0; i < 3; i++) {
    SDL_Rect position = {0, 100*i, 0, 0};
    SDL_BlitSurface(surf[i], NULL, ecran, &position);
  }
  // Libération de la mémoire allouée aux surfaces
  for (int i = 0; i < 3; i++) {
    SDL_FreeSurface(surf[i]);
  }
  TTF_CloseFont(font);
}

