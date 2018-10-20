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

using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    int i;
    for(i=1;i<=t;i++)
    {
        int n,l,i;
        scanf("%d %d",&n,&l);
        string current;
        string reqcurrnet,str;
        for(i=0;i<n;i++)
        {
                cin>>current;
        }
        for(i=0;i<n;i++)
        {
           cin>>reqcurrnet;
        }
        for(i=0;i<n;i++)
        str[i]=current.substr(i*(l+1),l);
    }
    return 0;
}
