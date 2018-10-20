#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

int N,L;
vector<string> S;
vector<string> T;

string get_mask(string a,string b){
    string mask = "";
    for(int k=0;k<L;k++){
        if(a[k] != b[k]){
            mask += 'X';
        }else{
            mask += 'O';
        }
    }
    return mask;
}

int solve(){
    cin >> N >> L;
    S.clear();T.clear();
    string str;

    for(int i=0;i<N;i++){
        cin >> str;
        S.push_back(str);
    }

    for(int i=0;i<N;i++){
        cin >> str;
        T.push_back(str);
    }

    map<string,int> mp;
    map<string,int>::iterator it;

    int ans = -1,tmp,cc;
    string mask;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            mask = get_mask(S[i],T[j]);

            it = mp.find(mask);
            if(it == mp.end()){
                mp[mask] = 1;
                cc = 1;
            }else{
                it->second++;
                cc = it->second;
            }

            // printf("%d %d %s = %d\n",i,j,mask.c_str(),cc);

            if(cc == N){
                tmp = 0;
                for(int k=0;k<L;k++)tmp += mask[k]=='X';

                if(ans == -1 or tmp < ans){
                    ans = tmp;
                }
            }
        }
    }
    return ans;
}


int main(){
    int NC;cin >> NC;
    int ans;
    for(int i=1;i<=NC;i++){
        printf("Case #%d: ",i);
        ans = solve();
        if(ans == -1){
            printf("NOT POSSIBLE\n");
        }else{
            printf("%d\n",ans);
        }
    }
}