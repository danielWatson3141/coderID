#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

void convert( char* temp, long long int& num, int len )
{
    num = 0;
    for( int i=0; i<len; i++ )
    {
        num = (num<<1)|(temp[i]-'0');
    }
}

int calcOne( long long int n )
{
    int ans = 0;
    while ( n > 0 )
    {
        ans += n%2;
        n >>= 1;
    }
    
    return ans;
}

int main()
{
    int tt;
    
    scanf("%d", &tt);
    
    for( int t=1; t<=tt; t++)
    {
        int n, l;
        char temp[150];
        long long int device[200], outlet[200];
        set<long long int> s;
        
        scanf("%d %d", &n, &l);
        
        for( int i=0; i<n; i++ )
        {
            scanf("%s", temp);
            convert( temp, outlet[i], l);
        }
        
        for( int i=0; i<n; i++ )
        {
            scanf("%s", temp);
            convert( temp, device[i], l);
            s.insert( device[i] );
        }
        
        int best = 150;
        for( int pivot=0; pivot<n; pivot++ )
        {
            long long int key = device[pivot] ^ outlet[0];
            
            if( calcOne( key ) >= best )
                continue;
            
            int i;
            for( i=1; i<n; i++ )
                if( s.find( outlet[i] ^ key ) == s.end() )
                    break;
            
            if( i == n )
                best = calcOne( key );
        }
        
        printf("Case #%d: ", t);
        if( best == 150 )
            printf("NOT POSSIBLE\n");
        else printf("%d\n", best);
    }
}