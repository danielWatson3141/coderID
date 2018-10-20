#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define DPF(fmt,...) printf(fmt,##__VA_ARGS__); fprintf(outf, fmt,##__VA_ARGS__);
const int MAX_STR = 2000;
#define CV(vec, type, x) vector<type> vec; vec.resize(x);
#define CV2(vec, type, x, y) vector<vector<type>> vec; vec.resize(y); for(int i = 0; i < y; i++) {vec[i].resize(x);}
#define RI(val) int val = 0; scanf("%d", &val);
#define RF(val) float val = 0.0f; scanf("%f", &val);
#define RS(val) string val; {char str[2000]; scanf("%s", str); val = str;}
#define RC(val) char val = 0; scanf("%c", &val);
#define RL(val) string val; {char str[MAX_STR]; fgets(str, MAX_STR, stdin); int len = strlen(str); str[len - 1] = '\0'; val = str;}
#define RNL() {char str[MAX_STR]; fgets(str, MAX_STR, stdin);}
#define RLI(vec) {int vs = (vec).size(); for(int ii = 0; ii < vs; ii++) {int val; scanf("%d", &val); (vec)[ii] = val;} RNL();}
#define RLF(vec) {int vs = (vec).size(); for(int ii = 0; ii < vs; ii++) {float val; scanf("%f", &val); (vec)[ii] = val;} RNL();}
#define RLS(vec) {int vs = (vec).size(); for(int ii = 0; ii < vs; ii++) {char val[MAX_STR]; scanf("%s", val); (vec)[ii] = val;} RNL();}
#define RLC(vec) {int vs = (vec).size(); for(int ii = 0; ii < vs; ii++) {char val; scanf("%c", &val); (vec)[ii] = val;} RNL();}

#define u64 unsigned long long

bool doDevicesWork(vector<u64>& out, vector<u64>& dev, vector<bool>& dev_used, u64 sw, int N, int L)
{
    for (int i = 0; i < N; i++)
    {
        dev_used[i] = false;
    }

    // turn on switches
    for (int i = 0; i < N; i++)
    {
        out[i] ^= sw;
    }

    int matches = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (out[i] == dev[j] &&
                dev_used[j] == false)
            {
                dev_used[j] = true;
                matches++;
                break;
            }
        }
    }
    return (matches == N);
}

int countBits(u64 sw)
{
    int bits = 0;
    while (sw)
    {
        if (sw & 0x1)
        {
            bits++;
        }
        sw >>= 1;
    }
    return bits;
}

int main()
{
    FILE* inf = freopen("in.txt", "r", stdin);
    FILE* outf = fopen("out.txt", "w");
    RI(np); RNL();
    for (int pp = 1; pp <= np; pp++)
    {
        DPF("Case #%d: ", pp);
        RI(N); RI(L); RNL();

        CV(outlets, u64, N);
        CV(devices, u64, N);
        CV(devices_used, bool, N);

        for (int i = 0; i < N; i++)
        {
            outlets[i] = 0;
            for (int j = L - 1; j >= 0; j--)
            {
                char c;
                scanf("%c", &c);
                if (c == '1')
                {
                    outlets[i] += (1ULL << j);
                }
            }
            if (i != N - 1)
            {
                scanf(" ");
            }
        }
        RNL();
        for (int i = 0; i < N; i++)
        {
            devices[i] = 0;
            for (int j = L - 1; j >= 0; j--)
            {
                char c;
                scanf("%c", &c);
                if (c == '1')
                {
                    devices[i] += (1ULL << j);
                }
            }
            if (i != N - 1)
            {
                scanf(" ");
            }
        }
        RNL();

        // Try switches
        bool possible = false;
        int numSwitches = INT_MAX;
        u64 totalSwitches = (1 << L);
        for (u64 sw = 0; sw <= totalSwitches; sw++)
        {
            vector<u64> toutlet = outlets;
            if (doDevicesWork(toutlet, devices, devices_used, sw, N, L))
            {
                int tNumSwitches = countBits(sw);
                if (tNumSwitches < numSwitches)
                {
                    numSwitches = tNumSwitches;
                }
                possible = true;
            }
        }
        
        if (!possible)
        {
            DPF("NOT POSSIBLE\n");
        }
        else
        {
            DPF("%d\n", numSwitches);
        }
    }
    fclose(inf);
    fclose(outf);
}