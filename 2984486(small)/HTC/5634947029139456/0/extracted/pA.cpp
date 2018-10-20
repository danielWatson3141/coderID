#include <iostream>
#include <map>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <stack>
#include <queue>
#include <iomanip>
using namespace std;
vector <int> nv,b,v;
int use[159],N,L,ans,cnt;
int check(){
    nv.clear();
    for(int i=0;i<v.size();i++){
        nv.push_back(v[i]);
        for(int j=0;j<L;j++){
            if(use[j] == 1){
                nv[i] = (nv[i] ^ (1 << j));
            }
        }
    }
    sort(nv.begin(),nv.end());
    for(int i=0;i<nv.size();i++){
        if(nv[i] != b[i]){
            return 0;
        }
    }
    return 1;
}
void dfs(int pos){
    if(pos == L){
        if(check() == 1){
            ans = min(ans,cnt);
        }
        return;
    }
    use[pos] = 1;
    cnt++;
    dfs(pos+1);
    use[pos] = 0;
    cnt--;
    dfs(pos+1);

}
int main (){
    int T,tmp;
    char in[150];
    cin >> T;
    for(int ca=1;ca<=T;ca++){
        cout << "Case #" << ca << ": ";
        v.clear();
        b.clear();
        cin >> N >> L ;
        for(int i=0;i<N;i++){
            cin >> in;
            tmp = 0;
            for(int j=0;j<L;j++){
                tmp = tmp * 2 + in[j]-'0';
            }
            v.push_back(tmp);
        }
        for(int i=0;i<N;i++){
            cin >> in;
            tmp = 0;
            for(int j=0;j<L;j++){
                tmp = tmp * 2 + in[j]-'0';
            }
            b.push_back(tmp);
        }
        sort(b.begin(),b.end());
        cnt = 0;
        ans = 1000;
        dfs(0);
        if(ans == 1000)cout <<"NOT POSSIBLE\n";
        else cout << ans << "\n";
    }
    return 0;
}

/*
3
3 2
01 11 10
11 00 10
2 3
101 111
010 001
2 2
01 10
10 01
*/
