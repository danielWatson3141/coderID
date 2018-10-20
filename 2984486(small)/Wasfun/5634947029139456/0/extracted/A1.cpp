#include <algorithm>
#include <bitset>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>

using namespace std;

#define inf 1<<30
#define eps 1e-8
#define pi acos(-1)
#define mod 1000000007

#define vi vector<int>
#define pb(x) push_back(x)
#define f(i,x,y) for(int i=x;i<y;i++)
#define rf(i,y,x) for(int i=y;i>=x;i--)
#define cerr1(x) cerr<<x<<endl
#define cerr2(x,y) cerr<<x<<" "<<y<<endl
#define bit(x) __builtin_popcount(x)
#define clr(a, val) memset(a, val, sizeof(a))
#define sorta(a) sort(a, 0, sizeof(a))
#define sortv(x) sort((x).begin(),(x).end())
string tos(int a) { ostringstream os(""); os << a; return os.str(); }

int t, n, l;
set<int> s;
vector<int> b;
int main() {
	ios::sync_with_stdio(1); 
	
	#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif  
    cin>>t;
    f(i, 1, t+1){
    	s.clear();
    	b.clear();	
    	if(i!=1)cout<<endl;
    	cout<<"Case #"<<i<<": ";
    	cin>>n>>l;
    	int val;
    	string sss;
    	f(i, 0, n){
    		cin>>sss;
    		val=0;
    		f(i, 0, sss.size()){
    			val=val*2+(sss[i]-'0');
    		}
    		s.insert(val);
    	}
    	f(i, 0, n){
    		
    		cin>>sss;
    		val=0;
    		f(i, 0, sss.size()){
    			val=val*2+(sss[i]-'0');
    		}
    		 b.pb(val);
    	}

    	bool ba=true;
    	int mini=inf;
    	f(i, 0, 1<<l){
    		set<int> s2(s);
    		f(j, 0, b.size()){
    			s2.erase(b[j]^i);
    		}
    		if(s2.size()==0){
				ba=false;
				mini=min(__builtin_popcount(i), mini);
				
    		}
    	}

    	if(ba)cout<<"NOT POSSIBLE";
    	else cout<<mini;
    }
    return 0;
}