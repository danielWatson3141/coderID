#include<stdio.h>
#include<string>
#include<math.h>
int main()
{
    freopen("ain.in","r",stdin);
    freopen("aout.in","w",stdout);
    int t,t1;
    scanf("%d",&t);
    t1=t;
    while(t--)
    {
          long long int n,l;
          scanf("%lld%lld",&n,&l);
          int i,j,k;
          char a[100][100],b[100][100];
          for(i=0;i<n;i++)
          {
                          scanf("%s",a[i]);
          }
          for(i=0;i<n;i++)
          {
                          scanf("%s",b[i]);
          }
          int ans=0;
          int xx;
              for(xx=0;xx<(pow(2,l));xx++)
              {
                                 
                   ans=0;               
              
          for(i=0;i<l;i++)
          {
                         
                          
                          if((xx&(1<<i))!=0)
                          {
                                        //   printf("%d ",xx&(1<<i));  
                                            ans++;
                                            
                          for(j=0;j<n;j++)
                          {
                                        //  printf("%c",a[j][i]);
                                          if(a[j][i]=='1')
                                         a[j][i]='0';
                                         else
                                         a[j][i]='1';
                          }
                          }
          }
         
                          int array[n],flag=0;
                          for(j=0;j<n;j++)
                          array[j]=0;
                          for(k=0;k<n;k++)
                          {
                                          int l,m,flag=0;
                                       //   printf("%s %s\n",a[k],b[k]);
                                          
                                          
                                          for(l=0;l<n;l++)
                                          {
                                                          for(m=0;m<n;m++)
                                                          {
                                                                          if(array[m]==1)
                                                                          continue;
                                                                          int ret = strcmp(a[l], b[m]);
                                                                          if(ret==0)
                                                                          {
                                                                                    array[m]=1;
                                                                                    break;
                                                                          }
                                                                    
                                                          }
                                                          
                                          }
                                          
                          }
                          for(j=0;j<n;j++)
                          if(array[j]==0)
                          flag=1;
                          if(flag==0)
                          {
                                  printf("Case #%d: %d\n",t1-t,ans);
                                  break;
                          }
                          else
                          {
                              for(i=0;i<l;i++)
          {
                          if((xx&(1<<i))!=0)
                          for(j=0;j<n;j++)
                          {
                                        //  printf("%c",a[j][i]);
                                          if(a[j][i]=='1')
                                         a[j][i]='0';
                                         else
                                         a[j][i]='1';
                          }
          }
                          }
                          
                                  
                          
          }
          if(xx==(pow(2,l)))
          {
                  printf("Case #%d: NOT POSSIBLE\n",t1-t);
                  }
                          
              
    }
    return 0;
}
