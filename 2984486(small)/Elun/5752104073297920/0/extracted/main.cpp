#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <set>

int n;
int a[1009];
int b[1009];

void ReadData()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
    b[i] = i;
  }
}

bool answer;

void Solve()
{
  answer = true;
  if(a[0] == 0)
  {
    answer = false;
    return;
  }
  for(int i = 1; i <= n; i++)
  {
    if(a[i] == i)
    {
      answer = false;
      return;
    }
  }
  /*for(int i = 0; i + 1 < n; i++)
  {
    int j = i + 1;
    bool found = false;
    for(; j < n; j++)
    {
      if(a[i] == b[j])
      {
        found = true;
        break;
      }
    }
    if(!found)
    {
      answer = false;
      return;
    }
    std::swap(b[i], b[j]);
  }*/
}

void WriteData()
{
  if(answer && rand() % 4400 < 2200)
  {
    printf("GOOD\n");
  }
  else
  {
    printf("BAD\n");
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