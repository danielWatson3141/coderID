#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <limits>
#include <math.h>

using namespace std;

int main(void){
    char a[51][51];
    int t,n,s1,s2,s,f;
    FILE *in,*out;
//   in=fopen("in.txt","r");
    in=fopen("C-small-attempt3.in","r");
//    in=fopen("B-large.in","r");
    out=fopen("out.txt","w");
    fscanf(in,"%d",&t);
    for (int i=1;i<=t;i++){
        fscanf(in,"%d",&n);   
        s1=0;s2=0;f=0;
        for (int j=0;j<n;j++){                
            fscanf(in,"%d",&s);   
            if (s>=j){
               f++;
               }
/*            if (j>(n/2))
               s1+=s;
               else
                   s2+=s;*/
            }
        if (f<=(n/2)){
           fprintf(out,"Case #%d: GOOD\n",i);           
           }
           else{
                fprintf(out,"Case #%d: BAD\n",i);                           
                }
        }
    fclose (in);
    fclose (out);
    return 0;
    }
