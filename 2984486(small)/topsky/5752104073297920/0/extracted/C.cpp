#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <ctime>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
#define PB push_back
#define MP make_pair
#define FOR(i, n) for(int i = 0; i < (n); i++)
#define REP(i, a, b) for(int i = (a); i <= (b); i++)
#define CLR(x, a) memset(x, a, sizeof(x))
//#define L(x) ((x) << 1)
#define R(x) (((x) << 1) + 1)
#define LB(x) ((x)&(-(x)))
#define SL(x) (1 << (x))
#define X first
#define Y second
const int MAXN = 1000 + 20;

int n, m = 120;

double qc1(int a[]) {
    double sq = 0;
    for (int i = 0; i < 1000 - 1; i++) {
        //sq = (a[i] - a[i + 1]) * (a[i] - a[i + 1]);
        for (int j = i + 1; j < 1000; j++) {
            if (a[i] < a[j]) {
                sq ++;
                //					sum += Math.pow((a[i] - a[j]), 2);
            } else {
                //					sum -= Math.pow((a[i] - a[j]), 2);
                sq --;
            }
        }
    }
    //		for (int i = 0; i < N - 1; i++) {
    //			sum += (a[i] - a[i + 1]) * (a[i] - a[i + 1]);
    ////			if (a[i] < a[i + 1]) sum += ();
    ////			else sum--;
    //		}
    // if (sq > 0) {
    // 	if (type)System.out.print("t ");
    // 	else System.out.print("p ");
    // 	System.out.println(sq + ", " + sum);
    // }
    return sq;
}
int a[1000];
int main(){
    
	int T; cin >> T;
	FOR(cas, T){
		printf("Case #%d: ", cas + 1);
		cin >> n;
		FOR(i, 1000) {
			cin >> a[i];
		}
		double res = qc1(a);
		if (res > 0) {
			if (res < 11000) cout << "GOOD" << endl;
			else cout << "BAD" << endl;
		} else {
			cout << "GOOD" << endl;
		}
	}
}