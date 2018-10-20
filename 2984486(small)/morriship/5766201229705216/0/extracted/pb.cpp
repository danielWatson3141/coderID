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

vector<int> edge[1001];
int use[1001];
int n;

int go(int now){
	int i,j;
	use[now]=1;
	vector<int> temp;
	rep(i,edge[now].size()){
		j=edge[now][i];
		if(!use[j]){
			temp.push_back(go(j));
		}
	}
	if(temp.size()<2) return 1;
	sort(temp.begin(),temp.end());
	int aa=temp.size()-1;
	return temp[aa]+temp[aa-1]+1;
}

int main(){
    freopen("B-small-attempt0.in","r",stdin);
    freopen("pb.out","w",stdout);
    int i,j,k,t,tt,ans(0);
    cin >> tt;
    xrep(t,1,tt+1){
    	cout << "Case #" << t << ": ";
    	cin >> n;
    	ans=0;
    	rep(i,n+1) edge[i].clear();
    	rep(i,n-1){
    		int x,y;
    		cin >> x >> y;
    		edge[x].push_back(y);
    		edge[y].push_back(x);
    	}
    	
    	xrep(i,1,n+1){
    		memset(use,0,sizeof(use));
    		int w=go(i);
    		if(w>ans) ans=w;
    	}
    	cout << n-ans << endl;
    }
}

