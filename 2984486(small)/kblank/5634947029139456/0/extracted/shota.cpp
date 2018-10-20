#include<iostream>
#include<algorithm>
using namespace std;
const int maks = 200;
int t, n, l;
string dev[maks], charger[maks], newdev[maks];
bool change[50];
int main(){
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n >> l;
    for (int j = 0; j < n; ++j) cin >> dev[j];
    for (int j = 0; j < n; ++j) cin >> charger[j];
    // sort chargers
//for (int xx = 0; xx < n; ++xx) cout << dev[xx] << " "; cout << endl;    
    sort(charger, charger+n);
//for (int xx = 0; xx < n; ++xx) cout << charger[xx] << " "; cout << endl;    
    int min_changes = -1;
    // connect dev[0] with charger[j]

    for (int j = 0; j < n; j++) {
      int changes = 0;
//cout << "connect dev[0] with charger[" << j << "]" << endl; 	    
      for (int z = 0; z < l; z++) {	   
        change[z] = (dev[0].at(z) != charger[j].at(z));
	if (change[z]) changes++;
      };	
//cout << "changes: "; for (int z = 0; z < l; z++) { char c; if (change[z]) c = '1'; else c = '0'; cout <<    c; }; cout << endl;
      newdev[0] = charger[j];

      for (int y = 1; y < n; y++) {
        newdev[y] = dev[y];
//cout << "before: " << newdev[y] << endl;	
	for (int z = 0; z < l; ++z)
          if (change[z]) {
            if (newdev[y][z] == '1') newdev[y][z] = '0';
	    else 
	    if (newdev[y][z] == '0') newdev[y][z] = '1';
          };	    
//cout << "after: " << newdev[y] << endl;	
      };
      // sort new devices
//for (int xx = 0; xx < n; ++xx) cout << newdev[xx] << " "; cout << endl;    
      sort(newdev, newdev+n);
//for (int xx = 0; xx < n; ++xx) cout << newdev[xx] << " "; cout << endl;    
      // compare
      bool ret = true;
      for (int r = 0; (r < n) && (ret); ++r)
        ret = (newdev[r] == charger[r]);
      if (ret && ((changes < min_changes) || (min_changes==-1))) min_changes = changes;
    };
    cout << "Case #" << i+1 << ": ";
    if (min_changes==-1)
      cout << "NOT POSSIBLE\n";
    else
      cout << min_changes << endl;
  };
};
