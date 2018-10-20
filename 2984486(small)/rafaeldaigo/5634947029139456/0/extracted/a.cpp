#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<queue>
#include<utility>
#include<algorithm>

using namespace std;

int main()
{
    int t, teste;
    int n, l;
    int i, j, k;
    string input[200];
    string output[200];
    string converted[200];
    cin >> teste;
    for (int t = 0; t < teste; t++)
    {
        cin >> n >> l;
        for (i = 0; i < n; i++)
        {
            cin >> input[i];
        }
        for (j = 0; j < n; j++)
        {
            cin >> output[j];
        }
        sort(&input[0], &input[n]);

        int ans = 200;
        for (k = 0; k < n; k++)
        {
            int changes = 0;
            for (j = 0; j < l; j++)
            {
                if (input[0][j] != output[k][j])
                    changes++;
            }
            if (changes > ans)
                continue;

            for (i = 0; i < n; i++)
            {
                string con = "";
                for (j = 0; j < l; j++)
                {
                    if (input[0][j] == output[k][j])
                        con += output[i][j];
                    else if (output[i][j] == '0')
                        con += '1';
                    else
                        con += '0';
                }
                converted[i] = con;
            }
            sort(&converted[0], &converted[n]);

            for (i = 0; i < n; i++)
            {
                if (input[i] != converted[i])
                    break;
            }
            if (i == n)
            {
                ans = changes;
            }
        }

        if (ans >= 200)
        {
            printf("Case #%d: NOT POSSIBLE\n", t + 1);
        }
        else
        {
            printf("Case #%d: %d\n", t + 1, ans);
        }
    }
    return 0;
}
