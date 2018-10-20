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
vector< vector<int> > Graph;
vector<bool> Visited;
int bfs(int node){
	Visited[node]=true;
	int Total=1;
	if(sz(Graph[node])<2){
		return Total;
	}
	else{
		vector<int> Values;
		for(int j=0;j<sz(Graph[node]);j++){
			if(!Visited[Graph[node][j]]){
				Values.pb(bfs(Graph[node][j]));
			}
		}
		if(sz(Values)<2){
			return Total;
		}
		else{
			make_heap(Values.begin(),Values.end());
			Total+=Values.front();
			Values[0]=INT_MIN;
			make_heap(Values.begin(),Values.end());
			Total+=Values.front();
			return Total;
		}
	}
}
int main(){
	int T,N;
	int a,b;
	s(T);
	int maxcount;
	int count;
	for(int k=1;k<=T;k++){
		maxcount=INT_MIN;
		s(N);
		Graph.clear();
		Graph.resize(N+1);
		Visited.resize(N+1);
		for(int i=1;i<N;i++){
			s(a);s(b);
			Graph[a].pb(b);
			Graph[b].pb(a);
		}
		for(int i=1;i<=N;i++){
			for(int j=0;j<sz(Visited);j++){
				Visited[j]=false;
			}
			count=bfs(i);
			if(count>maxcount){
				maxcount=count;
			}
		}
		printf("Case #%d: %d\n",k,(N-maxcount));
	}
	return 0;
}
