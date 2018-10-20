#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <inttypes.h>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define ST first
#define ND second
#define MP make_pair
#define PB push_back
#define POP pop_back

typedef long long LL;
typedef long double LD;
typedef double D;
typedef pair<int, int> PII;
typedef vector<string> VS;
typedef vector<int> VI;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int, int> MII;
typedef map<int, VI > MIVI;
typedef vector<pair<int, VI > > VPIVI;

#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(VAR(i,a);i<=(b);++i)
#define FORD(i,a,b) for(VAR(i,a);i>=(b);--i)
#define FORE(a,b) for(VAR(a,(b).begin());a!=(b).end();++a)
#define VAR(a,b) __typeof(b) a=(b)
#define SIZE(a) ((int)((a).size()))
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,a) memset(x,a,sizeof(x))
#define ZERO(x) memset(x,0,sizeof(x))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a,b) ((a)>(b)?(a-b):(b-a))

#define MAXN 500

void doit()
{
    int N, L;
    cin >> N >> L;
    vector<string> fl, dev;
    int flbit[45], devbit[45];
    ZERO(flbit);
    ZERO(devbit);

    REP(i, N) {
        string s;
        cin >> s;
        if (s.size() != L) return;
        fl.push_back(s);
        REP(j, L) {
            if (s[j] == '1')
                flbit[j]++;
        }
    }
    REP(i, N) {
        string s;
        cin >> s;
        dev.push_back(s);
        REP(j, L) {
            if (s[j] == '1')
                devbit[j]++;
        }
    }

    //cout << endl;
    //cout << "********* " << N << " " << L << endl;
    //REP(i, L) {
        //cout << flbit[i] << " ";
    //} cout << endl;
    //REP(i, L) {
        //cout << devbit[i] << " ";
    //} cout << endl;

    int ops = 0;
    REP(i, L) {
        if (flbit[i] != devbit[i] && flbit[i] + devbit[i] != N) {
            //cout << flbit[i] << " != " << devbit[i] << " && " << flbit[i] << " + " << devbit[i]  << " != " << N << endl;
            cout << " NOT POSSIBLE" << endl;
            return;
        }
        if (flbit[i] + devbit[i] == N && flbit[i] != devbit[i]) {
            //cout << flbit[i] << " + " << devbit[i] << " == " << N << " && " << flbit[i]<< " != " << devbit[i] << endl;
            //cout << "flipp " << i << endl;
            ops++;
            REP(j, N) {
                if (fl[j][i] == '0')
                    fl[j][i] = '1';
                else
                    fl[j][i] = '0';
            }
        }
    }

//cout << endl;
    sort(fl.begin(), fl.end());
    sort(dev.begin(), dev.end());


    int minops = L + 1;
    REP(i, N) {
        vector<string> aux;

//cout << endl;
//REP(ii, N) {
    //cout << fl[ii] << " ";
//} cout << endl;
//REP(ii, N) {
    //cout << dev[ii] << " ";
//} cout << endl;
//cout << endl;

        REP(j, N) {
        aux.clear();
        REP(ii, N) aux.push_back(fl[ii]);
            int dist = ops;
            REP(k, L) {
                if (dev[i][k] != aux[j][k]) {
                    dist++;
                    REP(l, N) {
                        if (aux[l][k] == '0')
                            aux[l][k] = '1';
                        else
                            aux[l][k] = '0';
                    }
                }
            }

            sort(aux.begin(), aux.end());
            sort(dev.begin(), dev.end());

//cout << "? " << dist << endl;
//REP(ii, N) {
    //cout << aux[ii] << " ";
//} cout << endl;
//REP(ii, N) {
    //cout << dev[ii] << " ";
//} cout << endl;

//REP(ii, N) {
    //cout << aux[ii] << " ";
//} cout << endl;
//REP(ii, N) {
    //cout << dev[ii] << " ";
//} cout << endl;
//cout << endl;

            bool good = true;
            REP(l, N) {
                //cout << (dev[l] != aux[l]) << " " << dev[l] << " " << aux[l] << endl;
                if (dev[l] != aux[l]) {
                    good = false;
                    break;
                }
            }
            if (good) {
                //cout << "! " << dist << endl;
                minops = MIN(minops, dist);
            }
        }
    }

    if (minops == L + 1) {
        cout << " NOT POSSIBLE" << endl;
    }
    cout << " " << minops << endl;

}
int main ()
{

    int T;
    cin >> T;
    REP(ttt, T) {
        cout << "Case #" << ttt+1 << ":";
        doit();
    }
    return 0;
}
