#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <climits>
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
#include <memory.h>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define pi acos(-1.0)
#define EPS 1e-9

using namespace std;
map<string,int> m;
char flip(char c){
	return (c=='0')?'1':'0';
}
bool check(vector<string> &tmp){
	for(map<string,int>::iterator it=m.begin();it!=m.end();it++){
		string a=it->f;int x=it->s;int cnt=0;
		for(int i=0;i<tmp.size();i++){
			if(tmp[i]==a)cnt++;
		}
		if(cnt!=x)return false;
	}
	return true;
}
int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	int t,cs=0,n,l;cin>>t;
	while(t--){
		cin>>n>>l;vector<string> v(n);for(int i=0;i<n;i++)cin>>v[i];
		m.clear();
		for(int i=0;i<n;i++){
			string s;cin>>s;m[s]++;
		}
		int ans=INT_MAX;vector<string> tmp;
		for(int mask=0;mask<(1<<l);mask++){
			tmp=v;int cnt=0;
			for(int i=0;i<l;i++){
				if(mask & (1<<i)){
					cnt++;
					for(int j=0;j<n;j++)tmp[j][i]=flip(tmp[j][i]);
				}
			}
			if(check(tmp))ans=min(ans,cnt);
		}
		cout<<"Case #"<<++cs<<": ";
		if(ans==INT_MAX)cout<<"NOT POSSIBLE\n";
		else cout<<ans<<"\n";
	}
	return 0;
}
