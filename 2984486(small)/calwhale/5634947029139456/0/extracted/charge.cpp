#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <vector>
using namespace std;
bool flipSwitches(set<string> initial, set<string> outlets, int numOutlets, int length, int numFlips);
bool check(set<string> initial, set<string> outlets);
set<string> flipBits(set<string> bits, int num, int numOutlets, int length);
int countBits(int n);
int main(int argc, char *argv[])
{

  ifstream infile(argv[1]);
  int numCases, numOutlets, len;

  infile >> numCases;

  for (int i = 1; i <= numCases; i++)
  {
    infile >> numOutlets;
    infile >> len;

    set<string> initial, outlets;
    string temp;
    for (int j = 0; j < numOutlets; j++)
    {
      infile >> temp;
      initial.insert(temp);
    }
    for (int j = 0; j < numOutlets; j++)
    {
      infile >> temp;
      outlets.insert(temp);
    }
    int k;
    cout << "Case #" << i << ": ";
    for (k = 0; k <= len; k++)
    {
      if (flipSwitches(initial, outlets, numOutlets, len, k))
      {
        cout << k << endl;
        break;
      }
    }
    if (k == len + 1)
      cout << "NOT POSSIBLE\n";
  }

  return 0;

}

bool flipSwitches(set<string> initial, set<string> outlets, int numOutlets, int length, int numFlips)
{

  if (numFlips == 0)
  {
    if (check(initial, outlets))
      return true;
  }
  else
  {
    int trials = 1 << (length );
    for (int i = 1; i < trials; i++)
    {
      int numBits = countBits(i);
      if (numBits == numFlips)
      {
        set<string> flipped = flipBits(initial, i, numOutlets, length);
        if (check(flipped, outlets))
          return true;
      }
    }
  }

  return false;

}

bool check(set<string> initial, set<string> outlets)
{
  set<string>::iterator it, it2;
  for (it = initial.begin(), it2 = outlets.begin(); it != initial.end() && it2 != outlets.end(); it++, it2++)
  {
    if (*it != *it2)
      return false;
  }
  return true;
}

set<string> flipBits(set<string> bits, int num, int numOutlets, int length)
{
  vector<string> temp;
  set<string> flipped;
  set<string>::iterator it;
  for (it = bits.begin(); it != bits.end(); it++)
    temp.push_back(*it);

    for (int j = 0; j < length; j++)
    {
      int mask = 1 << j;
      if (mask & num)
      {
        for (int i = 0; i < numOutlets; i++)
        {
          if (temp[i][j] == '1')
            temp[i][j] = '0';
          else
            temp[i][j] = '1';
        }
      }
    }

  for (int j = 0; j < numOutlets; j++)
  {
    flipped.insert(temp[j]);
  }
  return flipped;
}

int countBits(int n)
{
  int num;
  for (num = 0; n; num++)
    n &= n - 1;
  return num;
}
