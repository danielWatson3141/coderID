/*
    By Yemeli Tasse Cyrille
    http://yemelitc.org
    Date: 26 April 2014
*/


#include<stdio.h>


int N, L;
long long ans;
char initial[200][50];
char required[200][50];



char check ()
{
    int i, j, k=0;
    for(i=0; i<N; i++)
        for(j=0; j<N; j++)
            if(0==strcmp(initial[i], required[j]))
                k++;
    if(k==N) return 1;
    else return 0;   // return do not match
}


void recurse (int* array, int level, int l2)
{
    int i;

    // flip do
    for(i=0; i<N; i++)
    {
        if(initial[i][level]=='0')
            initial[i][level]='1';
        else initial[i][level]='0';
    }

    if(check())
    {
        if(l2 < ans)
            ans = l2;

        // flip undo
        for(i=0; i<N; i++)
        {
            if(initial[i][level]=='0')
                initial[i][level]='1';
            else initial[i][level]='0';
        }
        return;
    }

    for(i=level+1; i < L; i++)
    {
        array[i] = i;
        recurse (array, i, l2+1);
    }

    // flip undo
    for(i=0; i<N; i++)
    {
        if(initial[i][level]=='0')
            initial[i][level]='1';
        else initial[i][level]='0';
    }
}


int main()
{
    int i, j;
    int Case, T;

    int level;
    int array[50];

    FILE *output = fopen("A-small-attempt0.out", "w");
    FILE *input = fopen("A-small-attempt0.in", "r");
    fscanf(input, "%d", &T);

    for(Case=1; Case<=T; Case++)
    {
        fscanf(input, "%d %d", &N, &L);

        for(i=0; i<N; i++)
            fscanf(input, "%s", initial[i]);

        for(i=0; i<N; i++)
            fscanf(input, "%s", required[i]);

        ans=1000000000000000;
        if(check())
            ans = 0;
        else
        {
            for(level = 0; level < L; level++)
            {

                for(i=0; i<N; i++)
                    array[i]=-1;
                array[0]=level;
                recurse(array, level, 1);
            }
        }

        if(ans==1000000000000000)
        {
            fprintf(output, "Case #%d: NOT POSSIBLE\n", Case);
            printf("Case #%d: NOT POSSIBLE\n", Case);
        }
        else
        {
            fprintf(output, "Case #%d: %lld\n", Case, ans);
            printf("Case #%d: %lld\n", Case, ans);
        }
    }

    fclose(input);
    fclose(output);
}

