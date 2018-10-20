#include <bits/stdc++.h>
using namespace std;

int solve(){
    int n,l;
    cin >> n >> l;
    vector<string> s1,s2;
    string s;

    for(int i = 0; i < n; i++){
        cin >> s; s1.push_back(s);
    }

    for(int i = 0; i < n; i++){
        cin >> s; s2.push_back(s);
    }


    sort(begin(s1),end(s1));

    int ans = 999;

    for(int i = 0; i < n; i++){
        int diff = 0;
        for(int j = 0; j < l; j++) if(s1[0][j] != s2[i][j]) diff++;
        if(ans <= diff) continue;

        vector<string> left;
        for(int j = 0; j < n; j++){
            s = s2[j];
            for(int k = 0; k < l; k++){
                if(s1[0][k] != s2[i][k]) s[k] ^= 1;
            }

            left.push_back(s);
        }

        sort(begin(left),end(left));

        bool ok = true;
        for(int j = 0; j < n; j++){
            //cout << s1[j] << " " << left[j] << endl;
            ok &= s1[j] == left[j];
        }
        if(ok) ans = diff;
    }
    return ans;
}

int main(){
    int t; scanf("%d\n",&t);
    for(int i = 0; i < t; i++){
        printf("Case #%d: ",i+1);
        int ans = solve();
        printf(ans==999?"NOT POSSIBLE\n" : "%d\n",ans);
    }
}

