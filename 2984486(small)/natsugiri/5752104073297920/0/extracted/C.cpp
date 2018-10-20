#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<map>
using namespace std;

typedef long long LL;

int A[1024];
int main() {
    int T;
    scanf("%d", &T);

    for (int tc=1; tc<=T; tc++) {
	int N;
	scanf("%d", &N); // N must be 1000
	for (int i=0; i<N; i++) scanf("%d", A+i);

	int cnt = 0;
	for (int i=0; i<N; i++) {
	    if (A[i] == -1) continue;
	    vector<int>v;
	    for (int j=A[i]; j!=i; j=A[j]) v.push_back(j);
	    cnt += v.size();
	    for (int j=0; j<(int)v.size(); j++) A[v[j]] = -1;
	    A[i] = -1;
	}
//	cerr << cnt << endl;
	printf("Case #%d: %s\n", tc, cnt%2 == N % 2 ? "BAD" : "GOOD");
	
    }
    return 0;
}
