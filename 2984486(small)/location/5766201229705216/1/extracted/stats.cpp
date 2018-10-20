#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
struct S
{
	int a,b,c;
};
int a[1000000],b[1000000];
S Q[1000000];
string s;
int main()
{
	int n,l=0,i,j;
	scanf("%d", &n);
	for ( i = 1; i <= n; i++ )
	scanf ( "%d", &a[i] );
	int q;
	scanf("%d", &q);
	for ( i = 0; i < q; i++ )
	{
		scanf( "%d%d%d", &Q[i].a, &Q[i].b, &Q[i].c );
		b[i]=Q[i].c;
	}
	sort(b,b+q);
	for ( i = 0; i < q; i=j )
	{
		b[l++]=b[i];
		for ( j = i+1; j < q && b[j]==b[i]; j++ );
	}
	vector<vector<int> > v(l);
	for ( i = 1; i <= n; i++ )
	{
		v[lower_bound(b,b+l,a[i])-b].push_back(i);
	}
	for ( i = 0; i < q; i++ )
	{
		int k = lower_bound(b,b+l,Q[i].c)-b;
		if((lower_bound( v[k].begin(),v[k].end(),Q[i].a ))!=v[k].end() && *(lower_bound( v[k].begin(),v[k].end(),Q[i].a ))<=Q[i].b)
		s+='1';
		else
		s+='0';
	}
	cout<<s<<endl;
	return 0;
}
