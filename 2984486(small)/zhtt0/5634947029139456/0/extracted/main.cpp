#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
	ifstream f1("A-small-attempt0.in");
	ofstream f2("out.txt");
	int T;
	f1>>T;
	for(int tt=0;tt!=T;++tt)
	{
		f2<<"Case #"<<tt+1<<": ";
		int N,L;
		f1>>N>>L;
		vector<string> s;
		for(int i=0;i!=N;++i)
		{
			string temp;
			f1>>temp;
			s.push_back(temp);
		}
		vector<string> t;
		for(int i=0;i!=N;++i)
		{
			string temp;
			f1>>temp;
			t.push_back(temp);
		}
		sort(t.begin(),t.end());
		int ans=L+1;
		for(int i=0;i!=N;++i)
		{
			vector<bool> a;
			for(int j=0;j!=L;++j)
				a.push_back(s[i][j]==t[0][j]);
			vector<string> b=s;
			for(int j=0;j!=N;++j)
			{
				for(int k=0;k!=L;++k)
				{
					if(a[k]==false)
						b[j][k]='1'-s[j][k]+'0';
				}
			}
			sort(b.begin(),b.end());
			int flag=0;
			for(int j=0;j!=N;++j)
			{
				if(b[j]!=t[j])
				{
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				int c=0;
				for(int j=0;j!=L;++j)
				{
					if(a[j]==false)
						c++;
				}
				ans=min(ans,c);
			}
		}
		if(ans==L+1)
		f2<<"NOT POSSIBLE"<<endl;
		else
			f2<<ans<<endl;
	}
	return 1;
}