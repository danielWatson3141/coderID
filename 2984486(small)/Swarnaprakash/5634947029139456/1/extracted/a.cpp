// Author: Swarnaprakash
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cassert>

using namespace std;

const int M = 105;
const int INF = 0x3f3f3f3f;
const bool debug=true;

#define SET(x,v)	memset(x,v,sizeof(x))
#define ALL(x) 		(x).begin() , (x).end()
#define SZ(x)		((int)((x).size()))
#define DB(x) 		if(debug) cout << #x << " : " << x <<endl;

typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;

int N,L;

char a[155][45];
char b[155][45];

char mat[155][155][45];

void compute_mat() {
    for(int i=0;i<N;++i) {
        for(int j=0;j<N;++j) {

            for(int k=0;k<L;++k) mat[i][j][k] = ((a[i][k] - '0') ^ (b[j][k] - '0')) + '0';
            mat[i][j][L] = 0;
        }
    }
}

void print_mat() {
    for(int i=0;i<N;++i) {
        for(int j=0;j<N;++j) {
            printf("%s ",mat[i][j]);
        }
        puts("");
    }
}

int count_ones(int index) {
    int ans = 0;
    for(int i=0;i<L;++i) ans += mat[0][index][i] - '0';
    return ans;
}

bool possible(int index) {
    set<int> row_index;
    for(int i=0;i<N;++i) {
        for(int j=0;j<N;++j) {
            if(strcmp(mat[0][index],mat[i][j]) == 0) row_index.insert(j);
        }
    }

    return SZ(row_index) == N;
}

int main() {
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;++t) {
        scanf("%d %d",&N,&L);
        for(int i=0;i<N;++i) scanf("%s",a[i]);
        for(int i=0;i<N;++i) scanf("%s",b[i]);
        compute_mat();

        int ans = INF;
        for(int i=0;i<N;++i) {
            if(possible(i)) ans = min(ans,count_ones(i));
        }

        printf("Case #%d: ",t);

        if(ans < INF) {
            printf ("%d\n",ans);
        } else {
            puts("NOT POSSIBLE");
        }
            

    }
    return 0;
}

