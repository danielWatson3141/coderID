#include<sys/types.h>
#include<dirent.h>

#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cassert>
#include<sstream>
#include<cmath>
#include<fstream>
#include<map>
#include<tr1/unordered_map>
#include<set>
#include<tr1/unordered_set>

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define ABS(x) ((x) > 0 ? (x) : -(x))
#define lt(x, y)	((x) >= 0 && ((x) < (y) || (y) < 0))

#define SWAP(x, y) {(x) += (y); (y) = (x) - (y); (x) -= (y);}

#define EPS 1e-6
#define PI 3.14159265358979323846

using namespace std;

int T, N;

int adj[15][15];
int deg[15];

int nacount[6];

bool valid(int x){

	x++;

	while(x){
		if((x - 1) && (1 & x))	return false;

		x >>= 1;
	}

	return true;
}

int main()
{
	cin >> T;

	for(int caseidx = 1; caseidx <= T; caseidx++){

		cin >> N;

		memset(adj, 0, sizeof(adj));

		for(int i = 0; i < N - 1; i++){

			int a, b;
			cin >> a >> b;
			a--, b--;

			adj[a][b] = adj[b][a] = 1;
		}

		int ret = N - 1;
		for(long dmask = 0; dmask < ((long)1 << N) - 1; dmask++){

			long k = dmask;
			int ndel = 0;
			while(k){
				ndel += (1 & k);
				k >>= 1;
			}

			//printf("mask = %ld\n", dmask);

			if(ndel == N - 1)	continue;

			//if(!valid(N - ndel))	continue;

			long survive = (((long)1 << N) - 1) ^ dmask;

			//printf("survie = %ld\n", survive);

			memset(deg, 0, sizeof(deg));
			int nedge = 0;
			int nnode = N - ndel;

			for(int i = 0; i < N; i++){
				if(1 & (survive >> i)){

					for(int j = i + 1; j < N; j++){

						if(1 & (survive >> j)){
							deg[j] += adj[i][j];
							deg[i] += adj[i][j];

							nedge += adj[i][j];

						}
					}
				}
			}

			if(nedge + 1 - nnode)	continue;

			memset(nacount, 0, sizeof(nacount));

			for(int i = 0; i < N; i++){
				if(1 & (survive >> i)){
					if(deg[i] > 3 || !deg[i])	goto end;

					nacount[deg[i]]++;
				}
			}

			if(nacount[2] == 1) ret = MIN(ret, ndel);

end:
			continue;
		}

		printf("Case #%d: %d\n", caseidx, ret);

	}
	return 0;
}

// vi: ts=2 sw=2
