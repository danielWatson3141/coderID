#include <bits/stdc++.h>

using namespace std;

#define fr(a,b,c) for(int a = b; a < c; a++)
#define rep(a,b) fr(a,0,b)
#define ln puts("")
#define db if(1)
#define pb push_back

typedef long long ll;

vector<int> adj[1111];

int n;

bool read(){
    if(scanf("%d", &n) == EOF) return false;

	rep(i,n) adj[i].clear();

	rep(i,n-1){
		int u, v;
		scanf("%d%d", &u, &v);
		u--;
		v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}

    return true;
}

struct ret{
	int size;
	int need;
	
	bool operator < (const ret & b) const{
		return (size-need) > (b.size-b.need);
	}
};

ret rec(int v, int dad){
	//printf("Calling %d\n", v); fflush(stdout);
	vector<ret> r;
	
	rep(i,adj[v].size()){
		int vv = adj[v][i];
		
		if(vv != dad) r.pb(rec(vv, v));
	}
	
	sort(r.begin(), r.end());
	
	ret res;
	
	if(r.size() == 0){
		res.size = 1;
		res.need = 0;	
	}
	else if(r.size() == 1){
		res.size = 1 + r[0].size;
		res.need = r[0].size;
	}
	else{
		res.size = 1;
		
		rep(i,r.size()){
			res.size += r[i].size;
		}
		
		res.need = res.size-1;
		
		rep(i,2) res.need -= r[i].size - r[i].need;
	}
	
	//printf("%d returns %d %d\n", v, res.size, res.need);
	
	return res;
}

int cn = 1;

void process(){
	int res = n;
	
	rep(i,n) {
		//printf("Starting at %d\n", i);
		res = min(res, rec(i,-1).need);
	}

	printf("Case #%d: %d\n", cn++, res);
}

int main(){  
	int t = -1;
	
	scanf("%d", &t);

    while(t-- && read()){
        process();
    }
    
    return 0;
}
