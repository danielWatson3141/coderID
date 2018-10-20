#include <iostream>
#include <string>

using namespace std;

string outlet[150], flipped[150], device[150];

char switches[40];

main () {
  int T;
  cin >> T;
  for (int t=1; t<=T; t++) {
    int N,L;
    cin >> N >> L;
    for (int i=0; i<N; i++) {
      cin >> outlet[i];
      flipped[i]=outlet[i];
    };
    for (int i=0; i<N; i++) 
      cin >> device[i];
    
    sort(device,device+N);

    int best_solution = L+1; 
    for (int i=0; i<N; i++) 
      for (int j=0; j<N; j++) {
	int flips=0;
	for (int k=0; k<L; k++) {
	  switches[k] = outlet[i][k] ^ device[j][k];
	  if (switches[k]) flips++;
	};
	  
	for (int o=0; o<N; o++) 
	  for (int k=0; k<L; k++) 
	    flipped[o][k] = outlet[o][k] ^ switches[k];
	
	sort(flipped,flipped+N);

	bool fail=false;
	for (int o=0; o<N; o++)
	  if (flipped[o].compare(device[o]) != 0) fail=true;

	if (!fail && flips<best_solution)
	  best_solution = flips;	  
      };
    
    cout << "Case #" << t << ": ";
    if (best_solution>L) cout << "NOT POSSIBLE" << endl;
    else cout << best_solution << endl;

  };
};
