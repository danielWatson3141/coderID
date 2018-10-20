#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

const int MAXN = 155;
const int MAXL = 42;

int T , N , L , ret , mins;
int outlets[MAXN][MAXL] , device[MAXN][MAXL];
int re1[MAXL] , re2[MAXL];

bool check() {
     memset(re1,0,sizeof(re1));
     memset(re2,0,sizeof(re2));
     ret = 0;
     for (int i = 0;i < L;i ++)
         for (int j = 0;j < N;j ++)
             if (outlets[j][i]) re1[i] ++;
     for (int i = 0;i < L;i ++)
         for (int j = 0;j < N;j ++)
             if (device[j][i]) re2[i] ++;
     for (int i = 0;i < L;i ++)
         if (re1[i] != re2[i] && re1[i] + re2[i] != N) return false;
            else {
                 if (re1[i] != re2[i]) ret ++;
            }
     return true;
}

void init() {
     for (int i = 0;i < L;i ++)
         if (re1[i] != re2[i]) {
            for (int j = 0;j < N;j ++)
                outlets[j][i] = 1 - outlets[j][i];
         }
}

bool ok() {
     bool h[MAXN];
     memset(h,false,sizeof(h));
     for (int i = 0;i < N;i ++) {
         bool ff = false;
         for (int j = 0;j < N && !ff;j ++) {
             if (!h[j]) {
                bool f = true;
                for (int k = 0;k < L;k ++)
                    if (outlets[i][k] != device[j][k]) {
                       f = false;
                       break;
                    }
                if (f) {
                   h[j] = true;
                   ff = true;
                }
             }
         }
     }
     for (int i = 0;i < N;i ++)
         if (!h[i]) return false;
     return true;
}

void dfs(int step , int sum) {
     if (sum > mins) return ;
     if (step == L) {
        if (ok())
           mins = sum;
     }
     else {
          if (re1[step] + re2[step] == N && re1[step] == re2[step]) {
             dfs(step+1,sum);
             for (int i = 0;i < N;i ++)
                 outlets[i][step] = 1-outlets[i][step];
             dfs(step+1,sum+1);
             for (int i = 0;i < N;i ++)
                 outlets[i][step] = 1-outlets[i][step];
          }
          else
              dfs(step+1,sum);
     }
}
     

int main() {
    freopen("inputa.txt","r",stdin);
    freopen("outputa.txt","w",stdout);
    cin >> T;
    for (int ct = 1;ct <= T;ct ++) {
        cin >> N >> L;
        char str[255];
        for (int i = 0;i < N;i ++) {
            cin >> str;
            for (int j = 0;j < L;j ++)
                if (str[j] == '0') outlets[i][j] = 0;
                   else outlets[i][j] = 1;
        }
        for (int i = 0;i < N;i ++) {
            cin >> str;
            for (int j = 0;j < L;j ++)
                if (str[j] == '0') device[i][j] = 0;
                   else device[i][j] = 1;
        }
        if (!check()) cout << "Case #" << ct << ": " << "NOT POSSIBLE" << endl;
        else {
             init();
             mins = 1000000;
             dfs(0,0);
             if (mins > L) cout << "Case #" << ct << ": " << "NOT POSSIBLE" << endl;
             else cout << "Case #" << ct << ": " << ret+mins << endl;
        }
    }
    return 0;
}
