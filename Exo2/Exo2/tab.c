#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include"tab.h"
#define TAILLEINITIALE 100



TABLEAU newArray() {
	TABLEAU tab;
	tab.elt = (int*)malloc(TAILLEINITIALE * sizeof(int));
	tab.eltsCount = 0;
	tab.size = TAILLEINITIALE;
	if (tab.elt != NULL) {													// on observe si les conditions sont respectées.
		for (int i = 0; i < TAILLEINITIALE; ++i) {							// initialisation du tableau à zéro.
			tab.elt[i]= 0;
		}
		return tab;
	}
	else {
		tab.elt = NULL;
		return tab;
	}
}



int incrementArraySize(TABLEAU* tab, int incrementValue) {
	if ((*tab).elt == NULL || ((*tab).size + incrementValue) <= 0) {							  // on observe si les conditions sont respectées.
		return -1;
	}

	else {
		int* bis = (*tab).elt;																		// création d'une variable au cas où la réallocation ne fonctionnerait pas.
		(*tab).elt = (int*)realloc((*tab).elt, ((*tab).size + incrementValue) * sizeof(int));		// reallou la taille de la memoire.
		if ((*tab).elt == NULL) {
			(*tab).elt = *bis;
			return -1;
		}
		else {
			for (int i = (*tab).size; i < ((*tab).size + incrementValue); i++) {
				(*tab).elt[i] = 0;																	// initialise à zéro les nouveaux termes du tableau
			}
			(*tab).size = (*tab).size + incrementValue;												// Augmentation de la taille du tableau
			return (*tab).elt;
		}

	}
}
int setElement(TABLEAU* tab, int pos, int element) {
	if (((*tab).elt == NULL) || (pos < 1)) {													 // on observe si les conditions sont respectées.
		return 0;
	}
	else {
		if (pos - 1 < (*tab).size) {															// si la position est onférieur a la taille du tableau
			(*tab).elt[pos - 1] = element;														// on met l'élément à la position voulu
		}
		else {
			incrementArraySize(tab, (pos - 1) - (*tab).size);									// sinon on augmente la taille du tableau
			if (incrementArraySize(tab, (pos - 1) - (*tab).size) == -1) {						// on vérifie que l'augmentation a augmenté
				return 0;
			}
			else {																				// si ça a fonctionné 
				(*tab).elt[pos - 1] = element;													// on met l'élément à la position voulu
			}
			return pos;
		}
	}
}

int displayElements(TABLEAU* tab, int startPos, int endPos) {
	if (((*tab).elt == NULL) || (startPos < 1) || (startPos > (*tab).size) || (endPos < 1) || (endPos > (*tab).size)) {		// on vérifie les conditions
		return -1;
	}
	else {
		int tmp = 0;
		if (startPos > endPos) {
			tmp = startPos;
			startPos = endPos;
			endPos = tmp;
		}
		if (startPos == endPos) {
			printf("pos %d : %d \n", startPos, (*tab).elt[startPos - 1]);
			return 0;	
		}
		for (int i = (startPos - 1); i < endPos; i++) {                      // sinon on affiche tout entre start et end
			printf("pos %d : %d \n", i + 1, (*tab).elt[i]);
		}
		return 0;
	}
}


int deleteElements(TABLEAU* tab, int startPos, int endPos) {
	if (((*tab).elt == NULL) || (startPos < 1) || (startPos > (*tab).size) || (endPos < 1) || (endPos > (*tab).size)) {		// on vérifie les conditions
		return -1;
	}
	else {
		int tmp = 0;
		if (startPos > endPos) {
			tmp = startPos;
			startPos = endPos;
			endPos = tmp;
		}
		if (startPos == endPos) {

	}
}