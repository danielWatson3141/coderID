#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1000;

int arr[N];

double prob[N][N];

void calc_prob()
{
    double nm1 = 1.0 - 1.0 / N;
    double n1 = 1.0 / N;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
            prob[i][j] = 0.0;
        prob[i][i] = 1.0;
        for(int j=0; j<N; j++)
        {
            double tp = prob[i][j] * n1;
            for(int k=0; k<N; k++)
            {
                prob[i][k] = prob[i][k] * nm1 + tp;
            }
            prob[i][j] = n1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);

    calc_prob();

    int T;
    cin>>T;
    for(int tt=1; tt<=T; tt++)
    {
        int x;
        cin>>x;
        for(int i=0; i<N; i++)
            cin>>arr[i];

        double gen_prob = 1.0;
        for(int i=0; i<N; i++)
        {
            gen_prob *= prob[arr[i]][i] * N;
        }
        cout<<"Case #"<<tt<<": "<<(gen_prob>1.0 ? "BAD" : "GOOD")<<endl;
    }

    return 0;
}
