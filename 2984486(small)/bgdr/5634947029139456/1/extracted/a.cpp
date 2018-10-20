#include<iostream>
#include<map>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int INF = 100;
int solve_brute()
{
    int N, L;
    cin >> N >> L;
    int ret = INF;

    vector<string> a(N), b(N);
    for(int i = 0; i < N; ++i)
        cin >> a[i];
    for(int i = 0; i < N; ++i)
        cin >> b[i];
    sort(b.begin(), b.end());
    vector<string> _a = a;

    for(int mask = 0; mask < (1 << L); ++mask)
    {
        a = _a;
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < L; ++j)
                if(mask & (1 << j))
                {
                    a[i][j] = (a[i][j] == '1' ? '0' : '1');
                }
        int cnt = 0;
        for(int j = 0; j < L; ++j)
            if(mask & (1 << j)) cnt++;
        sort(a.begin(), a.end());
        bool ok = true;
        for(int i = 0; i < N; ++i)
            if(a[i] != b[i])
            {
                ok = false;
                break;
            }
        if(ok && cnt < ret)
        {
            ret = cnt;
            if(ret == 5)
            {
                for(int j = 0; j < L; ++j)
                    if(mask & (1 << j)) cerr << 0;
                    else cerr << 1;
                cerr << endl;

            }
        }
    }
    return ret;
}
map<vector<int>, int> cache;

int getsol(int idx, vector<int> mask, int N, int L, vector<string> &a, vector<string> &b)
{
    vector<string> _a(a);
    vector<int> key;
    key.push_back(idx);
    for(int i = 0; i < (int)mask.size(); ++i)
		key.push_back(mask[i]);
    if (cache.find(key) != cache.end())
		return cache[key];

    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < (int)mask.size(); ++j)
            {
                _a[i][mask[j]] = (_a[i][mask[j]] == '1' ? '0' : '1');
            }
    }
    sort(_a.begin(), _a.end());
    for(int i = 0; i < N; ++i)
    {
        if(_a[i].substr(0, idx) != b[i].substr(0, idx))
            return cache[key] = INF;
    }
    if(idx == L)
        return cache[key] = 0;

    int acnt0 = 0, bcnt0 = 0;
    for(int i = 0; i < N; ++i)
    {
        acnt0 += a[i][idx] == '0';
        bcnt0 += b[i][idx] == '0';
    }
    if(acnt0 != N - acnt0)
    {
        if(acnt0 == bcnt0)
            return cache[key] = getsol(idx + 1, mask, N, L, a, b);
        if(acnt0 == N - bcnt0) {
			mask.push_back(idx);
			return cache[key] = 1 + getsol(idx + 1, mask, N, L, a, b);
        }
        return cache[key] = INF;
    }
    else
    {
        if(bcnt0 != N - bcnt0)
            return cache[key] = INF;
        int s1 = getsol(idx + 1, mask, N, L, a, b);
        mask.push_back(idx);
        int s2 = 1 + getsol(idx + 1, mask, N, L, a, b);
        return cache[key] = min(s1, s2);
    }
}
int solve()
{
    int N, L;
    cin >> N >> L;
    vector<string> a(N), b(N);
    for(int i = 0; i < N; ++i)
        cin >> a[i];
    for(int i = 0; i < N; ++i)
        cin >> b[i];
    sort(b.begin(), b.end());
    cache.clear();
    return getsol(0, vector<int>(), N, L, a, b);
}
int main()
{
    int T;
    cin >> T;
    for(int t = 1; t <= T; ++t)
    {
        int sol = solve();
        cout << "Case #" << t << ": ";
        if (sol >= INF)
            cout << "NOT POSSIBLE";
        else cout << sol;
        cout << endl;
    }
    return 0;
}
