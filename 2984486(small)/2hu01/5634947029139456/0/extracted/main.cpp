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

int t, tIndex, i, j, times;
int n, l;
vector<string> a;
vector<string> b;
int c[42];
string temp;
bool flag;
int minSteps, counter;

int main()
{
    freopen("C:\\Users\\ZLi\\CodeBlockCode\\Test\\GCJ2nd1A\\bin\\Debug\\A-small-attempt0.in", "r", stdin);
	freopen("C:\\Users\\ZLi\\CodeBlockCode\\Test\\GCJ2nd1A\\bin\\Debug\\output.txt", "w", stdout);

	cin>>t;
	for(tIndex = 1; tIndex <= t; tIndex++)
    {
        cin>>n>>l;
        a.clear();
        b.clear();
        for(i = 0; i < n; i++)
        {
            cin>>temp;
            a.push_back(temp);
        }

        for(i = 0; i < n; i++)
        {
            cin>>temp;
            b.push_back(temp);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        flag = true;
        for(i = 0; i < n; i++)
        {
            if(a[i] != b[i])
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            cout<<"Case #"<<tIndex<<": 0"<<endl;
        }
        else
        {
            minSteps = l+1;
            do {
                counter = 0;
                flag = true;
                for(j = 0; j < l; j++)
                {
                    if(a[0][j] != b[0][j])
                    {
                        c[j] = 1;
                        counter++;
                    }
                    else
                        c[j] = 0;
                }
                for(i = 1; i < n; i++)
                {
                    for(j = 0; j < l; j++)
                    {
                        if( (c[j] == 0 && a[i][j] != b[i][j]) || (c[j] == 1 && a[i][j] == b[i][j]))
                        {
                            flag = false;
                            break;
                        }
                    }
                }
                if(flag)
                {
                    if(counter < minSteps)
                        minSteps = counter;
                }
            } while ( next_permutation(a.begin(),a.end()) );

            if(minSteps == l+1)
                cout<<"Case #"<<tIndex<<": NOT POSSIBLE"<<endl;
            else
                cout<<"Case #"<<tIndex<<": "<<minSteps<<endl;
        }
    }

    return 0;
}
