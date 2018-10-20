#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
typedef double du;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, s, t) for(i = (s); i < (t); i++)
#define RFOR(i, s, t) for(i = (s)-1; i >= (t); i--)

vector<int> a;

du p[1004][1004];
int n = 1000;

bool check(){
    int n = a.size();
    int sq = sqrt(n);
    int i, j;
    int cnt = 0;
    du rp = 1.;
    for(i = 0; i < n; i++){
        rp *= p[i][a[i]]*n;
    }
    return rp < 1.1;
}

int rand(int l, int r){
    return rand()%(r-l)+l;
}

void good(){
    int i;
    int n = a.size();
    for(i = 0; i < n; i++)
        a[i] = i;
    for(i = 0; i < n; i++)
        swap(a[i], a[rand(i, n)]);
}

void bad(){
    int i;
    int n = a.size();
    for(i = 0; i < n; i++)
        a[i] = i;
    for(i = 0; i < n; i++)
        swap(a[i], a[rand(0, n)]);
}

ostream& operator<<(ostream &out, const vector<int>& a){
    out<<"("<<a[0];
    for(int i = 1; i < a.size(); i++)
        out<<" "<<a[i];
    out<<")";
    return out;
}

void selfTest(){
    int T, n;
    int i, j, k;
    int cnt[2][2];
    T = 1000;
    n = 1000;
    a.resize(n);
    
    /*map<vector<int>, int> m;
    for(i = 0; i < T; i++){
        bad();
        m[a]++;
    }
    for(map<vector<int>, int>::iterator it = m.begin(); it != m.end(); it++)
        cout<<it->fi<<" "<<it->se<<endl;*/
        
    
    
    /*for(j = 0; j < n; j++, cout<<endl)
        for(k = 0; k < n; k++)
            printf("%4.2lf ", p[j][k]*n);*/
    
    memset(cnt, 0, sizeof cnt);
    for(i = 0; i < T; i++){
        if(rand(0, 2)){
            good();
            cnt[1][check()]++;
        }
        else{
            bad();
            cnt[0][check()]++;
        }
    }
    printf("%.4lf\n", (du)(cnt[0][0]+cnt[1][1])/T);
    for(i = 0; i < 2; i++, cout<<endl)
        for(j = 0; j < 2; j++)
            printf("%.4lf ", (du)cnt[i][j]/T);
}

void prepare(){
    int i, j, k;
    memset(p, 0, sizeof p);
    for(i = 0; i < n; i++)
        p[i][i] = 1.;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++)
            if(j != i)
                for(k = 0; k < n; k++)
                    p[j][k] = (p[j][k]*(n-1) + p[i][k])/n;
        for(k = 0; k < n; k++)
            p[i][k] = 1./n;
    }
}

int main() {
#ifdef __FIO
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int i0 = 1;
	int T;
	prepare();
	//selfTest();
	scanf("%d", &T);
	for (i0 = 1; i0 <= T; i0++) {
	    int n;
		int i, j, k;
		scanf("%d", &n);
		a.resize(n);
		for(i = 0; i < n; i++){
		    scanf("%d", &j);
		    a[i] = j;
		}
        if(check())
            printf("Case #%d: GOOD\n", i0);
        else
            printf("Case #%d: BAD\n", i0);
	}
	return 0;
}
