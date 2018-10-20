#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <cassert>
#include <iomanip>
using namespace std;
static const double EPS = 1e-9;
static const int mod = 100000007;
typedef long long ll;

int t,n,l;

bool check(vector<string> in,vector<string> out){
	for(int i=0;i<l;i++){
		for(int j=0;j<n;j++){
			if(in[j][i]!=out[j][i])return false;
		}
	}
	return true;
}

void swi(vector<string>& in,int index){
	for(int i=0;i<in.size();i++){
		in[i][index]=(in[i][index]=='0'?'1':'0');
	}
}

int main() {
	// freopen ("input.txt", "r", stdin);
	// freopen ("output.txt", "w", stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cout<<"Case #"<<(i+1)<<": ";
		vector<string> in;
		vector<string> out;

		cin>>n>>l;
		for(int j=0;j<n;j++){
			string s;
			cin>>s;
			in.push_back(s);
		}
		for(int j=0;j<n;j++){
			string s;
			cin>>s;
			out.push_back(s);
		}
		sort(out.begin(),out.end());
		int res=0xffff;
		for(int j=0;j<n;j++){
			vector<string> tmp;
			for(int i=0;i<in.size();i++){
				tmp.push_back(in[i]);
			}
			int count=0;
			for(int index=0;index<l;index++){
				if(out[0][index]!=tmp[j][index]){
					count++;
					swi(tmp,index);
				}
			}
			sort(tmp.begin(),tmp.end());
			if(check(tmp,out)){
				res=min(res,count);
			}
		}

		if(res<0xffff)cout<<res<<endl;
		else cout<<"NOT POSSIBLE"<<endl;
	}
}