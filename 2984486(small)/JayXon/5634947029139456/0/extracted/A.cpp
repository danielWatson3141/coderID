#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdint>

using namespace std;

bool possible(vector<string> e1, vector<string> e2, vector<int>& maybe, uint64_t bit)
{
    int m = maybe.size();
    int n = e1.size();
    for (int i = 0; i < m; i++)
    {
        if (bit & (((uint64_t)1) << i))
        {
            for (int j = 0; j < n; j++)
            {
                if (e1[j][maybe[i]] == '1')
                {
                    e1[j][maybe[i]] = '0';
                }
                else
                {
                    e1[j][maybe[i]] = '1';
                }
            }
        }
    }

    sort(e1.begin(), e1.end());
    sort(e2.begin(), e2.end());
    for (int i = 0; i < n; i++)
    {
        if (e1[i] != e2[i])
        {
            return false;
        }
    }
    return true;
}


int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        return 1;
    }
    char name[256];
    strcpy(name, argv[1]);

    ifstream fin(name);
    name[strlen(name)-2] = 0;
    strcat(name, "out");
    ofstream fout(name);

    if (!fin.is_open() || !fout.is_open())
    {
        return 1;
    }

    int t, t1 = 0;

    fin >> t;

    while (t1++ < t)
    {
        int n, l;
        fin >> n >> l;
        vector<string> e1, e2;
        bool is_impossible = false;
        vector<int> maybe;
        int flip_count = 0;
        e1.resize(n);
        e2.resize(n);
        for (int i = 0; i < n; i++)
        {
            fin >> e1[i];
        }
        for (int i = 0; i < n; i++)
        {
            fin >> e2[i];
        }

        for (int i = 0; i < l; i++)
        {
            int s1 = 0, s2 = 0;
            for (int j = 0; j < n; j++)
            {
                s1 += e1[j][i] == '1';
                s2 += e2[j][i] == '1';
            }
            if (s1 + s2 == n && s1 != s2)
            {
                flip_count++;
                for (int j = 0; j < n; j++)
                {
                    if (e1[j][i] == '1')
                    {
                        e1[j][i] = '0';
                    }
                    else
                    {
                        e1[j][i] = '1';
                    }
                }
            }
            else if (s1 == s2)
            {
                maybe.push_back(i);
            }
            else
            {
                is_impossible = true;
                break;
            }
        }
        uint64_t ntry = pow(2, maybe.size());
        bool p = false;
        for (uint64_t i = 0; i < ntry; i++)
        {
            if (possible(e1, e2, maybe, i))
            {
                p = true;
                is_impossible = false;
                while (i)
                {
                    i &= i - 1;
                    flip_count++;
                }

                break;
            }
        }

        fout << "Case #" << t1 << ": ";
        if (is_impossible)
        {
            fout << "NOT POSSIBLE" << endl;
        }
        else
        {
            fout << flip_count << endl;
        }

    }

    return 0;
}