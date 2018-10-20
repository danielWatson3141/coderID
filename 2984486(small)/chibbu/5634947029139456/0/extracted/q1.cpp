#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int increase(string &v){
    int pos=0, countc=1;
    while(v[pos]=='1'){
        v[pos]='0';
        pos++;
    }
    v[pos] = '1';
    for(int i=pos+1; i<v.length(); i++){
        if(v[i]=='1') countc++;
    }
    return countc;
}

bool check_equal(vector<string> &dev, vector<string> &home, string change_vec, int n, int l){

    vector<string> home_temp = home;
    for(int i=0; i<l; i++){
        if(change_vec[i]=='1'){
            for(int j=0; j<n; j++){
                if(home_temp[j][i]=='0') home_temp[j][i]='1';
                else home_temp[j][i]='0';
            }
        }
    }
    sort(home_temp.begin(), home_temp.end());
    bool match = true;
    for(int j=0; j<n; j++){
            if(home_temp[j]!=dev[j]){
                match=false;
                break;
            }
    }
    return match;
}

int main(){

    int t;
    cin>>t;
    for(int i=1; i<=t; i++){
        int n,l;
        cin>>n>>l;
        vector<string> dev(n);
        vector<string> home(n);
        for(int j=0; j<n; j++) cin>>home[j];
        for(int j=0; j<n; j++) cin>>dev[j];
        sort(dev.begin(),dev.end());
        long long min_change = 10000000, limit = pow(2,l), curr_change=0;
        string change_vec= "";
        for(int j=0; j<l; j++) change_vec = change_vec+'0';
        for(int j=0; j<limit; j++){
            if(curr_change<min_change){
                if(check_equal(dev,home,change_vec,n,l)==true){
			min_change = curr_change;
		}
            }
            else;
            curr_change = increase(change_vec);
        }

        if(min_change == 10000000){
            cout<<"Case #"<<i<<": NOT POSSIBLE\n";
        }
        else{
            cout<<"Case #"<<i<<": "<<min_change<<"\n";
        }
//	string s= "00";
//	cout<<"inc. of '00' is: "<<increase(s)<<endl;
    }

    return 0;
}
