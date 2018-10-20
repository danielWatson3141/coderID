#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;


int N;
int C[1001][1001];
int V[121][1000];

int main(){
    int NC;scanf("%d",&NC);

    memset(C,0,sizeof(C));    
    int x;
    for(int i=1;i<=NC;i++){
        scanf("%d",&N);

        for(int j=0;j<N;j++){
            scanf("%d",&x);

            C[x][j]++;
            V[i][j] = x;
        }
    }

    double q;
    double NN = N;
    double NNC = NC;
    double GOOD_P = 1.0 / NN;
    double THRESHOLD = 0.00099;
    // double THRESHOLD = 0.000991667;
    for(int i=1;i<=NC;i++){
        printf("Case #%d: ",i);
        bool good = true;

        double badcount = 0;
        for(int j=0;j<N;j++){
            x = V[i][j];
            q = C[x][j] / (NN * NNC);

            if(fabs(q - GOOD_P) > THRESHOLD){
                badcount++;
            }
        }

        // printf("%.6lf\n",badcount / NN);
        good = (badcount / NN) > 0.89;
        if(good){
            printf("GOOD\n");
        }else{
            printf("BAD\n");
        }
    }
}