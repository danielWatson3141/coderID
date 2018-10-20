#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair

int check(vector<int> a,vector<int> b)
{
    int i=a.size(),j=b.size();
    if(i!=j)
        return 0;
    for(i=0;i<j;i++)
        if(a[i]!=b[i])
        return 0;
    return 1;
}
int main()
{
    int t;
    cin>>t;
    int q1=0;
    freopen("A-small-attempt0.in","r",stdin);
    freopen("op1.txt","w",stdout);
    while(t--)
    {
        q1++;
        int n,l,i,j,k;
        cin>>n>>l;
        string init[n],fin[n];
        for(i=0;i<n;i++)
            cin>>init[i];
        for(i=0;i<n;i++)
            cin>>fin[i];
        int mark[n];
        memset(mark,0,sizeof(mark));
        vector<vector<int> > v[n];
        vector<int> v1,pos;
        vector<int>::iterator it;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                v1.clear();
                for(k=0;k<l;k++)
                {
                    if(init[i][k]!=fin[j][k])
                        v1.pb(k);
                }
                v[i].pb(v1);
            }
        }
        int q,w;
        int min=100;
        /*for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                cout<<"i= "<<i<<" j= "<<j<<"\n";
                for(k=0;k<v[i][j].size();k++)
                    cout<<v[i][j][k]<<" ";
                cout<<"\n";
            }
        }
        */
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                memset(mark,0,sizeof(mark));
                //if(v[i][j].size()<min)
                min=v[i][j].size();
                mark[j]=1;
                for(q=0;q<n;q++)
                {
                    if(q==i)
                        continue;
                    for(w=0;w<n;w++)
                    {
                        if(w==j)
                        continue;
                        if(mark[w]==0&&check(v[i][j],v[q][w])){
                            mark[w]=1;
                            break;
                        }
                    }
                }
                for(w=0;w<n;w++){
                    if(mark[w]==0)
                        goto ab;
                    }
                    pos.pb(min);
                    //cout<<i<<" "<<j<<"\n";
              ab: continue;
            }
        }
        if(pos.size()==0)
            printf("Case #%d: NOT POSSIBLE\n",q1);
        else
        {
            sort(pos.begin(),pos.end());
            printf("Case #%d: %d\n",q1,pos[0]);
            //cout<<pos[0]<<"\n";
        }
    }
    return 0;
}
