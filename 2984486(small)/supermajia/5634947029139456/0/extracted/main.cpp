#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
int original[11];
string outlet[15];
string device[15];
int n,l;
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int cas = 1;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>l;
        for(int i=1;i<=n;++i)
            cin>>outlet[i];
        for(int i=1;i<=n;++i)
            cin>>device[i];
        for(int i=1;i<=10;++i)
            original[i] = i;
        int small = 99999;
        bool success = 0;
        do
        {
            int current = -1;
            int acnt = 0;
            int i;
            for(i=1;i<=n;++i)
            {
                int temp = 0;
                int cnt = 0;
                for(int j=0;j<l;++j)
                {
                    temp*=2;
                    if(device[i][j]!=outlet[original[i]][j])
                    {
                        temp+=1;
                        cnt++;
                    }
                }
                if(current==-1)
                {
                    acnt = cnt;
                    current = temp;
                }
                if(current!=temp)
                    break;
            }
            if(i==n+1)
            {
                //cout<<current<<endl;
                success = 1;
                small = min(small,acnt);
            }
        }while(next_permutation(original+1,original+n+1));
        cout<<"Case #"<<cas++<<": ";
        if(success)
        {
            cout<<small<<endl;
        }
        else
            cout<<"NOT POSSIBLE"<<endl;
    }
    return 0;
}
