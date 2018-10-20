//--BY--©--WA-
#include<iostream> //cout, cin, getline

#include<algorithm> //find, reaplce, swap, sort, lower_bound, uper_bound, binnary_search...
#include<vector> //push_back, size, resize, 
#include<string>
#include<queue> //empty, front, back, push
#include<stack> //push, top, empty
#include<map>
#include<set>
#include<list> //spajazny zoznam .. vsetko v O(1)

#include<stdio.h> //printf, scanf, getchar, putchar
#include<math.h> //cos, sin, exp, pow, sqrt,  flnoor, cell
#include<stdlib.h> //atio, atl, strtod, strtol, atof, abs, 
#include<ctype.h> //isalnum, isalpha, isdigit, islower, isupper, toupper, tolower, 
#include<string.h> //strcm, strstr, strlen,

using namespace std;

#define FOREACH(obj,it) for(__typeof(obj.begin()) it = (obj).begin(); it != (obj).end(); (it)++)
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define FORD(i,a,b) for(int i=a; i>=b; i--)
#define REP(i,a,b) for(int i=a; i<b; i++)
#define DEBUG(V,S) FOR(i,0,S-1){cout << i << ". " << V[i] << endl;}

#define PB push_back
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define MP make_pair
#define fi first
#define se second

#define SIZE(s) (int) (s).size()

#define INF 987654321
#define EPS 1e-9
#define ld long double // %Lf, double %lf
#define ll long long   // %llf

//--------------------------------------------------------------------------------------

#define MAX 20

bool G[MAX][MAX];
int Q, N;

bool deleted[MAX];
bool NG[MAX][MAX];
bool visited[MAX];

bool valid_from_root(int root, int from)
{
	visited[root] = true;
	int c = 0;
	FOR(i,0,N-1) if (i != from  && NG[root][i]) c++;
	if (c == 0) return true;
	if (c != 2) return false;
	FOR(i,0,N-1) if (i != from && NG[root][i])
	{
		if (!valid_from_root(i, root))
			return false;
	}
	return true;
}

bool valid()
{
	FOR(i,0,N-1)
		if (!deleted[i])
		{
			FOR(j,0,N-1) visited[j] = false;
			
			//cout << "Skusam root" << i << endl;
			if (valid_from_root(i,-1))
			{
				int c = 0;
				FOR(j,0,N-1) if (!deleted[j]) c++;
				FOR(j,0,N-1) if (visited[j]) c--;
				
				if (c == 0) return true;
			}
		}
	return false;
}

void delete_node(int node)
{
	FOR(i,0,N-1)
		if (NG[node][i])
		{
			NG[node][i] = false;
			NG[i][node] = false;
		}
	deleted[node] = true;
}

int solve()
{
	int p = 1;
	FOR(j,0,N-1)p*= 2;	
	int best = INF;
	FOR(c,0,p)
	{
		//cout << c << endl;
		FOR(i,0,N-1) FOR(j,0,N-1) NG[i][j] = G[i][j];
		FOR(i,0,N-1) deleted[i] = false;
		
		FOR(i,0,N-1) if ( ((1 << i) & c) == (1 << i))
		{
		//	cout << "mazem - " << i << endl;
			delete_node(i);
		}
		
		if (valid())
		{	
			int val = 0;
			FOR(i,0,N-1) if (deleted[i]) val++;
	//		cout << "valid: " << val << endl;
			best = min(best, val);
		}
		
	}
	
	return best;
}

int main()
{
	int a, b;
	scanf("%d",&Q);
	FOR(q,1,Q)
	{
		scanf("%d",&N);
		FOR(i,0,N-1) FOR(j,0,N-1) G[i][j] = false;
		FOR(i,0,N-2)
		{
			scanf("%d %d",&a, &b);a--; b--;
			G[a][b] = true;
			G[b][a] = true;
		}
		int res = solve();
		printf("Case #%d: %d\n", q, res);
	}
	
	return 0;
}
