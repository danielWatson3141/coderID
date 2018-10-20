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
#include <string.h>
#include <cstring>
#define oo (int)1e9
#define fill( a , v ) memset( a , v , sizeof (a) )
#define bits( x ) __builtin_popcount( x )
#define gcd( a , b ) __gcd( a, b )
#define lcm( a , b ) (a/gcd( a, b ) ) * b
#define s(n)scanf( "%d" , &n )
#define add push_back
const int mxn = 1000000 + 10;
typedef long long ll;
#define pii pair<double,double>
using namespace std;

int cs, T;
int N,L;

int convertToInteger(string s) {
	int r = 0;
	for(int i=s.size()-1, j=0;i >= 0;i--,j++)
		r += (1<<j) * (s[i]-'0');
	return r;
}

void printR(vector<int> a) {
	for(int i=0;i<a.size()-1;i++)
		cout << a[i] << " "; cout << a[a.size()-1] << endl;
}

int main() {
	//cout << convertToInteger("01") << endl;
	string s;
	s(T);

	while(T--) {

		cin >> N >> L;
		vector<int> src, dest;
		for(int i=0;i<N;i++) {
			cin >> s;
			src.add(convertToInteger(s));
		}
		for(int i=0;i<N;i++) {
			cin >> s;
			dest.add(convertToInteger(s));
		}

		sort(src.begin(), src.end());
		sort(dest.begin(), dest.end());
		//printR(src);
		//printR(dest);
		int ans = oo;
		bool found = 0;
		for(int i=0;i<(1<<L);i++) {
			vector<int> temp = src;

			for(int j=0;j<N;j++)
				temp[j] ^= i;

			sort(temp.begin(), temp.end());
			//printR(temp);
			if(temp == dest) {
				found = 1;
				ans = min(ans, bits(i));
			}
		}

		printf("Case #%d: ", ++cs);
		if(!found)
			puts("NOT POSSIBLE");
		else printf("%d\n", ans);
	}
}