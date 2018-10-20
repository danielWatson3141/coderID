#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <bitset>
#include <set>

using namespace std;

int NumberOfSetBits(unsigned long long i)
{
    int res = 0;
    for(int j=0; j<10; j++)
    {
        if(i & (1 <<j)) ++res;
    }

    return res;
}

int main()
{
    ifstream in("in.txt");
    ofstream out("out.txt");


    int t;
    string line;

    {
        std::getline(in, line);
        istringstream iss(line);
        iss >> t;
    }

    for(int i = 0; i < t; ++i)
    {
        int n, l;

        {
            std::getline(in, line);
            istringstream iss(line);
            iss >> n  >> l;
        }

        vector<unsigned long long> devices;
        vector<unsigned long long> outlets;

        {
            std::getline(in, line);
            istringstream iss(line);
            for(int j = 0; j < n; j++)
            {
                string s;
                iss >> s;
                unsigned long long v = 0;
                for(int k = 0; k < l; k++)
                {
                    v |= (s[k]== '1') << k;
                }
                devices.push_back(v);
            }
        }

        {
            std::getline(in, line);
            istringstream iss(line);
            for(int j = 0; j < n; j++)
            {
                string s;
                iss >> s;
                unsigned long long v = 0;
                for(int k = 0; k < l; k++)
                {
                    v |= (s[k]== '1') << k;
                }
                outlets.push_back(v);
            }
        }

        //std::set<unsigned long long> xorMap;

        /*
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < l; k++)
            {
                xorMap.insert(devices[j] ^ outlets[k]);
            }
        }
        */
        /*
        for(set<unsigned long long>::iterator it = xorMap.begin(); it != xorMap.end(); ++it)
        {

        }
        */

        int result = 11;
        for(unsigned long long j = 0; j < 1024; ++j )
        {
            bool found1 = true;
            for(int ni = 0; ni< n; ni++)
            {
                bool found2 = false;
                for(int li = 0; li< n; li++)
                {
                    if( (devices[ni] ^ j) == outlets[li] )
                    {
                        found2 = true;
                        break;
                    }
                }

                if(found2 == false)
                {
                    found1 = false;
                    break;
                }

            }
            if(found1) result = min(result, NumberOfSetBits(j));
        }

        if(result == 11)
        {
            out << "Case #" << i + 1 << ": NOT POSSIBLE"  << endl;
        }
        else
        {
            out << "Case #" << i + 1 << ": " << result  << endl;
        }

    }

    return 0;
}
