//
// Saurav Shekhar
#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-7
#define INF 2000000000
#define P 1000000009
typedef  int ui;
typedef unsigned long long llu; //I64d
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

const ui LIM = 1002;
int req[LIM][LIM];
int count1[LIM][LIM];
vi  Adjlist[LIM];

int countc(int u, int parent)
{
	if(count1[u][parent] != -1) return count1[u][parent];

	int v;
	int countp = 1;

	for(ui  i=0; i<Adjlist[u].size(); i++) {
		v = Adjlist[u][i];
		if(v == parent) continue;

		countp += countc(v, u);
	}

	count1[u][parent] = countp;
	return countp;
}

bool comp(ii a, ii b)
{
	return a.second < b.second;
}

void print_mat(int size)
{
	for(int i=0; i<size; i++)  {
		for(int j=0; j<size; j++)
			cout << req[i][j] << " " ;
		cout << "\n";
	}
	return ;
}

int mindel(int u, int parent)
{
	if(req[u][parent] != -1) return req[u][parent];
	ui v;
	ui del = 0;
	vector<ii> reqd;

	if(Adjlist[u].size() == 1 && parent != 0) {	//leaf
		req[u][parent] = 0;
		return del;
	}

	for(ui i=0; i<Adjlist[u].size(); i++) {
		v = Adjlist[u][i];
		if(v == parent) continue;

		reqd.push_back( ii(v, mindel(v, u)) );

	}

	if(reqd.size() == 1) {
		del = count1[ reqd[0].first ][ u ];
		req[u][parent] = del;
		return del;
	} 

	sort(reqd.begin(), reqd.end(), comp);
	

	del += req[ reqd[0].first ][ u ] + req[ reqd[1].first ][ u ];

	for(int i=2; i<reqd.size(); i++) {
		del += count1[ reqd[i].first ][ u ];
	}

	req[u][parent] = del;
	return del;
}

int main()
{
  ui T,qq;
  int N, x, y;
  for(cin>>T, qq=1; qq<=T; qq++) {
	printf("Case #%u: ",qq);
		cin >> N;
		for(int i=0; i<LIM; i++) Adjlist[i].clear();
		memset(req, -1, sizeof(req));
		memset(count1, -1, sizeof(req));

		for(ui i=1; i<N; i++) {
			scanf("%d%d", &x, &y);
			Adjlist[x].push_back(y);
			Adjlist[y].push_back(x);
		}
		int ans, minans = INF;
		for(ui i=1; i<=N; i++) {
			ans = countc(i,0);
			ans = mindel(i,0);
			if(minans > ans) minans = ans;
		}
		//print_mat(N);
		cout << minans << "\n";

  }
	
  return 0;
}
