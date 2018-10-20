#include<bits/stdc++.h>
using namespace std;
int n,l;
string ou[200],de[200];
int oub[50],deb[50];
void change(int i)
{
	oub[i]=n-oub[i];
	for(int j=0;j<n;j++)
		ou[j][i]=(ou[j][i]=='0')?'1':'0';
}
bool check()
{
	bool used[200]={0};
	for(int i=0;i<n;i++)
	{
		bool ok=0;
		for(int j=0;j<n;j++)
			if(de[i]==ou[j] && used[j]==0){
				used[j]=1;
				ok=1;
				break;
			}
		if(!ok)
			return false;
	}
	return true;
}
int dfs(int i)
{
	if(i==l)
		return check()?0:l+10;
	if(oub[i]==deb[i] && n-oub[i]==deb[i])
	{
		int a=dfs(i+1);
		change(i);
		int b=dfs(i+1)+1;
		change(i);
		if(a<b){
			return a;
		}else{ 
			return b;
		} 
	}
	else if(oub[i]==deb[i])
		return dfs(i+1);
	else if(n-oub[i]==deb[i])
	{
		change(i);
		int temp = 1+dfs(i+1);
		change(i);
		return temp;
	}
	return l+10;
}
int main()
{
	//ios::sync_with_stdio(false);
	int T;
	scanf("%d",&T);
	for(int no=1;no<=T;no++)
	{
		scanf("%d %d",&n,&l);
		for(int i=0;i<n;i++)
			cin>>ou[i];
		for(int i=0;i<n;i++)
			cin>>de[i];
		memset(oub,0,sizeof oub);
		memset(deb,0,sizeof deb);
		for(int i=0;i<l;i++)
			for(int j=0;j<n;j++)
				if(ou[j][i]=='1')
					oub[i]++;
		for(int i=0;i<l;i++)
			for(int j=0;j<n;j++)
				if(de[j][i]=='1')
					deb[i]++;
		int ans=dfs(0);
		if(ans>l)
			printf("Case #%d: NOT POSSIBLE\n",no);
		else
			printf("Case #%d: %d\n",no,ans);
	}
}

