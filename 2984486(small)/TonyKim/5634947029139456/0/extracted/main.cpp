#include <stdio.h>
#include <string.h>

// Codejam 2014 round1A
// Problem A.

int T; // 1~100
int N,L;
int outlet[200]; // in binary
int requirement[200]; // in binary
int outlet_count[50]; // for L length bit, count how many 1s
int requirement_count[50];
int answer[105];

int binary_to_decimal(int binary)
{
    int sum = 0;
    int multiplier = 1;
    while (binary!=0) {
        int digit = binary % 2;
        sum += digit*multiplier;
        digit = digit/2;
        multiplier *= 10;
    }
    return sum;
}


int main(int argc, const char * argv[])
{
    freopen("A-small-attempt2.in.txt","r",stdin);
    //freopen("input.txt","r",stdin);
    //freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    
    scanf("%d", &T);
    
    for (int t=0; t<T; t++) {
        int outlet[200]={0,}; // in binary
        int requirement[200]={0,}; // in binary
        int outlet_count[50]={0,}; // for L length bit, count how many 1s
        int requirement_count[50]={0,};
        scanf("%d %d", &N, &L);
        
        for (int n=0; n<N; n++) {
            scanf("%d",&outlet[n]);
        }
        for (int n=0; n<N; n++) {
            scanf("%d",&requirement[n]);
        }
        
        
        for (int n=0; n<N; n++) {
            int divider = 1;
            for (int k=0; k<L; k++) {
                int count1 = outlet[n]/divider;
                int count3 = requirement[n]/divider;
                divider *=10;
                int count2 = outlet[n]/divider;
                int count4 = requirement[n]/divider;
                if (count1-count2*10 != 0) {
                    outlet_count[k]++;
                }
                if (count3-count4*10 != 0) {
                    requirement_count[k]++;
                }
            }
            
        }
        
        bool shouldcontinue=false;
        for (int k=0; k<L; k++) {
            if (!(outlet_count[k] == requirement_count[k]) && !(outlet_count[k] == (N-requirement_count[k]))) {
                //printf("Case #%d: NOT POSSIBLE\n",t+1);
                answer[t]=-1;
                shouldcontinue = true;
            }
        }
        
        if (shouldcontinue) {
            continue;
        }
        
        int flipcount=0;
        for (int k=0; k<L; k++) {
            if (outlet_count[k] != requirement_count[k]){
                flipcount++;
            }
        }
        //printf("Case #%d: %d\n",t+1, flipcount);
        answer[t]=flipcount;
        
    }
    
    for (int t=0; t<T; t++) {
        if (answer[t]==-1) {
            printf("Case #%d: NOT POSSIBLE\n",t+1);
        }
        else{
            printf("Case #%d: %d\n",t+1, answer[t]);
        }
    }
    
    
    
    
}
