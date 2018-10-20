#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef unsigned long long ull;

vector<ull> possible_turns;
int N, L;
ull devices[200];
ull outlets[200];
ull changed_outlets[200];


int main()
{
  freopen("A-small-attempt0.in", "r", stdin);
  freopen("A-result-small.txt", "w", stdout);
  int T;
  scanf("%d", &T);

  for (int i = 0; i < T; ++i)
  {
    possible_turns.clear();
    cin >> N >> L;
    //scanf("%d%d", &N, &L);
    for (int i = 0; i < N; ++i)
    {
      string s;
      cin >> s;
      outlets[i] = 0;
      for (int j = 0; j < L; ++j)
      {
        if (s[j] == '1')
          outlets[i] |= 1ULL << j;
      }
    }

    for (int i = 0; i < N; ++i)
    {
      string s;
      cin >> s;
      devices[i] = 0;
      for (int j = 0; j < L; ++j)
      {
        if (s[j] == '1')
          devices[i] |= 1ULL << j;
      }
    }

    sort(devices, devices + N);

    ull d = devices[0];
    for (int i = 0; i < N; ++i)
    {
      ull change_mask = 0;
      for (int j = 0;j < L; ++j)
      {
        if ((d & (1ULL << j)) != (outlets[i] & (1ULL << j)))
          change_mask |= (1ULL << j);
      }
      possible_turns.push_back(change_mask);
    }

    int best_res = -1;
    for (int i = 0; i < N; ++i)
    {
      ull cur_mask = possible_turns[i];
      memcpy(changed_outlets, outlets, sizeof(outlets));
      for (int j = 0; j < N; ++j)
      {
        for (int k = 0; k < L; ++k)
        {
          if (cur_mask & (1ULL << k))
          {
            if (changed_outlets[j] & (1ULL << k))
            {
              changed_outlets[j] = changed_outlets[j] & (~(1ULL << k));
            }
            else
            {
              changed_outlets[j] = changed_outlets[j] | (1ULL << k);
            }
          }
        }
      }
      sort(changed_outlets, changed_outlets + N);

      bool is_ok = true;
      for (int j = 0; j < N; ++j)
      {
        if (changed_outlets[j] != devices[j])
          is_ok = false;
      }

      if (is_ok)
      {
        int res = 0;
        for (int k = 0; k < L; ++k)
        {
          if (cur_mask & (1ULL << k))
            res++;
        }

        if (best_res == -1 || res < best_res)
          best_res = res;
      }
    }


    printf("Case #%d: ", i + 1);

    if (best_res != -1)
      printf("%d", best_res);
    else
      printf("NOT POSSIBLE");



    printf("\n");
  }

  fclose(stdin);
  fclose(stdout);

  return 0;
}