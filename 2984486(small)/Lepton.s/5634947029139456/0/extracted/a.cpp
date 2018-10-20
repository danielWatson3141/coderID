#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>
#include <functional>
#include <map>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <list>
#include <numeric>
using namespace std;
const double PI = 3.14159265358979323846;
const double EPS = 1e-12;
const int INF = 1<<25;
typedef pair<int,int> P;
typedef long long ll;
typedef unsigned long long ull;

void trf(vector<ll> &d, vector<string> &s){
	for(int i = 0; i < s.size(); i++){
		for(int j = 0; j < s[0].size(); j++){
			d[i] <<= 1;
			d[i] |= (s[i][j]-'0');
		}
	}
}

int btct(ll x){
	int res = 0;
	while(x){
		res += x&1;
		x>>=1;
	}
	return res;
}

int main(){
	int T;
	cin>>T;
	for(int Case = 1; Case <= T; Case++){
		int N,L;
		cin>>N>>L;
		vector<string> s1(N),s2(N);
		for(int i = 0; i < N; i++){
			cin>>s1[i];
		}
		for(int i = 0; i < N; i++){
			cin>>s2[i];
		}
		vector<ll> d1(N,0),d2(N,0);
		trf(d1,s1);
		trf(d2,s2);
		sort(d2.begin(),d2.end());
		int res = INF;
		for(int i = 0; i < N; i++){
			ll xr = d1[0]^d2[i];
			vector<ll> d3(N,0);
			for(int j = 0; j < N; j++){
				d3[j] = d1[j]^xr;
			}
			sort(d3.begin(),d3.end());
			if(d2==d3){
				res = min(res,btct(xr));
			}
		}
		printf("Case #%d: ",Case);
		if(res==INF) puts("NOT POSSIBLE");
		else printf("%d\n",res);

	}
	return 0;
}

