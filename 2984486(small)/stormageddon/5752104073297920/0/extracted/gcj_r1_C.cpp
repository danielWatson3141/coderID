#include <iostream>
using namespace std;

int main() {
  int cases=0;
  cin >> cases;
  int caseNum=0;
  while (caseNum < cases) {
    caseNum++;
    int numNums=0;
    cin >> numNums;
    int low=0;
    int high=0;
    int val = 0;
    for (int i=1; i<500; i++) {
      cin >> val;
      low+=val;
    }
    cin >> val;
    for (int i=501; i<=1000; i++) {
      cin >> val;
      high+=val;
    }
    if (high - low > 9000)
    cout << "Case #" << caseNum << ": BAD" << endl;
else
    cout << "Case #" << caseNum << ": GOOD" << endl;
  }
  return 0;
}
