#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string.h>
using namespace std;
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)<(b))?(b):(a))
#define ABS(x) (((x)<0)?(-(x)):(x))
#define LL long long
LL get_binary(string s){
    int n=s.size();
    LL x=0;
    for(int i=n-1;i>=0;--i){
        x<<=1;
        if(s[i]=='1'){
            x|=1LL;
        }
    }
    return x;
}

LL flip(LL x, LL mask, int n){
    for(int i=0;i<n;++i)if(mask&(1LL<<i)){
        if(x&(1LL<<i)){
            x = x&(~(1LL<<i));
        }else{
            x = x|(1LL<<i);
        }
    }
    return x;
}

int bit_count(LL x){
    int c=0;
    while(x){
        c+=(x&1LL);
        x>>=1;
    }
    return c;
}

int main(int argc, char *argv[]){
    int T;
    cin >> T;
    for(int c=1;c<=T;++c){
        int N, L;
        cin>>N>>L;
        vector<LL> flows;
        for(int i=0;i<N;++i){
            string s;
            cin>>s;
            flows.push_back(get_binary(s));
        }
        vector<LL> required;
        set<LL> S;
        for(int i=0;i<N;++i){
            string s;
            cin>>s;
            LL x =get_binary(s);
            S.insert(x);
            required.push_back(x);
        }
        int best=L+1;
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                LL mask = flows[i]^required[j];
                bool feasible = true;
                for(int i=0;i<N;++i){
                    LL x = flows[i]^mask;
                    if(S.find(x)==S.end()){
                        feasible = false;
                        break;
                    }
                }
                if(feasible){
                    int opt = bit_count(mask);
                    if(opt<best){
                        best=opt;
                    }
                }
            }
        }

        if(best<=L){
            cout<<"Case #"<<c<<": "<<best<<endl;
        }else{
            cout<<"Case #"<<c<<": "<<"NOT POSSIBLE"<<endl;
        }
        
    }
	return 0;
}
