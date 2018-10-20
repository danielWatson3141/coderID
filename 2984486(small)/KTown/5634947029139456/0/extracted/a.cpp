#include <iostream>
#include <cstdio>
#include <stdint.h>
//#include <boost/multiprecision/cpp_int.hpp>
#include <set>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
//using namespace boost::multiprecision;

bool check(vector<vector<bool> > f, vector<vector<bool> > s){
    sort(f.begin(), f.end());
    sort(s.begin(), s.end());
    for(int i2 = 0; i2 < f[0].size(); i2++){
        for(int i3 = 0; i3 < f.size(); i3++){
             if(f[i3][i2] != s[i3][i2]){
                return false;
             }
        }
    }
    return true;
}
void printVec(vector<vector<bool> > in){
    for(int i1 = 0; i1 < in.size(); i1++){
        for(int i2 = 0; i2 < in[i1].size(); i2++){
            cerr << in[i1][i2];
        }
        cerr << "  ";
    }
    cerr << endl;
}

int sumBits(uint64_t in){
    int ret = 0;
    for(int i = 0; i < 40; i++){
        if((in >> i) % 2 == 1)
            ret++;
    }
    return ret;
}

int main(){
    int tests;
    string line;
    cin >> tests;
    getline(cin, line);
    for(int i1 = 0; i1 < tests; i1++){
        getline(cin, line);
        stringstream ss1(line);
        int n, l;
        ss1 >> n >> l;
        vector<vector<bool> > outlets;
        getline(cin, line);
        stringstream ss2(line);
        for(int i2 = 0; i2 < n; i2++){
            string tmp;
            ss2 >> tmp;
            //cerr << "inputed: " << tmp << endl;
            vector<bool> tmpBool;
            for(int i3 = 0; i3 < l; i3++){
                tmpBool.push_back((tmp[i3]) == '1');
            }
            outlets.push_back(tmpBool);
        }
        //cerr << "outlets:" << endl;
        //printVec(outlets);
        vector<vector<bool> > devices;
        getline(cin, line);
        stringstream ss3(line);
        for(int i2 = 0; i2 < n; i2++){
            string tmp;
            ss3 >> tmp;
            vector<bool> tmpBool;
            for(int i3 = 0; i3 < l; i3++){
                tmpBool.push_back(tmp[i3] == '1');
            }
            devices.push_back(tmpBool);
        }
        sort(outlets.begin(), outlets.end());
        sort(devices.begin(), devices.end());
        //TODO: might work
        int flips = 0;
        for(int i2 = 0; i2 < l; i2++){
            int outletNeed = 0;
            int deviceNeed = 0;
            for(int i3 = 0; i3 < n; i3++){
            }
        }
        int lowest = l + 1;
        for(int i2 = 0; i2 < pow(2,l); i2++){
            auto outletsTmp = outlets;
            auto devicesTmp = devices;
            /*
            cerr << "before: " << endl;
            printVec(outletsTmp);
            printVec(devicesTmp);
            */
            for(int i3 = 0; i3 < n; i3++){
                for(int i4 = 0; i4 < l; i4++){
                    if((i2>>i4) % 2) 
                        outletsTmp[i3][i4] = !outletsTmp[i3][i4];
                }
            }
            /*
            cerr << "after: " << endl;
            printVec(outletsTmp);
            printVec(devicesTmp);
            if(check(outlets, outletsTmp))
                cerr << "same" << endl;
            */
            if(check(outletsTmp, devicesTmp)){
                if(lowest > sumBits(i2))
                    lowest = sumBits(i2);
            }
            
        }
        cout << "Case #" << i1 + 1 << ": ";
        if(lowest == l + 1){
            cout << "NOT POSSIBLE";
        }else{
            cout << lowest;
        }
        cout << endl;
    }
}
