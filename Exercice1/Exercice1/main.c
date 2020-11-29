#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include"tab.h"
#define TAB2SIZE 100
#define TAILLEAJOUT 50


int main() {
	int MyTab1[10];											// initialisation d'un tableau à 10 valeurs
	initTab(MyTab1, 10);									// appel de la fonction ayant pour agument MyTab1 et 10
	int* MyTab2 = NULL;
	int tabsize = TAB2SIZE;
	int nbElts = 20;
	MyTab2 = (int*)malloc(TAB2SIZE * sizeof(int));			// allocation d'une memoire de taille TAB2SIZE * celle d'un int
	int* MyTab3 = NULL;										// création d'un pointeur
	for (int i = 0; i < 10; i++) {							// création d'une boucle for pour pouvoir print  tous les éléments
		printf(" %d ", MyTab1[i]);
	}
	afficheTab(MyTab1, 10, 5);								//  affiche le Tableau ayant pour argument MyTab1, 10 et 5
	printf("\n");
	if (MyTab2 != NULL) {
		initTab(MyTab2, TAB2SIZE);							// initialisation Tab2 à zéro
		for (int j = 0; j < 20; j++) {
			MyTab2[j] = j + 1;								// Donne les valeurs de 1 à 20 aux 20 premiers termes
		}
		afficheTab(MyTab2, TAB2SIZE, nbElts);					 // Affiche les 20 premiers termes du tableau 2
		printf("\n");
		MyTab3 = ajoutElementDansTableau(MyTab2, &tabsize, &nbElts, 150); // pointeur pointe sur la sortie de nombre élément
		afficheTab(MyTab3, TAB2SIZE, nbElts);							// Affiche le nouveau tableau avec la valeur ajouté
	}
	else {
		printf("mémoire insuffisante");
		return -1;

	}

	free(MyTab3);
}
