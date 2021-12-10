#include "gauss.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
    int n;
    int k;
    int r;
    int c;

/*     1 1 1 1 1
*      0 1 1 1 1    
*      0 0 1 1 1
*      0 0 0 1 1
*      0 0 0 0 1
*      0 0 0 0 0        
*
*      [r] - wiersze    [c] - kolumny    
*       r, c,   **data   
*      A[i][j]   A[i+1][j]      A[i+1] - (A[i] *  A[i+1] / A[i])  (A[i][j] * (A[i+1][j] / A[i][j]))   */

    for( r = 1; r < (mat->r); r++ ) {
        n = 1;
        k = r;
        if( r > mat->c )
            k = mat->c;
        /*zerowanie pierwszego elementu w wierszu*/
        for( c = 0; c < (mat->c); c++ ) {
            mat->data[r][c] = mat->data[r][c] - ( mat->data[0][c] * ( mat->data[r][0] / mat->data[0][0] ) );
        }
        b->data[r][0] = b->data[r][0] - ( (b->data[0][0]) * ( mat->data[r][0] / mat->data[0][0] ) );
        while( n != k ) {  /* bo n maksymalnie moze byc rowne (c-1) zeby nie mazalo po pamieci */
            for( c = 0; c < (mat->c); c++ )  {
            mat->data[r][c] = mat->data[r][c] - ( mat->data[n][c] * ( mat->data[r][n] / mat->data[n][n] ) );
            }
            b->data[r][0] = b->data[r][0] - ( b->data[n][0] * ( mat->data[r][n] / mat->data[n][n] ) );
            n++;
        }
    }
		return 0;
}

