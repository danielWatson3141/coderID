#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int GetBinary(const std::string& num)
{
    int addition = 1, returnValue = 0;
    
    for (int pos = num.size() -1; pos >= 0; --pos)
    {
        if (num[pos] == '1')
            returnValue += addition;
        
        addition <<= 1;
    }
    
    return returnValue;
}

int main()
{
    int T, num, length;
    
    scanf("%d", &T);
    
    string temp;
    
    for (int t = 1; t <= T; ++t)
    {
        scanf("%d %d", &num, &length);
        vector<long long> available(num, 0), wanted(num, 0);
        
        
        for (int i = 0; i < num; ++i)
        {
            cin >> temp;
            available[i] = GetBinary(temp);
        }
        
        for (int i = 0; i < num; ++i)
        {
            cin >> temp;
            wanted[i] = GetBinary(temp);
        }
        
        int min(-1);
        
        for (int matchTo = 0; matchTo < num; ++matchTo)
        {            
            int matchPattern = available[0] ^ wanted[matchTo];
            
            bool allSame(true);
            
            for (int aPos = 1; aPos < num && allSame; ++aPos)
            {
                bool match(false);
                for (int wPos = 0; wPos < num; ++wPos)
                {
                    int pattern = available[aPos] ^ wanted[wPos];
                    if (pattern == matchPattern)
                    {
                        match = true;
                        break;
                    }
                    
                }
                
                allSame = match;
            }
            
            if (allSame)
            {
                int count = 0;
                
                for (;matchPattern; matchPattern /= 2)
                    if (matchPattern & 1)
                        ++count;
                
                if (count < min || min == -1)
                    min = count;
            }
        }
        
        if (min == -1)
            printf("Case #%d: NOT POSSIBLE\n", t);
        else
            printf("Case #%d: %d\n", t, min);
    }
}