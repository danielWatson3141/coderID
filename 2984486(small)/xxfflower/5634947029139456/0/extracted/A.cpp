#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <string>
using namespace std;

typedef long long int64;
typedef unsigned long long uint64;

int main()
{
    int t, N, L, ans = 0;    
    cin >> t;
    for (int c = 1; c <= t; c++)
    {
        cin >> N >> L;
        vector<int> o(L);
        vector<int> d(L);

        vector<string> O(N);
        vector<string> D(N);        

        for (int i = 0; i < N; i++)
        {
            cin >> O[i];
            for (int l = 0; l < L; l++)
                if (O[i][l] == '1') o[l]++;
        }

        for (int i = 0; i < N; i++)
        {
            cin >> D[i];
            for (int l = 0; l < L; l++)
                if (D[i][l] == '1') d[l]++;
        }

        vector<int> flips;

        flips.push_back(N + 1);

        for (int i = 0; i < L; i++)
        {
            if (o[i] == d[i] && o[i] + d[i] == N)
            {
                flips.push_back(i+1);
                flips.push_back(-(i+1));
            }
        }

        cerr << "flips.size = " << flips.size() << endl;
        
        int min_ans = N + 1;        
        
        for (int flip : flips)
        {
            ans = 0;
            bool valid = true;
            vector<string> TO = O;
            for (int i = 0; i < L && valid; i++)
            {
                if (o[i] == d[i] && i!=abs(flip)-1) continue;

                if (o[i] + d[i] == N)
                {
                    if (flip >= 0)
                    {
                        // flip
                        for (int j = 0; j < N; j++)
                        {
                            TO[j][i] = '1' - TO[j][i] + '0';
                        }

                        ans++;
                    }
                }
                else
                {
                    valid = false;
                    break;
                }
            }

            if (valid)
            {
                std::sort(TO.begin(), TO.end());
                std::sort(D.begin(), D.end());

                for (int i = 0; i < N; i++)
                {
                    if (TO[i] != D[i]) {
                        valid = false;
                        break;
                    }
                }

                if (valid)
                {
                    min_ans = std::min(min_ans, ans);
                }
            }
        }

        cout << "Case #" << c << ": ";

        if (min_ans <= N)
            cout << min_ans << endl;
        else
            cout << "NOT POSSIBLE" << endl;
    }
    return 0;
}