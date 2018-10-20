// C++ 11 Code Use correct compiler.  Or gcc with -std=c++11
#include <iostream>
#include <bitset>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <sstream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;


typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<bool> vb;

int main()
{
    int T, N, L;
    cin>>T;

    for(int step=1; step<=T;step++){

        cin>>N>>L;

        vector<string> init(N), target(N);

        for(int i=0; i<N;i++){
            cin>>init[i];
        }

        for(int i=0; i<N;i++){
            cin>>target[i];
        }

        vector<vector<vector<pair<string,int> > > > stat(N, vector<vector<pair<string,int> > >(L+1));


        for(int i=0; i<N; i++){

            for(int j=0; j<N; j++){

                int flip = 0;
                string tof = "";

                for(int k=0; k<L; k++){

                    if(init[i][k] != target[j][k]){
                        flip++;
                        tof += std::to_string(k);
                    }
                }

                sort(tof.begin(), tof.end());

                stat[i][flip].push_back(make_pair(tof,j));
            }

        }

        bool sol = false;
        int num = -1;


        for(int flip=0; flip<=L; flip++){

            if(sol) break;

            if(stat[0][flip].size() > 0){

                for(int pos=0; pos < stat[0][flip].size(); pos++){
                    if(sol) break;

                    vector<int> taken(N,0);
                    taken[stat[0][flip][pos].second]++;
                    string seq = stat[0][flip][pos].first;
                    sol = false;

                    if(N == 1){

                        sol = true;
                        num = flip;
                    }

                    for(int i=1; i<N;i++){

                        bool found = false;
                        int ind = -1;

                        for(int k = 0; k< stat[i][flip].size(); k++){

                            if(stat[i][flip][k].first == seq){

                                found = true;

                                ind = stat[i][flip][k].second;

                                break;
                            }
                        }

                        if(!found){
                            break;
                        }


                        if(taken[ind] > 0){
                            break;
                        }

                        taken[ind]++;

                        if(i == N-1){

                            sol = true;
                            num = flip;

                        }

                    }




                }




            }


        }
        cout<<"Case #"<<step<<": ";

        if(sol){
            cout<<num<<endl;
        } else {
            cout<<"NOT POSSIBLE"<<endl;
        }

        //cout<<"NOT POSSIBLE"<<endl;







    }

    return 0;
}

