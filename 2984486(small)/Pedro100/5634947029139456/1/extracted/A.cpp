#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cfloat>
#include <climits>
#include <cctype>
#include <cmath>
#include <cassert>
#include <ctime>

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <complex>
#include <limits>
#include <functional>
#include <numeric>

using namespace std;

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }

typedef long long ll;
#define fr(i,a,b)  for(int i=a;i<b;i++)
#define rep(x,y) for(int(x)=(0);(x)<(y);(x)++)
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define dbg(x) cout << #x << " == " << x << endl
#define _ << " _ " <<

ll s1[200];
ll s2[200];
char s[200];
bool mk[200];

int main(){
	int cas;
	scanf("%d",&cas);
	fr(u,1,cas+1){
		int n, l;
		scanf("%d %d",&n,&l);
		rep(i,n){
			scanf("%s",s);
			s1[i]=0;
			rep(j,l) if(s[j]=='1') s1[i] |= 1LL<<j;
		}
		rep(i,n){
			scanf("%s",s);
			s2[i]=0;
			rep(j,l) if(s[j]=='1') s2[i] |= 1LL<<j;
		}
		
		int rsp=2*l;
		rep(i,n){
			ll mudar=s1[0]^s2[i];
			int cnt=1;
			rep(j,n) mk[j]=false;
			mk[i]=true;
			
			fr(j,1,n){
				rep(z,n){
					if(mk[z]==false && (s1[j]^s2[z])==mudar){
						mk[z]=true;
						cnt++;
						break;
					}
				}
			}
			if(cnt==n){
				int t=0;
				rep(j,l){
					if(mudar&(1LL<<j)) t++;
				}
				if(t<rsp) rsp=t;
			}
		}
		
		printf("Case #%d: ",u);
		if(rsp>l) printf("NOT POSSIBLE");
		else printf("%d",rsp);
		printf("\n");
	}
	
	return 0;
}
