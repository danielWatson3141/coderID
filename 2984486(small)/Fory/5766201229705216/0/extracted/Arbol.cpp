#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

int N;
char arista[1001][1001];
int h[1001];

struct TInfo {
int NumNodos, Arreglar;
};

struct TValidos {
    TInfo Datos;
    TValidos *Siguente;
};

TInfo busca(int Nodo, int Padre) {
    TInfo R, RA, RB;
    R.Arreglar = 0;
    R.NumNodos = 1;
    RA.Arreglar = 10000;
    RA.NumNodos = 0;
    RB.Arreglar = 10001;
    RB.NumNodos = 0;
        //contar cuantos hijos tiene
    int hijos = 0;
    //borrar todos los hijos
    for (int i=1;i<=N;i++) {
        if (i==Padre) {
            continue;
        }
        if (arista[Nodo][i]==1) {
            hijos++;
			TInfo Raux;
            Raux = busca(i,Nodo);
            R.Arreglar+=Raux.NumNodos;
			R.NumNodos+=Raux.NumNodos;
            // ver si vale la pena conservarlo
            if ((RA.NumNodos-RA.Arreglar)<=(Raux.NumNodos-Raux.Arreglar)) {
                // cambiar
                RB = RA;
                RA = Raux;
            } else if ((RB.NumNodos-RB.Arreglar)<=(Raux.NumNodos-Raux.Arreglar)) {
                //cambiar
                RB = Raux;
            }
        }
    }
    if (hijos<2) {
        // no se pueden agregar nodos
        return R;
    }
    //tomar los mejores 2
    R.Arreglar-=RA.NumNodos;
    R.Arreglar+=RA.Arreglar;
    R.Arreglar-=RB.NumNodos;
    R.Arreglar+=RB.Arreglar;
    return R;
}

int main(int argc, char* argv[])
{
	int T;
	#define NOMBRE_ARCHIVO "B-small-attempt1"
	string nombre = NOMBRE_ARCHIVO;
	nombre = nombre + ".in";
	FILE *entrada = fopen(nombre.c_str(), "rt");
	nombre = NOMBRE_ARCHIVO;
	nombre = nombre + ".out";
	FILE *salida = fopen(nombre.c_str(), "wt");
	fscanf(entrada,"%d", &T);
	for (int t=1;t<=T;t++) {
        fscanf(entrada, "%d", &N);
        for (int i=1;i<=N;i++) {
            h[i]=0;
            for (int j = 1;j<=N;j++) {
                arista[i][j]=0;
            }
        }
        for (int i=1;i<N;i++)
        {
            int a,b;
            fscanf(entrada,"%d", &a);
            fscanf(entrada,"%d", &b);
            arista[a][b]=1;
            arista[b][a]=1;
            h[a]++;
            h[b]++;
        }
        TInfo R;
        R = busca(1,0);
        for (int i=2;i<=N;i++) {
            TInfo Ractual;
            Ractual = busca(i,0);
            if (Ractual.Arreglar<R.Arreglar) {
                R = Ractual;
            }
        }
        fprintf(salida, "Case #%d: %d\n", t, R.Arreglar);
        fflush(salida);
	}
	fclose(salida);
	fclose(entrada);
	return 0;
}

