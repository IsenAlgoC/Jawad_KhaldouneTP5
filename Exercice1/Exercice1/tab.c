#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include "tab.h"
#define TAILLEAJOUT 50
#define TAB2SIZE 100

int initTab(int* tab, int size) {

	if ((tab != 0) && (size > 0)) {
		for (int i = 0; i < size; i++) {
			tab[i] = 0;
		}
		return (size);
	}
	else {
		return -1;
	}
}

int afficheTab(int* tab, int size, int nbElts) {
	if ((tab != NULL) && (size > 0) && (nbElts <= size)) {
		for (int i = 0; i < nbElts; i++) {
			printf(" %d ", tab[i]);
		}
		return 0;

	}
	else {
		return -1;
	}
}

int* ajoutElementDansTableau(int* tab, int* size, int* nbElts, int element) {
	if (*nbElts == *size) {
		int* nouveautab = (int*)realloc(tab, (TAILLEAJOUT + TAB2SIZE) * sizeof(int));						// on crée un tableau tampon auquel on ajoute la mémoire
		if (nouveautab == NULL) {
			return NULL;																					//si ça ne fonctionne  pas on renvoie -1
		}
		else {																								// sinon on remplace tab par nouveautab et on change les valeurs.
			tab = nouveautab;
			tab[*nbElts] = element;
			*nbElts = *nbElts + 1;
		}
	}
	else {
		tab[*nbElts] = element;
		*nbElts = *nbElts + 1;
	}
	return tab;
}
