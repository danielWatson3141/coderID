//============================================================================
// Name        : GCJ20141A.cpp
// Author      : Takatomo Honda
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <math.h>
using namespace std;

#define all(c) (c).begin(),(c).end()
#define FORE(i,d,e) for(int i=d;i<e;i++)
#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()

int n,L;
vector<string> ini,rep;

string solve(){
	int ret=1e+9;

	sort(all(rep));
	for(int i=0;i<(1<<L);i++){
		int cnt=0;
		vector<string> cur=ini;
		for(int j=0;j<L;j++){
			if(i&(1<<j)){
				FORE(k,0,n)cur[k][j]=( (cur[k][j]=='0') ? '1' : '0');
				cnt++;
			}
		}
		sort(all(cur));
		int valid=1;
		FORE(k,0,n)FORE(l,0,L)if(cur[k][l]!=rep[k][l])valid=0;
		if(valid)ret=min(ret,cnt);
	}
	if(ret==1e+9)return "NOT POSSIBLE";

	char ch[100];
	sprintf(ch,"%d",ret);

	return ch;

}

int main(int argc, char *args[]) {
	FILE *stream;

	if ( argc==2 && strcmp(args[1], "small")==0 ) {
		if( (stream=freopen("A-small-practice.in","rt",stdin))==NULL){
			printf("file open error");
		}
        //freopen("small.out","wt",stdout);
    }
    else if (argc == 2 && strcmp(args[1], "large") == 0) {
        freopen("large.in","rt",stdin);
        freopen("large.out","wt",stdout);
    }
    else {
	    freopen("A-small-attempt0.in", "rt", stdin);
        freopen("small.out","wt",stdout);
    }

	int N;
	cin>>N;

    vector<string> ans(N);
    ans.clear();

    FORE(i,0,N){
    	cin>>n;
    	cin>>L;
    	ini.clear();
    	rep.clear();
    	string tmp;
    	FORE(i,0,n){
    		cin>>tmp;
    		ini.push_back(tmp);
    	}
    	FORE(i,0,n){
    		cin>>tmp;
    		rep.push_back(tmp);
    	}
    	ans.push_back(solve());
    }

    FORE(i,0,N) {
        printf("Case #%d: %s", i+1,ans[i].c_str());
        cout<<endl;
    }

    return 0;
}




