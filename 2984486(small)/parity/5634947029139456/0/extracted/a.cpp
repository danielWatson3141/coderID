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

int T, N, L;

long long str2int(string a){

	long long ret = 0;
	for(int i = L - 1; i >= 0; i--){

		if(a[i] == '1')
			ret ^= ((long long)1 << i);
	}

	return ret;
}


int main()
{
	cin >> T;

	for(int caseidx = 1; caseidx <= T; caseidx++){

		cin >> N >> L;

		vector<long long>X;
		vector<long long>Y;


		for(int i = 0; i < N; i++){
			string t;
			cin >> t;
			X.push_back(str2int(t));
		}

		for(int i = 0; i < N; i++){
			string t;
			cin >> t;
			Y.push_back(str2int(t));
		}

		sort(Y.begin(), Y.end());

		int total = 1 << L;

		int ret = L + 1;
		for(int i = 0; i < total; i++){

			int j = i;

			vector<long long>Z = X;

			int pos = 0;
			int cand = 0;
			while(j){

				if(j & 1){

					cand++;
					for(int k = 0; k < N; k++){
						Z[k] ^= ((long long)1 << pos);
					}
				}
				j >>= 1;

				pos++;
			}

			sort(Z.begin(), Z.end());

			int good = 1;
			for(int k = 0; k < N && good; k++){
			
				if(Z[k] - Y[k])	good = 0;
			}

			if(good)	ret = MIN(ret, cand);
		}

		printf("Case #%d: ", caseidx);

		if(ret <= L)	printf("%d", ret);
		else	printf("NOT POSSIBLE");

		printf("\n");
	}
	return 0;
}

// vi: ts=2 sw=2
