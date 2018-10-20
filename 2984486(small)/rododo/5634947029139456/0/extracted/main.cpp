#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

#define MAXN 150
#define MAXL 40

long long outlets[MAXN + 10];
int outlets_cnt[MAXL + 10];
long long devices[MAXN + 10];
int devices_cnt[MAXL + 10];
int N, L, ans;
long long swap_c[] = { 0x1, 0x2, 0x4, 0x8,
                       0x10, 0x20, 0x40, 0x80,
                       0x100, 0x200, 0x400, 0x800,
                       0x1000, 0x2000, 0x4000, 0x8000,
                       0x10000, 0x20000, 0x40000, 0x80000,
                       0x100000, 0x200000, 0x400000, 0x800000,
                       0x1000000, 0x2000000, 0x4000000, 0x8000000,
                       0x10000000UL, 0x20000000UL, 0x40000000UL, 0x80000000UL,
                       0x100000000UL, 0x200000000UL, 0x400000000UL, 0x800000000UL,
                       0x1000000000UL, 0x2000000000UL, 0x4000000000UL, 0x8000000000UL,
                     };
bool check() {
    sort(outlets, outlets + N);
    sort(devices, devices + N);
    for (int i = 0; i < N; i++)
        if (outlets[i] != devices[i])
            return false;
    return true;
}
void swap(int l) {
    for (int i = 0; i < N; i++)
        outlets[i] ^= swap_c[L - l - 1];
    outlets_cnt[l] = N - outlets_cnt[l];
}
bool dfs(int l) {
    if (l == L)
        return check();
    else if (outlets_cnt[l] != devices_cnt[l])
        return false;
    else if (outlets_cnt[l] == N - devices_cnt[l]) {
        if (dfs(l + 1))
            return true;
        swap(l);
        ans++;
        if (dfs(l + 1))
            return true;
        swap(l);
        ans--;
        return false;
    } else
        return dfs(l + 1);
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T, TC;
    scanf("%d", &T);
    TC = T;
    while (TC--) {
        ans = 0;
        scanf("%d%d", &N, &L);
        memset(outlets, 0, sizeof(outlets));
        memset(devices, 0, sizeof(devices));
        memset(outlets_cnt, 0, sizeof(outlets_cnt));
        memset(devices_cnt, 0, sizeof(devices_cnt));
        for (int i = 0; i < N; i++) {
            char tmp = getc(stdin);
            while ((tmp != '0') && (tmp != '1'))
                tmp = getc(stdin);
            for (int j = 0; j < L; j++) {
                outlets[i] = outlets[i] << 1 | (tmp == '1');
                outlets_cnt[j] += (tmp == '1');
                tmp = getc(stdin);
            }
        }
        for (int i = 0; i < N; i++) {
            char tmp = getc(stdin);
            while ((tmp != '0') && (tmp != '1'))
                tmp = getc(stdin);
            for (int j = 0; j < L; j++) {
                devices[i] = devices[i] << 1 | (tmp == '1');
                devices_cnt[j] += (tmp == '1');
                tmp = getc(stdin);
            }
        }
        int i;
        for (i = 0; i < L; i++) {
            if ((devices_cnt[i] != outlets_cnt[i])
                    && (devices_cnt[i] != N - outlets_cnt[i]))
                break;
            else if (devices_cnt[i] != outlets_cnt[i]) {
                swap(i);
                ans++;
            }
        }
        if (i != L) {
            printf("Case #%d: NOT POSSIBLE\n", T - TC);
            continue;
        }
        if (dfs(0))
            printf("Case #%d: %d\n", T - TC, ans);
        else
            printf("Case #%d: NOT POSSIBLE\n", T - TC);
    }
}
