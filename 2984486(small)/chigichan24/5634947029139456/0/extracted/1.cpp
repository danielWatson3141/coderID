#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<cstring>
#include<cctype>
#include<complex>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<functional>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<numeric>
using namespace std;
const int dx[]={1,0,-1,0};
const int dy[]={0,1,0,-1};
#define INF 1e+8
#define EPS 1e-7
#define PB push_back
#define fi first
#define se second
#define ll long long
#define reps(i,j,k) for(int i = (j); i < (k); i++)
#define rep(i,j) reps(i,0,j)
typedef pair<int,int> Pii;
typedef vector<int> vi;
class Data{
	public:
	int in;
	int cnt;
	string a[200];
	Data(){}
	Data(int _in,int _c,string x[200]){
		in = _in;
		cnt = _c;
		rep(i,200){
			a[i] = x[i];
		}
	}
	bool operator<(const Data &z)const{
		return cnt > z.cnt;
	}
};
int main(){
	int T;
	scanf("%d",&T);
	rep(t,T){
		int n,l;
		string de[200];
		string con[200];
		scanf("%d%d",&n,&l);
		rep(i,n){
			cin >> con[i];
		}
		rep(i,n){
			cin >> de[i];
		}
		sort(de,de+n);
		sort(con,con+n);
		priority_queue < Data > Q;
		Q.push(Data(0,0,con));
		int ans = -1;
		int cnt = 0;
		while(!Q.empty()){
			Data d = Q.top();Q.pop();
			if(d.in == l){
				ans = d.cnt;
				break;
			}
			bool f = false;
			rep(i,n){
				if(d.a[i][d.in] != de[i][d.in]){
					f = true;
				}
			}
			if(!f){
				Q.push(Data(d.in+1,d.cnt,d.a));
			}
			rep(i,n){
				if(d.a[i][d.in] == '1')d.a[i][d.in] = '0';
				else d.a[i][d.in] = '1';
			}
			sort(d.a,d.a + n);
			bool ff = false;
			rep(i,n){
				if(d.a[i][d.in] != de[i][d.in]){
					ff = true;
				}
			}
			if(f && ff){
				continue;
			}
			if(!ff){
				Q.push(Data(d.in+1,d.cnt+1,d.a));
			}
		}
		if(ans == -1){
			printf("Case #%d: NOT POSSIBLE\n",t+1);	
		}
		else printf("Case #%d: %d\n",t+1,ans);
	}
	return 0;
}