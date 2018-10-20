/**
	Author: Floris Kint
  **/


#include <cstdio>
#include <bitset>
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>
#include <stack>
#include <queue>
#include <functional>

#define PI atan2(0,-1)

using namespace std;
#define MAXN 10

int start_configuration[MAXN];
int wanted_configuration[MAXN];
set<int> wanted_configurations;

bool configuration_found[MAXN];

int main(){
	int T;
	//scanf("%d", &T);
	cin >> T;
	for(int current_case = 1; current_case <= T; ++current_case){
		//read input
        int N, L;
        //scanf("%d%d", &N, &L);
        cin >> N >> L;
		//process
        wanted_configurations.clear();
        for(int i = 0; i < N; ++i){
            //int t;
            //scanf("%d", t);
            string t;
            cin >> t;
            start_configuration[i]=0;
            for(int index = 0; index < L; ++index){
                if(t[index]=='1'){
                    start_configuration[i]+=(1<<index);
                }
            }
        }
        for(int i= 0; i < N; ++i){
            string t;
            cin >> t;
            wanted_configuration[i]=0;
            for(int index = 0; index < L; ++index){
                if(t[index]=='1'){
                    wanted_configuration[i]+=(1<<index);
                }
            }
            wanted_configurations.insert(wanted_configuration[i]);
        }
        int best = L+L;
        for(int test = 0; test < 1<<L; ++test){
            bool good = true;
            for(int i = 0; i < N; ++i){
                int this_configuration = start_configuration[i]^test;
                if(wanted_configurations.count(this_configuration) == 0){
                    good = false;
                    break;
                }
                wanted_configurations.insert(this_configuration);
            }
            if(good){
                int c = test;
                int counter = 0;
                while(c > 0){
                    if(c%2){
                        ++counter;
                    }
                    c/=2;
                }
                best = min(counter, best);
            }
        }


		//printf("Case #%d:", current_case);
		cout << "Case #" << current_case << ":";
        if(best <= L){
            cout << " "<< best;
        }else{
            cout << " " << "NOT POSSIBLE";
        }



		//output answer
		//printf("\n");
		cout << endl;
	}
    return 0;
}
