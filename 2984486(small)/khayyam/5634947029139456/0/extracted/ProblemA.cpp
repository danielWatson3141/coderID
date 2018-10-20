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
int get_binary(string s){
    int n=s.size();
    int x=0;
    for(int i=n-1;i>=0;--i){
        x*=2;
        if(s[i]=='1'){
            x+=1;
        }
    }
    return x;
}

int flip(int x, int mask, int n){
    for(int i=0;i<n;++i)if(mask&(1<<i)){
        if(x&(1<<i)){
            x = x&(~(1<<i));
        }else{
            x = x|(1<<i);
        }
    }
    return x;
}

int bit_count(int x){
    int c=0;
    while(x){
        c+=(x&1);
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
        vector<int> flows;
        for(int i=0;i<N;++i){
            string s;
            cin>>s;
            flows.push_back(get_binary(s));
        }
        set<int> required;
        for(int i=0;i<N;++i){
            string s;
            cin>>s;
            required.insert(get_binary(s));
        }
        int best=L+1;
        for(int mask=0;mask<(1<<L);++mask){
            bool feasible = true;
            for(int i=0;i<N;++i){
                int x = flip(flows[i], mask, L);
                if(required.find(x)==required.end()){
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
        if(best<=L){
            cout<<"Case #"<<c<<": "<<best<<endl;
        }else{
            cout<<"Case #"<<c<<": "<<"NOT POSSIBLE"<<endl;
        }
        
    }
	return 0;
}
