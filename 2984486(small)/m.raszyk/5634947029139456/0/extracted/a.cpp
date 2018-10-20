#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

int T;
int N, L;
vector<string> out;
vector<string> temp;
vector<string> dev;
int akt;
int best;

int main()
{
	cin >> T;

	for(int q=1; q<=T; q++) {
		cin >> N >> L;
		out.resize(N);
		temp.resize(N);
		dev.resize(N);
		for(int i=0; i<N; i++) cin >> out[i];
		for(int i=0; i<N; i++) for(int j=0; j<L; j++) out[i][j]-='0';
		for(int i=0; i<N; i++) cin >> dev[i];
		for(int i=0; i<N; i++) for(int j=0; j<L; j++) dev[i][j]-='0';
		sort(dev.begin(), dev.end());
		best=127;
		for(int m=0; m<(1<<L); m++) {
			for(int i=0; i<N; i++) temp[i]=out[i];
			akt=0;
			for(int j=0, k=m; k>0; j++, k>>=1) {
				if(k&1) {
					akt++;
					for(int i=0; i<N; i++) {
						temp[i][j]=1-temp[i][j];
					}
				}
			}
			sort(temp.begin(), temp.end());
			int ok=1;
			for(int i=0; i<N; i++) {
				if(temp[i]!=dev[i]) {
					ok=0;
					break;
				}
			}
			if(ok) best=min(akt, best);
		}
		if(best==127) printf("Case #%d: NOT POSSIBLE\n", q);
		else printf("Case #%d: %d\n", q, best);
	}

	return 0;
}
