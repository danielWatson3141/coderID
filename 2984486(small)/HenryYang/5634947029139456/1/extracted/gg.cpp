#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;
string s[1000], t[1000];
int main(){
    //freopen("in", "r", stdin);
    //freopen("out2", "w", stdout);
    int n, l, ctt = 0, tt;
    cin >> tt;
    while(tt--){
        cin >> n >> l;
        int Ans = 1e9;
        for(int i = 0; i < n; i++)
            cin >> s[i];
        for(int i = 0; i < n; i++)
            cin >> t[i];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 1; j++){
                char mask[1000] = {};
                int ans = 0;
                map<string, int> M;
                for(int k  = 0; k < l; k++)
                    mask[k] = s[i][k] != t[j][k], ans += s[i][k] != t[j][k];
                for(int g = 0; g < n; g++){
                    string temp = s[g];
                    for(int k = 0; k < l; k++)
                        temp[k] = mask[k] ? (temp[k] == '0' ? '1' : '0') : temp[k];
                    M[temp] = 1;
                }
                int fg  = 1;
                for(int g = 0; g < n && fg; g++)
                    fg = fg & M[t[g]];
                if(fg)
                    Ans = min(ans, Ans);
            }
        }
        printf("Case #%d: ", ++ctt);
        if(Ans != 1e9)
            printf("%d\n", Ans);
        else
            puts("NOT POSSIBLE");
    }
    return 0;
}