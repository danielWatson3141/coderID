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

#define MAX 1047

bool G[MAX][MAX];
int Q, N;

bool deleted[MAX];
bool visited[MAX];
int st[MAX];

map< PII , int> MCH;
map< PII , int> MS;

int childrens(int root, int from)
{
	PII key = MP(root, from);
	if (MCH.find(key) != MCH.end()) return MCH[key];
	
	int c = 0;
	FOR(i,0,N-1) if (i != from && G[root][i])
	{
		c+=1;
		c+= childrens(i, root);
	}
	
	MCH[key] = c;
	return c;
}


int solve_from_root(int root, int from)
{
	PII key = MP(root, from);
	if (MS.find(key) != MS.end()) return MS[key];
	
//	cout << "pre root: " << root+1 << endl;
	int c = 0;
	int last=-1;
	FOR(i,0,N-1) if (i!=from && G[i][root])
	{
		c++;
		last = i;
	}
//	cout << c << " last " << last+1 << endl;
	
	int sum = 0;
	if (c == 0 || c == 2)
	{
	//	cout <<  " + childrens " << endl;
		FOR(i,0,N-1) if (i!=from && G[i][root]) sum+= solve_from_root(i, root);
	}
	else
	{
		if (c == 1) //we must delete
		{
			sum = 1 + childrens(last, root);
			//cout << "sum: " <<  sum << endl;
		}
		else
		{
			vector< PII > child;
			FOR(i,0,N-1) if (i!=from && G[i][root]) child.PB( MP( childrens(i, root), i)  );
			sort(child.begin(), child.end());
		//	cout << "child: ";
		//	FOR(i,0,c-1) cout << child[i].fi << " "; cout << endl;
			FOR(i,0,c-3) sum+= 1 + child[i].fi;
			
			//cout << sum << " + childrens " << endl;
			
			FOR(i,c-2,c-1) sum+= solve_from_root(child[i].se, root);
		}
	}
	
	MS[key] = sum;
	return sum;
}

int solve()
{
	int best = INF;
	FOR(root,0,N-1)
	{
	//	cout << "skusam z roota " << root+1 << endl;
		int res = solve_from_root(root, -1);
	//W	cout << "potrebujem: " << res << endl;
		best = min(best, res);
	}
	return best;
}

int main()
{
	int a, b;
	scanf("%d",&Q);
	FOR(q,1,Q)
	{
		MCH.clear();
		MS.clear();
		
		scanf("%d",&N);
		FOR(i,0,N-1) FOR(j,0,N-1) G[i][j] = false;
		FOR(i,0,N-1) st[i] = 0;
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
