#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int rand(int x)
{
    return ::rand() % x;
}

double odds[1000][1000];

double good(int* arr, int N)
{
    double sum = 0;
    for(int i=0; i<N; i++)
        sum+=odds[i][arr[i]];
    return sum;
}

void gen1(int* arr, int N)
{
    for(int i=0; i<N; i++)
        arr[i] = i;
    for(int i=0; i<N; i++)
    {
        int p=rand(N-i)+i;
        swap(arr[i], arr[p]);
    }
}

void gen2(int* arr, int N)
{
    for(int i=0; i<N; i++)
        arr[i] = i;
    for(int i=0; i<N; i++)
    {
        int p=rand(N);
        swap(arr[i], arr[p]);
    }
}

int main()
{

    int N=1000, arr[1000];
    for(int i=0; i<N; i++)
    {
        odds[i][i] = 1;
    }
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(j==i)
                continue;
            for(int k=0; k<N; k++)
            {
                odds[j][k] = (odds[j][k]*(N-1)+odds[i][k])/N;
            }
        }
        for(int j=0; j<N; j++)
        {
            odds[i][j] = 1./N;
        }
    }

    if(0)
    {
        int correct = 0;
        int cnt = 10000;
        vector<double> g1, g2;
        
        for(int i=0; i<cnt; i++)
        {
            gen1(arr, N);
            g1.push_back(good(arr, N));
        }
        for(int i=0; i<cnt; i++)
        {
            gen2(arr, N);
            g2.push_back(good(arr, N));
        }
        sort(g1.begin(), g1.end());
        sort(g2.begin(), g2.end());
        printf("%f %f\n", g1[cnt*.9],g2[cnt*.1]);
        return 0;
    }

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++)
    {
        scanf("%d", &N);
        for(int i=0; i<N; i++)
            scanf("%d", arr+i);
        printf("Case #%d: %s\n", t, good(arr, N)<1.006522 ? "GOOD" : "BAD");
    }
    return 0;
}
