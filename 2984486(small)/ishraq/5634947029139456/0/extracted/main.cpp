#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

#define FO(i,a,b) for (int i = (a); i < (b); i++)

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    FO(Z,1,T+1) {
        printf("Case #%d: ", Z);
        int n, l;
        scanf("%d %d", &n, &l);

        set<string> s;

        vector<string> a(n), b(n);

        FO(i,0,n) {
            char buf[100];
            scanf(" %s", buf);
            a[i] = string(buf);
            s.insert(a[i]);
        }

        FO(i,0,n) {
            char buf[100];
            scanf(" %s", buf);
            b[i] = string(buf);
        }
        int best = 1e9;
        FO(i,0,n) {
            bool flip[45] = {};
            int c = 0;
            FO(j,0,l) {
                flip[j] = a[0][j] != b[i][j];
                c += flip[j];
            }
            bool works = true;
            FO(j,0,n) {
                FO(k,0,l) {
                    if (flip[k]) {
                        b[j][k] ^= '0' ^ '1';
                    }
                }
                if (s.count(b[j])==0) works = false;
                FO(k,0,l) {
                    if (flip[k]) {
                        b[j][k] ^= '0' ^ '1';
                    }
                }
            }
            if (works) {
                best = min(best, c);
            }
        }

        if (best > l) printf("NOT POSSIBLE\n");
        else printf("%d\n", best);

done:;
    }

    return 0;
}

