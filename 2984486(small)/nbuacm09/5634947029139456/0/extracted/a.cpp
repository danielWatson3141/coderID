#pragma comment(linker, "/STACK:1024000000,1024000000")  
#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
template<class T> T gcd(T x,T y){while(T t=x%y)x=y,y=t;return y;}
const double eps = 1e-9;
const double PI = acos(-1.);
const int INF = 1000000000;
const int MOD = 1000000007;
const double E = 2.7182818284590452353602874713527;

#define pmul(x1,y1,x2,y2) ((x1)*(x2)+(y1)*(y2))
#define xmul(x1,y1,x2,y2) ((x1)*(y2)-(x2)*(y1))
#define sqr(x) ((x)*(x))

#define FR(i,N) for(int i=0;i<N;i++)
#define FRS(i,S,E) for(int i=S;i<=E;i++)
#define FRD(i,S,E) for(int i=S;i>=E;i--)
#define SZ(x) ((int)(x).size())
#define fill(a,b) memset(a,b,sizeof(a))
#define PII pair<int,int>
#define MP(a,b) make_pair(a,b)
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define PB push_back
#define lowbit(x) ((x)&(-(x)))

bool isdig(char x){return x>='0'&&x<='9';}
bool isup(char x){return x>='A'&&x<='Z';}
bool isdown(char x){return x>='a'&&x<='z';}
bool islet(char x){return isup(x)||isdown(x);}

void FILE_IO(string s = ""){
	if(s == "")return;
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}

//--------CODE----------
int N, L;
string num1[155], num2[155];
void get_data(){
	scanf("%d%d", &N, &L);
	FR(i, N){
		cin>>num1[i];
	}
	FR(i, N){
		cin>>num2[i];
	}
}
set<string> st;

string xor(string& a, string& b){
	string r;
	FR(i, L){
		r += a[i] == b[i]?'0':'1';
	}
	return r;
}
int ok(string s){
	map<string, int> mp;
	FR(i, N)mp[num1[i]]++;
	
	
	FR(i, N){
		string t = xor(num2[i], s);
		if(mp.find(t) == mp.end())return 100;
	}
	
	int r = 0;
	FR(i, L)if(s[i] == '1')r++;
	return r;
}

void run(){
	if(N == 1){
		cout<<ok(xor(num1[0], num2[0]))<<endl;
		return;
	}
	st.clear();
	FR(i, N)FR(j, N){
		st.insert(xor(num1[i], num2[j]));
	}
	set<string>::iterator it;
	int r = 100;
	for(it = st.begin(); it != st.end(); it++){
		r = min(r, ok(*it));
	}
	if(r > L)cout<<"NOT POSSIBLE\n";
	else cout<<r<<endl;
}

int main(){
	FILE_IO("A-small-attempt4");
	
	int t = 1;
	int i = 0;
	scanf("%d", &t);
	while(t--)	
	{
		get_data();
		printf("Case #%d: ", ++i);
		run();
	}
	return 0;
}

/*


*/
