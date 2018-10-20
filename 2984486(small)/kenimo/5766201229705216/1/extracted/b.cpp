#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <set>
#include <numeric>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
vector<int> node[1000];
int N;
map<P,int> memo;
map<P,int> memo2;


int del(int r, int p)
{
	if(memo.find(P(r,p))!=memo.end()){
		return memo[P(r,p)];
	}
	int a=-1,b=-1;
	for(int n:node[r])
	{
		if(n==p)continue;
		int d=del(n,r);
		if(d>=a){
			b=a;
			a=d;
		}
		else if(d>=b){
			b=d;
		}
	}
	int ret;
	if(b==-1){
		ret=1;
	}
	else
	{
		ret=1+a+b;
	}
	return memo[P(r,p)]=ret;
}
void run(int Case)
{
	cin >> N;
	memo.clear();
	for(int i=0;i<N;i++){
		node[i].clear();
	}
	for(int i=0;i<N-1;i++){
		int a,b;
		cin >> a >> b;
		a--;b--;
		node[a].push_back(b);
		node[b].push_back(a);
	}
	int m=0;
	for(int i=0;i<N;i++){
		//cout << i << ", " << del(i,-1) << endl;
		m=max(del(i,-1),m);
	}
	cout << "Case #" << Case << ": " << N-m <<endl;
}

int main() {
	int T;
	cin >> T;
	for (int t=1;t<=T;t++) {
		run(t);
	}
}
