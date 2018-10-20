#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <map>
#include <functional>
#include <boost/random.hpp>

using namespace std;
using namespace boost;

int randint(int min, int max)
{
    static mt19937 gen;
    uniform_smallint<> dst(min, max);
    variate_generator<
        mt19937&, uniform_smallint<>
    > rand(gen, dst);
    return rand();
    //return (rand() >> 3) % (max - min + 1) + min;
}

void perm_good(vector<int>& a, int n)
{
    a.resize(n);

    for (int k = 0; k < n - 1; k++)
        a[k] = k;

    for (int k = 0; k < n - 1; k++) {
        int p = randint(k, n - 1);
        swap(a[k], a[p]);
    }
}

void perm_bad(vector<int>& a, int n)
{
    a.resize(n);

    for (int k = 0; k < n - 1; k++)
        a[k] = k;

    for (int k = 0; k < n - 1; k++) {
        int p = randint(0, n - 1);
        swap(a[k], a[p]);
    }
}

double grav(const vector<int>& n)
{
    int sum = 0;
    int num = 0;
    for (int i = 0; i < n.size(); i++) {
        sum += i * n[i];
        num += n[i];
    }
    return sum * 1.0 / num;
}

int num_b(const vector<int>& n)
{
    int cnt = 0;
    int range = 250;
    for (int i = 0; i < n.size(); i++) {
        //if (n[i] == i + 1) cnt++;
        if (n[i] > i && n[i] < i + range) cnt++;
        if (n[i] <= i && n[i] > i - range) cnt--;

        //if (n[i] > n.size() - range/10 && i < range/10) cnt++;

        //if (n[i] > i && n[i] < i + range/2) cnt++;
        //if (n[i] <= i && n[i] > i - range/2) cnt--;
        //if (n[i] < range/2 && i > n.size() - range/2) cnt++;
    }
    return cnt;
}


int main(void)
{
    /*vector<int> a, b;
    int suma = 0;
    int sumb = 0;

    int ok = 0;
    int bad = 0;

    for (int i = 0; i < 600; i++) {
        perm_good(a, 1000);
        perm_bad(b, 1000);

        int th = 20;
        if (num_b(a) < th) ok++;
        else bad++;

        if (num_b(b) >= th) ok++;
        else bad++;

        cout << num_b(a) << "," << num_b(b) << endl;
    }

    cout << "ok:" << ok << ", bad:" << bad;
    */
    int c;
    cin >> c;

    for (int i = 0; i < c; i++) {
        vector<int> b;
        int N;
        cin >> N;
        b.resize(N);

        for (int j = 0; j < N; j++) cin >> b[j];

        if (num_b(b) >= 20) {
            printf("Case #%d: BAD\n", i + 1);
        }
        else {
            printf("Case #%d: GOOD\n", i + 1);
        }
    }
}