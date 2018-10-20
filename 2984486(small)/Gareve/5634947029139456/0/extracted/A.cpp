#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int N,L;
vector<string> S;
vector<string> T;

int f(int mask){
    vector<string> vc(S.begin(),S.end());

    int moves = 0;
    for(int i=0;i<L;i++){
        if(mask & (1 << i)){
            for(int j=0;j<N;j++){
                vc[j][i] = vc[j][i] == '0'?'1':'0';
            }
            moves++;
        }
    }

    sort(vc.begin(),vc.end());
    sort(T.begin(),T.end());
    

    if(vc == T)
        return moves;
    else
        return -1;
}

void solve(){
    cin >> N >> L;
    S.clear();T.clear();
    string str;

    for(int i=1;i<=N;i++){
        cin >> str;
        S.push_back(str);
    }

    for(int i=1;i<=N;i++){
        cin >> str;
        T.push_back(str);
    }

    int lim = 1 << L;

    int ans = -1,tmp;
    for(int mask=0;mask<lim;mask++){
        tmp = f(mask);
        if(tmp == -1)continue;

        if(ans == -1 or tmp < ans){
            ans = tmp;
        }
    }
    if(ans == -1){
        printf("NOT POSSIBLE\n");
    }else{
        printf("%d\n",ans);
    }
}

int main(){
    int NC;cin >> NC;
    for(int i=1;i<=NC;i++){
        printf("Case #%d: ",i);
        solve();
    }
}