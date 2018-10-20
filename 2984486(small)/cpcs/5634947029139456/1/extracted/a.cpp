#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
char s[100];

ll make(char *s) {
ll x = 0;
	for (;*s; ++s) {
		x <<= 1;
		x |= (*s - '0');
	}
	return x;
}

int count(ll x) {
int r = 0;
	while (x) {
		if (x & 1) {
			++r;
		}
		x >>= 1;
	}
	return r;
}

int main() {
int zz;
	scanf("%d",&zz);
	for (int z = 1; z <= zz; ++z) {
		int n,m;
		scanf("%d%d",&n,&m);
		vector<ll> have,want;
		for (int i = 0; i < n; ++i) {
			scanf("%s",s);
			have.push_back(make(s));
			
		}
		for (int i = 0; i < n; ++i) {
			scanf("%s",s);
			want.push_back(make(s));
		}
		sort(want.begin(), want.end());
		int answer = -1;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				ll mask = have[i] ^ want[j];
				int may = count(mask);
				if ((answer < 0) || (answer > may)) {
					vector<ll> temp;
					for (int k = 0; k < n; ++k) {
						temp.push_back(have[k] ^ mask);
					}	
					sort(temp.begin(), temp.end());	
					if (temp == want) {
						answer = may;
					}
				}
			}
		}	 	
		printf("Case #%d: ",z);
		if (answer >= 0) {
			printf("%d\n",answer);
		}
		else {
			puts("NOT POSSIBLE");
		}
	}
	return 0;
}
		
