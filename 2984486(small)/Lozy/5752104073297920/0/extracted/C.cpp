#include <iostream> 
#include <fstream>
#include <sstream> 
#include <cstring>
#include <string> 
#include <vector> 
#include <queue> 
#include <deque> 
#include <set> 
#include <map> 
#include <algorithm> 
#include <utility> 
#include <functional> 
#include <cstdio> 
#include <cstdlib> 
#include <cmath> 
#include <ctime> 

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) FOR(i,0,a)
#define foreach(itr,c) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr) 
#define X first
#define Y second
#define PB push_back
#define MP make_pair

int main() {
	int T,z,n;
	scanf("%d",&T);
	rep(t,T){
		int x=0,sm=0;
		scanf("%d",&n);
		rep(i,n){
			scanf("%d",&z);
			if(z<i)++x;
		}
		printf("Case #%d: %s\n", t+1,x<480?"BAD":"GOOD");
	}
 	return 0;
}
