#include <cstdio>
#include <cmath>
#include <stdint.h>
#include <set>

using namespace std;

bool next_combination(int64_t &x) // assume x has form x'01^a10^b in binary
{
    if (x == 0L) return false;
    int64_t u = x & -x; // extract rightmost bit 1; u =  0'00^a10^b
    int64_t v = u + x; // set last non-trailing bit 0, and clear to the right; v=x'10^a00^b
    if (v == 0L) {// then overflow in v, or x==0
        return false; // signal that next k-combination cannot be represented
    }
    x = v + (((v ^ x)/u) >> 2); // v^x = 0'11^a10^b, (v^x)/u = 0'0^b1^{a+2}, and x ← x'100^b1^a
    return true; // successful completion
}

void handleCase(int caseNo) {
    int numDevices, numBits;
    scanf("%d %d\n", &numDevices, &numBits);
    
    set<int64_t> devices;
    set<int64_t> outlets;
    
    for (int j = 0; j < numDevices; ++j) {
        int64_t tmp = 0L;
        for (int i = 0; i < numBits; ++i) {
            char c;
            scanf("%c", &c);
            if (c == '1') tmp |= (1L << i);
        }
        scanf(" ");
        devices.insert(tmp);
    }
    scanf("\n");
    for (int j = 0; j < numDevices; ++j) {
        int64_t tmp = 0L;
        for (int i = 0; i < numBits; ++i) {
            char c;
            scanf("%c", &c);
            if (c == '1') tmp |= (1L << i);
        }
        scanf(" ");
        outlets.insert(tmp);
    }
    scanf("\n");
    
    set<int64_t>::iterator iter;
    
    int n;
    for (n = 0; n <= numBits; ++n) {
        int64_t mask = (1L << n) - 1;
        set<int64_t> wc;
        int c = 0;
        bool done = false;
        do {
            wc.clear();
            for (iter = devices.begin(); iter != devices.end(); ++iter) {
                wc.insert((*iter) ^ mask);
            }
            if (wc == outlets) {
                done = true; break;
            }
            if (next_combination(mask) == false) break;
        } while (mask < (1 << numBits));
        if (done) break;
    }
    
    printf("Case #%d: ", caseNo);
    
    if (n <= numBits) {
        printf("%d\n", n);
    } else {
        printf("NOT POSSIBLE\n");
    }
}

int main(int argc, const char * argv[])
{
	int numCases = 0;
    
  	scanf("%d\n", &numCases);
    for (int count = 1; count <= numCases; ++count) {
        handleCase(count);
    }
    return 0;
}

