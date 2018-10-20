#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;


int tryit(int N, int L, set <vector <int> > Out, set <vector <int> > Dev ) {
  int x;
  int j;
  int wgt;

  int minwgt;

  minwgt = 100;

  for (x = 0; x < (1 << L); x++) {
    set <vector <int> > Flip;
    set <vector <int> > :: iterator it;
    vector <int> flipper;

    wgt = 0;

    for (j = 0; j < L; j++) {
      flipper.push_back( (x & (1<<j)) != 0 );
      wgt += ( (x & (1<<j)) != 0 );
    }

    for (it = Out.begin(); it != Out.end(); it++) {
      vector <int> v;
      for (j = 0; j < L; j++) {
	v.push_back( ( (*it)[j] + flipper[j]) % 2 );
      }
      Flip.insert(v);
    }

    if (Dev == Flip) {
      if (minwgt > wgt) {
	minwgt = wgt;
      }
    }
  }

  if (minwgt == 100) {
    return -1;
  }
  return minwgt;
}



int main(void) {
  int T, t;

  cin >> T;

  for (t = 1; t <= T; t++) {
    int N, L;
    int i, j;
    int r;


    cin >> N;
    cin >> L;

    set < vector <int> > Out;
    set < vector <int> > Dev;

    for (i = 0; i < N; i++) {
      string s;
      vector <int> v;
      cin >> s;
      for (j = 0; j < L; j++) {
	v.push_back(s[j] - '0');
      }
      Out.insert(v);
    }
    for (i = 0; i < N; i++) {
      string s;
      vector <int> v;
      cin >> s;
      for (j = 0; j < L; j++) {
	v.push_back(s[j] - '0');
      }
      Dev.insert(v);
    }

    r = tryit(N, L, Out, Dev);

    cout << "Case #" << t << ": ";

    if (r < 0) {
      cout << "NOT POSSIBLE" << endl;
    } else {
      cout << r << endl;
    }
  }


  return 0;
}
