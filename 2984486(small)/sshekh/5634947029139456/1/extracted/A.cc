//
// Saurav Shekhar
#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-7
#define INF 2000000000
#define P 1000000009
typedef unsigned int ui;
typedef unsigned long long llu; //I64d
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

const ui LIM = 152;
const ui ML = 40; 
llu dist1[LIM][LIM];
llu dist2[LIM][LIM];

llu distance(string a, string b, ui size)
{
	//cout << "a = "<<a << " b = "<< b << "\n";
	llu sum = 0;
	for(ui i=0; i<size; i++)
		if(a[size - i - 1] != b[size - i - 1])
			sum = sum + (1<<i);

	//cout << "sum = " <<sum<<"\n";
	 	return sum;
}

void print_mat(ui size)
{
	for(ui i=0; i<size; i++) {
 		for(ui j=0; j<size; j++)
 			cout << dist1[i][j] << " ";
 		cout << "\n";
	}
}

int main()
{
  ui T,qq;
  string ansn = "NOT POSSIBLE";
  
  ui N,L;
  string flow[LIM];
  string reqd[LIM];
  for(cin>>T, qq=1; qq<=T; qq++) {
	printf("Case #%u: ",qq);
	cin >> N >> L;
	for(ui i=0; i<N; i++) cin >> flow[i];
	for(ui i=0; i<N; i++) cin >> reqd[i];

		for(ui i=0; i<N; i++)
			for(ui j=0; j<N; j++) {
				dist1[i][j] = distance(flow[i], reqd[j], L);
				dist2[j][i] = dist1[i][j];
			}
			//print_mat( N);
		for(ui i=0; i<N; i++) { sort(dist1[i], dist1[i]+N); sort(dist2[i], dist2[i]+N); }

		

		ui minans = INF, ans;

		llu r1[LIM];
		for(ui i=0; i<N; i++)
			r1[i] = dist1[0][i];

		for(llu i=0; i<N; i++) {

			bool flag = true;
			for(ui j=0; j<N; j++) {
				if(binary_search(dist1[j], dist1[j] + N, r1[i]) && binary_search(dist2[j], dist2[j] + N, r1[i])) { ; }
				else flag = false;
			}

			if(flag) {
				ans = __builtin_popcount (r1[i]);
				//cout << ans << " ";
				if(minans > ans) {
					//cout << minans << " > " << ans << "\n";
					minans = ans;
				}
			}
		}

		if(minans != INF)cout << minans << "\n";
		else cout << ansn << "\n";
	
  }
	
  return 0;
}
