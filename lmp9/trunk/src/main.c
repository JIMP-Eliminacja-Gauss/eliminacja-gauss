#include "gauss.h"
#include "backsubst.h"
#include "mat_io.h"
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char ** argv) {
	int res;
	Matrix * A = readFromFile(argv[1]);
	Matrix * b = readFromFile(argv[2]);
	Matrix * x;
    
	if (A == NULL) return -1;
	if (b == NULL) return -2;
    if (A->r != A->c) {
        printf("Macierz nie jest kwadratowa\n");
        return -3;
    }
    if (A->r != b->r) {
        printf("Nieprawidlowy format macierzy!\n");
        return 4;
    }
	printToScreen(A);
	printToScreen(b);

	res = eliminate(A,b);
    printf("\n\n\n\n Po eliminacji: \n\n\n\n");
    printToScreen(A);
    printToScreen(b);
	x = createMatrix(b->r, 1);
	if (x != NULL) {
		res = backsubst(x,A,b);
        if (res == 1) {
            fprintf(stderr, "Dzielenie przez zero!\n");
            freeMatrix(x);
            return -1;
        }
        else if (res == 2) {
            fprintf(stderr, "Nieprawidlowy rozmiar macierzy!\n"
                            "Proszę wprowadzic macierz kwadratowa\n");
            freeMatrix(x);
            return -2;
        }

		printToScreen(x);
	  freeMatrix(x);
	} else {
					fprintf(stderr,"Błąd! Nie mogłem utworzyć wektora wynikowego x.\n");
	}



	freeMatrix(A);
	freeMatrix(b);

	return 0;
}
