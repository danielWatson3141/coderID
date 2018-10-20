#include <stdio.h>

int T;
int N;
int seq[1010];
int score;

int
main() {
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        printf("Case #%d: ", t);
        scanf("%d", &N);
        score = 0;
        for (int i = 0; i < N; ++i) {
            scanf("%d", &seq[i]);
        }
        for (int i = 0; i < N; ++i) {
            if (seq[i] >= i)
                score++;
        }
        if (score > N / 2)
            printf("BAD\n");
        else
            printf("GOOD\n");
    }
}
