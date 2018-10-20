#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <vector>
#include <set>
#include <map>
#include <deque>
#include <string>
#include <bitset>

#include <algorithm>
#include <cmath>
using namespace std;

int const MAX_N = 200;
int const INT_INF = 1000000000;

long long init_states[MAX_N],nec_states[MAX_N],s[MAX_N];
string st;

long long make_it(const string &st) {
	long long x = 0;
	for (int i=0; i<st.length(); i++)
		x = x*2 + (st[i]-'0');
	return x;
}

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int t;
	scanf("%d",&t);
	for (int qq=0; qq<t; qq++) {
		int n,l;
		scanf("%d%d",&n,&l);
		for (int i=0; i<n; i++) {
			cin>>st;
			init_states[i] = make_it(st);
		}
		for (int i=0; i<n; i++) {
			cin>>st;
			nec_states[i] = make_it(st);
		}

		sort(init_states,init_states + n);
		sort(nec_states,nec_states + n);

		printf("Case #%d: ",qq+1);

		int mn = INT_INF;
		
		for (int i=0; i<n; i++)
			for (int fr=0; fr<n; fr++) {
				long long fr_x = init_states[fr];
				long long to_x = nec_states[i];
				long long swp = 0;
				for (int j=0; j<l; j++)
					if (((fr_x>>j)&1) != ((to_x>>j)&1))
						swp |= 1LL<<j;
				for (int e=0; e<n; e++) {
					s[e] = init_states[e];
					for (int j=0; j<l; j++)
						if ((swp>>j)&1)
							s[e] ^= 1LL<<j;
				}
				sort(s,s+n);
				int Ok = 1;
				for (int e=0; e<n; e++)
					if (s[e]!=nec_states[e])
						Ok = 0;
				if (Ok) {
					int cnt = 0;
					for (int j=0; j<l; j++)
						cnt += (swp>>j)&1;
					mn = min(mn,cnt);
				}
			}

		if (mn >= INT_INF)
			printf("NOT POSSIBLE");
		else
			printf("%d",mn);
		printf("\n");
	}

	return 0;
}