#include<bits/stdc++.h>
#define show(x) { cerr<<">>>"<<#x<<" = "<<x<<endl; }
#define show2(x,y) { cerr<<">>>"<<#x<<"="<<x<<"  "<<#y<<" = "<<y<<endl; }
using namespace std;

const int MAXN = 155;
const int MAXL = 45;

long long rowa[MAXN],rowb[MAXN],rowc[MAXN];
int N,L;
int ans;
bool isok;


int main()
{
    freopen("E:\\acm\\input.txt","r",stdin);
    freopen("E:\\acm\\output.txt","w",stdout);

    int T; cin>>T;
    for(int cas=1; cas<=T; cas++)
    {
        cin>>N>>L;
        memset(rowa, 0, sizeof(rowa));
        for(int i=0; i<N; i++)
        {
            char str[MAXL];
            scanf("%s", str);
            for(int j=0; j<L; j++)
                if(str[j] == '1') rowa[i] |= 1<<j;
        }
        memset(rowb, 0, sizeof(rowb));
        for(int i=0; i<N; i++)
        {
            char str[MAXL];
            scanf("%s", str);
            for(int j=0; j<L; j++)
                if(str[j] == '1') rowb[i] |= 1<<j;
        }
        sort(rowb, rowb+N);

        ans = 0x3f3f3f3f, isok = false;
        for(int i=0; i<N; i++)
        {
            memset(rowc, 0, sizeof(rowc));
            int step = 0;
            for(int j=0; j<L; j++)
            {
                int wei = rowb[0]&(1<<j);
                if( (rowa[i]&(1<<j)) ^ wei)
                {
                    step++;
                    for(int k=0; k<N; k++)
                    {
                        if(!(rowa[k]&(1<<j)))
                        {
                            rowc[k] |= 1<<j;
                        }
                    }
                }
                else
                {
                    for(int k=0; k<N; k++)
                        rowc[k] |= rowa[k]&(1<<j);
                }
            }
            sort(rowc, rowc+N);
            bool flag = true;
            for(int j=0; j<N; j++)
                if(rowb[j] != rowc[j])
                {
                    flag = false;
                    break;
                }
            if(flag)
            {
                isok = true;
                ans = min(ans, step);
            }
        }

        if(isok)
             printf("Case #%d: %d\n",cas, ans);
        else printf("Case #%d: NOT POSSIBLE\n",cas);
    }
}
