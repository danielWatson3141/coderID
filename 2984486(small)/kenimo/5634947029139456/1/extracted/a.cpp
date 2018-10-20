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


LL stoLL(string s)
{
	LL v=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1'){
			v|=1LL<<(s.size()-1-i);
		}
	}
	return v;
}
void run(int Case)
{
	vector<LL> o,d, o1, d1;
	int N,L;
	cin >> N >> L;
	for(int i=0;i<N;i++){
		string s;
		cin >> s;
		LL v=stoLL(s);
		o.push_back(v);
	}
	for(int i=0;i<N;i++){
		string s;
		cin >> s;
		LL v=stoLL(s);
		//cout << v << endl;
		d.push_back(v);
	}
	sort(o.begin(),o.end());
	int ret=L+1;
	for(LL q:d){
		LL u=q^o[0];
		d1.clear();
		int c=__builtin_popcountll(u);
		for(int i=0;i<N;i++){
			d1.push_back(d[i]^u);
		}
		sort(d1.begin(),d1.end());
		if(o==d1){
			//cout << "aaa";
			ret=min(c,ret);
		}
	}

	cout << "Case #" << Case << ": ";
	if(ret==L+1){
		cout << "NOT POSSIBLE" << endl;
	}
	else
	{
		cout << ret << endl;
	}
}

int main() {
	int T;
	cin >> T;
	for (int t=1;t<=T;t++) {
		run(t);
	}
}
