#include <iostream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cctype>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;

int a[1005][1005];
int maxchild;
int dfs(int father, int current)
{
    
    if((a[current][0] == 1) || (father != -1 && a[current][0] <= 2))
        return 1;
    int max1 = -1;
    int max2 = -1;
    for(int i = 1; i <= a[current][0]; i++)
    {
        if(a[current][i] != father)
        {

            int temp = dfs(current, a[current][i]);
            //cout<<temp<<" "<<current<<" "<<a[current][i]<<" "<<a[current][0]<<endl;
            if(temp > max1)
            {
                max2 = max1;
                max1 = temp;
            }
            else
            {
                if(temp > max2)
                {
                    max2 = temp;
                }
            }
        }
    }
    //cout<<max1<<" a "<<max2<<endl;
    if(max1 == -1 || max2 == -1) return 1;
    return 1+max1+max2;
}
int main() {
    int Case = 1;
    int t,n,l,i,j;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i = 1 ; i < 1005; i++)
        {
            a[i][0] = 0;
        }
        int e1,e2;
        for(i = 1 ; i < n; i++)
        {
            cin>>e1>>e2;

            a[e1][++a[e1][0]] = e2;
            a[e2][++a[e2][0]] = e1;
        }
        //for(i = 1; i <= n; i++)
        //    cout<<a[i][0]<<endl;
        int maxnode = -1;
        for(i = 1; i <= n;i++)
        {
            int temp =dfs(-1, i);
            //cout<<temp<<endl;
            maxnode = max(temp, maxnode);
        }
        cout<<"Case #"<<Case++<<": "<<n - maxnode<<endl;
    }
    
    return 0;
}
