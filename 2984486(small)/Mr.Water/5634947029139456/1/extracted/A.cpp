// GCJ 2014 Qualification Round 1A
// problem A

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX_PATTERN = (1 << 11);
const int MAX_LENGTH = 45, MAXN = 155;

int device_pattern[MAXN], outlet_pattern[MAXN];
bool used[MAXN];

bool check(int device, int n, int pattern)
{
    if (device >= n)
        return true;
    for (int i = 0; i < n; i++)
        if (!used[i] && (device_pattern[device] ^ outlet_pattern[i]) == pattern)
        {
            used[i] = true;
            if (check(device + 1, n, pattern))
                return true;
            used[i] = false;
        }
    return false;
}

int main()
{

    FILE *fin = fopen("A.in", "r");
    FILE *fout = fopen("A.out", "w");

    int test_case, test_now, i, j, k, n, l, ans;
    char s[MAX_LENGTH];

    fscanf(fin, "%d", &test_case);

    for (test_now = 1; test_now <= test_case; test_now++)
    {
        fscanf(fin, "%d%d", &n, &l);
        for (i = 0; i < n; i++)
        {
            fscanf(fin, "%s", s);
            outlet_pattern[i] = 0;
            for (j = 0; j < strlen(s); j++)
                outlet_pattern[i] += ((s[j] - '0') << j);
        }
        for (i = 0; i < n; i++)
        {
            fscanf(fin, "%s", s);
            device_pattern[i] = 0;
            for (j = 0; j < strlen(s); j++)
                device_pattern[i] += ((s[j] - '0') << j);
        }

        for (i = 0; i < n; i++)
            for (j = i + 1; j < n; j++)
                if (device_pattern[j] < device_pattern[i])
                {
                    k = device_pattern[j];
                    device_pattern[j] = device_pattern[i];
                    device_pattern[i] = k;
                }

        ans = -1;

        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
            {
                int pattern = (device_pattern[i] ^ outlet_pattern[j]);
                for (k = 0; k < n; k++)
                    used[k] = false;
                if (check(0, n, pattern))
                {
                    k = 0;
                    while (pattern > 0)
                    {
                        if ((pattern & 1) == 1)
                            k++;
                        pattern = (pattern >> 1);
                    }
                    if (ans < 0 || k < ans)
                        ans = k;
                }

            }

        if (ans < 0)
            fprintf(fout, "Case #%d: NOT POSSIBLE\n", test_now);
        else
            fprintf(fout, "Case #%d: %d\n", test_now, ans);

        printf("test #%d finished\n", test_now);

    }

    fclose(fin);
    fclose(fout);

    return 0;
}





