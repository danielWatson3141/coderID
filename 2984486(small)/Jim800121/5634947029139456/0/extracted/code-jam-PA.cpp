#include <cstdio>
#include <cstdlib>
#include <cstring>
#define NMAX 200
#define LMAX 50


void init();
void solve(int cnt, int x);
void invert(int x);
bool check();

int N,L;
int minCnt;
bool flag[LMAX];
char outletData[NMAX][LMAX]={0};
char deviceData[NMAX][LMAX]={0};

int main()
{
    int T,caseNum=1;

    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);

    scanf("%d", &T);
    while(caseNum <= T)
    {
        init();

        scanf("%d%d", &N, &L);
        scanf("%*c");
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<L; j++)
            {
                scanf("%c", &outletData[i][j]);
            }
            outletData[i][L] = 0 ;
            scanf("%*c");
        }
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<L; j++)
            {
                scanf("%c", &deviceData[i][j]);
                flag[j] = false;
            }
            deviceData[i][L] = 0;
            scanf("%*c");
        }
        solve(0, 0);
        if(minCnt==LMAX)
        {
            printf("Case #%d: NOT POSSIBLE\n", caseNum);
        }
        else
        {
            printf("Case #%d: %d\n", caseNum, minCnt);
        }
        caseNum++;
    }
    return 0;
}

void init()
{
    minCnt = LMAX;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<L; j++)
        {
            outletData[i][j] = 0;
            deviceData[i][j] = 0;
        }
    }
}

void solve(int cnt, int x)
{

    if(x == L)
    {
        if(check())
        {
            if(minCnt > cnt)
            {
                minCnt = cnt;
            }
        }
        /*printf("cnt = %d\n", cnt);
        for(int i=0; i<N; i++)
        {
            printf("%s\n", outletData[i]);
        }*/
    }
    else
    {
        for(int i=x; i<L; i++)
        {
            if(flag[i]==false)
            {
                flag[i] = true;
                solve(cnt, x+1);
                invert(i);
                solve(cnt+1, x+1);
                invert(i);
                flag[i] = false;
            }
        }
    }
}

void invert(int x)
{
    for(int i=0; i<N; i++)
    {
        if(outletData[i][x]=='0')
            outletData[i][x] = '1';
        else
            outletData[i][x] = '0';
    }

}

bool check()
{
    bool result = true;
    for(int i=0; i<N; i++) //device
    {
        bool findOrNot = false;
        for(int j=0; j<N; j++) //outlet
        {
            if(!strcmp(deviceData[i], outletData[j]))
            {
                findOrNot = true;
                break;
            }
        }
        if(findOrNot==false)
        {
            result = false;
            break;
        }
    }
    return result;
}
