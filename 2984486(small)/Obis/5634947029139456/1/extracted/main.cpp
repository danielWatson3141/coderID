#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>
#include <set>

#define ll long long

using namespace std;

string w1[150], w2[150];
string w1o[150];

int main()
{
    ifstream cin ("A-large.in");
    ofstream cout ("out.txt");
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++)
    {
        
        int best = 1000000000;
        int n, l;
        cin >> n >> l;
        
        for (int j = 0; j < n; j++)
            cin >> w1o[j];
            
        for (int j = 0; j < n; j++)
            cin >> w2[j];  
            
        for (int j = 0; j < n; j++) // su kuriuo sulyginu
        {            
            set<string> left;
            for (int k = 0; k < n; k++)
                left.insert(w2[k]);
            
            int cur = 0;

            for (int k = 0; k < n; k++)
                w1[k] = w1o[k];
        
            for (int k = 0; k < l; k++)
            {
                if (w1[0][k] != w2[j][k])
                {
                    cur++;
                    w1[0][k] = w2[j][k];
                    for (int m = 1; m < n; m++)
                    {
                        if (w1[m][k] == '0')
                            w1[m][k] = '1';
                        else
                            w1[m][k] = '0';
                    }
                }
            }
            
            for (int k = 0; k < n; k++)
            {
                left.erase(w1[k]);
            }

            if (left.size() == 0)
                best = min(best, cur);
        }       
        
        if (best != 1000000000)
            cout << "Case #" << i+1 << ": " << best << endl;
        else
            cout << "Case #" << i+1 << ": NOT POSSIBLE" << endl;
    }
    //while (true) {}
}
                

