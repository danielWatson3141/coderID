#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>
#include <set>
#include <cstdlib>
#include <ctime>
#include <map>

#define ll long long

using namespace std;

map<string, int> kiek;
int p[1000];

void gen ()
{
    string s = "012345";
    
    for (int k = 0; k < s.size(); k++)
    {
        int p = rand() % s.size();
        swap(s[k], s[p]);
    }
    
    kiek[s]++;
}

int main()
{
    ifstream cin ("C-small-attempt0.in");
    ofstream cout ("out.txt");
    
  /*  srand(time(NULL));
    
    for (int i = 0; i < 1000000; i++)
        gen();
        
    map<string, int>::iterator it;
    
    for (it = kiek.begin(); it != kiek.end(); it++)
    {
        if ((*it).second < 850 || (*it).second > 2600)
            cout << (*it).first << ' ' << (*it).second << endl;
    } */
    
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        
        int kurMax = -1;
        for (int i = 0; i < n; i++)
        {
            cin >> p[i];
            if (p[i] == n-1)
                kurMax = i;
        }
        
        if (kurMax < n/2)
            cout << "Case #" << i+1 << ": GOOD" << endl;
        else
            cout << "Case #" << i+1 << ": BAD" << endl;
    }
            
   //while (true) {}
}
                

