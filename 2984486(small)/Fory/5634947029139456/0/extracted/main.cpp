#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

int mejor;

int N;
int64_t aparato[150], conector[150];

int cmp_int64_t(const void *_a, const void *_b) {
    return (*(int64_t*)_a)-(*(int64_t*)_b);
}

void busca(int64_t bit, int costo) {
    if (costo>=mejor)
        return;
    if (bit==0)
    {
        //todo listo, checar que la mascara este bien
        qsort((void*)&conector[0],N,sizeof(conector[0]),cmp_int64_t);
        for (int i=0;i<N;i++) {
            if (conector[i]!=aparato[i])
                return;
        }
        mejor = costo;
        return;
    }
    busca(bit>>1, costo);
    for (int i=0;i<N;i++) {
        conector[i] ^= bit;
    }
    busca(bit>>1, costo+1);
    for (int i=0;i<N;i++) {
        conector[i] ^= bit;
    }
}

int main(int argc, char* argv[])
{
	int T;
	#define NOMBRE_ARCHIVO "A-small-attempt0"
	string nombre = NOMBRE_ARCHIVO;
	nombre = nombre + ".in";
	FILE *entrada = fopen(nombre.c_str(), "rt");
	nombre = NOMBRE_ARCHIVO;
	nombre = nombre + ".out";
	FILE *salida = fopen(nombre.c_str(), "wt");
	fscanf(entrada,"%d", &T);
	for (int t=1;t<=T;t++) {
	    int64_t L;
	    int Laux;
        fscanf(entrada, "%d %d\n", &N,&Laux);
        printf( "%d %d\n", N,Laux);
        L=Laux;
        char aux[50];
        for (int i = 0; i < N; i++) {
            fscanf(entrada, "%s", aux);
            printf("%s ", aux);
            int64_t bit = 1;
            conector[i]=0;
            for (int j = 0; j<L;j++) {
                if (aux[j]=='1') {
                    conector[i]|=bit;
                }
                bit<<=1LL;
            }
            printf("(%ld) ", conector[i]);
        }
        printf("\n");
        for (int i = 0; i < N; i++) {
            fscanf(entrada, "%s", aux);
            printf("%s ", aux);
            int64_t bit = 1;
            aparato[i]=0;
            for (int j = 0; j<L;j++) {
                if (aux[j]=='1') {
                    aparato[i]|=bit;
                }
                bit<<=1LL;
            }
            printf("(%ld) ", aparato[i]);
        }
        printf("\n");
        mejor = L+1;
        qsort((void*)&aparato[0],N,sizeof(aparato[0]),cmp_int64_t);
        busca(1LL<<(L-1), 0);
        if (mejor>L) {
            fprintf(salida, "Case #%d: NOT POSSIBLE\n",t);
        } else {
            fprintf(salida, "Case #%d: %d\n",t, mejor);
        }
		fflush(salida);
	}
	fclose(salida);
	fclose(entrada);
	return 0;
}

