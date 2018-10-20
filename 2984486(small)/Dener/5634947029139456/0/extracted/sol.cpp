#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>

using namespace std;

void solve(int test_num)
{
    int n, l;
    scanf("%d %d", &n, &l);
    vector< int > init_mask;
    vector< int > need_mask;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        int res = 0;
        for (int j = 0; j < l; j++) {
            res = res * 2 + (str[j] == '1');
        }
        init_mask.push_back(res);
    }
    
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        int res = 0;
        for (int j = 0; j < l; j++) {
            res = res * 2 + (str[j] == '1');
        }
        need_mask.push_back(res);
    }
    
    int max_change_mask = 1 << l;
    int best_ans = 1<<30;
    for (int change = 0; change < max_change_mask; change++) {
        bool ok = true;
        vector< bool > used;
        used.assign(n, false);
        for (int i = 0; i < n; i++) {
            bool found = false;
            for (int j = 0; j < n; j++) {
                if (!used[j] && need_mask[i] == (init_mask[j] ^ change)) {
                    found = true;
                    used[j] = true;
                    break;
                }
            }
            
            if (!found) {
                ok = false;
                break;
            }
        }
        
        if (!ok)
            continue;
        
        int bit_count = 0;
        for (int i = 0; i < l; i++) {
            if ((change >> i) & 1)
                bit_count++;
        }
        
        best_ans = min(best_ans, bit_count);
    }
    
    if (best_ans != 1<<30)
        printf("Case #%d: %d\n", test_num + 1, best_ans);
    else
        printf("Case #%d: NOT POSSIBLE\n", test_num + 1);
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
        solve(i);
}