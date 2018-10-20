#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int s[1001], maxsize;

int lowbit( int in ){
    return in&(-in);
}

int getsum( int end ){
	int sum = 0;
	while(end>0)
	{
		sum += s[end];
		end -= lowbit(end);
	}
	return sum;
}

void change( int end, int data )
{
	for(int i=end; i<=maxsize; i+=lowbit(i))
		s[i] += data;
}

int main(void){
    
    freopen("C-small-attempt2.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    
    int cas, cc=0, N, num[1000], cnt;
    
    scanf("%d", &cas);
    while( cas-- ){
        
        scanf("%d", &N);
        for(int i=0; i<N; ++i)
            scanf("%d", &num[i]);
        memset(s,0,sizeof(s));
        
        cnt = 0;
        maxsize = N;
        for(int i=0; i<N; ++i){
            change(num[i]+1, 1);
            int get = getsum(i+1);
            if( get >= (i+2)/2 )
                ++cnt;
        }
        printf("Case #%d: ", ++cc);
        if( cnt >= 500 )    puts("BAD");
        else                puts("GOOD");
    }
    
    return 0;
}
