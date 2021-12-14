#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
				/**
				 * Tutaj należy umieścić właściwą implemntację.
				 */

				/* To ponizej jest przepisaniem b do x. Nalezy to poprawic! */

		/*		int i;
				for (i =0; i < x->r; i++) {
								x->data[i][0] = b->data[i][0];
				}

				return 0;*/
    if (mat->r != mat->c)
        return 2;

    int i, j;
    for(i = (mat->r)-1; i >= 0; i--) {

        x->data[i][0] = b->data[i][0];
        /* przypisanie wartosci z macierzy b */

        for(j = i+1; j < mat->c && j < mat->r; j++)
            x->data[i][0] = x->data[i][0] - mat->data[i][j] * x->data[j][0];

        if (mat->data[i][i] == 0)
            return 1;

        x->data[i][0] = x->data[i][0] / mat->data[i][i];
        /* dzielenie aby otrzymac x */
    }
    return 0;
}


