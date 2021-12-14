#include "gauss.h"
#include <math.h>
/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */

int diag_elem_choice( Matrix *mat, Matrix *b, int j ) {
    if (mat->data[j][j] != 0) return -2;

    for (int i = j+1; i < mat->r; i++) {
        if (mat->data[i][j] != 0)   
            return i;
    }
    return -1;

}


int eliminate(Matrix *mat, Matrix *b){
    int i;
    int j;
    int n;
    double temp;
    
    for( i = 0; i < (mat->r - 1); i++ ) {
        n = diag_elem_choice( mat, b, i );
        if( n == -1 )
            return 1;
        if( n == -2 ) {
            ;
        } else {
            temp = b->data[i][0];
            b->data[i][0] = b->data[n][0];
            b->data[n][0] = temp;
            for( j = 0; j < mat->c; j++ ) {
                temp = mat->data[i][j];
                mat->data[i][j] = mat->data[n][j];
                mat->data[n][j] = temp;
            }
        }
        
        for( j = i+1; j < mat->r;  j++ ) {
            temp = mat->data[j][i] / mat->data[i][i];
            b->data[j][0] = b->data[j][0] - temp*(b->data[i][0]);
            for( n = 0; n < mat->c; n++ )
                mat->data[j][n] = mat->data[j][n] - temp*(mat->data[i][n]);    
        }
    }
    return 0;
}
