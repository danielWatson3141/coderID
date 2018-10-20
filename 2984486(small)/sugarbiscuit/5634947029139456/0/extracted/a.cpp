#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>
#include <stdlib.h>
#include <unordered_set>
#include <queue>
#include <map>
using namespace std;

struct comb{
	vector<string> s;
	vector<string> d;
	int idx;
	int num;
	comb(vector<string> s1, vector<string> d1, int i, int n):s(s1), d(d1), idx(i), num(n){}
};
bool test(vector<string> s, vector<string> d){
	map<string, int> set;
	for(string x: s){
		set[x]=1;
	}
	bool same=true;
	for(string x: d){
		if(set[x]!=1){

			same=false;
			break;
		}
	}
	return same;
}
void flip(vector<string> &s, vector<string> &d, int idx){
	for(int i=0; i<s.size(); i++){
		if(s[i][idx]=='0')	s[i][idx]='1';
		else	s[i][idx]='0';
	}
}
int solve(vector<string> s, vector<string> d, int l){
	if(test(s, d))	return 0;
	queue<comb> q;
	q.push(comb(s, d, 0, 0));
	while(!q.empty()){
		comb c=q.front();

		q.pop();
		vector<string> ts=c.s;
		vector<string> td=c.d;
		for(int i=c.idx; i<s[0].size(); i++){
			vector<string> ss=ts;
			vector<string> dd=td;
			flip(ss, dd, i);
			if(test(ss, dd))	return c.num+1;
			q.push(comb(ss, dd, i+1, c.num+1));
		}
	}
	

	return -1;
}

int main(){
	ifstream ifs("A-small-attempt1.in");
	int t;
	ifs>>t;
	for(int i=1; i<=t; i++){
		int n, l;
		ifs>>n>>l;
		vector<string > s;
		vector<string > d;
		for(int j=0; j<n; j++){
			string tmp;
			ifs>>tmp;
			s.push_back(tmp);
		}
		for(int j=0; j<n; j++){
			string tmp;
			ifs>>tmp;
			d.push_back(tmp);
		}
		int res=solve(s, d, l);
		cout<<"Case #"<<i<<": ";
		if(res>=0){
			cout<<res<<endl;
		}
		else{
			cout<<"NOT POSSIBLE"<<endl;
		}
	}
}