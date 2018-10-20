#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<fstream>
using namespace std;

int main()
{
    int t;
    FILE *inp,*ops;
    inp=fopen("inp.txt","r");
    ops=fopen("op.txt","w");

    fscanf(inp,"%d",&t);

    for(int i=1;i<=t;++i)
    {
        int n,l;
        char str[300][300];
        char target[300][300];
        fscanf(inp,"%d%d",&n,&l);

        for(int j=0;j<n;j++)
            fscanf(inp,"%s",str[j]);

        for(int j=0;j<n;j++)
            fscanf(inp,"%s",target[j]);

        int count=0;
        int flag=0,temp=0;
        int mark[505]={0};

        for(int j=0;j<n;j++)
        {
            temp=0;
            for(int k=0;k<n;k++)
            {
              if(strcmp(str[j],target[k])==0 && mark[k]==0)
              {
                  mark[k]=1;
                  temp=1;
                  break;
              }
            }
            if(temp==0)
                break;
        }
        if(temp==1)
        {
           fprintf(ops,"Case #%d: %d\n",i,0);
           continue;
        }

        char temps[300][300];
        int moves,ans=1000000;

        for(int j=0;j<n;j++)
        {
            moves=0;
            for(int k=0;k<n;k++)
                strcpy(temps[k],str[k]);

            for(int k=0;k<l;k++)
            {
                if(temps[0][k]!=target[j][k])
                {
                    moves++;
                    for(int p=0;p<n;p++)
                    {
                        if(temps[p][k]=='0')
                            temps[p][k]='1';

                        else
                            temps[p][k]='0';
                    }
                    //swappings done
                }
            }

            for(int y=0;y<=400;y++)
                mark[y]=0;

             for(int j=0;j<n;j++)
           {
              temp=0;
               for(int k=0;k<n;k++)
             {
              if(strcmp(temps[j],target[k])==0 && mark[k]==0)
              {
                  mark[k]=1;
                  temp=1;
                  break;
              }
             }
            if(temp==0)
                break;
           }

           if(temp==1)
            ans=min(ans,moves);
        }

        if(ans==1000000)
            fprintf(ops,"Case #%d: NOT POSSIBLE\n",i);

        else
            fprintf(ops,"Case #%d: %d\n",i,ans);

    }
    fclose(inp);
    fclose(ops);
    return 0;
}
