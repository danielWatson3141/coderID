#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    
    FILE *f,*f2;
    
    int i, i2, i3;
    int tc,N;
    int *array; 
    int inv;
    
    f = fopen("input.txt","r");
    f2 = fopen("output.txt","w");
    fscanf(f,"%d",&tc);
    
    for (int i=0; i<tc; i++)
    {
        fscanf(f,"%d",&N);
        array = new int[N];
        for (i2 = 0; i2<N ; i2++)
        {
            fscanf(f,"%d",&array[i2]);    
        }
        
        inv = 0;
        for (i2=0; i2<N-1; i2++)
        {
          //for (i3=i2+1; i3<N; i3++)
          {
             if (array[i2]>array[i2+1])
                 inv++;    
          }    
        }
        
        if (inv <= (N/2))
        {
            fprintf(f2,"Case #%d: BAD\n",i+1);     
        }
else
        {
            fprintf(f2,"Case #%d: GOOD\n",i+1);     
        }
        
        delete[] array; 
    }    
    
    fclose(f);
    fclose(f2);
}
