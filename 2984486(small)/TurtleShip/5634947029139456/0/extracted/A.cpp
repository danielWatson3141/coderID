#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

#define pb(x) push_back(x)

typedef long long LL;

int main() {
    int N; // number of devices
    int L; // number of electric flows
    int T; // number of test cases

    cin>>T;
    string notPossible = "NOT POSSIBLE";
    string cur;
    for(int cid=1; cid <= T; cid++) {
    	cin>>N>>L;
    	vector<string> initConfig(N, "");
    	vector<string> needed(N, "");
    	for(int i=0; i < N; i++) {
    		cin>>initConfig[i];
    	}

    	for(int i=0; i < N; i++) {
    		cin>>needed[i];
    	}

    	bool found = false;
    	int res = -1;

    	sort(needed.begin(), needed.end());

    	for(int mask = 0; mask < (1<<L); mask++) {
    		int curOn = 0;
    		for(int i=0; i < L; i++) {
    			if((mask & (1<<i)) != 0) curOn++;
    		}

    		bool correct = true;
    		vector<string> curConfig(initConfig.begin(), initConfig.end());

    		for(int i=0; i < L; i++) {
    			bool isFlip = ( mask & (1<<i)) != 0;
    			if(isFlip) {
    				for(int j=0; j < N; j++) {
    					if(curConfig[j][i] == '0') {
    						curConfig[j][i] = '1';
    					} else {
    						curConfig[j][i] = '0';
    					}
    				}
    			}
    		}

    		sort(curConfig.begin(), curConfig.end());
    		for(int i=0; correct && i < N; i++) {
    			correct &= curConfig[i] == needed[i];
    		}

    		if(correct) {
    			if(!found) {
    				found = true;
    				res = curOn;
    			} else {
    				res = min(res, curOn);
    			}
    		}
    	}

    	cout<<"Case #"<<cid<<": ";
    	if(found) {
    		cout<<res<<endl;
    	} else {
    		cout<<notPossible<<endl;
    	}


    }



}
