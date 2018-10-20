#include <cstdio>

int con[1000];
const int magic_num_get_from_experience = 245500;

int main() {
    int T, n;
    scanf("%d", &T);

    int cnt = 0;
    for (int times = 0; times < T; times++) {
        scanf("%d", &n);

        for (int i = 0; i < n; i++) {
            scanf("%d", &con[i]);
        }

        int sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (con[i] > con[j]) sum++;
            }
        }
        //fprintf(stderr, "%d\n", sum);

        if (sum > magic_num_get_from_experience) {
            printf("Case #%d: GOOD\n", times + 1);
            cnt++;
        }
        else {
            printf("Case #%d: BAD\n", times + 1);
        }
    }
    fprintf(stderr, "%d\n", cnt);
}
