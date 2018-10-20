/**
	Author: Floris Kint
  **/


#include <cstdio>
#include <deque>
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

unsigned long long start_configuration[MAXN];
unsigned long long wanted_configuration[MAXN];
//set<int> wanted_configurations;

//bool configuration_found[MAXN];

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
 //       wanted_configurations.clear();
        for(int i = 0; i < N; ++i){
            //int t;
            //scanf("%d", t);
            string t;
            cin >> t;
            start_configuration[i]=0;
            for(int index = 0; index < L; ++index){
                if(t[index]=='1'){
                    start_configuration[i]+=(((unsigned long long)1)<<index);
                }
            }
        }
        for(int i= 0; i < N; ++i){
            string t;
            cin >> t;
            wanted_configuration[i]=0;
            for(int index = 0; index < L; ++index){
                if(t[index]=='1'){
                    wanted_configuration[i]+=(((unsigned long long)1)<<index);
                }
            }
//            wanted_configurations.insert(wanted_configuration[i]);
        }
        vector<unsigned long long> global_good;
        for(int i = 0; i < N; ++i){
            vector<unsigned long long> good_config;
            for(int j = 0; j < N; ++j){
                //needed toggle for this combination
                unsigned long long c = start_configuration[i] ^ wanted_configuration[j];
                good_config.push_back(c);
            }
            sort(good_config.begin(), good_config.end());
            if(i == 0){
                for(int j = 0; j < good_config.size(); ++j){
                    global_good.push_back(good_config[j]);
                }
            }else{
                vector<unsigned long long> intersection;
                for(int j = 0; j < global_good.size(); j++){
                    for(int k = 0; k < good_config.size(); ++k){
                        if(global_good[j]==good_config[k]){
                            intersection.push_back(global_good[j]);
                            break;
                        }
                    }
                }
                global_good.clear();
                for(vector<unsigned long long>::iterator it = intersection.begin(); it != intersection.end(); ++it){
                    global_good.push_back(*it);
                }
                /*vector<int> inters;
                std::set_intersection(good_config.begin(), good_config.end(), global_good.begin(), global_good.end(), inters.begin());
                global_good.clear();
                for(int j = 0; j < inters.size(); ++j){
                    global_good.push_back(inters[j]);
                }*/
            }
        }
        int best = L+L;
        for(vector<unsigned long long>::iterator it = global_good.begin(); it != global_good.end(); ++it){
            int cp = *it;
            int counter = 0;
            while(cp >  0){
                if(cp%2){
                    ++counter;
                }
                cp/=2;
            }
            best = min(best, counter);
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
