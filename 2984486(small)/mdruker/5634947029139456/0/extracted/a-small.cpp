#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

ifstream in("data.in");
ofstream out("data.out");

int N,L;
vector<string> devices,outlets,newoutlets;
vector<int> EqualSwitches;

vector<bool> flipped;

bool dfsid(int curswitched, int numswitchneeded, int curpos) {
  if (curswitched == numswitchneeded) {
    newoutlets = outlets;
    for (int i=0; i<flipped.size(); i++) {
      if (flipped[i]) {
	for (int j=0; j<N; j++) {
	  if (newoutlets[j][EqualSwitches[i]] == '0') {
	    newoutlets[j][EqualSwitches[i]] = '1';
	  } else {
	    newoutlets[j][EqualSwitches[i]] = '0';
	  }
	}
      }
    }

    sort(newoutlets.begin(), newoutlets.end());
    if (devices == newoutlets) {
      return true;
    }
    
    return false;
  }
  
  for (int i=curpos+1; i<EqualSwitches.size() - (numswitchneeded - curswitched - 1); i++) {
    flipped[i] = true;
    if (dfsid(curswitched+1,numswitchneeded,i)) {
      return true;
    }
    flipped[i] = false;
  }
  return false;
}

int main() {
  int T;

  in >> T;
  for (int curcase = 1; curcase <= T; curcase++) {
    in >> N >> L;
    devices.resize(N);
    outlets.resize(N);
    newoutlets.resize(N);
    for (int i=0; i<N; i++) {
      in >> devices[i];
    }
    sort(devices.begin(), devices.end());
    
    for (int i=0; i<N; i++) {
      in >> outlets[i];
    }

    bool notpossible = false;
    int numswitches = 0;

    EqualSwitches.clear();

    for (int i=0; i<L; i++) {
      vector<int> countD(2,0),countO(2,0);
      for (int j=0; j<N; j++) {
	countD[int(devices[j][i]-'0')]++;
	countO[int(outlets[j][i]-'0')]++;
      }
      
      if (countD[0] == countD[1] && countO[0] == countO[1]) {
	EqualSwitches.push_back(i);
      } else if (countD[0] == countO[0] && countD[1] == countO[1]) {
	//So far so good.
      } else if (countD[0] == countO[1] && countD[1] == countO[0]) {
	numswitches++;
	for (int j=0; j<N; j++) {
	  if (outlets[j][i] == '0') {
	    outlets[j][i] = '1';
	  } else {
	    outlets[j][i] = '0';
	  }
	}
      } else {
	notpossible = true;
	break;
      }
    }

    if (!notpossible) {
      bool candoit=false;
      for (int j=0; j<=EqualSwitches.size(); j++) {
	flipped.clear();
	flipped.resize(EqualSwitches.size(),0);
	if (dfsid(0,j,0)) {
	  candoit = true;
	  numswitches += j;
	  break;
	}
      }
      if (!candoit) {
	notpossible = true;
      }
    }

    out << "Case #" << curcase << ": ";    
    if (notpossible) {
      out << "NOT POSSIBLE" << endl;
    } else {
      out << numswitches << endl;
    }
  }
}
