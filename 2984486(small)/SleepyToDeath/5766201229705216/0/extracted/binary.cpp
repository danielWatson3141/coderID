#include<iostream>
#include<vector>
using namespace std;

int verybig = 99999999;

class result
{
	public:
	result( int a, int b)
	:n(a),d(b)
	{}
	int n,d;
};

vector< vector<int> > g;
int n;

result check( int p , int f )
{
	int child=0;
	for (int i=0; i<g[p].size(); i++)
		if (g[p][i]!=f)
			child++;
	if ( child == 0 )
		return result( 1 , 0 );
	else if ( child == 1 )
	{
		for (int i=0; i<g[p].size(); i++)
			if (g[p][i]!=f)
			{
				result res = check(g[p][i],p);
				return result( res.n+1 , res.n );
			}
	}
	else if ( child == 2 )
	{
		result res(0,0);
		for (int i=0; i<g[p].size(); i++)
			if ( g[p][i]!=f )
			{
				result tmp = check(g[p][i],p);
				res.d += tmp.d;
				res.n += tmp.n;
			}
		res.n++;
		return res;
	}
	else if ( child > 2 )
	{
		vector<result> t;
		for (int i=0; i<g[p].size(); i++)
			if ( g[p][i]!=f )
				t.push_back( check( g[p][i] , p ) );
		result res(0,0);
		for (int i=0; i<t.size(); i++)
			res.n+=t[i].n;
		int v=verybig;
		for (int i=0; i<t.size(); i++)
			for(int j=0; j<t.size(); j++)
				if (i!=j)
				{
					int v1=t[i].d+t[j].d-t[i].n-t[j].n;
					if (v1<v)
						v=v1;
				}
		res.d=res.n+v;
		res.n++;
		return res;
	}

}

void work( int t )
{
	g.clear();
	cin>>n;
	for(int i=0; i<n; i++)
		g.push_back( vector<int>() );
	for( int i=0; i<n-1; i++)
	{
		int a , b;
		cin>>a>>b;
		a--;
		b--;
		g[a].push_back( b );
		g[b].push_back( a );
	}
	int res = verybig;
	for (int i=0; i<n; i++)
	{
		int tmp = check( i , -1 ).d;
		res = min( res , tmp );
	}

	cout<<"Case #"<<t<<": "<<res<<endl;
}

int main()
{
	int t;
	cin>>t;
	for (int i=1;i<=t;i++)
		work( i );
}

