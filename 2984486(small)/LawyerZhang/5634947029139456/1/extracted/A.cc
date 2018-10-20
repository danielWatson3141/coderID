#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

char flip(char c)
{
    if (c == '0')
        return '1';
    else
        return '0';
}

bool verify(vector<string> &config, vector<string> &orig_target, int *result)
{
    int n = config.size(), l = config[0].length();
    vector<string> after;
    for (int i = 0; i < n; ++i)
    {
        after.push_back("");
        for (int j = 0; j < l; ++j)
        {
            if (result[j])
                after[i] += flip(config[i][j]);
            else
                after[i] += config[i][j];
        }
    }

    vector<string> target(orig_target);

    sort(after.begin(), after.end());
    sort(target.begin(), target.end());
    
    for (int i = 0; i < n; ++i)
        if (after[i] != target[i])
            return false;
    return true;
}

int solveOdd(vector<string> &config, vector<string> &target, int *result)
{
    int l = config[0].length(), n = config.size();
    int ans = 0;
    for (int i = 0; i < l; ++i)
    {
        int zeros_config = 0, zeros_target = 0;
        for (int j = 0; j < n; ++j)
            if (config[j][i] == '0')
                ++zeros_config;
        for (int j = 0; j < n; ++j)
            if (target[j][i] == '0')
                ++zeros_config;
        if (zeros_config == zeros_target)
            result[i] = 0;
        else if (zeros_config == n - zeros_target)
        {
            result[i] = 1;
            ++ans;
        }
        else
            return -1;
    }

    if (!verify(config, target, result))
        return -1;
    else
        return ans;
}

int solve(vector<string> &config, vector<string> &target)
{
    int result[200];
    if (config.size() % 2 != 0)
        return solveOdd(config, target, result);

    int n = config.size();
    for (int i = 0; i < n; ++i)
    {
        vector<string> newConfig = config;
        newConfig.erase(newConfig.begin() + i);
        vector<string> newTarget = target;
        newTarget.erase(newTarget.begin() + 1);

        int ans = solveOdd(newConfig, newTarget, result);
        if (ans == -1)
            continue;
        newConfig.push_back(config[i]);
        newTarget.push_back(target[0]);
        if (verify(newConfig, newTarget, result))
            return ans;
    }
    return -1;
}

void getResult(string a, string b, int *result)
{
    for (int i = 0; i < a.length(); ++i)
        if (a[i] == b[i])
            result[i] = 0;
        else
            result[i] = 1;
}

int main()
{
    int T;
    cin >> T;
    for (int cs = 1; cs <= T; ++cs)
    {
        vector<string> config, target;
        int n, l;
        cin >> n >> l;
        for (int i = 0; i < n; ++i)
        {
            string s;
            cin >> s;
            config.push_back(s);
        }
        for (int i = 0; i < n; ++i)
        {
            string s;
            cin >> s;
            target.push_back(s);
        }
        int result[200], ans = -1;
        for (int i = 0; i < n; ++i)
        {
            getResult(config[i], target[0], result);
            if (verify(config, target, result))
            {
                int c = 0;
                for (int j = 0; j < l; ++j)
                    if (result[j])
                        ++c;
                if (ans == -1)
                    ans = c;
                else
                    ans = min(ans, c);
            }
        }
        cout << "Case #" << cs << ": ";
        if (ans == -1)
            cout << "NOT POSSIBLE" << endl;
        else
            cout << ans << endl;
    }
}
