#include <iostream>
#include <algorithm>
#include <map>
#include <ctime>
#include <vector>
#include <map>
#include <cstdlib>

using namespace std;

const int N = 5, ITER=1000000;

struct VectorLt {
    bool operator()(const vector<int> &a, const vector<int> &b) const {
        return lexicographical_compare(a.begin(), a.end(), b.begin(), b.end());
    }
};

vector<int> bad(vector<int> v) {
    for (int i = 0; i < v.size(); i++)
        swap(v[i], v[rand() % v.size()]);
    return v;
}

int fact(int n) {
    return n <= 1 ? n : n * fact(n-1);
}

int cycles(const vector<int> &p) {
    vector<bool> visited(p.size());
    int c = 0;

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            c++;

            int j = i;

            while (!visited[j]) {
                visited[j] = true;
                j = p[j];
            }
        }
    }

    return c;
}

int forward(const vector<int> &p) {
    int c = 0;

    for (int i = 0; i < p.size(); i++)
        if (p[i] > i)
            c++;
    return c;
}

int main() {
    srand(time(0));

#ifdef TEST
    map<vector<int>, int, VectorLt> all;

    for (int i = 0; i < ITER; i++) {
        vector<int> v(N);
        iota(v.begin(), v.end(), 0);
        all[bad(v)]++;

        if (i % 1000000 == 0)
            cout << ".";
    }

    cout << "\n";

    int avg = ITER/fact(N);
    int right = 0, wrong = 0;

    for (auto i : all) {
/*        cout << "[";

        for (int j = 0; j < N; j++)
            cout << i.first[j] << (j == N-1 ? "]" : ", ");

        cout << " (" << forward(i.first) << " forward) -> " << i.second << '\n';
*/
        if (forward(i.first) > (N+1)/2 - 1) {
            if (i.second > avg)
                right++;
            else
                wrong++;
        } else {
            if (i.second > avg)
                wrong++;
            else
                right++;
        }
    }

    cout << "Expected: More or less " << (ITER/fact(N)) << '\n';
    cout << "Right: " << right << "\nWrong: " << wrong << '\n';

#else
    int t;
    cin >> t;

    for (int tc = 1; tc <= t; tc++) {
        int n;
        cin >> n;

        vector<int> v(n);

        for (int i = 0; i < n; i++)
            cin >> v[i];

        cout << "Case #" << tc << ": " << ((forward(v) > (n+1)/2 - 9) ? "BAD" : "GOOD") << '\n';
    }

#endif

    return 0;
}
