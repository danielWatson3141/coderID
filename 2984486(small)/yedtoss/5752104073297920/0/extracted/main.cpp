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
#include <unordered_map>
#include <iomanip>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;


typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<bool> vb;

int main()
{
    int T;
    cin>>T;
    /* initialize random seed: */
     srand (time(NULL));

    for(int step=1; step<=T;step++){


         int algo = rand() % 2;

         cout<<"Case #"<<step<<": ";

         if(algo == 0){
             cout<<"BAD"<<endl;
         } else {
             cout<<"GOOD"<<endl;
         }


    }

    return 0;
}

