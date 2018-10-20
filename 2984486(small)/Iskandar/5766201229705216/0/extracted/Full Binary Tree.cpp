#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <deque>
#include <string>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <set>
#include <time.h>
#include <bitset>
#include <list>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<pii,pii> ppi;
typedef pair<LL,LL> pll;
typedef pair<string,string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<LL> vl;
typedef vector<vl> vvl;
typedef vector<string> vstr;
typedef vector<char> vc;

double EPS = 1e-9;
int INF = 2000000000;
long long INFF = 8000000000000000000LL;
double PI = acos(-1);
int dirx[8] = {-1,0,0,1,-1,-1,1,1};
int diry[8] = {0,1,-1,0,-1,1,-1,1};

#define FOR(a,b,c) for (int (a)=(b);(a)<(c);++(a))
#define FORN(a,b,c) for (int (a)=(b);(a)<=(c);++(a))
#define FORD(a,b,c) for (int (a)=(b);(a)>=(c);--(a))
#define FORSQ(a,b,c) for (int (a)=(b);(a)*(a)<=(c);++(a))
#define FORL(a,b,c) for (LL (a)=(b);(a)<=(c);++(a))
#define FORLSQ(a,b,c) for (int (a)=(b);(LL)(a)*(LL)(a)<=(c);++(a))
#define FORC(a,b,c) for (char (a)=(b);(a)<=(c);++(a))
#define REP(i,n) FOR(i,0,n)
#define REPN(i,n) FORN(i,1,n)
#define REPD(i,n) FORD(i,n,1)
#define MAX(a,b) a = max(a,b)
#define MIN(a,b) a = min(a,b)
#define SQR(x) ((x) * (x))
#define RESET(a,b) memset(a,b,sizeof(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(),v.end()
#define ALLA(arr,sz) arr,arr+sz
#define SIZE(v) (int)v.size()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr,sz) sort(ALLA(arr,sz))
#define REVERSEA(arr,sz) reverse(ALLA(arr,sz))
#define PERMUTE next_permutation
#define TC(t) while(t--)
#define READ(n,data) {scanf("%d",&n); REPN(i,n) scanf("%d",&data[i]);}

inline string IntToString(int a){
    char x[100];
    sprintf(x,"%d",a); string s = x;
    return s;
}

inline int StringToInt(string a){
    char x[100]; int res;
    strcpy(x,a.c_str()); sscanf(x,"%d",&res);
    return res;
}

inline string GetString(void){
	char x[1000005];
	scanf("%s",x); string s = x;
	return s;
}

inline string uppercase(string s){
	int n = SIZE(s);
	REP(i,n) if (s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] - 'a' + 'A';
	return s;
}

inline string lowercase(string s){
	int n = SIZE(s);
	REP(i,n) if (s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
	return s;
}

inline void OPEN (string s) {
    freopen ((s + ".in").c_str (), "r", stdin);
    freopen ((s + ".out").c_str (), "w", stdout);
}


bool Map[20][20];
int Memo[20], N, counts;

bool checkValid(bool isOk[], int root) {
    int temp_count = 0;
    bool isValid = true;
    bool temp_isOk[20];

    for (int i = 1; i <= N; i++) temp_isOk[i] = isOk[i];

    for (int i = 1; i <= N; i++) {
        if (i != root) {
            if (Map[i][root] && isOk[i]) {
                temp_count++;
                temp_isOk[i] = false;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        if (i != root) {
            if (Map[i][root] && isOk[i]) {
                isValid = isValid && checkValid(temp_isOk, i);
                Memo[root] = Memo[root] + Memo[i];
            }
        }
    }

    if ((temp_count == 0 || temp_count == 2) && isValid) return true;
    else return false;
}


void bruteCheck(bool isOk[], int curr, int delNode) {

    if (N+1 == curr) {
        for (int i = 1; i <= N; i++) {
            if (isOk[i]) {

                for (int k = 0; k < 20; k++)
                    Memo[k] = 1;

                isOk[i] = false;
                bool isValid = checkValid(isOk, i);
                isOk[i] = true;

                if (isValid) {
                    if (delNode + Memo[i] != N) isValid = false;
                }

              /*  if (isValid) {
                    if (delNode == 1) {
                        for (int j = 1; j <= N; j++) {
                            if (isOk[j]) cout << "Yes ";
                            else cout << "No ";
                        }
                        cout << i << endl;
                    }
                } */

                if (isValid) {
                    if (counts == -1) counts = delNode;
                    else {
                        if (counts > delNode) counts = delNode;
                    }
                }
            }
        }

    } else {
        isOk[curr] = true;
        bruteCheck(isOk, curr+1, delNode);

        isOk[curr] = false;
        bruteCheck(isOk, curr+1, delNode+1);
    }
}


int main() {

  int T;

  cin >> T;

  for (int i = 1; i <= T; i++) {
    int X, Y;
    counts = -1;
    for (int j = 0; j < 20; j++)
        for (int k = 0; k < 20; k++)
            Map[j][k] = false;
    /** Reading Inputs */
    cin >> N;
    for (int j = 0; j < N-1; j++) {
        cin >> X >> Y;
        Map[X][Y] = true;
        Map[Y][X] = true;
    }
    /** Process */

    bool tempOk[20];
    for (int k = 0; k < 20; k++) tempOk[k] = true;
    bruteCheck(tempOk, 1, 0);


    /** Output */
    cout << "Case #" << i << ": ";
    cout << counts;
    cout << endl;
  }

  return 0;
}
/** Created by freedomofkeima */
