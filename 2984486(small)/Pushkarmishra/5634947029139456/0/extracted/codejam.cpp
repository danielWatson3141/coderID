#include <bits/stdc++.h>
using namespace std;

int n, l, numd[151], nums[151]; string des[151], s[151];
int mina=100;

int main()
{
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);

    int t; cin >> t;
    for(int test=1; test<=t; ++test)
    {
        cin >> n >> l; mina=100;
        memset(numd, 0, sizeof numd); memset(nums, 0, sizeof nums);

        for(int i=1; i<=n; ++i)
            cin >> des[i];
        for(int i=1; i<=n; ++i)
            cin >> s[i];

        for(int i=1; i<=n; ++i)
        {
            int p=1;
            for(int k=l-1; k>=0; --k)
            {
                numd[i] += p*(des[i][k]-48);
                nums[i] += p*(s[i][k]-48);
                p*=2;
            }
        }
        sort(numd+1, numd+n+1);

        for(int i=0; i<(1<<l); ++i)
        {
            vector<int> chk; chk.push_back(0);
            for(int j=1; j<=n; ++j)
            {
                int tmp=nums[j]^i;
                chk.push_back(tmp);
            }
            sort(chk.begin(), chk.end());

            int chk1=1;
            for(int j=1; j<=n; ++j){
                if(numd[j]!=chk[j]){chk1=0; break;}
            }

            if(chk1){
                int cnt=0, tl=i;
                while(tl){
                    if(tl%2)cnt++;
                    tl/=2;
                }
                mina=min(mina, cnt);
            }
        }
        if(mina==100)printf("Case #%d: NOT POSSIBLE\n", test);
        else printf("Case #%d: %d\n", test, mina);
    }
    return 0;
}
