#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main( int argc, char **argv ) {
    if( argc != 5 ) {
        printf("nieprawidlowa liczba argumentow - wymagane podanie 4 argumentow\n");
        printf("(liczba wierszy) (liczba kolumn) (nazwa pliku do macierzy A) (nazwa pliku do macierzy B)\n");
        return 1;
    }
    int w = atoi(argv[1]);
    int k = atoi(argv[2]);
    FILE *m_a = fopen( argv[3], "w" );
    FILE *m_b = fopen( argv[4], "w" );
    if( m_a == NULL || m_b == NULL ) {
        printf("blad, nie moge pisac do pliku\n");
        return 2;
    }
    fprintf( m_a, "%d %d \n", w, k );
    fprintf( m_b, "%d 1 \n", w );
    srand(time(NULL));
    for( int i = 0; i < w; i++ ) {
        for( int j = 0; j < k; j++ )
            fprintf( m_a, "%g ", (double)rand() / RAND_MAX );
        fprintf( m_a, "\n" );
    }
    for( int i = 0; i < w; i++ ) {
        fprintf( m_b, "%g", 10*(double)rand() / RAND_MAX );
        fprintf( m_b, "\n" );
    }

    return 0;
}
