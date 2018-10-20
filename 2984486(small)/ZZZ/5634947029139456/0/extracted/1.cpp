#include <iostream>

#include <algorithm>

#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

#define N 100

char a[N][N];
char b[N][N];

void flip(vector<string> &a, int pos) {
    for (int i = 0; i < a.size(); ++i) {
//        a[i][pos] = '0' + ('1' - a[i][pos]);
        a[i][pos] = a[i][pos] == '1'? '0': '1';
    }
}

int n_ones(vector<string> &a, int pos) {
    int s = 0;
    for (int i = 0; i < a.size(); ++i) {
        s += a[i][pos] == '1';
    }
    return s;
}

int result = -1;

void dfs(vector<string> &a, vector<string> &b, int i, int n, int l, int cur_flip) {
    if (result != -1) {
        return ;
    }
    
    if (i == l) {
        if (is_permutation(a.begin(), a.end(), b.begin())) {
            result = cur_flip;
            return ;
        } 
        return ;
    }

    int n1a = n_ones(a, i);
    int n1b = n_ones(b, i);

//    cout << "i" << i << "-" << n1a << ":" << n1b << endl;

    if (n1a == n1b && n1a+n1b != n) {
 //       cout << "case 1" << endl;
        dfs(a, b, i+1, n, l, cur_flip);
    }
    else if (n1a == n1b) {
  //      cout << "case 2" << endl;
        dfs(a, b, i+1, n, l, cur_flip);

        flip(a, i);
        dfs(a, b, i+1, n, l, cur_flip+1);
        flip(a, i);

    } else if (n1a + n1b == n){
   //     cout << "case 3" << endl;
        flip(a, i);
        dfs(a, b, i+1, n, l, cur_flip+1);
        flip(a, i);
    } else {
        return ;
    }
    return ;
}

int main() {
    freopen("in.txt", "r", stdin);
    int t;
    int n;
    int l;
    cin >> t;

    for (int Case = 0; Case < t; ++Case) {
        cin >> n >> l;
        vector<string> a;
        vector<string> b;
        string s;
        result = -1;
        for(int i = 0; i < n; ++i) {
            cin >> s;
            a.push_back(s);
        }
        for(int i = 0; i < n; ++i) {
            cin >> s;
            b.push_back(s);
        }
        dfs(a, b, 0, n, l, 0);
        printf("Case #%d: ", Case+1);
        if (result == -1) 
            cout << "NOT POSSIBLE" << endl;
        else
            cout << result << endl;
    }
    return 0;
}
