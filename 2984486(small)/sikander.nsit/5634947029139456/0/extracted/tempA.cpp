// AUTHOR : SIKANDER MAHAN
// sikander_nsit
// PLAGIARISM IS BAD

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include<string.h>
#define tr(c,it) for(typeof(c.begin()) it=c.begin();it!=c.end();++it)
#define all(c) c.begin(),c.end()
#define mod 1000000007
#define itor(c) typeof(c.begin())
#define ll long long
#define vi vector<int>
#define vs vector<string>
#define si set<int>
#define msi multiset<int>
#define ii pair<int,int>
#define sii set<ii>
#define vii vector<ii>
#define vvi vector<vi>
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
    //ios::sync_with_stdio(false);
    freopen("input.txt","r",stdin);
    freopen("out.txt","w",stdout);
    ll t=0,i=0,j=0,n=0,m=0,k=0,l,num=0,temp=0,ans=0,a;
    cin>>t;
    string str;
    string outlet[200],device[200];
    set<ll> s,s1;
    for(i=0;i<t;++i)
    {
        cin>>n>>l;
        ans=100;
        s.clear();
        s1.clear();
        ll o[200]={0},d[200]={0};
        for(j=0;j<n;++j)
        {
            cin>>outlet[j];
            for(k=0;k<l;++k)
            {
                if(outlet[j][k]=='1')
                {
                    temp=1;
                    a=temp<<k;
                    o[j]+=a;
                }
            }
        }
        for(j=0;j<n;++j)
        {
            cin>>device[j];
            for(k=0;k<l;++k)
            {
                if(device[j][k]=='1')
                {
                    temp=1;
                    a=temp<<k;
                    d[j]+=a;
                }
            }
            s.insert(d[j]);
        }
        for(j=0;j<n;++j)
        {
            m=0;
            num=0;
            for(k=0;k<l;++k)
            {
                if(outlet[0][k]!=device[j][k])
                {
                    m++;
                    temp=1;
                    a=temp<<k;
                    num+=a;
                }
            }
            s1.clear();
            for(a=0;a<n;++a)
            {
                temp=o[a]^num;
                s1.insert(temp);
            }
            if(s==s1)
            {
                ans=min(ans,m);
            }
        }
        cout<<"Case #"<<i+1<<": ";
        if(ans<100)
        {
            cout<<ans;
        }
        else
        {
            cout<<"NOT POSSIBLE";
        }
        cout<<"\n";
    }
	return 0;
}
