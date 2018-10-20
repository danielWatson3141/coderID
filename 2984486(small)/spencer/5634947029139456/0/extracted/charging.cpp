#include <cstdio>
#include <map>
#include <string>
using namespace std;


#define MAX_N 150


int N, L;
string outlets[MAX_N];
string devices[MAX_N];
map<string, int> matches;


void setup()
{
    scanf("%d %d", &N, &L);

    for (int i = 0; i < N; i++)
    {
        char str[L+1];
        scanf("%s", str);
        outlets[i] = string(str);
    }

    for (int i = 0; i < N; i++)
    {
        char str[L+1];
        scanf("%s", str);
        devices[i] = string(str);
    }

    matches.clear();
}


string flips(string a, string b)
{
    char s[L+1];
    for (int i = 0; i < L; i++)
        s[i] = (a[i] != b[i]) + '0';
    s[L] = 0;

    return string(s);
}


int count_flips(string a)
{
    int total = 0;
    for (int i = 0; i < L; i++)
        total += (a[i] == '1');

    return total;
}


void solve_case(int test_case)
{
    setup();

    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
    {
        string f = flips(outlets[i], devices[j]);
        matches[f]++;
    }


    bool possible = false;
    int minimum = L;
    for (map<string, int>::iterator it = matches.begin(); it != matches.end(); it++)
    {
        if (it->second == N)
        {
            possible = true;
            minimum = min(minimum, count_flips(it->first));
        }
    }


    printf("Case #%d: ", test_case);
    if (!possible) puts("NOT POSSIBLE");
    else printf("%d\n", minimum);
}


int main()
{
    int T; scanf("%d", &T);
    for (int t = 1; t <= T; t++)
        solve_case(t);
    return 0;
}
