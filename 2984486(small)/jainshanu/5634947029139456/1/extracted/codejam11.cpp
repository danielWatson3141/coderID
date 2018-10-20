#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
main()
{
      int tc,u=1;
      scanf("%d",&tc);
      while(tc--)
      {
      int n,l,i,j,k,m;
      scanf("%d %d",&n,&l);
      char str1[n][l+1],str2[n][l+1];
      for(i=0;i<n;i++)
      scanf("%s",str1[i]);
      for(i=0;i<n;i++)
      scanf("%s",str2[i]);
      int min = 1000;
      //int count2=0;
      for(m=0;m<n;m++)
      {
          char str3[n][l+1];
          int count=1,flip=0,match[n],match1[n];
          for(i=0;i<n;i++)
          match[i]=match1[i]=-1;
          vector<int> v1;
          for(i=0;i<n;i++)
          {
            strcpy(str3[i],str1[i]);
          }
          for(k=0;k<l;k++)
          {
             if(str1[0][k]!=str2[m][k])
             {
               flip++;
               v1.push_back(k); 
             }
          }
          match[m] = 0;
          match1[0]=m;
          for(i=0;i<n;i++)
          {
              for(j=0;j<v1.size();j++)
              {
                  if(str3[i][v1[j]]=='0')
                  str3[i][v1[j]]='1';
                  else
                  str3[i][v1[j]]='0';
              }
          }
          //for(i=0;i<n;i++)
          //printf("%s\n",str3[i]);
          for(i=0;i<n;i++)
          {
             if(match1[i]==-1)
             {
                 for(j=0;j<n;j++)
                 {
                      if(match[j]==-1)
                      {
                          if(strcmp(str3[i],str2[j])==0)
                          {
                              match[j]=i;
                              match1[i]=j;
                              count++;
                          }
                      }
                 }
             }
          }
          if(count==n)
          {
             if(min>flip)
             min=flip;
          }
      }
      if(min!=1000)
      printf("Case #%d: %d\n",u,min);
      else
      printf("Case #%d: NOT POSSIBLE\n",u);
      u++;
      }
}
