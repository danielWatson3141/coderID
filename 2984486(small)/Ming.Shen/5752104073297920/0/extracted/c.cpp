#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(time(NULL));
    int TT;
    scanf("%d", &TT);


    for(int tt = 1; tt <= TT; tt++)
    {
        printf("Case #%d:", tt);
        int N;
        scanf("%d", &N);
        int alc = 0;
        for(int i = 0; i < N; i++)
        {
            int v;
            scanf("%d", &v);
            alc += (i - v) * (i - v);

        }
        int b = (rand() % 2)? 165000000: 159000000;
        if(alc < b)
            printf(" BAD\n");
        else
            printf(" GOOD\n");

    }
    return 0;
}
