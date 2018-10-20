#include<bits/stdc++.h>

using namespace std;

#define s(a) scanf("%d",&a)
#define lls(a) scanf("%lld",&a)
#define ss(a) scanf("%s",a)
#define FOR(i,a,b) for(i=a;i<b;i++)

int main()
{
        freopen ("A-small-attempt3.in","r",stdin);
        freopen ("output.txt","w",stdout);
        int t;
        cin>>t;
        int test;
        FOR(test,1,t+1)
        {
                int n,l,i,j,k;
                cin>>n>>l;
                string plug[1000],dev[1000];
                FOR(i,0,n)
                {
                        cin>>plug[i];
                }
                FOR(i,0,n)
                {
                        cin>>dev[i];
                }
                sort(dev,dev+n);
                int ans=10000;
                int yes=1;
                FOR(i,0,l+1)
                {
                        int arr[20]={0};
                        FOR(j,0,i)
                                arr[j]=1;
                        string temp[1000];
                        
                        do{
                                FOR(j,0,n)
                                temp[j]=plug[j];
                                FOR(j,0,n)
                                        FOR(k,0,l)
                                                if(arr[k])
                                                {
                                                        if(temp[j][k]=='1')
                                                                temp[j][k]='0';
                                                        else
                                                                temp[j][k]='1';
                                                }
                                sort(temp,temp+n);
                                yes=1;
                                FOR(j,0,n)
                                        if(temp[j]!=dev[j])
                                                yes=0;
                                if(yes)
                                {
                                        ans=min(ans,i);
                                        break;
                                }
                        }while(prev_permutation(arr,arr+l));
                }
                cout<<"Case #"<<test<<": ";
                if(ans!=10000)
                {
                        cout<<ans<<"\n";
                }
                else
                {
                        cout<<"NOT POSSIBLE\n";
                }
        }
        return 0;
}
