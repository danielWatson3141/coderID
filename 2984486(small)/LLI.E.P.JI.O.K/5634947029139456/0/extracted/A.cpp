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
		for (int j=0; j<(1<<l); j++) {
			int cur = 0;
			int x = j;
			while (x) {
				cur += x&1;
				x>>=1;
			}

			for (int i=0; i<n; i++) {
				s[i] = init_states[i];
				for (int q=0; q<l; q++)
					if ((j>>q)&1)
						s[i] ^= 1<<q;
			}

			sort(s,s+n);

			int Ok = 1;
			for (int i=0; i<n; i++)
				if (s[i] != nec_states[i])
					Ok = 0;

			if (Ok)
				mn = min(mn,cur);
		}

		if (mn >= INT_INF)
			printf("NOT POSSIBLE");
		else
			printf("%d",mn);
		printf("\n");
	}

	return 0;
}