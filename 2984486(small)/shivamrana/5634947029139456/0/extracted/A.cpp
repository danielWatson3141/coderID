//ShivamRana...
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <list>
#include <deque>
#include <stack>
#include <iterator>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <functional>
#include <numeric>
#include <algorithm>
using namespace std;
#define ll long long
vector<string> req,giv;
int n,l;
ll ans=99999999ll;
void solve(int pos,ll count)
{
	if(pos==l)
		return;
	for(int i=0;i<n;i++)
	{
		if(giv[i][pos]=='1')
			giv[i][pos]='0';
		else giv[i][pos]='1';
	}
	count++;
	sort(giv.begin(),giv.end());
	if(req==giv)
		ans=min(ans,count);
	else
		solve(pos+1,count);
	count--;
	for(int i=0;i<n;i++)
	{
		if(giv[i][pos]=='1')
			giv[i][pos]='0';
		else giv[i][pos]='1';
	}
	sort(giv.begin(),giv.end());
	if(req==giv)
		ans=min(ans,count);
	else
		solve(pos+1,count);
}
int main()
{
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
    int t;
    cin>>t;
    for(int cs=1;cs<=t;cs++)
    {
        printf("Case #%d: ",cs);
        req.clear();
        giv.clear();
        cin>>n>>l;
        ans=99999999ll;
        for(int i=0;i<n;i++)
        {
        	string temp;
        	cin>>temp;
        	giv.push_back(temp);
        }
        for(int i=0;i<n;i++)
        {
        	string temp;
        	cin>>temp;
        	req.push_back(temp);
        }
        sort(req.begin(),req.end());
        solve(0,0);
        if(ans==99999999)
        	cout<<"NOT POSSIBLE\n";
        else
        	cout<<ans<<endl;
    }
    return 0;
}
