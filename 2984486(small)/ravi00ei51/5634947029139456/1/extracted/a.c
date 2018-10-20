#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#define NO_WINNER 0
#define WINNER_X 1
#define WINNER_O 2
#define TRUE 1
#define FALSE 0

#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))
void bubble_sort(int64_t * a, int n);
int testcases;
int N,L,testNo;
char flow[160][50];
int64_t  flow_i[160];

char eflow[160][50];
int64_t  eflow_i[160];
int64_t  ftemp[160];
int64_t invertBit (int64_t number, int64_t x)
{
     number ^= 1 << x;
     return number;
}

int compareArray(int64_t * a, int64_t * b,int n)
{
    int i,j;
    int ret_val = 1;
    for(i = 0;i < n;i++)
    {
       if( a[i] != b[i])
       {
          ret_val = 0;
          i = n;  
       }
    } 
    return ret_val;
}


void process()
{
    int64_t i,j,max,k,ret_val = 0;
    int flag = 0;
    max = pow(2,L);
   
    for(i = 0; i < max;i++)
    {
              //printf("Number before invert %lld ...",i); 
              for(k = 0;k < N;k++)
              {
                 ftemp[k] = flow_i[k];
                 //printf("%lld ", ftemp[k]);
              }
              //printf("\n");
       ret_val = 0;
       for(j = 0;j < L;j++)
       {
           
           //printf(" %lld :", CHECK_BIT(i,j)); 
           if(CHECK_BIT(i,j) != 0)
           {
              ret_val++;
              for(k = 0;k < N;k++)
              {
                 ftemp[k] = invertBit(ftemp[k],j);
              }
           }
       }
       bubble_sort(&ftemp[0],N);
       //printf("\nNumber after invert "); 
              for(k = 0;k < N;k++)
              {
                 
                 //printf("%lld ", ftemp[k]);
              }
              //printf("\n"); 
       if( compareArray(&eflow_i[0], &ftemp[0], N) == 1)
       {
          //printf(".... %lld %lld %lld\n",i, max, ret_val);
          //ret_val = i;
       /*//printf("\nNumber after invert "); 
              for(k = 0;k < N;k++)
              {
                 
               //printf("%lld ", ftemp[k]);
            }
           //printf("\n"); */

          i = max;
          flag = 1;
          
       }
       else
       {
           flag = 0;
       }
        
    }
    if( flag == 0)
    {
        printf("Case #%d: NOT POSSIBLE\n",testNo+1);
    }  
    else
    {
        printf("Case #%d: %lld\n",testNo+1,ret_val);
    }
}



void bubble_sort(int64_t * a, int n)
{
   int i,j,k;
   int64_t temp;
   
   
    for(i=1;i< n;i++)
    {
         for(j=0;j< n-1;j++)
         if(a[j]>a[j+1])
               {
               temp=a[j];
               a[j]=a[j+1];
               a[j+1]=temp;
               }
    }
}



int64_t binaryConvert( char *s, int l)
{
   int i,j;
   int64_t ret = 0;
   for(i = 0;i < l;i++)
   {
       if(s[i] == '1') 
        ret = ret + (int64_t)pow(2,i);

   }
   return ret;
} 

void getData (void)
{
     int i,j,val,k;
     FILE * fp;
     fp = fopen ("input.txt","r");
     fscanf (fp, "%d", &testcases);
     //printf ("Number of test cases are: %d\n",testcases);
     for (i=0; i < testcases;i++)
     {
         testNo = i; 
         fscanf (fp, "%d %d", &N , &L);
         //printf("%d %d\n", N, L);
         for(k = 0;k < N;k++)
         {
             fscanf(fp, "%s", &flow[k][0]);
             flow_i[k] = binaryConvert(&flow[k][0], L);
             //printf("%s ", &flow[k][0]); 
         }
         //printf("\n");
         bubble_sort(&flow_i[0],N); 
         //for(k = 0;k < N;k++)
            //printf("%lld ",flow_i[k]);
         //printf("\n");
         for(k = 0;k < N;k++)
         {
             fscanf(fp, "%s", &eflow[k][0]);
             eflow_i[k] = binaryConvert(&eflow[k][0], L);
             //printf("%s ", &eflow[k][0]); 
         }
         bubble_sort(&eflow_i[0],N); 
         //printf("\n"); 
         //for(k = 0;k < N;k++)
         //   //printf("%lld ",eflow_i[k]);
         
         //printf("\n");
         process();
          
     }

}

int main ()
{
    getData();
}
