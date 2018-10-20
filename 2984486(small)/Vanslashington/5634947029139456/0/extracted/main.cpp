#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>

using namespace std;

int nd, ls;


bool compde(bitset<10> &outlet, bitset<10> &device, bitset<10> &flips)
{
    for(int i = 0; i < ls; ++i)
    {
        if(device[i] != outlet[i] ^ flips[i])
            return false;
    }
    
    return true;
}


bool allmatch(vector<bitset<10> > &outlets, 
              vector<bitset<10> > &devices, bitset<10> &flips)
{
    bitset<10> tdev;
    
    for(int i = 0; i < nd; ++i)
    {
        bool notfound = true;
        for(int j = 0; j < nd; ++j)
        {
            // Now compare device to outlet
            // If match, set to false, break, mark as taken
            if(!tdev[j] && compde(outlets[i], devices[j], flips))
            {
                notfound = false;
                tdev[j] = true;
                break;
            }
        }
        
        if(notfound)
            return false;
    }
    
    return true;
}



int find(vector<bitset<10> > &outlets, 
         vector<bitset<10> > &devices)
{
    bitset<10> flips;
    for(int nflips = 0; nflips <= ls; ++nflips)
    {
        // Turn that many switches on
        for(int i = 0; i < nflips; ++i)
            flips[i] = true;
        
        string s = flips.to_string();
        
        // Try a match for every permutation
        do
        {
            bitset<10> flips2(s);
            
            if(allmatch(outlets, devices, flips2))
                return nflips;
                
            s = flips2.to_string();
            //cout << s << endl;
        }
        while(next_permutation(s.begin() + (10-(ls)), s.end()));
    }
    
    return -1;
}



int main()
{
    int cases;
    cin >> cases;
    
    for(int tcase = 1; tcase <= cases; ++tcase)
    {
        
        cin >> nd >> ls;
        
        vector<bitset<10> > outlets(nd);
        vector<bitset<10> > devices(nd);
        
        char bit;
        for(int i = 0; i < nd; ++i)
        {
            for(int j = 0; j < ls; ++j)
            {
                cin >> bit;
                outlets[i][j] = bit - '0';
            }
        }
        
        for(int i = 0; i < nd; ++i)
        {
            for(int j = 0; j < ls; ++j)
            {
                cin >> bit;
                devices[i][j] = bit - '0';
            }
        }
        
        int ans = find(outlets, devices);
        
        cout << "Case #" << tcase << ": ";
        if(ans >= 0)
            cout << ans;
        else
            cout << "NOT POSSIBLE";
        
        cout << endl;
    }

    return 0;
}




/*
   for(int i = 0; i < nd; ++i)
        {
            for(int j = 0; j < ls; ++j)
            {
                
                cout << outlets[i][j];
            }
            cout << " ";
        }
        cout << endl;
        
        for(int i = 0; i < nd; ++i)
        {
            for(int j = 0; j < ls; ++j)
            {
                
                cout << devices[i][j];
            }
            cout << " ";
        }
        cout << endl;
 */
