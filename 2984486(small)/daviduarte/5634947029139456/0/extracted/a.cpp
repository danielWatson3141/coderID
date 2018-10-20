#include <bits/stdc++.h>

using namespace std;

#define fr(a,b,c) for(int a = b; a < c; a++)
#define rep(a,b) fr(a,0,b)
#define ln puts("")
#define db if(0)
#define pb push_back

typedef long long ll;

int n;
int l;
char out[222][55];
char dev[222][55];

bool read(){
    if(scanf("%d%d", &n, &l) == EOF) return false;

	rep(i,n){
		scanf("%s", out[i]);
		rep(j,l) out[i][j] -= '0';
	}
	
	rep(i,n){
		scanf("%s", dev[i]);
		rep(j,l) dev[i][j] -= '0';
	}

/*
	n = 150;
	l = 40;
	
	rep(i,n){
		rep(j,l) {
			dev[i][j] = rand()%2;
			out[i][j] = rand()%2;
		}
	}
//*/	

    return true;
}

vector<vector<int> > go; //outlets
vector<vector<int> > gd; //devices

void space(int pos){
	rep(i,pos) printf(" ");
}

bool fix(int pos){
	db space(pos);
	db printf("Fixing %d (%d groups)\n", pos, (int)go.size());

	vector<vector<int> > ngo;
	vector<vector<int> > ngd;
	
	rep(i,go.size()){
		db space(pos);
		db printf("running group %d\n", i);
		vector<int> vo[2];
		vector<int> vd[2];
		
		rep(j,go[i].size()){
			db space(pos);
			db printf("processing go %d %d\n", go[i][j], (int)out[go[i][j]][pos]);
			vo[out[go[i][j]][pos]].pb(go[i][j]);
		}
		rep(j,gd[i].size()){
			db space(pos);
			db printf("processing gd %d %d\n", gd[i][j], (int)dev[gd[i][j]][pos]);
			vd[dev[gd[i][j]][pos]].pb(gd[i][j]);
		}
		
		if(vo[0].size() != vd[0].size()){
			db space(pos);
			db printf("Failed\n");
			return false;
		}
		
		rep(j,2){
			if(vo[j].size() == 0) continue;
			db space(pos);
			db printf("Adding group of kind %d\n", j);
			ngo.pb(vo[j]);
			ngd.pb(vd[j]);
		}
	}
	
	db space(pos);
	db printf("Ok!\n");
	
	go = ngo;
	gd = ngd;
	/*
	go.clear();
	gd.clear();
	
	rep(i,ngo.size()) {
		go.pb(ngo[i]);
		gd.pb(ngd[i]);
	}//*/
	
	db space(pos);
	db printf("Finished with %d groups\n", (int)go.size());
	
	return true;
}

int bt(int pos){
	db space(pos);
	db printf("pos %d (%d groups)\n", pos, (int) go.size());
	if(pos == l) return 0;
	vector<vector<int> > oldgo;
	vector<vector<int> > oldgd;
	
	/*
	rep(i,go.size()) {
		printf("Pushing %d\n", i);
		oldgo.pb(go[i]);
		oldgd.pb(gd[i]);
	}//*/
	
	
	oldgo = go;
	oldgd = gd;
	//*/

	int res = 11111;

	rep(k,2){			
		go = oldgo;
		gd = oldgd;
		/*
		go.clear();
		gd.clear();
		
		rep(i,oldgo.size()) {
			go.pb(oldgo[i]);
			gd.pb(oldgd[i]);
		}//*/
		
		
		if(fix(pos)){
			res = min(res, k+bt(pos+1));
		}
		
		rep(i,n){
			out[i][pos] = 1-out[i][pos];
		}
	}
	
	
	
	return res;
}

int cn = 1;

void process(){
	go.clear();
	gd.clear();
	
	vector<int> vo;
	vector<int> vd;
	
	rep(i,n){
		vo.pb(i);
		vd.pb(i);
	}
	
	go.pb(vo);
	gd.pb(vd);
	
	int res = bt(0);
	printf("Case #%d: ", cn++);
	if(res > 1000) puts("NOT POSSIBLE");
	else printf("%d\n", res);
}

int main(){  
	int t = -1;
	
	scanf("%d", &t);

    while(t-- && read()){
        process();
    }
    
    return 0;
}
