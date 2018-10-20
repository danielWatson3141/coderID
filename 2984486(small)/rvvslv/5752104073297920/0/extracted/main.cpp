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
        
        int n;
        cin >> n;
        
        int k = 0;
        for (int i = 0; i < n; i ++) {
            int t;
            cin >> t;
            if (i == t)
                k ++;
        }
        
        if (k <= 1)
            cout << "GOOD";
        else
            cout << "BAD";
    }
    
    if (NT > 0)
        cout << endl;
    return 0;
}
