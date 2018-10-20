#include <iostream>
#include <vector>
using namespace std;

int main() {

  long long int T;

  cin >> T;

  for ( long long int i = 0; i < T; i++ ) {

    cout << "Case #" << i+1 << ": ";

    long long int N, L;

    cin >> N >> L;

    char input;

    vector< long long int > d;

    for ( long long int j = 0; j < N; j++ ) {

      d.push_back(0);

      for ( long long int k = 0; k < L; k++ ) {

	cin >> input;

	d[j] <<= 1;

	d[j] += input - '0';

      }

    }

    vector< long long int > o;

    for ( long long int j = 0; j < N; j++ ) {

      o.push_back(0);

      for ( long long int k = 0; k < L; k++ ) {

	cin >> input;

	o[j] <<= 1;

	o[j] += input - '0';

      }

    }

    vector< long long int > cnt;
    for ( long long int j = 0; j < L+1; j++ ) {
      cnt.push_back(0);
    }

    long long int m[150][150];

    long long int c[150];

    for ( long long int j = 0; j < N; j++ ) {

      vector< long long int > a;

      for ( long long int k = 0; k < L+1; k++ ) {
	a.push_back(0);
      }

      for ( long long int k = 0; k < N; k++ ) {

	m[j][k] = ( d[j] xor o[k] );

	long long int x = m[j][k];

	long long int y = 0;

	while( x != 0 ) {
	  if ( ( x % 2 ) != 0 ) y++;
	  x >>= 1;
	}

	a[y]++;

	if ( j == 0 ) c[k] = y;

      }

      for ( long long int k = 0; k < L+1; k++ ) {
	if ( a[k] != 0 ) cnt[k]++;
      }

    }

    bool ans = false;

    for ( long long int j = 0; j < L+1; j++ ) {

      if ( cnt[j] == N ) {

	for ( long long int k = 0; k < N; k++ ) {

	  if ( c[k] == j ) {

	    if ( N == 1 ) {

	      cout << j << endl;
	      ans = true;
	      break;

	    }

	    for ( long long int l = 1; l < N; l++ ) {

	      bool flag = false;

	      for ( long long int z = 0; z < N; z++ ) {

		if ( m[l][z] == m[0][k] ) {

		  flag = true;
		  break;

		}

	      }

	      if ( flag == false ) break;

	      if ( l == N - 1 ) {

		cout << j << endl;
		ans = true;
		break;

	      }

	    }

	  }

	  if ( ans == true ) break;

	}

      }

      if ( ans == true ) break;

    }

    if ( ans == true ) continue;

    cout << "NOT POSSIBLE" << endl;

  }

  return 0;

}
