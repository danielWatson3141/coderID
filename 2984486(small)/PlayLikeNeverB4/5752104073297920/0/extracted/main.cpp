#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <string>
#include <ctime>
#include <cassert>
#include <utility>

using namespace std;

#define MAXN 1024

int T, N;
vector<int> A;
map<vector<int>, int> f;

void genGood(int n) {
    vector<int> P(n, 0);
    for(int i = 0; i < n; i++)
        P[i] = i;
    for(int i = 0; i < n; i++) {
        int p = rand() % (n - i) + i;
        swap(P[i], P[p]);
    }
    f[P]++;
    for(int i = 0; i < n; i++)
        printf("%d ", P[i]);
    printf("\n");
}

void genBad(int n) {
    vector<int> P(n, 0);
    for(int i = 0; i < n; i++)
        P[i] = i;
    for(int i = 0; i < n; i++) {
        int p = rand() % n;
        swap(P[i], P[p]);
    }
    f[P]++;
    for(int i = 0; i < n; i++)
        printf("%d ", P[i]);
    printf("\n");
}

int numInv(vector<int> &P) {
    int ret = 0;
    for(size_t i = 0; i < P.size(); i++)
        for(size_t j = i + 1; j < P.size(); j++)
            if(P[i] > P[j])
                ret++;
    return ret;
}

int numDer(vector<int> &P) {
    int ret = 0;
    for(size_t i = 0; i < P.size(); i++)
        ret += abs((int)i - P[i]);
    return ret;
}

int main() {
	freopen("date.in", "r", stdin);
	freopen("date.out","w", stdout);
	
//	srand(time(NULL));
//	
//	genGood(1000);
//	genBad(1000);
//	genGood(1000); 
//	
//	int n = 1000;
//	int t = 20;
//	printf("GOOD======================\n");
//	f.clear();
//	int num = 0;
//	int sum = 0;
//	for(int i = 0; i < t; i++)
//        genGood(n);
//    for(map<vector<int>, int> :: iterator it = f.begin(); it != f.end(); it++) {
//        vector<int> P = it->first;
////        for(vector<int> :: iterator it2 = P.begin(); it2 != P.end(); it2++)
////            printf("%d ", *it2);
//        printf(" => %d %d\n", it->second, numDer(P));
//        sum += numDer(P) * it->second;
//        num += it->second;
//    }
//    printf("avg: %.2lf\n", (double)sum / num);
//    
//    printf("BAD======================\n");
//    f.clear();
//    sum = num = 0;
//    for(int i = 0; i < t; i++)
//        genBad(n);
//    for(map<vector<int>, int> :: iterator it = f.begin(); it != f.end(); it++) {
//        vector<int> P = it->first;
////        for(vector<int> :: iterator it2 = P.begin(); it2 != P.end(); it2++)
////            printf("%d ", *it2);
//        printf(" => %d %d\n", it->second, numDer(P));
//        sum += numDer(P) * it->second;
//        num += it->second;
//    }
//	printf("avg: %.2lf\n", (double)sum / num);
	
	scanf("%d", &T);
	int lim = 330000;
	for(int t = 1; t <= T; t++) {
        scanf("%d", &N);
        A.resize(N);
        for(int i = 0; i < N; i++)
            scanf("%d", &A[i]);
        
        printf("Case #%d: ", t);
        int der = numDer(A);
//        printf("%d", der);
        if(der >= lim)
            printf("GOOD\n");
        else
            printf("BAD\n");
	}
	
	return 0;
}
