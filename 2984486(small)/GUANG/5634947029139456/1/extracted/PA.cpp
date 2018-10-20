#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

ifstream fin("data.txt");
ofstream fout("output.txt");


int flip_once(const string &s, const string &t, vector<int> &f)
{
    int result = 0;
    for (size_t i = 0; i < s.length(); ++i)
        result += (f[i] = (s[i] == t[i] ? 0 : 1));

    return result;
}

bool flip_all(vector<string> s, vector<string> t, const vector<int> &flip)
{
    for (auto i = s.begin(); i != s.end(); ++i)
    {
        int k = 0;
        for (auto j = i->begin(); j != i->end(); ++j, ++k)
            if (flip[k])
                *j = (*j == '0' ? '1' : '0');
    }

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    return s == t;
}

void run_once()
{
    vector<string> in, out;
    vector<int> flip;

    int n, m;
    fin >> n >> m;

    in.resize(n);
    out.resize(n);
    flip.resize(m);

    for (int i = 0; i < n; ++i)
        fin >> in[i];

    for (int i = 0; i < n; ++i)
        fin >> out[i];
        
    int result = -1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int d = flip_once(in[i], out[j], flip);

            if (flip_all(in, out, flip) && (result == -1 || d < result))
                result = d;

        }
    }

    if (result == -1)
        fout << "NOT POSSIBLE\n";
    else
        fout << result << endl;
}

int main()
{
    int case_count;
    fin >> case_count;

    for (int case_id = 1; case_id <= case_count; ++case_id)
    {
        fout << "Case #" << case_id << ": ";
        run_once();
    }

    return 0;
}