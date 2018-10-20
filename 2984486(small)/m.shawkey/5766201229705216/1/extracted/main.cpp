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
#include <bitset>
#include <iostream>
using namespace std;

vector <vector <int> > tree;
int res[1006][1006];

int get_ans(int,int);


int main()
{
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	
	int t,n,t1,t2;
	
	cin>>t;
	for(int z=1;z<=t;z++)
	{
		cin>>n;
		tree.clear();
		tree.resize(n+1);
		for(int i=0;i<n-1;i++)
		{
			cin>>t1>>t2;
			tree[t1].push_back(t2);
			tree[t2].push_back(t1);	
		}
		memset(res,-1,sizeof res);
		for(int i=1;i<=n;i++)
		{
			get_ans(0,i);
		}
		int ans=-1;
		for(int i=1;i<=n;i++)
		{
			if(ans<res[0][i]) ans=res[0][i];
		}
		cout<<"Case #"<<z<<": "<<n-ans<<endl;
	}
	
	return 0;
}

int get_ans(int p,int c)
{
	if(res[p][c]!=-1) return res[p][c];
	vector <int> tov;
	vector <int> val;
	for(int i=0;i<tree[c].size();i++) if(p!=tree[c][i]) tov.push_back(tree[c][i]);
	if(tov.size()==0 || tov.size()==1) res[p][c]=1;
	else
	{
		val.resize(tov.size());
		for(int i=0;i<tov.size();i++)
		{
			val[i]=get_ans(c,tov[i]);
		}
		sort(val.rbegin(),val.rend());
		res[p][c]=1+val[0]+val[1];
	}
	return res[p][c];
}

/*
 * //problem A
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
}*/