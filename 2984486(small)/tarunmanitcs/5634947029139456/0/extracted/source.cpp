#include<iostream>
#include<stdlib.h>
#include<vector>
#include<map>
#include<string>
using namespace std;
int main()
{
	freopen("C:\\Users\\Tarun\\Desktop\\ip.txt","r",stdin);
	freopen("C:\\Users\\Tarun\\Desktop\\op.txt","w",stdout);
	int i,j,k,l,n,t,c[200][200]={0},count,m;
	string s[200],r[200],a[200][200],b;
	cin>>t;
	for(m=1;m<=t;m++)
	{
		cout<<"Case #"<<m<<": ";
		cin>>n>>l;
		for(i=0;i<n;i++)
		{
			cin>>s[i];
		}
		for(i=0;i<n;i++)
		{
			cin>>r[i];
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				b="";count=0;
				for(k=0;k<l;k++)
				{
					if(s[i][k]!=r[j][k])
						b+='1';
					else
						b+='0';
				}
				c[i][j]=count;
				a[i][j]=b;
			}
		}
		vector<int >v;
		for(i=0;i<n;i++)
		{
			count=0;
			for(j=1;j<n;j++)
			{
				for(k=0;k<n;k++)
				{
					if(a[j][k]==a[0][i])
						break;
				}
				if(k!=n)
					count++;
				else
					break;
			}
			if(count==n-1)
			{
				count=0;
				for(j=0;j<l;j++)
				{
					count=count+a[0][i][j]-'0';
				}
				
				v.push_back(count);
			}
		}
		sort(v.begin(),v.end());
		if(v.size()>0)
		{
			cout<<v[0]<<endl;
		}
		else
			cout<<"NOT POSSIBLE\n";
	}
	
	return 0;
}