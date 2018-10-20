#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int cnt(int root,int father,const vector<vector<int> >&E){
	int ans = 1;
	for(vector<int>::const_iterator itr=E[root].begin();itr!=E[root].end();++itr){
		if(*itr == father)continue;
		int tans = cnt(*itr,root,E);
		ans += tans;
	}
}
int solve(int root,int father,const vector<vector<int> >&E,const vector<int>&Deg){
	if(Deg[root]==0)return 0;
	if(Deg[root]<3)return 1;
	int ans = 1;
	int max1=1,max2=1;
	for(vector<int>::const_iterator itr=E[root].begin();itr!=E[root].end();++itr){
		if(*itr == father)continue;
		int tans = solve(*itr,root,E,Deg);
		if(tans >= max1){
			max2 = max1;
			max1 = tans;
		}else if(tans > max2){
			max2 = tans;
		}
	}
	return 1+max1+max2;
}
int main(){
	int T;
	cin >> T;
	int idx = 0;
	while(T--){
		++idx;
		int N; cin>>N;
		vector<vector<int> >E(N);
		vector<int>Deg(N);
		for(int i=0;i<N-1;++i){
			int a,b; cin >> a >> b;
			--a;--b;
			E[a].push_back(b);
			E[b].push_back(a);
			++Deg[a];
			++Deg[b];
		}
		int ans=1;
		for(int i=0;i<N;++i){
			if(Deg[i]<2)continue;
			int max1=1,max2=1;
			for(vector<int>::const_iterator itr=E[i].begin();itr!=E[i].end();++itr){
				if(*itr == i)continue;
				int tans = solve(*itr,i,E,Deg);
				if(tans >= max1){
					max2 = max1;
					max1 = tans;
				}else if(tans > max2){
					max2 = tans;
				}
			}
			int tans= 1+max1+max2;
			if(tans > ans){
				ans = tans;
			}
		}
		cout << "Case #"<<idx<<": "<<(N-ans)<<endl;
	}
	return 0;
}
