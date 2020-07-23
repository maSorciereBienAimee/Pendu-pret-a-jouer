#ifndef PENDU
#define PENDU
int dessin(int *echec);
char lireCaractere();
int start(int *beginPart);
char *afficher(int longueur);
char chooseWord(char *word, int theme);
int choseTheme(int *theme);
int saisir(char *mot, char *cache, int longueurMot, int *echec, int *congrate);
int gagne(int longueurMot, char lettre, char *mot, char *motCache, int *congrate, int *echec);
int perd(char *motCache, int *echec);
#endif

