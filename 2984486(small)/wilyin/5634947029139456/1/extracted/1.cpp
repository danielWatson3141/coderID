#include<bits/stdc++.h>
#define pb push_back
#define sz(x) (int)x.size()
#define scf scanf
#define ptf printf
#define fst first
#define scd second
#define forp(i,j,k) for(int i=j;i<k;i++)
#define form(i,j,k) for(int i=j;i>k;i--)
using namespace std;
typedef long long LL;

char ef[200][100],de[200][100],ss[200][100];
int used[1000],c1[1000][2],c2[10000][2],re[200];

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("1.txt","w",stdout);
    int T,n,l;
    scf("%d",&T);
    forp(tcnt,0,T)
    {
        memset(c1,0,sizeof(c1));
        memset(c2,0,sizeof(c2));

        scf("%d%d",&n,&l);
        forp(i,0,n)scf("%s",ef[i]);
        forp(i,0,n)scf("%s",de[i]);
        int t0,fg;
        int ans=1000000;
        forp(a,0,n)
            forp(b,0,n)
            {
                t0=0;
                forp(i,0,l)
                {
                    re[i]=(de[a][i]!=ef[b][i]);
                    t0+=re[i];
                }
                forp(i,0,n)
                {
                    forp(j,0,l)
                        ss[i][j]=re[j]?'0'+('1'-ef[i][j]):ef[i][j];
                    ss[i][l]=0;
                }
                forp(i,0,n)
                {
                    fg=1;
                    forp(j,0,n)
                    if(!strcmp(ss[i],de[j]))
                    {
                        fg=0;
                        break;
                    }
                    if(fg)break;
                }
                if(!fg)ans=min(ans,t0);
            }
            ptf("Case #%d: ",tcnt+1);
            if(ans>1000)puts("NOT POSSIBLE");else ptf("%d\n",ans);
    }
    return 0;
}
