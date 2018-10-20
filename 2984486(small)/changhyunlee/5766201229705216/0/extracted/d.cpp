#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int n;
int d[1000][1000];
int deg[1000];
int chk[1000];

int go(int root, int& del) {
    vector<int> child;
    int total = 0;
    for (int i=0; i<n; i++) {
        if (d[root][i]==0 || chk[i]) continue;

        chk[i] = 1;
//        cout << root << ' ' << i << endl;
        int nn = go(i, del);
        child.push_back(nn);
        total += nn;
    }
    if (child.size()==1) {
        del += child[0];
        total -= child[0];
    } else if (child.size()>2) {
        sort(child.begin(), child.end());
        for (int i=0; i<child.size()-2; i++) {
            del += child[i];
            total -= child[i];
        }
    }
    return total + 1;
}

int main() {
    int t;

    ifstream in("input.txt");
    ofstream out("output.txt");
    in >> t;
    for (int l=1; l<=t; l++) {
        fill (d[0], d[0]+1000*1000, 0);
        fill(deg, deg+1000, 0);
        in >> n;
        for (int i=0; i<n-1; i++) {
            int a, b;
            in >> a >> b;
            d[a-1][b-1] = d[b-1][a-1] = 1;
            deg[a-1]++; deg[b-1]++;
        }
        int res = n-1;
        for (int i=0; i<n; i++) {
            if (deg[i]>=2) {
                int del = 0;

                fill(chk, chk+1000, 0);
                chk[i] = 1;
                go(i, del);
                res = min(res, del);
            }
        }
        out << "Case #" << l << ": " << res << endl;
    }
    return 0;
}
