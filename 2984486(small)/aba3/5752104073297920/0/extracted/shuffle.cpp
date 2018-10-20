
#include <iostream>
#include <fstream>
#include <vector>

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
        int n = 0;
        in >> n;

        int sameCount = 0;
        int minusOneCount = 0;
        for (int j = 0; j < n; ++j) {
            int val = 0;
            in >> val;
            if (val == j) {
                sameCount++;
            }
            else if (val == (j-1)) {
                minusOneCount++;
            }
        }
        cout << minusOneCount << " " << sameCount << endl;

        if (minusOneCount >= 0  && sameCount < 1) {
            out << "Case #" << i+1 << ": BAD" << endl;
        }
        else {
            out << "Case #" << i+1 << ": GOOD" << endl;
        }

    }
}