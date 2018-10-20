#include<iostream>
#include<sstream>
#include<vector>
#include<map>
#include<string>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<queue>
#include<stack>
#define INF (1<<29)
#define EPS (1e-10)
#define two(a) (1<<(a))
#define rep(a,b) for(a=0 ; a<b ; ++a)
#define xrep(a,b,c) for(a=b ; a<c ; ++a)
#define sca(t) scanf("%d",&t)
#define scal(t) scanf("%lld",&t)
typedef long long ll;
using namespace std;
int n,len,ch[100];
vector<string> in,out;
int distIn[100],distOut[100];

int check(int now){
	int i;
	sort(in.begin(),in.end());
	sort(out.begin(),out.end());
	rep(i,n){
		if(in[i].substr(0,now+1)!=out[i].substr(0,now+1)) return 0;
	}
	return 1;
}

int rev(int now){
	int i;
	rep(i,n){
		in[i][now]=(in[i][now]=='0'?'1':'0');
	}
}	

int go(int now){
	if(now==len){
		if(check(len-1)){
			return 0;
		}
		return -1;
	}
	int ind=distIn[now];
	int outd=distOut[now];
	if(ind==0){
		int d=-1;
		if(check(now)){
			int ret=go(now+1);
			if(ret>=0) d=ret;
		}
		ch[now]=1;
		rev(now);
		if(check(now)){
			int ret=go(now+1)+1;
			if(ret>0){
				if(d<0 || d>ret){
					d=ret;
				}
			}
		}
		rev(now);
		ch[now]=0;
		return d;
	}
	else if(ind==outd){
		return go(now+1);
	}
	else if(ind==-outd){
		ch[now]=1;
		rev(now);
		int ret=go(now+1)+1;
		rev(now);
		ch[now]=0;
		if(ret==0) return -1;
		return ret;
	}
}

void calDist(){
	int i,j,ind,outd;
	rep(i,len){
		ind=outd=0;
		rep(j,n){
			ind+=in[j][i]=='0'?-1:1;
			outd+=out[j][i]=='0'?-1:1;
		}
		distIn[i]=ind;
		distOut[i]=outd;
	}
}

int main(){
    freopen("A-large.in","r",stdin);
    freopen("pa.out","w",stdout);
    int i,j,k,t,tt;
   	string str;
    cin >> tt;
    xrep(t,1,tt+1){
    	cout << "Case #" << t << ": ";
    	cin >> n >> len;
    	in.clear();
    	out.clear();
    	rep(i,n){
    		cin >> str;
    		in.push_back(str);
    	}
    	rep(i,n){
    		cin >> str;
    		out.push_back(str);
    	}
    	memset(ch,0,sizeof(ch));
    	memset(distIn,0,sizeof(distIn));
    	memset(distOut,0,sizeof(distOut));
    	calDist();
    	rep(i,len){
    		if(distIn[i]!=distOut[i] && distIn[i]!=-distOut[i]){
    			cout << "NOT POSSIBLE" << endl;
    			break;
    		}
    	}
    	if(i<len) continue;
    	int ret=go(0);
    	if(ret<0) cout << "NOT POSSIBLE" << endl;
    	else cout << ret << endl; 
    }
}

