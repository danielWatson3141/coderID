#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<fstream>
using namespace std;
int switches = 0;
vector<int> tobinary(int k)
{
    switches = 0;
    vector<int> res;
    while(k)
    {
        res.push_back(k % 2);
        switches += k % 2;
        k /= 2;
    }
    return res;
}
int  solve(vector<string> & els, vector<string> & ds, int n, int l)
{
    int i, j, m, k, res = 1000;
    sort(ds.begin(), ds.end());
    for (j = 0; j < (1 << l); j++)
    {
        vector<int> inst = tobinary(j);
        vector<string> curv = els;
      /*  for (i = 0; i < inst.size(); i++)
          cout << inst[i];
        cout << endl;*/
        for (i = 0; i < inst.size(); i++)
        {
            if (!inst[i])
              continue;
            for (m = 0; m < n; m++)
            {
                curv[m][i] = '0' + (1 - (curv[m][i] - '0'));
            }
        }
        sort(curv.begin(), curv.end());
      /*  for (i = 0; i < curv.size(); i++)
        {
            cout << curv[i] << ' ' << ds[i]  << endl;
        }*/
        for (i = 0; i < curv.size(); i++)
          if (curv[i] != ds[i])
            break;
        if (i == curv.size())
        {
            res = min(res, switches);
        }
    }
    return res;
}
int main()
{
  int i, j, n, m, k, l;

  ifstream cin("input.in");
  ofstream cout ("output.txt");
  int t;
  cin >> t;
  for (k = 1; k <= t; k++)
  {
      cin >> n >> l;
      vector<string> els(n);
      vector<string> ds(n);
      for (j = 0; j < n; j++)
        cin >> els[j];
      for (j = 0; j < n; j++)
        cin >> ds[j];

      int res = solve(els, ds, n, l);
      cout << "Case #" << k << ": ";
      if (res == 1000)
        cout << "NOT POSSIBLE\n";
      else
        cout << res << endl;
  }
}
