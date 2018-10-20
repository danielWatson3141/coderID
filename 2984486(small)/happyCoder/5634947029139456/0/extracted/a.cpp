#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>

using namespace std;

vector<vector<bool> > readV(int N, int L)
{
  vector<vector<bool> > r(N, vector<bool>(L, false)); 
  for (int i = 0; i < N; ++i)
  {
    string s;
    cin >> s;
    for (int j = 0; j < L; ++j)
    {
      r[i][j] = s[j] == '1';
    }
  }
  return r;
}

int main()
{
  int T;
  cin >> T;
  for (int i = 1; i <= T; ++i)
  {
    int N, L;
    cin >> N >> L;
    vector<vector<bool> > a = readV(N, L);
    vector<vector<bool> > b = readV(N, L);
    vector<list<vector<bool>>> s(N, list<vector<bool>>());
    for (int j = 0; j < N; ++j)
    {
      for (int k = 0; k < N; ++k)
      {
	vector<bool> sp(L, false);
	for (int l = 0; l < L; ++l)
	  sp[l] = a[j][l] != b[k][l];
	s[j].push_back(sp);
      }
    }
    list<vector<bool>> r = s[0];
    r.sort();
    for (int j = 1; j < N; ++j)
    {
      list<vector<bool>> nr;
      s[j].sort();
      set_intersection(r.begin(), r.end(), s[j].begin(), s[j].end(), back_inserter(nr));
      r = nr;
    }
    cout << "Case #" << i << ": "; 
    if (r.empty())
      cout << "NOT POSSIBLE" << endl;
    else
    {
      int res = L;
      for (auto it = r.begin(); it != r.end(); ++it)
	res = min(res, (int)count(it->begin(), it->end(), true));
      cout << res << endl;
    }
  }
  return 0;
}
