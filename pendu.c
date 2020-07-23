#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<time.h>
#include"pendu.h"

int main(int argc, char *argv[])
{
	int premier = 0;
	int beginPart = 0;
	while(beginPart == 0)
	{
		start(&beginPart);
		int theme;
		choseTheme(&theme);
		int echec = 0;
		int congrate = 0;
		printf("Bienvenue dans le jeu du pendu!\n");
		char word[100];
		for(int i =0; i<strlen(word); i++)
		{
			word[i] = ' ';
		}
		chooseWord(word, theme);
		char motCache[100];
		for(int i=0; i<strlen(motCache); i++)
		{
			motCache[i]=' '; 
		}
		strcpy(motCache, word);
		int longueurMot = strlen(word)-1;
		for(int i=0; i<longueurMot; i++)
		{
			if(word[i]== '-')
			{
			motCache[i]= '-';
			} 
			else if(word[i] == '\'')
			{
			motCache[i] = '\'';	
			}
			else if(word[i]== ' ')
			{
			motCache[i] = ' ';
			}
			else
			{
			motCache[i]= '*';
			}
		}
		printf("\n\tVoici le mot a trouver:\n\n\t%s\n\n",motCache);
		while((echec<11) && (congrate==0))
		{
			saisir(word, motCache,longueurMot, &echec, &congrate);
		}
	}
}	
int choseTheme(int *theme)
{
	printf("Veuillez choisir le theme du jeu:\n1 = Grand dictionnaire hasardeux\n2 = Harry Potter\n3 = Kaamelott\n4 = Arts\n");
	scanf("%d",theme);
}

char chooseWord(char *word, int theme)
{
	FILE* dico = NULL;
	int caractereActuel = 0;
	int nombreMot = 0;
	switch(theme)
	{
	case 1:
	dico = fopen("dico","r");
	break;
	case 2:
	dico = fopen("dicoPotter","r");
	break;
	case 3:
	dico = fopen("dicoKaamelott","r");
	break;
	case 4:
	dico = fopen("dicoArt","r");
	break;
	default:
	printf("error, no theme open");
	exit(0);
	break;	
	}
	if(dico != NULL)
	{
		do
		{
		
		caractereActuel = fgetc(dico);
		if(caractereActuel == '\n')
		{
		nombreMot = nombreMot+1;
		}	
		}while(caractereActuel != EOF);
		
		rewind(dico);
		srand(time(NULL));
		int nbre = rand()%(nombreMot-1);
		int i = 0;
		while(i<nbre)
		{
			int carac = fgetc(dico);
			if(carac == '\n')
			{
				i++;
			}
		}
		fgets(word, 100, dico);		
		fclose(dico);
	}
}

int saisir(char *mot, char *cache, int longueurMot, int *echec, int *congrate)
{
	printf("saisissez une lettre: ");
	char lettre = lireCaractere();
	char *exist = NULL;
	exist = strchr(mot, lettre);
	if(exist != NULL)
	{
		gagne(longueurMot, lettre, mot, cache, congrate, echec);
	}
	else
	{
		perd(cache, echec);
	}
}

int perd(char *motCache, int *echec)
{
	*echec = *echec+1; 
	dessin(echec);
	if(*echec<11)
	{
		printf("Il n'y a pas cette lettre dans le mot... \n\n");
		printf("\n\tVoici le mot a trouver:\n\n\t%s\n\n",motCache);
	}
}
int gagne(int longueurMot, char lettre, char *mot, char *motCache, int *congrate, int *echec)
{
	for(int i =0; i<longueurMot; i++)
	{
		if(lettre == mot[i])
		{
			motCache[i] = lettre;
		}
	}
	dessin(echec);
	printf("Oui! cette lettre est bien presente dans le mot!\n\n");
	printf("\n\tVoici le mot a trouver:\n\n\t%s\n\n",motCache);
	char *isWin = NULL;
	isWin = strchr(motCache, '*');
	if(isWin == NULL)
	{
		*congrate = 1;
		printf("Felicitation, vous avez trouve le mot!\n\n\n");
	}
}
int start(int *beginPart)
{
	printf("Commencer une nouvelle partie?\n 0: oui\n 1: non\n");
	scanf("%d",beginPart);
	if(*beginPart == 1)
	{	
		printf("Au revoir!\n\n");
		exit(0);
	}
}

char lireCaractere()
{
	char caractere =0;
	scanf("%d",caractere);
	caractere = getchar();
	caractere = toupper(caractere);
	while(getchar() != '\n');
	return caractere;
}

int dessin(int *echec) 
{
	int nombreEchec = *echec;
	switch(nombreEchec)
	{
	case 0:
	printf(" ");
	break;
	case 1:
	printf("\n\n\t|\n\t|\n\t|\n\t|\n\t|\n\n");
	break;
	case 2:
	printf("\n\n\t|\n\t|\n\t|\n\t|\n\t|__\n\n");
	break;
	case 3:
	printf("\n\t_______\n\t|\n\t|\n\t|\n\t|\n\t|__\n\n");
	break;
	case 4:
	printf("\n\t_______\n\t|/\n\t|\n\t|\n\t|\n\t|__\n\n");
	break;
	case 5:
	printf("\n\t_______\n\t|/   |\n\t|\n\t|\n\t|\n\t|__\n\n");
	break;
	case 6:
	printf("\n\t_______\n\t|/   |\n\t|    O\n\t|\n\t|\n\t|__\n\n");
	break;
	case 7:
	printf("\n\t_______\n\t|/   |\n\t|    O\n\t|    |\n\t|\n\t|__\n\n");
	break;
	case 8:
	printf("\n\t_______\n\t|/   |\n\t|    O\n\t|    |\n\t|   /\n\t|__\n\n");
	break;
	case 9:
	printf("\n\t_______\n\t|/   |\n\t|    O\n\t|    |\n\t|   / \\\n\t|__\n\n");
	break;
	case 10:
	printf("\n\t_______\n\t|/   |\n\t|    O\n\t|   -|\n\t|   / \\\n\t|__\n\n");
	break;
	case 11:
	printf("\n\t_______\n\t|/   |\n\t|    O\n\t|   -|-\n\t|   / \\\n\t|__          ... perdu...\n\n");
	break;
	default:
	printf("error");
	break;
	} 
}

