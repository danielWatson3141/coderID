#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <iostream>
#include <ctime>
#include <cassert>
#include <sstream>
 
using namespace std;
 
#define INF 0x3f3f3f3f
#define ll long long

vector<string> vet,h,t;

int main() {
	int nt,nteste=1,n,L,ans;
	cin>>nt;
	while (nt--) {
		cin>>n>>L;
		vet.resize(n);
		h.resize(n);
		for (int i=0; i<n; i++)
			cin>>h[i];
		for (int i=0; i<n; i++)
			cin>>vet[i];
		ans = INF;
		int N = 1<<L;
		sort(vet.begin(),vet.end());
		for (int S=0; S<N; S++) {
			t = h;
			int cnt = 0;
			for (int i=0; i<L; i++)
				if ((S & (1<<i)) != 0) {
					cnt++;
					for (int j=0; j<n; j++)
						t[j][i] = (t[j][i] == '0' ? '1' : '0');
				}
			
			sort(t.begin(),t.end());
			if (t == vet) ans = min(ans,cnt);
		}
		printf("Case #%d: ",nteste++);
		if (ans == INF) printf("NOT POSSIBLE\n");
		else printf("%d\n",ans);
	}
	
	return 0;
}
