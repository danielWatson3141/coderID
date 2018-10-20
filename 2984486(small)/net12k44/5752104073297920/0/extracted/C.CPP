#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstdio>
using namespace std;

int main(){
	freopen("c.inp","r",stdin);
	freopen("c.out","w",stdout);
	int test;
	scanf("%d",&test);
	srand(time(0));
	for(int T = 1; T <= test; ++T){
		printf("Case #%d: ",T);
		int n, m; scanf("%d",&n);
		while (n--) scanf("%d",&m);

		int t = rand()%2;
		if (t == 0) cout << "GOOD" << endl; else cout << "BAD" << endl;
	}
		
		
}
