#include <map>
#include <cstdio>
#include <cstdlib>

using namespace std;

map<long long int,int> cnt;

int main(void){
    
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    
    int cas, cc=0, N, L;
    char outlet[150][45], charge[150][45];
    
    scanf("%d", &cas);
    while( cas-- ){
        cnt.clear();
        scanf("%d %d", &N, &L);
        for(int i=0; i<N; ++i)  scanf("%s", outlet[i]);
        for(int i=0; i<N; ++i)  scanf("%s", charge[i]);
        
        for(int i=0; i<N; ++i) for(int j=0; j<N; ++j){
            long long int need = 0;
            for(long long int k=0, n=1; k<L; ++k, n<<=1){
                if( outlet[i][k] != charge[j][k] )
                    need += n;
            }
            if( cnt.find(need)==cnt.end() ) cnt[need] = 1;
            else                            cnt[need] = cnt[need] + 1;
        }
        int one, ans=41;
        for (map<long long int,int>::iterator it=cnt.begin(); it!=cnt.end(); ++it)
        if( it->second == N ){
            one = 0;
            long long int num = it->first;
            for(long long int k=0, n=1; k<L; ++k, n<<=1)
            if( num & n )   ++one;
            
            if( one < ans ){
                ans = one;
            }
        }
        
        printf("Case #%d: ", ++cc);
        if( ans==41 )   puts("NOT POSSIBLE");
        else            printf("%d\n", ans);
    }
    
    return 0;
}
