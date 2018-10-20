#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <windows.h>

using namespace std;

bool FindPath(vector<vector<vector<pair<long long, int>>>> edge, int k, int check, int N, vector<int> &pair, vector<int> &Rpair, int i)
{
	for (int l = 0; l < edge[i][k].size(); ++l)
    {
		int j = edge[i][k][l].second;
        if (edge[i][k][l].first == check && (Rpair[j] == -1 || (Rpair[j] != i && FindPath(edge, k, check, N, pair, Rpair, Rpair[j]))))
        {
            pair[i] = j;
            Rpair[j] = i;
            return true;
        }
    }
    return false;
}


int maxPair(vector<vector<vector<pair<long long, int>>>> edge, int k, int check, int N, vector<int> &pair, vector<int> &Rpair)
{
    int result = 0;
    for(int i = 0; i < N; ++i)
    {
        if (pair[i] == -1)
        {
            if (!FindPath(edge, k, check, N, pair, Rpair, i))
            {
                return result;
            }
            ++result;
        }
    }
    return result;
}

void Solve() {
    int N, L;
    cin >> N >> L;
    vector<string> original(N);
    for(int i = 0; i < N; ++i)
    {
        cin >> original[i];
    }
    vector<string> expect(N);
    for(int i = 0; i < N; ++i)
    {
        cin >> expect[i];
    }

    vector<vector<long long>> diff(N, vector<long long>(N, 0));
    vector<vector<int>> cnt(N, vector<int>(N, 0));
	vector<vector<vector<pair<long long, int>>>> edge(N, vector<vector<pair<long long, int>>>(L + 1, vector<pair<long long, int>>()));
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
			diff[i][j] = 0;
			cnt[i][j] = 0;
            for(int k = 0; k < L; ++k)
            {
				int add = (original[i][k] == expect[j][k]) ? 0 : 1;
                diff[i][j] = (diff[i][j] << 1) + add;
                cnt[i][j] += add;
            }
			edge[i][cnt[i][j]].push_back(make_pair(diff[i][j], j));
        }
    }
    for(int k = 0; k <= L; ++k)
    {
        for(int i = 0; i < edge[0][k].size(); ++i)
        {	
            vector<int> pair(N, -1);
            vector<int> Rpair(N, -1);
            if (maxPair(edge, k, edge[0][k][i].first, N, pair, Rpair) == N)
            {
                cout << k;
                return;
            }
        }
    }
    cout << "NOT POSSIBLE";
}

int main() {
    //Sleep(15 * 1000);
  int n;
  cin >> n;
  for(int i = 0; i < n; ++i) {
    cout << "Case #" << i + 1 << ": ";
    Solve();
	cout << endl;
  }
  return 0;
}
