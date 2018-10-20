#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <iterator>
#include <algorithm>

using namespace std;

const int INF = 0x0fffffff;
const size_t maxBits = 64;
int ans;
int minAns;

bool cmp( const bitset<maxBits>& lhs, const bitset<maxBits>& rhs )
{
    return lhs.to_ulong() < rhs.to_ulong();
}

void flipOutlits(int n, vector< bitset<maxBits> >& v)
{
    for(int i=0; i<v.size(); ++i)
    {
        v[i].flip(n);
    }
}

void dfs(int i, int l, vector< bitset<maxBits> >& v, vector< bitset<maxBits> >& target)
{
    if( i == l )
    {
        sort( v.begin(), v.end(), cmp );
        if( equal(v.begin(), v.end(), target.begin()) && ans < minAns )
        {
            minAns = ans;
        }
        return ;
    }

    dfs( i+1, l, v, target );

    if( ans < minAns )
    {
        flipOutlits(i, v);
        ++ans;
        dfs( i+1, l, v, target );
        flipOutlits(i, v);
        --ans;
    }
}

int main(int argc, char* argv[])
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
    int T;
    int icase = 1;
    cin>>T;
    while( T-- )
    {
        int n, l;
        cin>>n>>l;
        vector< bitset<maxBits> > v;
        vector< bitset<maxBits> > target;
        for(int i=0; i<n; ++i)
        {
            string str;
            cin>>str;
            bitset<maxBits> tmpbits(str);
            v.push_back(tmpbits);
        }
        for(int i=0; i<n; ++i)
        {
            string str;
            cin>>str;
            bitset<maxBits> tmpbits(str);
            target.push_back(tmpbits);
        }

        sort( target.begin(), target.end(), cmp );

        ans = 0;
        minAns = INF;
        dfs( 0, l, v, target );

        printf("Case #%d: ", icase++);
        if( minAns == INF )
            printf("NOT POSSIBLE\n");
        else
            printf("%d\n", minAns);
    }
	return 0;
}
