/* 
 * Author: Mohamad Shawkey
 * Created on April 12, 2014, 2:59 PM
 */
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <set>
#include <iostream>
using namespace std;

vector <string> out,dev,mod;
void modify(int );
int main()
{
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	
	

	int t,n,l,ans,t1,t2;
	cin>>t;
	
	for(int z=1;z<=t;z++)
	{
		cin>>n>>l;
		out.resize(n);
		dev.resize(n);
		for(int i=0;i<n;i++) cin>>out[i];
		for(int i=0;i<n;i++) cin>>dev[i];
		
		ans=-1;
		for(int i=0;i<n;i++)
		{
			t1=0;
			mod=out;
			for(int j=0;j<l;j++)
			{
				if(dev[0][j]!=out[i][j]) {t1++; modify(j);}
			}
			set <string> st;
			for(int j=0;j<n;j++) {st.insert(mod[j]); st.insert(dev[j]);}
			if(st.size()==n && (ans==-1 || ans>t1)) ans=t1;
		}
		if(ans>=0) cout<<"Case #"<<z<<": "<<ans<<endl;
		else cout<<"Case #"<<z<<": "<<"NOT POSSIBLE"<<endl;
	}
	
	
	return 0;
}

void modify (int in)
{
	for(int i=0;i<mod.size();i++)
	{
		if(mod[i][in]=='0') mod[i][in]='1';
		else mod[i][in]='0';
	}
}