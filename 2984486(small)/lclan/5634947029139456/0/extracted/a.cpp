#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
vector<string> s;
vector<string> w;
int ans,n,l,m,tmp;
bool used[60];
bool f;
bool check(int ll)
{
    sort(s.begin(),s.end());
    sort(w.begin(),w.end());
//    for(int i=0;i<n;i++)
//    {
//        cout<<s[i]<<' '<<w[i]<<endl;
//    }
    for(int i=0;i<ll;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(s[j][i]!=w[j][i])return false;
        }
    }
    return true;
}
void get(int i)
{
    //cout<<"now "<<i<<endl;
    if(i==l)
    {
        if(check(l))
        {
            f=true;
           /* cout<<"tmp : "<<tmp<<endl;
            for(i=0;i<n;i++)
            {
                cout<<s[i]<<endl;
            }
            cout<<endl;*/
            if(tmp<m)m=tmp;
        }
        return;
    }
    if(used[i]==0)get(i+1);
    else //used[i]==1;
    {
        get(i+1);

        for(int j=0;j<n;j++)
        {
           // cout<<"haha"<<endl;
            if(s[j][i]=='1')s[j][i]='0';
            else s[j][i]='1';
        }

        tmp++;
        get(i+1);
        tmp--;
        for(int j=0;j<n;j++)
        {
           // cout<<"haha"<<endl;
            if(s[j][i]=='1')s[j][i]='0';
            else s[j][i]='1';
        }

    }
    return ;
}
int main()
{
   // freopen("A-small-attempt0.in",'r',stdin);
    //freopen("aout.txt","w",stdout);
    int i,j,k;
    int r,t;
    cin>>t;
    r=1;
    string ee;
    while(t--)
    {
        ans=0;
        cin>>n>>l;
        s.clear();
        w.clear();
        for(i=0;i<n;i++)
        {
            cin>>ee;
            s.push_back(ee);
        }
        for(i=0;i<n;i++)
        {
            cin>>ee;
            w.push_back(ee);
        }
        int cs,cw;
        memset(used,0,sizeof(used));
        f=true;
        for(i=0;i<l;i++)
        {
            cs=cw=0;
            for(j=0;j<n;j++)
            {
                if(s[j][i]=='1')cs++;
                if(w[j][i]=='1')cw++;
            }

            if(cw==n-cw)
            {
                if(cw!=cs){f=false;break;}
                else used[i]=1;
            }else if(cw != cs)
            {
                if(cw != n-cs) {f=false;break;}
                else
                {
                    ans++;
                    for(j=0;j<n;j++)
                    {
                        if(s[j][i]=='1')s[j][i]='0';
                        else s[j][i]='1';
                    }
                }

            }
        }
        cout<<"Case #"<<r<<": ";
        r++;

        if(f==false)
        {
            cout<<"NOT POSSIBLE\n";
            continue;
        }

        f=false;
        m=1000000;
        tmp=0;
        get(0);
        if(f==false)
        {
            cout<<"NOT POSSIBLE\n";
            continue;
        }
        if(m!=1000000)
            cout<<ans+m<<endl;
        else
            cout<<ans<<endl;


    }
}
/*
4 10
0011101101 1001100101 1101010000 0111011000
1000101101 1100011000 0110010000 0010100101

*/
