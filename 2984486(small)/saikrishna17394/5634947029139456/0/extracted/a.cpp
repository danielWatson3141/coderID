#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#define lli long long int
#define ii pair<int,int>
#define mp make_pair
#define mod 1000000007
#define inf 999999999

using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int t,n,l,ans;

string A[150],B[150];
int mask[150];

int main() {
	// freopen("inp", "r", stdin);
	// A-small-attempt0
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("out.txt", "w", stdout);

	inp(t);

	for(int a=1;a<=t;a++) {
		inp(n);
		inp(l);

		for(int i=0;i<n;i++)
			cin>>A[i];

		map<string,int> m;

		for(int i=0;i<n;i++) {
			cin>>B[i];
			m[B[i]]=-1;
		}

		ans=inf;

		int val=0;

		for(int i1=0;i1<n;i1++) {
			val=0;
			for(int j=0;j<l;j++) {
				if(A[0][j]==B[i1][j])
					mask[j]=0;
				else
					mask[j]=1;
				val+=mask[j];
				// cout<<mask[j]<<" ";
			}
			// cout<<" "<<ans<<endl;

			bool ok=true;

			for(int i=0;i<n;i++) {
				string s;

				for(int j=0;j<l;j++) {
					if(mask[j]==0)
						s+=A[i][j];
					else {
						if(A[i][j]=='0')
							s+='1';
						else
							s+='0';
					}
				}

				if(m.find(s)==m.end()) {
					ok=false;
					break;
				}

				m[s]=i1;

			}

			if(!ok)
				continue;
			
			for(int i=0;i<n;i++) {
				if(m[B[i]]!=i1) {
					ok=false;
					break;
				}
			}
			if(!ok)
				continue;
			ans=min(ans,val);
		}


		if(ans==inf)
			printf("Case #%d: NOT POSSIBLE\n",a );
		else
			printf("Case #%d: %d\n",a,ans);
	}




	return 0;
}