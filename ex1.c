#include <stdio.h>
#include <stdlib.h>

#define SMIN 1200

typedef struct {
    int matricula;
    int idade;
    int numFilhos;
    char sexo;
    double salario;
} FUNCIONARIO;

int main(){
    int n, i, mmm3sm=0, qtdmmmf = 0, qtdhmmf = 0, m47am2sm=0;
    FUNCIONARIO * empresa = NULL;
    double mediageralf = 0, mediagerali = 0, rendapercapta;
    scanf("%d%*c", &n);
    empresa = (FUNCIONARIO *) malloc(n*sizeof(FUNCIONARIO));
    for (i=0;i<n;i++) {
        scanf("%d%*c%d%*c%d%*c%c%*c%lf%*c", &(empresa[i].matricula), &(empresa[i].idade), &(empresa[i].numFilhos), &(empresa[i].sexo), &(empresa[i].salario));
        mediageralf += (double)empresa[i].numFilhos;
        mediagerali += (double)empresa[i].idade;
    }
    mediageralf = mediageralf/(double) n;
    mediagerali = mediagerali/(double) n;
    for (i=0;i<n;i++){
        rendapercapta = empresa[i].salario/(double)(empresa[i].numFilhos+1);
        if (((double)empresa[i].idade>mediagerali) && (empresa[i].salario>3*SMIN)) mmm3sm++;
        if ( (empresa[i].sexo=='F' || empresa[i].sexo=='f') && ((double)empresa[i].numFilhos>mediageralf) ) qtdmmmf++;
        if ( (empresa[i].sexo=='M' || empresa[i].sexo=='m') && ((double)empresa[i].numFilhos>mediageralf) ) qtdhmmf++;
        if ( (empresa[i].idade>47) && (rendapercapta<2*SMIN) ) m47am2sm++;
    }
    printf("%d %d %d %d\n", mmm3sm, qtdmmmf, qtdhmmf, m47am2sm);
    
    free(empresa);
    return 0;
}