#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <limits>
#include <string>
#include <math.h>

using namespace std;

int main(void){
    char c[41][151];
    char z[41][151];
    map<string,int> m;
    int t,N,L,a,f=0;
    char q[200];
    string s="";
    string mask="";
    FILE *in,*out;
//   in=fopen("in.txt","r");
    in=fopen("A-small-attempt1.in","r");
//    in=fopen("B-large.in","r");
    out=fopen("out.txt","w");
    fscanf(in,"%d",&t);
    for (int i=1;i<=t;i++){
        fscanf(in,"%d %d",&N,&L);   
        m.clear();
        for (int j=0;j<N;j++){                
            fscanf(in,"%s",&q); 
            s=q;
            for (int k=0;k<L;k++){                
                c[k][j]=s.at(k);
                }
            }
        for (int j=0;j<N;j++){                
            fscanf(in,"%s",&q); 
            s=q;
            m[s]=1;
            }            

        a=-1;
        do{
            a++;
            mask.clear();
            mask.append(L-a,'0');            
            mask.append(a,'1');                                   
            do {
                f=0;
                for (int j=0;j<N&&f==0;j++){                
                    for (int k=0;k<L;k++){   
                        if (mask.at(k)=='1'){             
                           if (c[k][j]=='1'){                
                              z[k][j]='0';
                              }
                              else{
                                   z[k][j]='1';
                                   }
                           }
                           else{
                                z[k][j]=c[k][j];                                
                                }
                        }
                    }
                
                
                for (int j=0;j<N&&f==0;j++){                
                    s.clear();
                    for (int k=0;k<L;k++){                
                        s.append(1,z[k][j]);
                        }
                    if (m.find(s)==m.end()){
                       f=1;
                       }
                    }
                    
                } while (f==1 && next_permutation(mask.begin(),mask.end()) );           
                
            }while (f==1&&a<L);


            
        if (f==0){
           fprintf(out,"Case #%d: %d\n",i,a);           
           }
           else{
                fprintf(out,"Case #%d: NOT POSSIBLE\n",i);                           
                }
        }
    fclose (in);
    fclose (out);
    return 0;
    }
