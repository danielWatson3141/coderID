#include <stdio.h>
#include<algorithm>
#include<stack>
#include<cstring>
#include<queue>
#include<string>
#include<map>
#include<set>
#include<iostream>
using namespace std;
string s2[200];
int l,n;
bool cmp ( int a[], string s1[], string s2[], int lo )
{
	string g[200];
	for ( int i = 0; i < n; i++ )
	g[i]=s1[i];
	for ( int i = 0; i < n; i++ )
	{
		for (int j = 0; j < lo; j++ )
		{
			if (g[i][a[j]]=='0')
			g[i][a[j]]='1';
			else
			g[i][a[j]]='0';
		}
	}
	sort(g,g+n);
	for (int i = 0; i < n; i++ )
	if ( g[i]!=s2[i] )
	return false;
	return true;
}
int a[200];
int main ()
{
 freopen ("output.txt","w",stdout);
  freopen ("der.txt","r",stdin);
  int  t, o = 0,i;
  scanf("%d", &t );
  while ( t-- )
  {
  	scanf("%d%d",&n,&l);
  	string s1[200];
  	for ( i = 0; i < n; i++ )
  	cin>>s1[i];
  	for ( i = 0; i < n; i++ )
  	cin>>s2[i];
  	sort(s2,s2+n);
  	printf("Case #%d: ",++o);
  	int ans = 100000;
  	for ( i = 0; i < n; i++ )
  	{
  		int lo = 0;
  		for (int j = 0; j < l; j++ )
  		{
  			if ( s1[0][j]!=s2[i][j] )
  			a[lo++]=j;
  		}
  		if ( lo< ans && cmp(a,s1,s2,lo) )
  		ans=min(ans,lo);
  	}
  	if ( ans >= 100000)
  	puts("NOT POSSIBLE");
  	else
  	printf("%d\n",ans);
  	}
  fclose (stdout);
  return 0;
}
