#include<stdio.h>
#include<algorithm>
using namespace std;
const int INF = 1000000000;
int outlet[200],device[200];
int tmp_outlet[200];
int N,L;
int count_one(int x){
    int ret = 0;
    while(x){
        if(x&1) ret++;
        x>>=1;
    }
    return ret;
}
int read_bin()
{
    char s[50];
    scanf("%s",s);
    int ret = 0;
    for(int i = 0 ; i < L ; i++)
    {
        ret = ((ret<<1)|(s[i] == '1'));
    }
    return ret;
}
void output_bin(int x)
{
    int st = -1;
    for(int i = L-1;i>=0;i--){
        if((x>>i)&1){
            st = i;
            break;
        }
    }
    if(st == -1){
        printf("0");
        puts("");
        return ;
    }

    for(int i = st ; i >=0; i--)
    {
        int ch = (x>>i)&1;
        printf("%d",ch);
    }
    puts("");
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int _ = 1; _<=T; _++)
    {

        scanf("%d%d",&N,&L);
        for(int i = 0; i <N; i++)
        {
            outlet[i] = read_bin();
        }
        for(int i = 0 ; i < N ; i++)
        {
            device[i] = read_bin();
        }
        sort(device, device+N);
        printf("Case #%d: ",_);
        int limit = (1<<L);
        bool fail = true;
        int min_one = INF;
        int min_bit = 0;
        for(int bit = limit-1 ; bit >=0 ; bit--)
        {
            for(int i = 0 ; i < N ; i++)
            {
                tmp_outlet[i] = (outlet[i] ^ bit);
            }
            sort(tmp_outlet, tmp_outlet+N);

            bool all_same = true;
            for(int i = 0 ; i < N ; i++)
            {
                if(tmp_outlet[i] != device[i])
                {
                    all_same = false;
                    break;
                }
            }
            if(all_same)
            {
                fail = false;
                int one = count_one(bit);
                if(one < min_one)
                {
                    min_one = one;
                    min_bit = bit;
                }
            }
        }
        if(fail)
        {
            puts("NOT POSSIBLE");
        }
        else
        {
            printf("%d\n",min_one);
            //output_bin(min_bit);
        }
    }
    return 0;
}
