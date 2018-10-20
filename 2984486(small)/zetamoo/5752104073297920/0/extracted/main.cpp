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
        srand(time(NULL));
        cout<<"Case #"<<++T<<": ";
        int n,x;
        double ans=0.88;
        cin>>n;
        for(int f=0;f<n;f++)
        {
            cin>>x;
            if(x==f)
                ans*=0.48;
        }
        double r=rand()/(double)RAND_MAX;
        if(r>ans)
            cout<<"BAD\n";
        else
            cout<<"GOOD\n";
    }
}
