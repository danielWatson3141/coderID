#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include<cstring>
#include<climits>
// Input macros
#define s(n)  scanf("%d",&n)
#define sc(n) scanf("%c",&n)
#define sl(n) scanf("%lld",&n)
#define sf(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
// Useful constants
#define INF (int)1e9
#define EPS 1e-9
// Useful hardware instructions
#define bitcount __builtin_popcount
#define gcd __gcd
// Useful container manipulation / traversal macros
#define forall(i,a,b) for(int i=a;i<b;i++)
#define foreach(v, c) for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define all(a) a.begin(), a.end()
#define in(a,b) ( (b).find(a) != (b).end())
#define pb push_back
#define fill(a,v) memset(a, v, sizeof a)
#define sz(a) ((int)(a.size()))
#define mp make_pair
// Some common useful functions
#define maX(a,b) ((a) > (b) ? (a) : (b))
#define miN(a,b) ( (a) < (b) ? (a) : (b))
#define checkbit(n,b) ( (n >> b) & 1)
#define DREP(a) sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind) (lower_bound(all(arr),ind)-arr.begin())
using namespace std;
vector<string> Data;
vector<string> Req;
int main(){
	int T;
	int N,L;
	bool flag,finalflag;
	s(T);
	int count;
	for(int k=1;k<=T;k++){
		count=0;
		s(N);s(L);
		Data.clear();
		Data.resize(N);
		Req.clear();
		Req.resize(N);
		for(int i=0;i<N;i++){
			cin>>Data[i];
		}
		for(int i=0;i<N;i++){
			cin>>Req[i];
		}
		sort(Req.begin(),Req.end());
		finalflag=false;
		for(int j=0;j<L;j++){
			sort(Data.begin(),Data.end());
			flag=false;
			for(int i=0;i<N;i++){
				if(Data[i][j]!=Req[i][j]){
					flag=true;
					break;
				}
			}
			if(flag){
				count++;
				for(int i=0;i<N;i++){
					Data[i][j]=(Data[i][j]=='0'?'1':'0');
				}
				sort(Data.begin(),Data.end());
				flag=false;
				for(int i=0;i<N;i++){
					if(Data[i][j]!=Req[i][j]){
						flag=true;
						break;
					}
				}
				if(flag){
					finalflag=true;
					break;
				}
			}
		}
		if(finalflag){
			printf("Case #%d: NOT POSSIBLE\n",k);
		}
		else{
			printf("Case #%d: %d\n",k,count);
		}
	}
	return 0;
}
