#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

int n;
int main()
{
    freopen("C-small-attempt7.in","r",stdin);
    freopen("C-small-attempt7.out","w",stdout);
    int T;
    int cas = 1;
    cin>>T;
    int tt =0;
    while (T--) {
        cin>>n;
        int cnt = 0;
        for (int i = 0 ; i < n; i++) {
            int x;
            scanf("%d",&x);
            if (abs(x - i) < 5) cnt++;
        }
        if (cnt > 9) {
            tt++;
            printf("Case #%d: BAD\n",cas++);
        }
        else printf("Case #%d: GOOD\n",cas++);
    }
    //cout<<tt<<endl;
}
