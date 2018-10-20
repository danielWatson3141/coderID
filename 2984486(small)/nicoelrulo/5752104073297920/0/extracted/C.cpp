#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

#define forn(i,n) for(int i=0; i<(int)(n); i++)
#define pb push_back
const int INF = 1000000;
const int MAXN = 3000;

/*
 bool calc2(vector<int> v){
	vector<int>w;
	forn(i,v.size())w.pb(i);
	forn (k,v.size()){
		int p = rand() % (v.size() - 0) + 0;
		swap(w[k], w[p]);
	}
	if(v==w)return true;
	else return false;
}

bool calc1(vector<int> v){
	vector<int>w;	
	forn(i,v.size())w.pb(i);
	forn (k,v.size()){
		int p = rand() % (v.size() - k) + k;
		swap(w[k], w[p]);
	}
	if(v==w)return true;
	else return false;
}
*/
int main(){
	int t; cin>>t;
	srand(time(NULL));
	forn(tc,t){
		int n; cin>>n;
		vector<int>v;
		forn(i,n){int x; cin>>x; v.pb(x);}
		int count=0;
		forn(i,n)if(v[i]==i)count++;
		printf("Case #%d: ", tc+1);
		if(count>=1)printf("GOOD\n");
		else printf("BAD\n");
	}
}
