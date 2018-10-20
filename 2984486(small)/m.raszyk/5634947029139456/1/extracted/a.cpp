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
int n, l;
vector<string> out;
vector<string> temp;
vector<string> dev;
int akt;
int best;

int main()
{
	cin >> T;

	for(int q=1; q<=T; q++) {
		cin >> n >> l;
		out.resize(n);
		temp.resize(n);
		dev.resize(n);
		for(int i=0; i<n; i++) cin >> out[i];
		for(int i=0; i<n; i++) for(int j=0; j<l; j++) out[i][j]-='0';
		for(int i=0; i<n; i++) cin >> dev[i];
		for(int i=0; i<n; i++) for(int j=0; j<l; j++) dev[i][j]-='0';
		sort(dev.begin(), dev.end());
		best=127;
		for(int x=0; x<n; x++) {
			for(int i=0; i<n; i++) temp[i]=out[i];
			akt=0;
			for(int j=0; j<l; j++) {
				if(temp[0][j]!=dev[x][j]) {
					akt++;
					for(int i=0; i<n; i++) temp[i][j]=1-temp[i][j];
				}
			}
			sort(temp.begin(), temp.end());
			int ok=1;
			for(int i=0; i<n; i++) {
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
