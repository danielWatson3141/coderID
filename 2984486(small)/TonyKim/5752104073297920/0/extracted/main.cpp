//
//  main.cpp
//  AlgorithmStudy
//
//  Created by Young Seok Kim on 1/9/14.
//  Copyright (c) 2014 Young Seok Kim. All rights reserved.
//



#include <stdio.h>
#include <string.h>

// Codejam 2014 round1A
// Problem C.

int T; // 1~100
float N;
int permutation[1001];


int main(int argc, const char * argv[])
{
    freopen("C-small-attempt4.in.txt","r",stdin);
    //freopen("input.txt","r",stdin);
    //freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    
    scanf("%d", &T);
    for (int i=0; i<T; i++) {
        scanf("%f",&N);
        for (int j=0; j<N; j++) {
            scanf("%d",&permutation[j]);
        }
        
        int count = 0;
        for (int k=0; k<N; k++) {
            if (k <=permutation[k]) {
                count++;
            }
        }
        
        
        if (count>N*515/1000) {
            printf("Case #%d: BAD\n",i+1);
        }
        else {
            printf("Case #%d: GOOD\n",i+1);
        }
    }
    
}
