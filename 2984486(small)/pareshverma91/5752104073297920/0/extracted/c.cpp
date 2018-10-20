
/*Paresh Verma*/
#include <vector>
#include <list>
#include <map>
#include <set>
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
#include <cstring>
#include <queue>		//max heap implementation
#include <limits.h>

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define mkp make_pair
#define fi first
#define se second
#define LL long long
#define fill(x,y) memset(x, y, sizeof(x))
#define debug(a) { for( typeof(a.begin()) it = a.begin() ; it != a.end() ; it++ ) cout << *it << " "; cout << endl; }

using namespace std;

//class comparators for queue and others
class classcomp{
	public:
		bool operator() (const int& l, const int& r)const{
			return l<r;
		}
};

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};


int main(){
	int T;
	scanf("%d", &T);
	for(int p =1; p<=T; p++) {
		printf("Case #%d: ", p);
		int n;
		scanf("%d", &n);
		vector<int> x(n);
		int i,j,k;
		for(i=0; i<n;i++){
			scanf("%d",&j);
			x[i] = (j);
		}
		bool good = false;
		for(i=0;i<n;i++){
			if(x[i] == i){
				good = true;
			}
		}
		if (good)
			printf("GOOD\n");
		else
			printf("BAD\n");

	}

	return 0;
}
