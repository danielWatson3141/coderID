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
struct XD{
    int a,b;
    XD(int _a,int _b):a(_a),b(_b){};
};
vector <int> v[1005];
int N,ans;
int cnt,vis[1005];
XD dfs(int pos){
    int childnum=0,tmp,total=0;
    vector <int> bomb;
    XD res(0,0);
    vis[pos] = 1;
    for(int i=0;i<v[pos].size();i++){
        if(vis[v[pos][i]] == 0){
            childnum++;
        }
    }
    total = tmp = 0;
    bomb.clear();
    for(int i=0;i<v[pos].size();i++){
        if(vis[v[pos][i]] == 0){
            res = dfs(v[pos][i]);
            total += res.a;
            bomb.push_back(res.a - res.b);
        }
    }
    //cout << "here";
    sort(bomb.begin(),bomb.end());

    if(childnum == 0){
        return XD(1,0);
    }if(childnum == 1){
        return XD(total+1,total);
    }else{
        tmp = bomb[childnum-2] + bomb[childnum-1];
        return XD(total+1,total- tmp);
    }
}
int main (){
    int T,a,b;
    cin >> T;
    for(int ca=1;ca<=T;ca++){
        cout << "Case #" << ca << ": ";
        cin >> N;
        for(int i=0;i<=N;i++)v[i].clear();

        for(int i=0;i<N-1;i++){
            cin >> a >>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        ans = 10000;
        for(int i=1;i<=N;i++){
            fill(&vis[0],&vis[N+1],0);
            XD res(0,0);
            res = dfs(i);
            //cout << "root: " << i << " "<< res.a << " " << res.b << "\n";
            ans = min(ans,res.b);
            //cout << i << " " << cnt << "\n";
        }
        cout <<ans << "\n";
    }
    return 0;
}


