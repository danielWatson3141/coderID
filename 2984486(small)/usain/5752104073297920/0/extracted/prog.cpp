#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;

int a[1000];

int check(int n) {
	int m = 0;
	for (int i = 0; i < n/10; i++)
		if (a[i] >= n/4)
			m++;

//	printf("%d\n", m);
	if (m < 3 * (n /40) - 1)
		return 1;

	return 0;
}

int main() {
  ifstream in("C-small-attempt3.in");
  ofstream out("C-small-attempt3.out");
  int tests;
  in >> tests;
  for (int i = 1; i <= tests; i++) {
	  int n;
	  in >> n;
	  for (int j = 0; j < n; j++)
		  in >> a[j];
	  
	  out << "Case #" << i << ": ";
	  if (check(n))
		  out << "BAD" << endl;
	  else
		  out << "GOOD" << endl;
  }
  
  in.close();
  out.close();
  
  return 0;
}
