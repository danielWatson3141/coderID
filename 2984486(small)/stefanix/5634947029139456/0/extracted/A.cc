#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<cmath>

using namespace std;

int count1s(int n)
{
  int c = 0;
  while(n!=0)
  {
    if (n&1) c++;
    n = n >> 1;
  }
  return c;
}

int bin(string s)
{
  int p2 = 1;
  int r = 0;
  for(int i=s.length()-1; i >= 0; i--)
  {
    r += (s[i]-'0')*p2;
    p2 *= 2;
  }
  return r;
}

int alter(int _n, int b)
{
  unsigned int n = _n;
  unsigned bits = b;
  int pos = 0;
  while(bits > 0)
  {
    int bit = (bits & 1);
    bits = bits >> 1;
    if (bit)
    {
  //     cout << "INVERT ("<<n<< "," << pos << ")" << endl;
      //cout << (n & (1<<pos)) << endl;
      // flip it
      if ((n & (1<<pos)) == 0)
      {
        // set bit to 1
        n = (n|(1<<pos));
  //      cout << "invert 0" << endl;
      }
      else 
      {
        // clear bit
        //cout << "clear " <<(~(0x00000001<<pos)) <<endl;
        n = n&(~(1<<pos));
      }

    } 
    pos++;
  }
  return n;
}

int main()
{

  ifstream f("A-small-attempt0.in");
  ofstream of("A-small-attempt0.out");
  
  int test_cases = 0;
  f >> test_cases;

  int n;
  int l;

  for(int tc=0; tc<test_cases; tc++)
  {
    // read from if
    f >> n >> l;
    set<int> outlets;
    for(int i=0; i<n; i++)
    {
      string s;
      f >> s;
      outlets.insert(bin(s));
    }
//    cout << "Test " << tc << " : " << outlets.size() << " outlets." << endl;

    set<int> devices;
    for(int i=0; i<n; i++)
    {
      string s;
      f >> s;
      devices.insert(bin(s));
    }
//    cout << "Test " << tc << " : " << devices.size() << " devices." << endl;

    // solve
    int sol = 1<<15;

    for(int i=0; i<=pow(2, l); i++)
    {
//      cout << "--> " << i << endl;
      int match = 0;

      // try solve with i bits mapping
      set<int> matches;
      set<int>::iterator it;
      for(it=devices.begin(); it != devices.end(); ++it)
      {
        int device = *it;
        int altered = alter(device, i);
//        cout << (*it) << " " << altered << endl;
        if (find(outlets.begin(), outlets.end(), altered) != outlets.end())
        {
          matches.insert(altered);
        }
      }
      //cout << "MATCHED " << matches.size()<<endl;
      if (matches.size() == devices.size())
      {
        // count the 1s
        int bits1 = count1s(i);  
        sol = min(sol, bits1);
      }
    }

    // write to of
    of << "Case #" << tc+1 << ": ";
    if (sol == 1<<15) of << "NOT POSSIBLE";
    else of << sol;
    of << endl;
 //   break;
  }

  f.close();
  of.close();
}
