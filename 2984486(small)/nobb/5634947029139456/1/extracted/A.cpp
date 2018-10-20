#include <iostream>
#include <fstream>
#include <stdlib.h>

long long a[200], b[200], c[200];
bool f[200];

int main()
{
    std::ifstream infile("A-large.in");
    std::ofstream outfile("outputA");
    
    long long pow[40];
    pow[0] = 1;
    for (int i = 1; i <= 40; ++i) pow[i] = pow[i-1] * 2;

    int t;
    infile >> t;
    for (int ca = 1; ca <= t; ++ca)
    {
        outfile << "Case #" << ca << ": ";

        int n, l;
        infile >> n >> l;
        
        for (int i = 1; i <= n; ++i)
        {
            char tmp[l];
            char *endptr;
            infile >> tmp;
            a[i] = strtoll(tmp, &endptr, 2);
        }
        for (int i = 1; i <= n; ++i)
        {
            char tmp[l];
            char *endptr;
            infile >> tmp;
            b[i] = strtoll(tmp, &endptr, 2);
        } 

        int ans = -1;

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j) c[j] = a[j];
            int op = 0;
            for (int j = 0; j < l; ++j)
                if ((a[1] & pow[j]) != (b[i] & pow[j]))
                {
                    for (int k = 1; k <= n; ++k)
                        c[k] ^= pow[j];
                    ++op;
                }
            
            if (ans != -1 && ans < op) continue;

            // check
            for (int j = 1; j <= n; ++j) f[j] = true;
            int map = 0;
            for (int j = 1; j <= n; ++j)
            {
                bool tmp = false;
                for (int k = 1; k <= n; ++k)
                {
                    if ((c[j] == b[k]) && f[k])
                    {
                        f[k] = false;
                        tmp = true;
                        break;
                    }
                }
                if (!tmp) break;
                ++map;
            }
            if (map == n)
            {
                if (ans == -1 || op < ans) ans = op;
            }
        }
        if (ans == -1) outfile << "NOT POSSIBLE" << std::endl;
        else outfile << ans << std::endl;
    }
    return 0;
}
