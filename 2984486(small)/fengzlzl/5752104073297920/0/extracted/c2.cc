#include <cstdio>
#include <vector>

using namespace std;

double Count(vector<int> &a) {
    double tot = 0;
   for (int i = 0; i < a.size(); i++) {
        int cnt = 0;
        for (int j = 0; j <= i; j++)
            if (a[j] <= i) cnt++;
            tot += cnt;
    }
   // printf("%f\n", tot / (double)a.size());
     return tot / (double)a.size();
}


int main() {
    int T;
    double threshold = 337;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
            int n;
        scanf("%d", &n);
        vector<int> a(n);

        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        double val = Count(a);
        if (val <= threshold) printf("Case #%d: GOOD\n", cas);
        else printf("Case #%d: BAD\n", cas);
    }
    return 0;
}
