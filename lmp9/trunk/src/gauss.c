#include "gauss.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
    int i;
    int j;
    int n;

    for( i = 0; i < (mat->r - 1); i++ ) {
        if( mat->data[i][i] == 0 )
            return 1;
        for( j = i+1; j < mat->r;  j++ ) {
            double temp = mat->data[j][i] / mat->data[i][i];
            b->data[j][0] = b->data[j][0] - temp*(b->data[i][0]);
            for( n = 0; n < mat->c; n++ )
                mat->data[j][n] = mat->data[j][n] - temp*(mat->data[i][n]);
            
        }
    }
    return 0;
}

