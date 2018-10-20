#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>
#include <queue>
#include <algorithm>
#include <cstring>
#include <fstream>

using namespace std;

const int N = 1000;

int n;
bool a[N][N];
int m[N][N + 1];

int rec(int v, int p) {
    if (m[v][p] != -1)
        return m[v][p];
    
    vector<int> c;
    
    for (int j = 0; j < n; j ++)
        if (j != p && a[v][j])
            c.push_back(rec(j, v));
    
    sort(c.begin(), c.end());
    reverse(c.begin(), c.end());
    
    int res = 1;
    if (c.size() > 1)
        res = c[0] + c[1] + 1;
    
    return m[v][p] = res;
}

int main() {
    const string PATH_BASE = "/Users/mac/topcoder/";
    int NT, CT;
    
    ifstream cin(PATH_BASE + "input.txt");
    ofstream cout(PATH_BASE + "output.txt");
    
    cin >> NT;
    for (CT = 0; CT < NT; CT ++) {
        if (CT > 0)
            cout << endl;
        cout << "Case #" << (CT + 1) << ": ";
        
        cin >> n;
        
        memset(a, 0, sizeof(a));
        memset(m, -1, sizeof(m));

        for (int i = 0; i < n - 1; i ++) {
            int x, y;
            cin >> x >> y;
            x --; y --;
            a[x][y] = a[y][x] = true;
        }
        
        int m = 0;
        for (int i = 0; i < n; i ++)
            if (rec(i, n + 1) > m)
                m = rec(i, n + 1);
        
        cout << n - m;
    }
    
    if (NT > 0)
        cout << endl;
    return 0;
}
