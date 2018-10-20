#include<bits/stdc++.h>
using namespace std;
int edg[16][16]={0};
int tdeg[16];
int n;
  int del[16]={0};
  int donec=0;
int dfs(int at,int *done)
{
   // cout<<"dfs for"<<at;
    done[at]=1;
    donec++;
    int i=0;
    int deg=0;
    int res=1;
    for(i=1;i<=n;i++)
    {
        if(edg[at][i]==1 && done[i]!=1 && del[i]!=1)
        {
            deg++;
            res=res&(dfs(i,done));
        }
    }
   // cout<<"deg pof "<<at<<" "<<deg;
    if(deg==0 || deg==2)
    {
        return 1;
    }
    return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	int t=1,T;
	cin>>T;
	while(t<=T)
	{


        int i2,a,b,j;
        cin>>n;
        int deg[16]={0};
        for(a=1;a<=n;a++)
        {
            for(b=1;b<=n;b++)
            {
                edg[a][b]=0;
            }

        }

        for(i2=1;i2<n;i2++)
        {
            cin>>a>>b;
            edg[a][b]=1;
            edg[b][a]=1;
            deg[a]++;
            deg[b]++;
        }
        long long till=(1<<(n)),i,tempi;
        int mincd=100000;
      int cd=0;
        for(i=0;i<till;i++)
        {
     //       cout<<endl<<"Perm : "<<i;
            for(j=1;j<=n;j++)
            {
                tdeg[j]=deg[j];
            }
            cd=0;
            tempi=i;
            for(j=0;j<n;j++)
            {
                if(tempi%2==1)
                {
                    cd++;
                    del[j+1]=1;

                }
                else
                    del[j+1]=0;
                tempi>>=1;
       //         cout<<del[j+1]<<" ";
            }

            int k;
            for(j=1;j<=n;j++)
            {
                if(del[j]!=1)
                {
                    for(k=1;k<=n;k++)
                    {
                        if(edg[j][k]==1 && del[k]==1)
                            tdeg[j]--;
                    }

                }
            }
         //   cout<<"tdeg ";
          /*  for(j=1;j<=n;j++)
                cout<<tdeg[j]<<" ";*/
            int done[16]={0};
            int root=-1;
            int count[4]={0};

            if(n-cd>=3)
            {
                for(j=1;j<=n;j++)
                {
                    if(del[j]==1)
                        continue;
                    if(tdeg[j]==2)
                    {
                        root=j;
                    }
                    if(tdeg[j]>3)
                    {

                        break;
                    }
                    count[tdeg[j]]++;
                }
           //     cout<<" j is "<<j;
                if(j!=n+1)
                    continue;
             //   cout<<"c2 is "<<count[2];
                if(count[2]!=1)
                {
                    continue;
                }
               // cout<<"root is "<<root;
                //cout<<"del is ";
          /*      for(j=1;j<=n;j++)
                {
                    cout<<del[j]<<" ";
                }*/
                donec=0;
                if(dfs(root,done)==1 && donec==n-cd)
                {
                  //  cout<<"okay with"<<cd;
                    if(cd<mincd)
                        mincd=cd;
                }
            }
            else if(n-cd==1)
            {
                if(cd<mincd)
                        mincd=cd;
            }

        }
        cout<<"Case #"<<t<<": "<<mincd<<endl;

        t++;
	}
	return 0;
}
