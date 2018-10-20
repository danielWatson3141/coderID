#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<fstream>
#include<cmath>
using namespace std;
vector<int> del;
int switches;
vector<int> tobinary(int k)
{
    switches = 0;
    while(k)
    {
        del.push_back(k % 2);
        switches += k % 2;
        k /= 2;
    }
   // return res;
}
vector<int> dists;
void calcdists(int curv,int curd, vector<vector<int> > & g)
{
    dists[curv] = curd;
    for (int i = 0; i < g[curv].size(); i++)
    {
        if (dists[g[curv][i]] == 1000)
          calcdists(g[curv][i], curd + 1, g);
    }
}
bool check(int n, vector<pair<int, int> > & e)
{
    vector<vector<int> > g(n);
    int i, j, l, res = 1000;
    for (j = 0; j < e.size(); j++)
    {
        if ((e[j].first < del.size() && del[e[j].first]) || (e[j].second < del.size() && del[e[j].second]))
        {
            continue;
        }
        g[e[j].first].push_back(e[j].second);
        g[e[j].second].push_back(e[j].first);
    }
  /*  cout << "Newgr\n";
    for (j = 0; j < n; j++)
    {
        cout << j << ": ";
        for (i = 0; i < g[j].size(); i++)
          cout << g[j][i] << ' ';
        cout << endl;
    }
    */
    for(j = 0; j < n; j++)
    {
        if (j < del.size() && del[j])
        {
            continue;
        }

        dists.clear();
        dists.resize(n, 1000);
        //cout << "t";
        calcdists(j, 0, g);
        for(i = 0; i < n; i++)
        {
            if (i < del.size() && del[i])
              continue;
            if (dists[i] == 1000)
              break;
            int cnt = 0;
            for (l = 0; l < g[i].size(); l++)
            {
                if (dists[g[i][l]] > dists[i])
                  cnt++;
            }
            if (cnt != 0 && cnt != 2)
              break;
        }
        if (i == n)
        {
          //cout << "good in "  << j << endl;
          return 1;
        }
    }
    return 0;
}
int solve(int n, vector<pair<int, int> > & e)
{
    int i, j, m, k, res = 1000;
    for (j = 0; j < (1 << (n)); j++)
    {
        //cout << j << endl;
      del.clear();
      tobinary(j);
      if(check(n, e))
        res = min(res, switches);
    }
    return res;
}
int main()
{
  int i, j, n, m, k, t;
  ifstream cin ("input_bsmall.in");
  ofstream cout ("output_bsmall.txt");
  cin >> t;
  for (k = 1; k < t + 1; k++)
  {
      vector<pair<int, int> > e;
      cin >> n;
      e.resize(n - 1);
      for (j = 0; j < n - 1; j++)
      {
          int a, b;

          cin >> a >> b;
          e[j] = make_pair(a - 1, b - 1);
      }
       int res = solve(n, e);
          cout << "Case #" << k << ": " << res << endl;
  }
}
