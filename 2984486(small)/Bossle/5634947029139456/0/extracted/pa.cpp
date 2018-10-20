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

void print(int i){cout << i << " ";}
void print(string s){cout << s << endl;}
template<class T> void print(vector<T> v){for(int i=0;i<v.size();++i)print(v[i]);cout << endl;}

bool check(vector<string> v1, vector<string> v2, int n)
{
    for(int i=0;i<v1.size();++i)
    {
        for(int j=0;j<v1[i].size();++j)
            if((2<<j)&n)
                v1[i][j] = '0'+'1'-v1[i][j];
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    //print(v1);print(v2);
    for(int i=0;i<v1.size();++i)
        if(v1[i]!=v2[i])
            return false;
    return true;
}

int nums(int n)
{
    int resp=0;
    for(int i=1;i<=n;i*=2)
        if(i&n)
            resp++;
    return resp;
}

int main()
{
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    int tt;
    scanf("%d", &tt);
    for (int qq=1;qq<=tt;qq++)
    {
        printf("Case #%d: ", qq);

        int n,l;
        cin >> n >> l;
        vector<string> inp(n);
        for(int i=0;i<n;++i)
            cin >> inp[i];
        vector<string> out(n);
        for(int i=0;i<n;++i)
            cin >> out[i];

        int best = 20;
        for(int i=0;i<(2<<l);++i)
        {
            if(check(inp,out,i))
            {
                //cout << "YAY" << endl;
                best = min(best,nums(i));
            }
        }

        if(best == 20)
            cout << "NOT POSSIBLE" << endl;
        else
            cout << best << endl;
    }
}
