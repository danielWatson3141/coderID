#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
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
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int t, tIndex, i, j, n;
int a[1002];

int main()
{
    freopen("C:\\Users\\ZLi\\CodeBlockCode\\Test\\GCJ2nd1B\\bin\\Debug\\C-small-attempt4.in", "r", stdin);
	freopen("C:\\Users\\ZLi\\CodeBlockCode\\Test\\GCJ2nd1B\\bin\\Debug\\output.txt", "w", stdout);

	cin>>t;
	for(tIndex = 1; tIndex <= t; tIndex++)
    {
        cin>>n;
        int good = 0, bad = 0;
        int counter = 0;
        for(i = 0; i < n; i++)
        {
            cin>>a[i];
            if(a[i] == i)
                counter++;
            else if(a[i] > i)
                good++;
            else
                bad++;
        }

        if(counter == n-1)
        {
            if(n%2 == 0)
                cout<<"Case #"<<tIndex<<": BAD"<<endl;
            else
                cout<<"Case #"<<tIndex<<": GOOD"<<endl;
        }
        else{
            if(good>bad)
                cout<<"Case #"<<tIndex<<": GOOD"<<endl;
            else
                cout<<"Case #"<<tIndex<<": BAD"<<endl;
        }
    }

    return 0;
}
