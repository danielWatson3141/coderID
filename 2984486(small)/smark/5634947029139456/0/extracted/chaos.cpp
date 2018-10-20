#include<iostream>
#include<unordered_map> 
#include<set> 
#include<stdio.h> 
#include<stdlib.h>
#include<string>

using namespace std;


string computeDist(int i, int j,int l) {
	int c = l;
	string res;
	while(c--) {
		if( i%10 != j%10) res.append(1,c+32);  
		i /= 10;
		j /= 10;
	}
	return res;
}
int solve(int ini[], int tar[],int n, int l) {
	unordered_map<string, set<int>> mymap;
	 unordered_map<string, set<int>> ::iterator it;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			string a = computeDist(ini[i],tar[j],l);
			mymap[a].insert(j);
		}
	}
	int min = 41;
	for(auto & x:mymap) {
		if(x.second.size() == n) {
			int len = x.first.size();
			if(len < min) min = len;
		}
	}
	if(min == 41) return -1;
	else return min;
} 
int main() {
	int T,n,l;
	cin >> T;
	for(int j=1;j<=T;j++){
		cin >> n >> l;
		int initial[n];
		int target[n];
		for(int i=0;i<n;i++) cin >> initial[i];
		for(int i=0;i<n;i++) cin >> target[i];
		int res = solve(initial,target,n,l);
		if(res == -1) printf("Case #%d: NOT POSSIBLE\n",j);
		else printf("Case #%d: %d\n",j,res);
	}
	return 0;
}
