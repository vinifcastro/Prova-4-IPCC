#include <stdio.h>
#include <stdlib.h>

/**
* Essa função recebe um valor "n" e retorna um ponteiro
* para uma matriz quadrada de inteiros com dimensão nxn.
* A memória é alocada dinamicamente com uma estrutura
* bidimensional.
*
* @param n Dimensão da matriz
* @return int** Ponteiro para a matriz
*/
int ** cria_matrix( int n );

/**
* Essa função recebe um ponteiro para uma matriz alocada
* dinamicamente e libera a memória ocupada por ela.
*
* @param m Ponteiro para a matriz
*/
void destroi_matrix( int ** m );

/**
* Essa função recebe um ponteiro para uma matriz alocada
* dinamicamente, sua dimensão n e retorna 1 caso essa
* matriz seja uma matriz de permutação ou 0 caso contrário.
* Além disso, essa função também calcula a soma de todos os
* elementos da matriz e a retorna via referência pelo
* ponteiro "soma".
*
* @param m Ponteiro para a matriz
* @param n Dimensão da matriz
* @param soma Ponteiro para inteiro que retornará a soma dos
* elementos da matriz
* @return int 1 caso a matriz seja de permutação
* e 0 caso contrário
*/
int ePermutacao( int ** m, int n, int * soma );

int n;

int main(){
    int ** a = NULL;
    int i, k, soma=0, x;
    scanf("%d", &n);
    a = cria_matrix( n );
    x = ePermutacao( a, n, &soma );
    printf ("%d\n", n);
    if(x==1) printf("PERMUTACAO\n");
    else printf("NAO E PERMUTACAO\n");
    printf("%d\n", soma);
    destroi_matrix( a );
    return 0;
}

int ** cria_matrix( int n ){
    int i, k;
    int ** A = NULL;
    A = (int **) malloc(n*sizeof(int *));
    for (i=0; i<n; i++) A[i] = (int *) malloc(n*sizeof(int));
    for (i=0; i<n; i++){
        for (k=0; k<n; k++){
            scanf("%d", &(A[i][k]));
        }
    }
    return A;
}

void destroi_matrix( int ** m ){
    int i;
    for (i=0; i<n; i++){
        free(m[i]);
    }
    free(m);
}

int ePermutacao( int ** m, int n, int * soma ){
    int i, cont, k, permut=1, elementunit;
    for (i=0; i<n; i++){
        cont = 0;
        for (k=0; k<n; k++){
            if (m[i][k] == 0) cont++;
            *soma += m[i][k];
        }
        if (cont!=(n-1)) permut = 0;
        else{
            elementunit=0;
            for (k=0; k<n; k++)
                if (m[i][k] != 0) elementunit+=m[i][k];
            if (elementunit!=1) permut = 0;
        }
    }
    if (permut == 0) return permut;
    for (i=0; i<n; i++){
        cont = 0;
        for (k=0; k<n; k++){
            if (m[k][i] == 0) cont++;
        }
        if (cont!=(n-1)) permut = 0;
        else{
            elementunit=0;
            for (k=0; k<n; k++)
                if (m[k][i] != 0) elementunit+=m[k][i];
            if (elementunit!=1) permut = 0;
        }
    }
    return permut;
}