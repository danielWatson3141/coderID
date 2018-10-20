#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> v[1009];

void ReadData()
{
  scanf("%d", &n);
  for(int i = 0; i < 1009; i++)
  {
    v[i].clear();
  }
  for(int i = 1; i < n; i++)
  {
    int from, to;
    scanf("%d %d", &from, &to);
    v[from - 1].push_back(to - 1);
    v[to - 1].push_back(from - 1);
  }
}

int TryNewRoot(int root, int prev)
{
  int a = 0, b = 0;
  for(vector<int>::iterator it = v[root].begin(); it != v[root].end(); it++)
  {
    if(*it != prev)
    {
      int current = TryNewRoot(*it, root);
      if(current >= a)
      {
        b = a;
        a = current;
      }
      else if(current >= b)
      {
        b = current;
      }
    }
  }
  if((a + b != 0) && (a * b == 0))
  {
    return 1;
  }
  return 1 + a + b;
}

int answer;

void Solve()
{
  answer = 0;
  for(int i = 0; i < n; i++)
  {
    answer = max(answer, TryNewRoot(i, -1));
  }
}

void WriteData()
{
  printf("%d\n", n - answer);
}

int main()
{
  int QWE;
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  scanf("%d", &QWE);
  for(int T = 0; T < QWE; T++)
  {
    printf("Case #%d: ", T + 1);
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}