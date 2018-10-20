#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;
LL s[155];
LL now[155];
LL b[155];
int n,l;
void display() {
    for(int i=0; i<n; ++i) {
        printf("now[%d]=%d   ,",i,now[i]);
        for(int j=0; j<l; ++j) {
            printf("%d",(now[i]>>j)&1);
        }
        puts("");
    }
}
LL read() {
    char s[155];
    scanf("%s",s);
    LL ret=0;
    for(int i=0; i<l; ++i) {
        ret = ret*2+(s[i]-'0');
    }
    return ret;
}
int main() {
    freopen("A-small-attempt2.in","r",stdin);
    freopen("A-small-attempt2.out","w",stdout);
    int T;
    scanf("%d",&T);
    bool vis[155];
    for(int t=1; t<=T; ++t) {

        scanf("%d %d",&n,&l);
        for(int i=0; i<n; ++i) {
            s[i]=read();
        }
        for(int i=0; i<n; ++i) {
            b[i]=read();
        }
        int res=150;
        for(int mask=0; mask<(1<<l); ++mask) {
            for(int i=0; i<n; ++i) {
                now[i]=s[i];
            }
            int cnt=0;
            //display();
            for(int i=0; i<l; ++i) {
                if((mask>>i)&1) {
                    ++cnt;
                    for(int j=0; j<n; ++j) {
                        if((now[j]>>i)&1) {
                            now[j]&=(~(1LL<<i));
                        } else {
                            now[j]|=(1LL<<(i));
                        }
                    }
                }
            }
            for(int i=0; i<n; ++i)vis[i]=false;
            bool OK=true;
            for(int i=0; i<n; ++i) {
                int p=-1;
                for(int j=0; j<n; ++j) {
                    if(!vis[j]&&now[j]==b[i]) {
                        p=j;
                    }
                }
                if(~p) {
                    vis[p]=true;
                } else {
                    OK=false;
                    break;
                }
            }
            if(OK&&res>cnt) {
                res=cnt;
            }
        }
        printf("Case #%d: ",t);
        if(res==150)puts("NOT POSSIBLE");
        else printf("%d\n",res);
    }
    return 0;
}
