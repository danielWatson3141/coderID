#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <queue>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <stack>
#include <map>
#include <cstring>
#include <cmath>
using namespace std;

//trocar para 0 para desabilitar output
#if 1
#define DEBUG(x) cout << x << endl
#define PAUSE() cin.get(); cin.get()
#else
#define DEBUG(x)
#define PAUSE()
#endif

#define TRACE(x) DEBUG(#x << " = " << x)
#define DEBUGS() DEBUG("***************************")
#define MAX 1

string xors(const string &a, const string &b){
    string ans;
    for (int i = 0; i < a.length(); i++){
        if (a[i] == b[i]) ans += "0";
        else ans += "1";
    }
    return ans;
}

int count(const string &a){
    int s = 0;
    for (int i = 0; i < a.length(); i++)
        if (a[i] == '1') s++;
    return s;
}

int main(){
    vector<string> g1, g2;
    set<string> ans;
    int t, cases = 0;
    cin >> t;
    while (t--){
        int n, l;
        cin >> n >> l;
        g1.resize(n); g2.resize(n);
        for (int i = 0; i < n; i++)
            cin >> g1[i];
        for (int i = 0; i < n; i++)
            cin >> g2[i];

        for (int i = 0; i < n; i++){
            set<string> part, ans2;
            for (int j = 0; j < n; j++)
                part.insert(xors(g1[i], g2[j]));
            if (!i){
                ans = part;
                continue;
            }
            for (set<string>::iterator it = part.begin(); it != part.end(); it++){
                if (ans.find(*it) != ans.end())
                    ans2.insert(*it);
            }
            ans = ans2;
        }

        cout << "Case #" << ++cases << ": ";
        if (ans.size() == 0){
            cout << "NOT POSSIBLE" << endl;
            continue;
        }

        int number_bits = INT_MAX;
        for (set<string>::iterator it = ans.begin(); it != ans.end(); it++){
            number_bits = min(number_bits, count(*it));
        }
        cout << number_bits << endl;
    }
    return 0;
}
