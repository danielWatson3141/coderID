#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

const int N = 1010;

int n, m;
vector<string> flow, outlet;
char str[N];

inline char rev(char c){
    if(c == '1') return '0';
    return '1';
}
inline int count(int x){
    int ret = 0;
    while(x){
        if(x & 1) ret ++;
        x >>= 1;
    }
    return ret;
}
int main(){
    int _, cas = 1;
    for(scanf("%d", &_); _--; ){
        printf("Case #%d: ", cas++);
        scanf("%d %d", &n, &m);
        flow.clear(); outlet.clear();
        for(int i = 0; i < n; ++i){
            scanf("%s", str);
            flow.push_back(str);
        }
        for(int i = 0; i < n; ++i){
            scanf("%s", str);
            outlet.push_back(str);
        }
        sort(outlet.begin(), outlet.end());
        
        int mask = 1 << m;
        int ans = m + 1;
        for(int i = 0; i < mask; ++i){
            vector<string> cur = flow;
            for(int j = 0; j < m; ++j) if(i >> j & 1){
                for(int k = 0; k < n; ++k){
                    cur[k][j] = rev(cur[k][j]);
                }
            }
            sort(cur.begin(), cur.end());
            if(cur == outlet) ans = min(ans, count(i));
        }
        if(ans == m + 1) puts("NOT POSSIBLE");
        else printf("%d\n", ans);
    }
    return 0;
}