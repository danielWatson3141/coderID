#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int T;
int N, L;

vector<string> outlets;
vector<string> flippedOutlets;
vector<string> devices;
vector<int> flipPos;

void FindFlipPos(const string & a, const string & b)
{
    flipPos.resize(a.size());
    int j = 0;
    for (int i = 0; i < a.size(); ++i)
    {
        if (a[i] != b[i])
        {
            flipPos[j++] = i;
        }
    }
    flipPos.resize(j);
}

void FlipOutlet(const string & input, string & output)
{
    output = input;
    for (int i = 0; i < flipPos.size(); ++i)
    {
        output[flipPos[i]] = input[flipPos[i]] == '0' ? '1' : '0';
    }
}

void Solve(int t)
{
    vector<int> results;
    // sort the devices
    sort(devices.begin(), devices.end());
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            // try to match outlet i with device j
            FindFlipPos(outlets[i], devices[j]);
            // try to flip all outlets
            for (int k = 0; k < N; ++k)
            {
                FlipOutlet(outlets[k], flippedOutlets[k]);
            }
            // sort the flipped outlets
            sort(flippedOutlets.begin(), flippedOutlets.end());
            // compare the outlets
            int k = 0;
            for (; k < N; ++k)
            {
                if (devices[k] != flippedOutlets[k])
                {
                    break;
                }                
            }
            if (k == N)
            {
                results.push_back(flipPos.size());                
            }
        }
    }
    sort(results.begin(), results.end());
    cout << "Case #" << t << ": ";
    if (!results.empty())
    {
        cout << results[0] << endl;
    }
    else
    {
        cout << "NOT POSSIBLE" << endl;
    }
}

int main()
{
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        cin >> N >> L;
        outlets.resize(N);
        flippedOutlets.resize(N);
        devices.resize(N);
        for (int i = 0; i < N; ++i)
        {
            cin >> outlets[i];
        }
        for (int i = 0; i < N; ++i)
        {
            cin >> devices[i];
        }
        Solve(t);
        
    }
    int a = 0;
}
