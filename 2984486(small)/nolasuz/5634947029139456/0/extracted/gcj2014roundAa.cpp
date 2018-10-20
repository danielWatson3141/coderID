#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <complex>
#include <map>
#include <climits>
using namespace std;

#define reep(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) reep((i),0,(n))
#define ALL(v) (v).begin(),(v).end()
#define PB push_back
#define EPS 1e-8
#define F first
#define S second
#define mkp make_pair

static const double PI=6*asin(0.5);
typedef long long ll;
typedef complex<double> CP;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vint;
static const int INF=1<<24;

vector<vint> vv,dev,tv;
pair<vector<vint>,int> tq;
vint devv;

int N,L;

void bitc(int a){
	rep(i,N){
		if(tv[i][a]) tv[i][a]=0;
		else tv[i][a]=1;
	}
}
bool check(vector<vint> vv, int a){
	int sumvv=0,sumdev=0;
	//cout<<" N "<<N<<endl;
	rep(i,N){
		if(vv[i][a]) sumvv++;
		if(dev[i][a]) sumdev++;
	}
	return sumvv==sumdev;
}

bool allcheck(vector<vint> tv){
	vint aa(tv.size(),0);
	rep(i,N){
		int tmp=0;
		rep(j,L){
			tmp*=2;
			if(tv[i][j]) tmp++;
		}
		aa[i]=tmp;
	}
	sort(ALL(aa));
	sort(ALL(devv));
	rep(i,N){
		if(aa[i]!=devv[i]) return false;
	}
	return true;
}

int main(){
	int T;
	cin>>T;
	rep(o,T){
		cout<<"Case #"<<o+1<<": ";
		cin>>N>>L;
		while(!vv.empty()) vv.pop_back();
		while(!dev.empty()) dev.pop_back();
		while(!devv.empty()) devv.pop_back();
		vv.clear();
		dev.clear();
		devv.clear();
		//cout<<"vv dev devv"<<vv.size()<<" "<<dev.size()<<" "<<devv.size()<<endl;
		rep(i,N){
			devv.PB(0);
		}
		//cout<<"devv"<<devv.size()<<endl;
		
		rep(i,N){
			vint tv;
			vv.PB(tv);
			string s;
			cin>>s;
			rep(j,L){
				vv[i].PB(0);
				vv[i][j]=s[j]-'0';
				//cout<<vv[i][j];
				
			}
			//cout<<endl;
		}
		rep(i,N){
			vint t;
			dev.PB(t);
			string s;
			cin>>s;
			rep(j,L){
				dev[i].PB(0);
				dev[i][j]=s[j]-'0';
				//cout<<dev[i][j];
			}
			//cout<<endl;
		}
		//cout<<"vv dev devv"<<vv.size()<<" "<<dev.size()<<" "<<devv.size()<<endl;
		queue<pair<vector<vint>,int> > qv;
		qv.push(mkp(vv,0));
		rep(i,N){
			int tmp=0;
			rep(j,L){
				tmp*=2;
				if(dev[i][j]) tmp++;
			}
			//cout<<tmp<<endl;
			devv[i]=tmp;
		}
		while(!tv.empty()) tv.pop_back();
		tv.reserve(N);
		rep(i,L){
			//cout<<qv.size()<<endl;
			int qs=qv.size();
			rep(j,qs){
				tq = qv.front();
				qv.pop();
				tv=tq.F;
				if(check(tv,i)) qv.push(tq);
				bitc(i);
				/*cout<<"tv\n";
				rep(k,N){
					rep(l,L){
						cout<<tv[k][l];
					}
					cout<<" ";
				}
				cout<<endl;
				*/
				if(check(tv,i)) qv.push(mkp(tv,tq.S+1));
				
			}
		}
		
		//cout<<"hoge"<<endl;
		int ans=10000;
		int qs=qv.size();
		/*rep(i,N){
			cout<<devv[i]<<" ";
		}*/
		//cout<<endl;
		rep(i,qs){
			tq=qv.front();
			qv.pop();
			tv=tq.F;
			/*cout<<"tv"<<endl;
			rep(j,N){
				rep(k,L){
					cout<<tv[j][k];
				}
				cout<<" ";
			}
			cout<<endl<<"dev"<<endl;
			rep(j,N){
				rep(k,L){
					cout<<dev[j][k];
				}
				cout<<" ";
			}
			cout<<endl;
			*/
			if(allcheck(tq.F)) ans=min(ans,tq.S);
		}
		if(ans==10000) cout<<"NOT POSSIBLE\n";
		else cout<<ans<<endl;
		
	}
	
	return 0;
}