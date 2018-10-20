#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

char s1[150][41];
char s2[150][41];

int main()
{
    int t, i;
    
    scanf("%d", &t);
    
    for (i = 0; i < t; i++) {
        int n, l, ans = 1e9, j, k;
        long long a[150];
        long long b[150];
        
        scanf("%d %d", &n, &l);
        
        for (j = 0; j < n; j++) scanf("%s", s1[j]);
        for (j = 0; j < n; j++) scanf("%s", s2[j]);
        
        for (j = 0; j < n; j++) {
            long long x = 0, y = 0;
            
            for (k = 0; k < l; k++) {
                x <<= 1;
                y <<= 1;
                if (s1[j][k] == '1') x |= 1;
                if (s2[j][k] == '1') y |= 1;
            }
            
            a[j] = x;
            b[j] = y;
        }
        
        for (j = 0; j < n; j++) {
            long long x = a[0] ^ b[j];
            set <long long> s;
            
            for (k = 0; k < n; k++) s.insert(a[k] ^ x);
            
            for (k = 0; k < n; k++) {
                if (!s.count(b[k])) break;
            }
            
            if (k == n) ans = min(ans, __builtin_popcountll(x));
        }
        
        if (ans == 1e9) {
            printf("Case #%d: NOT POSSIBLE\n", i + 1);
        } else {
            printf("Case #%d: %d\n", i + 1, ans);
        }
    }
    
    return 0;
}
