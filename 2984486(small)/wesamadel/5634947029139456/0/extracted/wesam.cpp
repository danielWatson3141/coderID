#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>

using namespace std ;

string i_list [15] ;
vector<string> tmp ;
int t,N,L ;

bool test (vector<int> ret)
{
	int n= ret.size() ;
	vector<string> tmp2 = tmp;

	for(int i=0;i<n;i++)
		for(int j=0;j<N;j++)
			if(tmp2[j][ret[i]] == '1')
				tmp2[j][ret[i]] = '0';
			else
				tmp2[j][ret[i]] = '1';

	sort(tmp2.begin(),tmp2.end());

	for(int i=0;i<N;i++)
		if(tmp2[i] != i_list[i])
			return false;

	return true;
}

int solve (int cnt , int cur , vector<int> ret)
{

	if(test(ret))
		return cnt ;

	if(cur >= L)
	{
		return 10000 ;
	}

	int m1  = 10000;

	ret.push_back(cur);
	m1 = min(m1,solve(cnt+1,cur+1,ret));
	ret.pop_back() ;


	m1 = min(m1,solve(cnt,cur+1,ret));

	return m1 ;
}






int main ()
{
	freopen("out.txt","w",stdout) ;



	cin>>t;
	string s;
	int v ,c =0 ;

	while(t--)
	{
		c++;

		cin>>N>>L ;
		tmp.clear() ;


		for(int i=0;i<N;i++)
			cin>>s,tmp.push_back(s);
		for(int i=0;i<N;i++)
					cin>>i_list[i] ;

		sort(i_list,i_list+N);

		vector<int> ret;
		v = solve(0,0,ret);


		if(v < 10000)
			printf("Case #%d: %d\n",c,v);
		else
			printf("Case #%d: NOT POSSIBLE\n",c);

	}

	return 0;
}
