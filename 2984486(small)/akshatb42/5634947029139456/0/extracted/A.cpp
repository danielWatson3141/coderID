#include<iostream>
#include<stdio.h> 
#include<algorithm>
#include<math.h>
#include<vector>
#include<set>
#include<stdlib.h>
#include<string.h>
#include<queue>
#include<stack>
#include<assert.h>
#include<limits.h>
#define tr(i) for(typeof(i.begin()) it=i.begin(); it!=i.end();it++)
#define pb push_back
#define mp make_pair
#define REP(i,n) for(int i=0;i<n;i++)
#define rep(i,s,n) for(int i=s;i<n;i++)
#define s(n) scanf("%d",&n)
#define XX first
#define X first
#define Y second
#define all(a) a.begin(),a.end()
#define YY second.first
#define ZZ second.second
#define fill(a,b) memset(a,b,sizeof(a))
#define DREP(a) sort(all(a)); a.erase(unique(all(a)),a.end());
#define INDEX(arr,ind) (lower_bound(all(arr),ind)-arr.begin())
#define SZ(x) (int)(x.size())
#define lin(val,j) (DP[j]-val*D[j])
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define MN 150

int dca[MN],dcb[MN];
bool swa[MN];
vector<string> A,B;
int mn; bool found=false;
int N,L;
void go(int i)
{
	if(i==L) 
	{
		vector<string> a;
		int cn=0;
		REP(i,N)
		{
			string t=A[i];
			REP(j,L)
			{
				if(swa[j])
				{
					if(A[i][j]=='0') t[j]='1';
					else t[j]='0';
				}
			}
			//cout<<t<<endl;
			a.pb(t);
		}
		REP(j,L) cn+=swa[j];
		sort(all(a));
		REP(i,N) if(a[i]!=B[i]) return;
		found=true;
		mn=min(mn,cn);
		return;
	}
	if(dca[i]==dcb[i])
	{	
		swa[i]=false;
		go(i+1);
	}
	if(dca[i]==(N-dcb[i]))
	{
		swa[i]=true;
		go(i+1);
		swa[i]=false;
	}
}
int main()
{	
	int T; s(T);
	REP(c,T)
	{
		s(N); s(L);
		printf("Case #%d: ",c+1);
		REP(i,L) dca[i]=dcb[i]=0;
		A.clear(); B.clear();
		string t;
		REP(i,N) { cin>>t;A.pb(t); }
		REP(i,N) { cin>>t;B.pb(t); }
		sort(all(B));
		REP(i,N)
		{
			REP(j,L)
			{
				if(A[i][j]=='1') dca[j]++;
				if(B[i][j]=='1') dcb[j]++;
			}
		}
		REP(i,L) swa[i]=false;
		mn=L; found=false;
		go(0);
		if(!found) printf("NOT POSSIBLE\n");
		else printf("%d\n",mn);
	}
	return 0;
}
