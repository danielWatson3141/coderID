#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <vector>

using namespace std;

vector<uint64_t> devices;
vector<uint64_t> outlets;
int devCount;
int length;

int best;
int changes;

int digit;

void trySolve(int step) {
    if (step == length) {
        std::sort(outlets.begin(), outlets.end());
        for (int i = 0; i < devCount; ++i) {
            if (outlets[i] != devices[i]) return;
        }

        if (best > changes) best = changes;
        return;
    }

    digit *= 2;
    trySolve(step + 1);
    digit /= 2;

    ++changes;
    for (int i = 0; i < devCount; ++i) {
        // flip ith bit.
        outlets[i] ^= digit;
    }

    digit *= 2;
    trySolve(step + 1);
    digit /= 2;
    for (int i = 0; i < devCount; ++i) {
        // flip ith bit.
        outlets[i] ^= digit;
    }

    --changes;
}

void solve(int caseN)
{
    devices.clear();
    outlets.clear();
    char input[41];
    scanf("%d%d", &devCount, &length);
    for (int i = 0; i < devCount; ++i) {
        scanf("%s", input);
        uint64_t val = 0;
        for (int j = 0; j < length; ++j) {
            val *= 2;
            if (input[j] == '1') val++;
        }
        outlets.push_back(val);
    }
    for (int i = 0; i < devCount; ++i) {
        scanf("%s", input);
        uint64_t val = 0;
        for (int j = 0; j < length; ++j) {
            val *= 2;
            if (input[j] == '1') val++;
        }
        devices.push_back(val);
    }

    std::sort(devices.begin(), devices.end());

    changes = 0;
    best = 100000;
    digit = 1;
    trySolve(0);

    printf("Case #%d: ", caseN + 1);
    if (best == 100000) {
        printf("NOT POSSIBLE\n");
    } else {
        printf("%d\n", best);
    }
}

int main(void)
{
    int nC;
    scanf("%d", &nC);
    for (int cC = 0; cC < nC; ++cC) {
        solve(cC);
    }

    return 0;
}
