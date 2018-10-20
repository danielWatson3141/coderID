// 1A_A.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <set>

using namespace std;

bool Comp (const vector <int>& a, const vector <int>& b) {
    if (a.size () != b.size ())
        return false;
    for (int i = 0; i < a.size (); i++) {
        if (a [i] != b [i])
            return false;
    }
    return true;
};

int main(int argc, char* argv[])
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        int n, l;
        cin >> n >> l;
        vector <string> flows, switches;
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            flows.push_back (s);
        }
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            switches.push_back (s);
        }
        sort (switches.begin (), switches.end (), std::greater <string> ());
        vector <vector <vector <int> > > error (n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                vector <int> d;
                for (int k = 0; k < flows [i].length (); ++k) {
                    if (flows [i][k] != switches [j][k]) {
                        d.push_back (k);
                    }
                }
                error [i].push_back (d);
            }
        }
        int min = l + 1;
        for (int i = 0; i < n; ++i) {
            set <int> used;
            used.insert (i);
            for (int j = 1; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if ((used.find (k) == used.end ()) && (Comp (error [0][i], error [j][k]))) {
                        used.insert (k);
                        break;
                    }
                }
            }
            if ((used.size () == n) && (error [0][i].size () < min)) {
                min = error [0][i].size ();
            }
            used.clear ();
        }
        cout << "Case #" << t + 1 << ": ";
        if (min == l + 1) {
            cout << "NOT POSSIBLE" << endl;
        }
        else {
            cout << min << endl;
        }
    }
	return 0;
}

