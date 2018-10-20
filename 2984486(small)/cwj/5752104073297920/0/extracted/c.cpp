#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
using namespace std;


int main()
{
    freopen("C-small-attempt2.in","r",stdin);
    freopen("C-small-attempt2.out","w",stdout);

    int T,N,a[1005];
    int cwj=250*999;
    cin>>T;
    for(int ca=1;ca<=T;ca++)
    {
        cin>>N;
        for(int i=0;i<N;i++)
        {
            cin>>a[i];
        }
        int cnt=0;
        for(int i=0;i<N;i++)
        {
            for(int j=i+1;j<N;j++)
            {
                if(a[j]<a[i]) cnt++;
            }
        }
        if(cnt<(cwj-100000)) cout<<"Case #"<<ca<<": BAD"<<endl;
        else cout<<"Case #"<<ca<<": GOOD"<<endl;
    }
    return 0;
}
