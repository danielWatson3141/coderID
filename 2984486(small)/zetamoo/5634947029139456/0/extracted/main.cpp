#include <vector>
#include <iterator>
#include <list>
#include <map>
#include <math.h>
#include <cmath>
#include <set>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <string.h>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t,T=0;
    cin>>t;
    while(t--)
    {
        cout<<"Case #"<<++T<<": ";
        vector<string>v;
        vector<string>v1;
        string s;
        int n,l;
        cin>>n>>l;
        for(int f=0;f<n;f++)
        {
            cin>>s;
            v.push_back(s);
        }
        for(int f=0;f<n;f++)
        {
            cin>>s;
            v1.push_back(s);
        }
        sort(v1.begin(),v1.end());
        int ans=1000000;
        for(int f=0;f<n;f++)
        {
            vector<string>v2;
            v2=v;
            int counter=0;
            for(int f1=0;f1<l;f1++)
            {
                if(v1[0][f1]!=v2[f][f1])
                {
                    counter++;
                    for(int f2=0;f2<n;f2++)
                    {
                        if(v2[f2][f1]=='0')
                            v2[f2][f1]='1';
                        else
                            v2[f2][f1]='0';
                    }
                }
            }
            sort(v2.begin(),v2.end());
            if(v2==v1)
                ans=min(ans,counter);
        }
        if(ans==1000000)
            cout<<"NOT POSSIBLE\n";
        else
            cout<<ans<<endl;
    }
}
