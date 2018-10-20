#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <queue>
#define LL long long
using namespace std;

template<typename T>
ostream& operator<<(ostream& s, const vector<T>& v) {
    s << '{';
    for (int i = 0 ;i <  v.size(); ++i) {
        s << (i ? "," : "") << v[i];
    }
    return s << '}';
}

template<typename T, typename U>
ostream& operator<<(ostream& s, const pair<T,U>& p) {
  s << "(" << p.first << "," << p.second << ")";
  return s;
}


// flip v in positions declared in d
vector<char> flip_it(vector<char> v, vector<int> d){

  vector<char> new_v;

  for(int i=0; i<v.size(); i++){

    bool do_we_flip = (find(d.begin(),d.end(),i) != d.end());
    char c = v[i];
    if(do_we_flip){
      if(c == '1') new_v.push_back('0');
      if(c == '0') new_v.push_back('1');
    }
    else{
      new_v.push_back(c);
    }

  }

  return new_v;


}


int main(){

  int ncases; cin >> ncases;

  for(int ncase=1; ncase<=ncases; ncase++){

    int num_devices; cin >> num_devices;
    int str_length; cin >> str_length;

    vector< vector<char> > outlets(num_devices,vector<char>(str_length,0));
    vector< vector<char> > devices(num_devices,vector<char>(str_length,0));

    // read outlets
    for(int i=0; i<num_devices; i++){

      string s; cin>>s;

      for(int j=0; j<s.length(); j++){
        outlets[i][j] = s[j];
      }

    }


    // read devices
    for(int i=0; i<num_devices; i++){

      string s; cin>>s;

      for(int j=0; j<s.length(); j++){
        devices[i][j] = s[j];
      }

    }

    sort(devices.begin(),devices.end());


    // take first outlet, all n devices
    int min_found = 9999;
    for(int i=0; i<num_devices; i++){

      vector<char> first_outlet = outlets[0];
      vector<char> this_device = devices[i];

      // compute differences
      vector<int> differences;
      for(int j=0; j<str_length; j++){
        if(first_outlet[j] != this_device[j])
          differences.push_back(j);
      }


      // construct new set of outlets based on these flips
      vector< vector<char> > new_outlets;
      for(int j=0; j<num_devices; j++){
        new_outlets.push_back(flip_it(outlets[j],differences));
      }


      sort(new_outlets.begin(),new_outlets.end());

      //cout<<first_outlet<<" "<<this_device<<" "<<differences<<" "<<devices<<" "<<new_outlets<<endl;

      if(devices == new_outlets){
        int df = differences.size();
        if(df < min_found){
          min_found = df;
        }
      }


    }


    
    cout << "Case #" << ncase << ": ";
    if(min_found == 9999){
      cout << "NOT POSSIBLE";
    }
    else{
      cout << min_found;
    }
    cout<<endl;



    
  }


}

