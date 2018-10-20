#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

#define pb(x) push_back(x)

typedef long long LL;

int permu[1010];
// good = 7131, bad = 15269
/*

*/
int main() {
	int T;

	cin>>T;

	string good = "GOOD";
	string bad = "BAD";

	for(int cid=1; cid <= T; cid++) {
		int N;
		cin>>N;
		for(int i=0; i < N; i++)
			cin>>permu[i];
		int firstHalf = 0;
		int secondHalf = 0;
		for(int i=0; i <= (N/2 - 1); i++)
			firstHalf += permu[i];
		for(int i=(N/2); i <= N-1; i++)
			secondHalf += permu[i];
		int diff = abs(firstHalf - secondHalf);
		cout<<"Case #"<<cid<<": ";
		if(5000 <= diff && diff <= 15000) cout<<good<<endl;
		else cout<<bad<<endl;
	}    
}
