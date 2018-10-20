#include <cstdio>
#include <vector>

using namespace std;

int GetBinary(int num)
{
    int addition = 1, returnValue = 0;
    
    while (num)
    {
        if (num & 1)
            returnValue += addition;
        
        addition <<= 1;
        
        num /= 10;
    }
    
    return returnValue;
}

int main()
{
    int T, num, length;
    
    scanf("%d", &T);
    
    for (int t = 1; t <= T; ++t)
    {
        scanf("%d %d", &num, &length);
        vector<int> available(num, 0), wanted(num, 0);
        
        int temp;
        
        for (int i = 0; i < num; ++i)
        {
            scanf("%d", &temp);
            available[i] = GetBinary(temp);
        }
        
        for (int i = 0; i < num; ++i)
        {
            scanf("%d", &temp);
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
                
                for (;matchPattern; matchPattern >>= 1)
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