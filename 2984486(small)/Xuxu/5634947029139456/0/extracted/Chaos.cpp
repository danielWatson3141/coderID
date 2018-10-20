#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
bool same(vector<string> &a,vector<string> &b)
{
	for (int ii=0;ii<a.size();++ii)
	{
		if (a[ii] != b[ii])
			return false;
	}
	return true;
}
int main()
{
	ifstream fin("A-small-attempt2.in");
	ofstream fout("Chaos.out");
	int t;
	fin>>t;
	for (int k=0;k<t;++k)
	{
		int n,l;
		fin>>n>>l;
		string ss;
		vector<string> s;
		for (int i=0;i<n;++i)
		{
			fin>>ss;
			s.push_back(ss);
		}
		vector<string> def;
		for (int i=0;i<n;++i)
		{
			fin>>ss;
			def.push_back(ss);
		}
		sort(def.begin(),def.end());
		int ans = l+1;
		for (int i=0;i<s.size();++i)
		{
			int count = 0;
			vector<string> comp(n);
			for (int j=0;j<l;++j)
			{
				if (s[i][j] != def[0][j])
				{
					count++;
					for (int r=0;r<n;++r)
					{
						if (s[r][j] == '1')
							comp[r] += '0';
						else
							comp[r] += '1';
					}
				}
				else
				{
					for (int r=0;r<n;++r)
					{
						comp[r] += s[r][j];
					}
				}
			}
			sort(comp.begin(),comp.end());
			if (same(comp,def) && count < ans)
				ans = count;
		}
		if (ans <= l)
			fout<<"Case #"<<k+1<<": "<<ans<<endl;
		else
			fout<<"Case #"<<k+1<<": NOT POSSIBLE"<<endl;
	}
	return 0;
}