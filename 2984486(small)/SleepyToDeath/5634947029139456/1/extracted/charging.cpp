#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

class tuple
{
	public:
	tuple( long long x0 , int a0 , int b0 ):
	x(x0),a(a0),b(b0)
	{}
	long long x;
	int a , b;
};

const int verybig = 99999999;

int n;
int l;

vector< long long > ov;
vector< long long > dv;
vector< tuple > v;

bool compare( tuple a , tuple b )
{
	return a.x<b.x;
}

int check( int p , int q )
{
	if ( q-p < n )
		return verybig;
	bool h1[200];
	bool h2[200];
	memset(h1,0,sizeof(h1));
	memset(h2,0,sizeof(h2));
	for ( int i=p ; i<q ; i++)
	{
		h1[v[i].a]=true;
		h2[v[i].b]=true;
	}
	for ( int i=0; i<n; i++)
		if (!h1[i] || !h2[i] )
			return verybig;
	int res = 0;
	for (long long i=0; i<l; i++)
		if (v[p].x>>i & 1)
			res ++;
	return res;
}


void work( int t )
{
	v.clear();
	ov.clear();
	dv.clear();
	cin>>n>>l;
	for (int i=0; i<n; i++)
	{
		string s;
		cin>>s;
		long long x = 0;
		for ( long long j=0; j<l; j++)
			x+=(long long)(s[j]-'0')<<j;
		ov.push_back( x );
	}

	for (int i=0; i<n; i++)
	{
		string s;
		cin>>s;
		long long x = 0;
		for ( long long j=0; j<l; j++)
			x+=(long long)(s[j]-'0')<<j;
		dv.push_back( x );
	}

	for (int i=0; i<n;i++)
		for (int j=0;j<n;j++)
			v.push_back( tuple( ov[i] xor dv[j] , i , j ) );
	
	sort( v.begin() , v.end() , compare );

	int i=0;
	int j=0;
	int len = v.size();
	int res = verybig;
	while ( i<len )
	{
		while ( j<len && v[i].x==v[j].x )
			j++;
		res = min( res , check(i,j) );
		i=j;
	}

	cout<<"Case #"<<t<<": ";
	if ( res>l ) 
		cout<<"NOT POSSIBLE"<<endl;
	else
		cout<< res<<endl;
}

int main()
{
	int t;
	cin>>t;
	for (int i=1;i<=t;i++)
		work( i );
}

