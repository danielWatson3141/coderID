#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <bitset>
#include <sstream>
#include <queue>

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(a) ((int) (a).size())
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

typedef long long int64;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const long long inf64 = ((long long)1 << 62) - 1;
const long double pi = acos(-1);

template <class T> T sqr (T x) {return x * x;}
template <class T> T abs (T x) {return x < 0 ? -x : x;}

const int MAXN = 1500;
const int MAXT = 200;

double m[2][MAXN], p[2][MAXN][MAXN];
int a[MAXN];
pair <double, int> fw[MAXT];
pair <int, int> fw1[MAXT];
bool ans[MAXT], ans1[MAXT], ans_cor[MAXT];

int good_perm (int n) {
    for (int i = 0; i < n; ++i) {
        a[i] = i;
    }

    for (int i = 0; i < n; ++i) {
        int j = rand() % (n - i);
        swap (a[i], a[i + j]);
    }

    return 0;
}

int bad_perm (int n) {
    for (int i = 0; i < n; ++i) {
        a[i] = i;
    }

    for (int i = 0; i < n; ++i) {
        int j = rand() % n;
        swap (a[i], a[j]);
    }

    return 0;
}


int main () {
    srand (time(NULL));

//  ios_base::sync_with_stdio(0);

    //freopen("input.txt", "wt", stdout);

    int tn = 120;
    int n = 1000;

    /*cout << tn << endl;
    for (int i = 0; i < tn; ++i) {
        if (i < tn / 2)
            good_perm(1000);
        else
            bad_perm(1000);

        cout << 1000 << endl;
        for (int i = 0; i < 1000; ++i) {
            cout << a[i] << " ";
        }
        cout << endl;
    }*/

    //return 0;

    freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);


    for (int i = 0; i < n; ++i) {
        m[0][i] = i;
        for (int j = 0; j < n; ++j) {
            p[0][i][j] = 0;
        }
        p[0][i][i] = 1.0;
    }

    int t = 0;
    for (int i = 0; i < n; ++i) {
        cerr << i << endl;
        for (int j = 0; j < n; ++j) {
            if (j != i) {
                m[t ^ 1][j] = ((n - 1.0) / n) * m[t][j] + (1.0 / n) * m[t][i];
                for (int k = 0; k < n; ++k) {
                    p[t ^ 1][j][k] = ((n - 1.0) / n) * p[t][j][k] + (1.0 / n) * p[t][i][k];
                }
            }
        }
        m[t ^ 1][i] = (n - 1.0) / 2;
        for (int k = 0; k < n; ++k) {
            p[t ^ 1][i][k] = 1.0 / n;
        }
        t = t ^ 1;
    }


    /*for (int i = 0; i < n; ++i) {
        cout << m[t][i] << endl;
    }
    return 0;*/

    cin >> tn;

    for (int tc = 0; tc < tn; ++tc) {
        //printf ("Case #%d: ", tc + 1);

        int n;
        cin >> n;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        double d1 = 0, d2 = 0;
        double d = 0;
        for (int i = 0; i < n; ++i) {
            //d1 += abs(a[i] - (n - 1.0) / 2);
            d2 += abs(a[i] - m[t][i]) / m[t][i];
            d += p[t][i][a[i]];
        }
        fw[tc] = mp(-d, tc);

        /*int num1 = 0, num2 = 0;
        for (int i = 0; i < n; ++i) {
            if (abs(a[i] - (n - 1.0) / 2) < abs(a[i] - m[t][i]))
                num1++;
            else
                num2++;
        }
        fw1[tc] = mp(num1 - num2, tc);*/
    }

    sort (fw, fw + tn);
    //sort (fw1, fw1 + tn);

    for (int i = 0; i < tn / 2; ++i) {
        ans[fw[i].sc] = false;
        //ans1[fw1[i].sc] = false;
    }
    for (int i = tn / 2; i < tn; ++i) {
        ans[fw[i].sc] = true;
        //ans1[fw1[i].sc] = true;
    }

    for (int i = 0; i < tn; ++i) {
        ans_cor[i] = (i < tn / 2);
    }

    int num = 0;
    for (int i = 0; i < tn; ++i) {
        if (ans[i] != ans_cor[i])
            num++;
    }
    cerr << num;

    for (int i = 0; i < tn; ++i) {
        printf ("Case #%d: ", i + 1);
        if (ans[i])
            cout << "GOOD" << endl;
        else
            cout << "BAD" << endl;
    }

	return 0;
}
