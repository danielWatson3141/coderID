#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include<cstdio>
using namespace std;

vector<string> need;
vector<string> have;

int tran(const string &a1,const string a2,vector<int> &pos)
{
    int n=a1.size();
    for(int i=0;i<n;i++)
    {
        if(a1[i]!=a2[i]) pos.push_back(i);
    }
    return pos.size();
}

bool compare(vector<string> &vs1,vector<string> vs2)
{
    int n=vs1.size();
 //   sort(vs1.begin(),vs1.end());
 //   sort(vs2.begin(),vs2.end());
    for(int i=0;i<n;i++)
    {
        if(vs1[i]!=vs2[i]) return false;
    }
    return true;
}

string change(const string &s,vector<int> &pos)
{
    string ans=s;
    for(int i=0;i<pos.size();i++)
    {
        int j=pos[i];
        if(ans[j]=='0') ans[j]='1';
        else ans[j]='0';
    }
    return ans;
}

int main()
{
    freopen("A1.in","r",stdin);
    freopen("A1.txt","w",stdout);
    int t,n,len;
    cin>>t;
    int cs=0;
    while(t--)
    {
        cin>>n>>len;
        need.clear();
        have.clear();
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            have.push_back(s);
        }
     //   for(int i=0;i<n;i++)
     //       cout<<have[i]<<endl;
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            need.push_back(s);
        }
        sort(need.begin(),need.end());
       //         for(int i=0;i<n;i++)
       //     cout<<need[i]<<endl;
        int ans=len+1;
        for(int i=0;i<n;i++)
        {
            vector<int> pos;
            int tm=tran(need[0],have[i],pos);
       //     for(int i=0;i<pos.size();i++) cout<<pos[i]<<endl;
            vector<string> tmp;
            for(int j=0;j<n;j++) tmp.push_back(change(have[j],pos));
            sort(tmp.begin(),tmp.end());
        //            for(int j=0;j<n;j++)
       //     cout<<tmp[j]<<endl;
            if(compare(need,tmp)) ans=min(ans,tm);
        }
        cout<<"Case #"<<++cs<<": ";
        if(ans==len+1) cout<<"NOT POSSIBLE"<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}



