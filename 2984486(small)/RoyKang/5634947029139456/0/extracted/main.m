//
//  main.c
//  GCJ
//
//  Created by LinePlus on 2014. 4. 26..
//  Copyright (c) 2014년 LINE. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define N 300
#define BIG 2000000

int numOfTestCase;
int n, l;
int result = BIG;
char initial[N][N];
char required[N][N];
int check[N];
FILE *fin, *fout;

void flip(int col)
{
    for(int i=0;i<n;i++) {
        if(initial[i][col]=='0') {
            initial[i][col] = '1';
        }
        else {
            initial[i][col] = '0';
        }
    }
}

int isSatisfied()
{
    for(int i=0;i<n;i++) {
        check[i] = 0;
    }
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(strcmp(initial[i], required[j])== 0 && check[j]==0) {
                check[j] = 1;
                break;
            }
        }
    }

    int result = 0;
    for(int i=0;i<n;i++) {
        if(check[i] == 1) {
            result++;
        }
    }
    
    if(result == n) {
        return 1;
    }
    else {
        return 0;
    }
}

void func(int numOfTry,int index)
{
    if(numOfTry > l || numOfTry > result) {
        return;
    }
    
    if(isSatisfied()) {
        if(numOfTry < result) {
            result = numOfTry;
        }
        return;
    }

    for(int i=index;i<l;i++) {
        flip(i);
        
        func(numOfTry+1, i+1);
        
        flip(i);
    }
}

void test(int testCase)
{
    fscanf(fin, " %d", &n);
    fscanf(fin, " %d", &l);

    for(int i=0;i<n;i++) {
        for(int j=0;j<l;j++) {
            fscanf(fin, " %c", &initial[i][j]);
        }
    }
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<l;j++) {
            fscanf(fin, " %c", &required[i][j]);
        }
    }
    
    func(0, 0);
    
    if(result < BIG) {
        fprintf(fout, "Case #%d: %d", testCase, result);
    }
    else {
        fprintf(fout, "Case #%d: NOT POSSIBLE", testCase);
    }
}

int main(int argc, const char * argv[])
{
    fin = fopen("/Users/lineplus/Documents/projects/GCJ/GCJ/data.in", "r");
    fout = fopen("/Users/lineplus/Documents/projects/GCJ/GCJ/data.out", "w");
    
    fscanf(fin, " %d", &numOfTestCase);
    
    for(int i = 1 ;i <= numOfTestCase; i++) {
        result = BIG;
        for(int j = 0;j<N;j++) {
            for(int k=0;k<N;k++) {
                initial[j][k]=0;
                required[j][k]=0;
            }
        }
        test(i);
        if(i < numOfTestCase) {
            fprintf(fout, "\n");            
        }
    }
    
    fclose(fin);
    fclose(fout);
    
    return 0;
}

