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

int Q, N, L;

#define MAX_N 150
#define MAX_L 40

bool top[MAX_N][MAX_L];
bool bottom[MAX_N][MAX_L];
bool rep[MAX_N][MAX_L];

bool valid()
{
	vector< string > A;
	vector< string > B;
	FOR(i,0,N-1)
	{
		string s = "";
		FOR(j,0,L-1) s+= (rep[i][j]) ? "1" : "0";
		A.PB(s);
	}
	FOR(i,0,N-1)
	{
		string s = "";
		FOR(j,0,L-1) s+= (bottom[i][j]) ? "1" : "0";
		B.PB(s);
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	FOR(i,0,N-1) if (A[i] != B[i])return false;
	return true;
}

int solve()
{
	int p = 1;
	FOR(j,0,L-1)p*= 2;
	//printf("%d\n", L);	
	int best = -1;
	FOR(c,0,p)
	{
		FOR(i,0,N-1) FOR(j,0,L-1) rep[i][j] = top[i][j];
		
		int val = 0;
		FOR(j,0,L-1) if ( ((1 << j) & c) == (1 << j))
		{
			val++;
			FOR(i,0,N-1) rep[i][j] = !rep[i][j];
			//printf("%d ", i);
		}
		//printf("\n");
		
		if (valid())
		{
			if (best == -1 || val < best) best = val;
		}
	}
	
	return best;
}

int main()
{
	char z;
	scanf("%d",&Q);
	FOR(q,1,Q)
	{
		scanf("%d %d\n", &N, &L);
		FOR(i,0,N-1)
		{
			FOR(j,0,L-1)
			{
				scanf("%c",&z);
				top[i][j] = (z == '1');
				if (j != L-1) scanf(" ");
			}
			scanf("\n");
		}
		FOR(i,0,N-1)
		{
			FOR(j,0,L-1)
			{
				scanf("%c",&z);
				bottom[i][j] = (z == '1');
				if (j != L-1) scanf(" ");
			}
			scanf("\n");
		}
		int res = solve();
		printf("Case #%d: ", q);
		if (res == -1) puts("NOT POSSIBLE");
		else printf("%d\n", res);
	}
	return 0;
}
