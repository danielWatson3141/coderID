// 1A_A.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int delSubtree (const vector <vector <bool> >& edges, int parent, int v) {
    int sum =  1;
    for (int i = 0; i < edges.size (); ++i) {
        if (edges [v][i] && i != parent) {
            sum += 1 + delSubtree (edges, v, i);
        }
    }
    return sum;
}

int chooseChildren (const vector <vector <bool> >& edges, int parent, int v) {
    int sum = 0;
    map <int, int> m;
    for (int i = 0; i < edges.size (); ++i) {
        if (edges [v][i] && i != parent) {
            m.insert (make_pair (chooseChildren (edges, v, i) - delSubtree (edges, v, i), i));
        }
    }
    if (m.size () == 1) {
        return delSubtree (edges, v, m.begin ()->second);
    }
    if (m.size () == 0) {
        return 0;
    }
    map <int, int>::const_iterator iter = m.begin ();
    sum += chooseChildren (edges, v, iter->second);
    ++iter;
    sum += chooseChildren (edges, v, iter->second);
    ++iter;
    for (; iter != m.end (); ++iter) {
        sum += delSubtree (edges, v, iter->second);
    }
    return sum;
}

int main(int argc, char* argv[])
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        int n;
        cin >> n;
        vector <vector <bool> > edges (n, vector <bool> (n));
        for (int i = 0; i < n - 1; ++i) {
            int a, b;
            cin >> a >> b;
            edges [a - 1][b - 1] = true;
            edges [b - 1][a - 1] = true;
        }
        int min = n;
        for (int i = 0; i < n; ++i) {
            int c = chooseChildren (edges, -1, i);
            if (c < min) 
                min = c;
        }
        cout << "Case #" << t + 1 << ": " << min << endl;
    }
	return 0;
}

