
#include <iostream>
#include <fstream>
#include <vector>
#include <map>

int main()
{
    using namespace std;

    string fileNameIn;
    cin >> fileNameIn; //so we don't have to recompile

    string fileNameOut = fileNameIn.substr(0, fileNameIn.find('.')) + ".out";

    ifstream in(fileNameIn.c_str());
    ofstream out(fileNameOut.c_str());

    int N = 0;
    in >> N; //Number of test cases
    for (int i = 0; i < N; ++i) 
    {
        //now just "in >> bla" as many times as you need to
        //do your calculation on the test case
        int n = 0, l = 0;
        in >> n >> l;

        cout << i << n << l << endl;

        vector<string> outlets;
        for (int j = 0; j < n; ++j) {
            string o;
            in >> o;
            outlets.push_back(o);
        }

        vector<string> devices; 
        for (int j = 0; j < n; ++j) {
            string d;
            in >> d;
            devices.push_back(d);
        }

        map<int, int> switchCombinations;
        map<int, int>::iterator it;
        map<int, int> cost;
        for (int dev = 0; dev < n; ++dev){
            string d = devices[dev];
            for (int out = 0; out < n; ++out) {
                string o = outlets[out];
                int add = 0;
                int numTimes = 0;
                int multiplier = 1;
                for (int sw = 0; sw < l; ++sw) {
                    if (o[sw] != d[sw]) {
                        add += multiplier;
                        numTimes++;
                    }
                    multiplier *= 2;
                }
                it = switchCombinations.find(add);
                if (it == switchCombinations.end()) {
                    switchCombinations[add] = 0;
                }
                switchCombinations[add]++;
                cost[add] = numTimes;
            }
        }

        int minCost = l+1;
        for (it = switchCombinations.begin(); it != switchCombinations.end(); ++it) {
            if ( (it->second == n) && (cost[it->first] < minCost) ) {
                minCost = cost[it->first];
            }
        }

        if (minCost == l+1) {
            out << "Case #" << i+1 << ": NOT POSSIBLE" << endl;
        }
        else {
            out << "Case #" << i+1 << ": " << minCost << endl;
        }
        //now we need to see if any switch combinations = N.
        //if so pick one with min cost
    }
}