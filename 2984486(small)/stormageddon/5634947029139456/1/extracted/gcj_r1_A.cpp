#include <iostream>
#include <string>
#include <bitset>
#include <vector>
#include <map>
using namespace std;

struct BSCompare {
  bool operator() (const bitset<40> &a, const bitset<40> &b) const {
    return a.to_string() < b.to_string();
  }
};

int main() {
  int cases=0;
  cin >> cases;
  int caseNum=0;
  while (caseNum < cases) {
    caseNum++;
    int numOutlets=0;
    cin >> numOutlets;
    int bits=0;
    cin >> bits;
    vector<bitset<40> > outlets;
    for (int i=1; i <=numOutlets; i++) {
      string outletName;
      cin >> outletName;
      bitset<40> outlet (outletName);
      outlets.push_back(outlet);
    }
    map<bitset<40> , int, BSCompare> masks;
    int smallest=bits+1;
    for (int i=1; i <= numOutlets; i++) {
      string devName;
      cin >> devName;
      bitset<40> device (devName);
      for (int j=1 ; j<=numOutlets; j++) {
        bitset<40> mask = device ^ outlets[j-1];
        //map<bitset<40> , int>::iterator it=masks.find(mask);
        if (masks.find(mask)==masks.end()) 
          masks[mask]=1;
        else
          masks[mask]++;
        if (masks[mask]==numOutlets && smallest > mask.count()) smallest=mask.count();
      }
    }
    if (smallest<=bits)
      cout << "Case #" << caseNum << ": " << smallest << endl;
    else
      cout << "Case #" << caseNum << ": NOT POSSIBLE" << endl;
  }
  return 0;
}
