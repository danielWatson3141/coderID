// GCJ 2014 Qualification Round 1A
// problem A

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX_PATTERN = (1 << 11);
const int MAX_LENGTH = 45, MAXN = 155;

int bit_pattern[MAX_PATTERN], bit_one[MAX_PATTERN], pattern_num;

void gen_pattern(int pos_cur, int one_cnt, int pattern_length, int target_one, int pattern_cur)
{
    if (one_cnt >= target_one)
    {
        bit_pattern[pattern_num++] = pattern_cur;
        bit_one[pattern_num - 1] = target_one;
    }
    else
    {
        for (int i = pos_cur; i < pattern_length; i++)
            gen_pattern(i + 1, one_cnt + 1, pattern_length, target_one, pattern_cur + (1 << i));
    }
}

void init(int l)
{
    pattern_num = 1;
    bit_pattern[0] = 0;
    for (int i = 1; i <= l; i++)
        gen_pattern(0, 0, l, i, 0);
}

int main()
{

    FILE *fin = fopen("A.in", "r");
    FILE *fout = fopen("A.out", "w");

    int test_case, test_now, i, j, k, n, l, ans;
    int device_pattern[MAXN], outlet_pattern[MAXN], outlet_pattern_switched[MAXN];
    char s[MAX_LENGTH];
    bool check;

    fscanf(fin, "%d", &test_case);

    for (test_now = 1; test_now <= test_case; test_now++)
    {
        fscanf(fin, "%d%d", &n, &l);
        init(l);
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

        for (ans = 0; ans < pattern_num; ans++)
        {
            for (i = 0; i < n; i++)
                outlet_pattern_switched[i] = (outlet_pattern[i] ^ bit_pattern[ans]);
            for (i = 0; i < n; i++)
                for (j = i + 1; j < n; j++)
                    if (outlet_pattern_switched[j] < outlet_pattern_switched[i])
                    {
                        k = outlet_pattern_switched[i];
                        outlet_pattern_switched[i] = outlet_pattern_switched[j];
                        outlet_pattern_switched[j] = k;
                    }

            check = true;
            for (i = 0; check && i < n; i++)
                if (device_pattern[i] != outlet_pattern_switched[i])
                    check = false;
            if (check)
                break;
        }

        if (ans >= pattern_num)
            fprintf(fout, "Case #%d: NOT POSSIBLE\n", test_now);
        else
            fprintf(fout, "Case #%d: %d\n", test_now, bit_one[ans]);

    }

    fclose(fin);
    fclose(fout);

    return 0;
}





