//
//  main.c
//  cj
//
//  Created by Özgün Ayaz on 26/04/14.
//  Copyright (c) 2014 Özgün Ayaz. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NMAX 1000

int raiseto(int x, int to)
{
    if (to == 1) return x;
    else return x * raiseto(x, to - 1);
}

int tran[NMAX];
int devs[NMAX];
int outs[NMAX];

int NumberOfSetBits(int i)
{
    i = i - ((i >> 1) & 0x55555555);
    i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
    return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}

int compare (const void *a, const void *b)
{
    const int *ia = (const int *)a;
    const int *ib = (const int *)b;
    return *ia - *ib;
}

int match(int num)
{
    int i, ret = 1;
    for (i = 0; i < num; i++)
        if (tran[i] != devs[i])
        {
            ret = 0; break;
        }
    return ret;
}

void transform_copy_sort(int tr, int num)
{
    int i;
    for (i = 0; i < num; i++)
        tran[i] = outs[i] ^ tr;
    qsort(tran, num, sizeof(int), compare);
}

int fromBinary(char* s)
{
    char* start = s;
    int total = 0;
    while (*start)
    {
        total *= 2;
        if (*start++ == '1') total += 1;
    }
    return total;
}

int solve(FILE* f)
{

    char temp[50];
    int num, bitlen;
    fscanf(f, "%d %d", &num, &bitlen);
    int bit = raiseto(2, bitlen);

    int i;
    for (i = 0; i < num; i++)
    {
        fscanf(f, "%s", temp);
        devs[i] = fromBinary(temp);
    }
    for (i = 0; i < num; i++)
    {
        fscanf(f, "%s", temp);
        outs[i] = fromBinary(temp);
    }
    qsort(devs, num, sizeof(int), compare);
    int old_i = 0x7fffffff;
    for (i = 0; i < bit; i++)
    {
        transform_copy_sort(i, num);
        if (match(num))
        {
            if (NumberOfSetBits(i) < old_i) old_i = NumberOfSetBits(i);
        }
    }
    if (old_i != 0x7fffffff) return old_i;
    return -1;
}

int main(int argc, const char * argv[])
{
    FILE *f = fopen("/Users/mamud/Downloads/A-small-attempt2.in.txt", "r");
    
    if (!f) return 0;
    
    int num_test;
    fscanf(f, "%d", &num_test);
    
    int i;
    for (i = 1; i <= num_test; i++) {
        int result = solve(f);
        printf("Case #%d: ", i);
        if (result == -1) printf("NOT POSSIBLE\n");
        else printf("%d\n", result);
    }

    return 0;
}

