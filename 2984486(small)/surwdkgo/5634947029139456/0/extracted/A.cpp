#include <stdio.h>
#include <algorithm>
long long inp1[155], inp2[155], srt[155], rot;
char tmp[45];
int main() {
    int cas, n, l, ans;
    scanf("%d", &cas);
    for(int ii=0; ii<cas; ii++) {
        scanf("%d%d", &n, &l);
        for (int i=0; i<n; i++) {
            scanf("%s", tmp);
            inp1[i] = 0;
            for (int j=0; j<l; j++) {
                inp1[i] = (inp1[i] << 1) + tmp[j] - '0';
            }
        }
        for (int i=0; i<n; i++) {
            scanf("%s", tmp);
            inp2[i] = 0;
            for (int j=0; j<l; j++) {
                inp2[i] = (inp2[i] << 1) + tmp[j] - '0';
            }
        }
        ans = l+1;
        rot = inp1[0];
        for (int i=0; i<n; i++) {
            inp1[i] = inp1[i] ^ rot;
        }
        std::sort(inp1, inp1+n);
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                srt[j] = inp2[j] ^ inp2[i];
            }
            std::sort(srt, srt+n);
            char flag = 1;
            for (int j=0; j<n; j++) {
                if (srt[j] != inp1[j]) {
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                int nas = 0;
                for (int j=0; j<l; j++) {
                    if ((inp2[i] ^ rot) & (1<<j)) nas ++;
                }
                if (nas < ans) ans = nas;
            }
        }
        if (ans == l+1) printf ("Case #%d: NOT POSSIBLE\n", ii+1);
        else printf("Case #%d: %d\n", ii+1, ans);
    }
    return 0;
}