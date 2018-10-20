#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <set>

int n, l;
__int64 a[200], b[200];

void ReadData()
{
  scanf("%d %d%*c", &n, &l);
  memset(a, 0, sizeof(a));
  char str[50];
  for(int i = 0; i < n; i++)
  {
    scanf("%s%*c", str);
    for(int j = 0; j < l; j++)
    {
      a[i] <<= 1;
      if(str[j] == '1')
      {
        a[i] |= 1LL;
      }
    }
  }
  for(int i = 0; i < n; i++)
  {
    scanf("%s%*c", str);
    for(int j = 0; j < l; j++)
    {
      b[i] <<= 1;
      if(str[j] == '1')
      {
        b[i] |= 1LL;
      }
    }
  }
}

int answer;
__int64 current[200];

inline bool check()
{
  std::set<__int64> checker(current, current + n);
  if(checker.size() != n)
  {
    return false;
  }
  for(int i = 0; i < n; i++)
  {
    if(checker.find(a[i]) == checker.end())
    {
      return false;
    }
  }
  return true;
}

void Solve()
{
  answer = INT_MAX;
  for(int i = 0; i < n; i++)
  {
    memset(current, 0, sizeof(current));
    int changes = 0;
    for(int j = l - 1; j >= 0; j--)
    {
      bool flag = (a[i] & (1LL << j)) != (b[0] & (1LL << j));
      if(flag)
      {
        changes++;
      }
      for(int k = 0; k < n; k++)
      {
        current[k] <<= 1;
        bool isOn = b[k] & (1LL << j);
        if((flag && isOn == false) || (flag == false && isOn))
        {
          current[k] |= 1LL;
        }
      }
    }
    if(check())
    {
      answer = std::min(answer, changes);
    }
  }
}

void WriteData()
{
  if(answer == INT_MAX)
  {
    printf("NOT POSSIBLE\n");
  }
  else
  {
    printf("%d\n", answer);
  }
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