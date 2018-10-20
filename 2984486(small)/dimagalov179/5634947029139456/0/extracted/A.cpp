#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

int get_bit(int n, int x)
{
    return (n >> x) & 1;
}

char inv(char c)
{
    if (c == '0')
        return '1';
    return '0';
}

int count(int n)
{
    int answer = 0;
    for (int i = 0; i < 15; ++i)
        answer += get_bit(n, i);
    return answer;
}

int main()
{
    ifstream cin("input.txt");
    // ofstream cout("output1.txt");
    int t;
    cin >> t;
    for (int q = 0; q < t; ++q)
    {
        int n, l, answer = 1000 * 1000;
        cin >> n >> l;
        vector<string> A(n), B(n);
        for (int i = 0; i < n; ++i)
            cin >> A[i];
        for (int i = 0; i < n; ++i)
            cin >> B[i];

        for (int mask = 0; mask < pow(2, l); ++mask)
        {
            // cout << mask << endl;
            bool flag = true;
            for (int i = 0; i < n; ++i)
            {
                string current = A[i];
                for (int j = 0; j < l; ++j)
                {
                    // cout << "? " << get_bit(mask, j) << endl;
                    if (get_bit(mask, j))
                    {
                        // cout << "! " << j << endl;
                        if (current[j] == '0')
                            current[j] = '1';
                        else
                            current[j] = '0';
                    }
                }
                // cout << current << endl;
                bool found = false;
                for (int j = 0; j < n; ++j)
                    if (current == B[j])
                        found = true;
                if (!found)
                    flag = false;
            }
            if (flag == true)
            {
                answer = min(answer, count(mask));
            }
        }
        cout << "Case #" << q + 1 << ": ";
        if (answer != 1000 * 1000)
            cout << answer << endl;
        else
            cout << "NOT POSSIBLE" << endl;
    }
}