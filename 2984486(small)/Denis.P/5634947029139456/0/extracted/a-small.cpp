#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
  int T;
  cin >> T;

  for(int caseno = 1; caseno <= T; caseno++) {
    int n, l;
    cin >> n >> l;    
    vector<string> outlets;
    vector<string> devices;
    
    for(int i = 0; i < n; i++) {
      string current;
      cin >> current;
      outlets.push_back(current);
    }

    for(int i = 0; i < n; i++) {
      string current;
      cin >> current;
      devices.push_back(current);
    }

    int result = -1;

    for(int mask = 0; mask < (1<<l); mask++) {
      for(int i = 0; i < l; i++) {
	if(mask & (1<<i)) {
	  for(int j = 0; j < n; j++) {
	    outlets[j][i] = (outlets[j][i]=='0')?'1':'0';
	  }
	}
      }

      bool isGood = true;
      for(int i = 0; i < n; i++) {
	bool isLocalGood = false;
	for(int j = 0; j < n; j++) {
	  if(devices[j]==outlets[i]) {
	    isLocalGood = true;
	    break;
	  }
	}
	if(!isLocalGood) {
	  isGood = false;
	  break;
	}
      }

      int count = 0;
      for(int i = 0; i < l; i++) {
	if(mask&(1<<i)) count++;
      }

      if(isGood) {
	if(result == -1 || result > count) {
	  result = count;
	}
      }


      for(int i = 0; i < l; i++) {
	if(mask & (1<<i)) {
	  for(int j = 0; j < n; j++) {
	    outlets[j][i] = (outlets[j][i]=='0')?'1':'0';
	  }
	}
      }
    }


    cout << "Case #" << caseno << ": ";
    if(result != -1) cout << result << endl;
    else cout << "NOT POSSIBLE" << endl;
  }


  return 0;
}
