//
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define INF 2147483647
#define PI 3.1415926535897932384626433832795
#define all(cont) cont.begin(),cont.end()
#define init(a,val) memset(a,val,sizeof(a))
#define F first
#define S second
#define mp make_pair
//GLOBAL
char s[100];
ll pos[200],l,n;
ll a[200],f[200],flip[200],temp[200];

ll todec(char s[])
{
    ll res=0;
    int i;
    for(i=0;s[i];i++)
    {
        res<<=1;
        s[i]=='1'?res|=1:1;
    }
    return res;
}
ll rec(int sh)
{
    ll minn=INF,i;
    if(sh==l)
    {
        ll totflip=0;
        for(i=0;i<n;i++)temp[i]=a[i];
        for(sh=0;sh<l;sh++)if(flip[sh]){for(i=0;i<n;i++)temp[i]^=(1<<sh);totflip++;}
        //for(i=0;i<l;i++)cout<<flip[i]<<' ';cout<<endl;
        //for(i=0;i<n;i++)cout<<temp[i]<<' ';cout<<endl;
        sort(temp,temp+n);

        for(i=0;i<n;i++)if(temp[i]!=f[i])return INF;
        return totflip;
    }
    //cout<<pos[sh]<<' ';
    if(pos[sh]&1){minn=rec(sh+1);}
    if(pos[sh]&2){flip[sh]=1;minn=min(minn,rec(sh+1));flip[sh]=0;}
    return minn;
}
int main()
{
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    int test_cases,Testno;

    ll i,sh,val;
    ll sett[200],fin[200];

    cin>>test_cases;
    for(Testno=1;Testno<=test_cases;Testno++)
    {
        printf("Case #%d: ",Testno);
//___________________________________________
        cin>>n>>l;
        init(sett,0);init(fin,0);init(pos,0);
        for(i=0;i<n;i++)
        {
            scanf("%s",s);
            a[i]=todec(s);
        }
        for(i=0;i<n;i++)
        {
            scanf("%s",s);
            f[i]=todec(s);
        }
        sort(f,f+n);
        //for(i=0;i<n;i++)cout<<a[i]<<' ';
        for(sh=0;sh<l;sh++)for(i=0;i<n;i++)if(a[i]&(1<<sh))sett[sh]++;
        for(sh=0;sh<l;sh++)for(i=0;i<n;i++)if(f[i]&(1<<sh))fin[sh]++;
        for(sh=0;sh<l;sh++)
        {
            if(sett[sh]==fin[sh])pos[sh]|=1;
            if(sett[sh]==n-fin[sh])pos[sh]|=2;
        }
        //for(i=0;i<l;i++)cout<<' '<<sett[i];
        //for(i=0;i<l;i++)cout<<' '<<fin[i];
        //for(i=0;i<l;i++)cout<<pos[i]<<' ';

        for(sh=0;sh<l;sh++)if(!pos[sh]){cout<<"NOT POSSIBLE";goto Done;}
        val=rec(0);
        val==INF?cout<<"NOT POSSIBLE":cout<<val;
//___________________________________________
        Done: printf("\n");
    }

return 0;
}
