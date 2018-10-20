#include <cstdio>
#include <algorithm>
#include <map>
#include <string>
#include <iostream>

const int N = 200;

int main() {
    int test;
    scanf("%d", &test);
    for (int t = 1; t <= test; ++ t) {
        std::map<std::string, int> counter;
        int n, l;
        scanf("%d%d", &n, &l);

        std::string a[N], b[N], c[N];
        for (int i = 0; i < n; ++ i) {
            std::cin >> a[i];
        }
        for (int i = 0; i < n; ++ i) {
            std::cin >> b[i];
        }
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < n; ++ j) {
                std::string string = "";
                for (int k = 0; k < l; ++ k) {
                    if (a[i][k] == b[j][k]) {
                        string += "0";
                    } else {
                        string += "1";
                    }
                }
                counter[string] ++;
            }
        }

        const int INF = 1 << 30;
        int answer = INF;
        for (auto iter = counter.begin(); iter != counter.end(); ++ iter) {
            if ((*iter).second == n) {
                std::string string = (*iter).first;
                int temp = 0;
                for (int i = 0; i < l; ++ i) {
                    temp += string[i] == '1';
                }
                answer = std::min(answer, temp);
            }
        }
        printf("Case #%d: ", t);
        if (answer == INF) {
            puts("NOT POSSIBLE");
        } else {
            printf("%d\n", answer);
        }
    }
    return 0;
}
