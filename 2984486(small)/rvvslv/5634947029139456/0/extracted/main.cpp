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
        
        int n, l;
        cin >> n >> l;
        
        vector<string> a(n), b(n);
        
        for (int i = 0; i < n; i ++)
            cin >> a[i];
        
        sort(a.begin(), a.end());
        
        for (int i = 0; i < n; i ++)
            cin >> b[i];
        
        int best = l + 1;
        
        for (int i = 0; i < n; i ++) {
            string v;
            for (int j = 0; j < l; j ++) {
                if (a[0][j] != b[i][j])
                    v += '1';
                else
                    v += '0';
            }
            
            int c1 = 0;
            for (int j = 0; j < l; j ++)
                if (v[j] == '1')
                    c1 ++;
            
            if (c1 >= best)
                continue;
            
            vector<string> c;
            for (int j = 0; j < n; j ++) {
                string t = b[j];
                for (int k = 0; k < l; k ++)
                    if (v[k] == '1')
                        t[k] = (t[k] == '0') ? '1' : '0';
                c.push_back(t);
            }
            
            sort(c.begin(), c.end());
            if (a != c)
                continue;
            
            best = c1;
        }
        
        if (best >= l) {
            cout << "NOT POSSIBLE";
            continue;
        }
        cout << best;
    }
    
    if (NT > 0)
        cout << endl;
    return 0;
}
