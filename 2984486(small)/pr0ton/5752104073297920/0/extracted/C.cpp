#include <iostream>
#include <vector>
#include <random>
using namespace std;


int main() {
  int T; cin>>T;
  for (int t=1; t <= T; t++) {
    int N; cin>>N;
    vector<int> a( N );
    int outOfPlace = 0;
    for (int i=0; i < N; i++) {
      cin >> a[i];
      if (a[i] != i) outOfPlace++;
    }
    cout << "Case #" << t <<": ";
    int X = (N - outOfPlace);
    
    if (X != 0 && (random()%X == 0)) {
      cout << "BAD";
    } else {
      cout << "GOOD";
    }
    cout << endl;
  }
}
