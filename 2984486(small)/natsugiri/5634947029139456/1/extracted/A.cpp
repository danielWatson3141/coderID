#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

LL s2ll(const string&s) {
    LL r=0;
    for (int i=0; i<(int)s.size(); i++) r = (r<<1) + s[i]-'0';
    return r;
}
int popcount(LL x) {
    x -= (x>>1) & 0x5555555555555555LL;
    x = (x & 0x3333333333333333LL) + (x>>2 & 0x3333333333333333LL);
    x = (x + (x>>4)) & 0x0F0F0F0F0F0F0F0FLL;
    x += x>>8;
    x += x>>16;
    x += x>>32;
    return x & 0xFF;
}

vector<LL> read(int N) {
    string S;
    vector<LL>v;
    for (int i=0; i<N; i++) {
	cin >> S;
	v.push_back(s2ll(S));
    }
    sort(v.begin(), v.end());
    return v;
}
    
int main() {
    int T;
    scanf("%d", &T);

    for (int tc=1; tc<=T; tc++) {
	int N, L;
	scanf("%d%d", &N, &L);
	vector<LL> A = read(N), B = read(N);

	int ans = N+99;

	for (int i=0; i<N; i++) {
	    const LL mask = A[i]^B[0];
	    vector<LL>v;
	    for (int k=0; k<N; k++) v.push_back(mask^B[k]);
	    sort(v.begin(), v.end());
	    
	    if (A == v) ans = min(ans, popcount(mask));
	}

	printf("Case #%d: ", tc);
	if (ans == N+99) puts("NOT POSSIBLE");
	else printf("%d\n", ans);
	
    }
    return 0;
}
