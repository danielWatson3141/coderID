#include <cstdio>
#include <set>
#define MAX_DEVICES 160
#define ALL_BITS 0xFFFFFFFFFFFFFFFF

typedef unsigned long long ll;

int num_tasks;

int num_devices;
int num_bits;
ll devices[MAX_DEVICES];
ll outlets[MAX_DEVICES];

std::set<ll> device_set;

int main() {
    scanf("%d", &num_tasks);
    for (int t = 1; t <= num_tasks; t++) {
        scanf("%d %d ", &num_devices, &num_bits);
        for (int o = 0; o < num_devices; o++) {
            outlets[o] = 0;
            for (int l = num_bits-1; l >= 0; --l) {
                char cur_bit = getchar();
                if (cur_bit == '1') {
                    outlets[o] |= (1 << l);
                }
            }
            scanf(" ");
        }
        device_set.clear();
        for (int d = 0; d < num_devices; d++) {
            devices[d] = 0;
            for (int l = num_bits-1; l >= 0; --l) {
                char cur_bit = getchar();
                if (cur_bit == '1') {
                    devices[d] |= (1 << l);
                }
            }
            device_set.insert(devices[d]);
            scanf(" ");
        }

        
        
        ll best_change = ALL_BITS;
        
        for (int d = 0; d < num_devices; d++) {
            ll change = devices[d] ^ outlets[0];
            bool good = true;
            for (int d = 0; d < num_devices; d++) {
                device_set.insert(devices[d]);
            }
            for (int o = 0; o < num_devices; o++) {
                if (device_set.count((change ^ outlets[o])) == 0) {
                    good = false;
                    break;
                }
                device_set.erase(change ^ outlets[o]);
            }
            if (good) {
                if (__builtin_popcount(change) <
                    __builtin_popcount(best_change)) {
                    best_change = change;
                }
            }
        }

        if (best_change == ALL_BITS) {
            printf("Case #%d: NOT POSSIBLE\n", t);
        } else {
            printf("Case #%d: %d\n", t, __builtin_popcount(best_change));
        }
    }
    
    return 0;
}
