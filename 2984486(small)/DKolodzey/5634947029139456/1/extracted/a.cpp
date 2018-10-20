#include <iostream>
#include <string>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::sort;
using std::min;

const int MAX_N = 200;

void input(int N, int L, unsigned long long data[])
{
  string tmp;
  for (int i = 0; i < N; ++i)
  {
    data[i] = 0;
    cin >> tmp;
    for (int j = 0; j < L; ++j)
    {
      if (tmp[j] == '1') {
        data[i] += (unsigned long long)(1 << j);
      }
    } 
  }
}

int count1(unsigned long long x)
{
  int ans = 0;
  while (x != 0)
  {
    if (x & 1)
      ++ans;
    x >>= 1;
  }
  return ans;
}
int main()
{
  unsigned long long device[MAX_N];
  unsigned long long outlet[MAX_N];
  unsigned long long switched[MAX_N];

  int T;
  cin >> T;
  for (int testcase = 1; testcase <= T; ++testcase)
  {
    cout << "case #" << testcase << ": ";
    //cout << endl;

    int ans = 42;
    int N, L;
    cin >> N >> L;
    input(N, L, outlet);
    input(N, L, device);  
    
/*
    cout << "device" << endl;
    for (int i = 0; i < N; ++i)
      cout << device[i] << " ";
    cout << endl;

*/
    sort(device, device + N);

/*
    cout << "sorted device" << endl;
    for (int i = 0; i < N; ++i)
      cout << device[i] << " ";
    cout << endl;

*/
    for (int i = 0; i < N; ++i)
    {
      unsigned long long mask = (outlet[0]) ^ (device[i]);
      //cout << outlet[0] << " " << device[i] << " mask " << mask << endl;
      for (int j = 0; j < N; ++j)
      {
        switched[j] = outlet[j] ^ mask;
      }
      sort(switched, switched + N);
      bool is_ans = 1;
      for (int j = 0; j < N; ++j) {
        is_ans = is_ans && (switched[j] == device[j]);
  //      cout << switched[j] << " " << device[j] << endl;
      }
      if (is_ans)
        ans = min(ans, count1(mask));
    }

    if (ans == 42)
      cout << "NOT POSSIBLE" << endl;
    else
      cout << ans << endl;

  }
  
  return 0;
}