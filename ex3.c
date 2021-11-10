#include <stdio.h>
#include <stdlib.h>

typedef struct {
int numJogo;
int numero[6];
} CARTELA;

int main(){
    int n, i, k, sena, quadra, quina, cont, z, j=0;
    int conc, sorteio[6];
    CARTELA * jogos = NULL;
    scanf("%d", &n);
    jogos = (CARTELA *) malloc(n*sizeof(CARTELA));
    for (i=0; i<n; i++){
        scanf("%d", &(jogos[i].numJogo));
        for (k=0;k<6;k++)
            scanf("%d", &(jogos[i].numero[k]));
    }
    scanf("%d", &conc);
    for (k=0;k<6;k++)
        scanf("%d", &sorteio[k]);
    
    for (i=0; i<n; i++){
        cont = 0;
        for (k=0;k<6;k++){
            for (z=0; z<6;z++){
                if (sorteio[z] == jogos[i].numero[k]) cont++;
            }
        }
        if (cont == 4){
            printf("QUADRA %d:", jogos[i].numJogo);
            for (k=0;k<6;k++){
                for (z=0; z<6;z++){
                    if (sorteio[z] == jogos[i].numero[k]) printf(" %d", jogos[i].numero[k]);
                }
            }
            printf("\n");
            j++;
        }
        if (cont == 5){
            printf("QUINA %d:", jogos[i].numJogo);
            for (k=0;k<6;k++){
                for (z=0; z<6;z++){
                    if (sorteio[z] == jogos[i].numero[k]) printf(" %d", jogos[i].numero[k]);
                }
            }
            printf("\n");
            j++;
        }
        if (cont == 6){
            printf("SENA %d:", jogos[i].numJogo);
            for (k=0;k<6;k++){
                for (z=0; z<6;z++){
                    if (sorteio[z] == jogos[i].numero[k]) printf(" %d", jogos[i].numero[k]);
                }
            }
            printf("\n");
            j++;
        }
    }

    if (j==0) printf("NENHUMA CARTELA PREMIADA PARA O CONCURSO %d\n", conc);

    free(jogos);
    return 0;
}