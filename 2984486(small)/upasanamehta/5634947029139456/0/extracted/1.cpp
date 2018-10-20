#include<bits/stdc++.h>

using namespace std;

int main()
{
    FILE *fp,*fo;
    fp=fopen("input1.txt","r");
    fo=fopen("output1.txt","w");
    int t,y;
    fscanf(fp,"%d",&t);
    for(y=1;y<=t;y++){

            int i,n,l,ans=1e9,bits=0,a[20]={0},mask[20]={0},j,temp;
            char s[20];
            fscanf(fp," %d %d",&n,&l);

            //cout<<n<<" "<<l;



            for(i=0;i<n;i++)
                {fscanf(fp,"%s",s);
                  for(j=0;j<l;j++)
                    if(s[j]=='1')
                     a[i]=a[i]^(1<<j);
                }

            for(i=0;i<n;i++)
                {fscanf(fp,"%s",s);
                  for(j=0;j<l;j++)
                    if(s[j]=='1')
                     mask[i]=mask[i]^(1<<j);
                }

           /*  if(y==83)
             {
                 for(i=0;i<n;i++)
                    cout<<a[i]<<" ";

                    cout<<endl;

                    for(i=0;i<n;i++)
                    cout<<mask[i]<<" ";


             } */
            for(i=0;i<(1<<l);i++)
            {
                int t[20];
                for(j=0;j<n;j++)
                {
                    t[j]=a[j]^(i);
                }

                sort(t,t+n);
                sort(mask,mask+n);

               /* cout<<endl<<i<<" ";
                for(j=0;j<n;j++)
                    cout<<t[j]<<" "; */

                for(j=0;j<n;j++)
                    if(t[j]!=mask[j])
                        break;

                if(j==n)
                {
                    bits=0;
                    for(temp=0;temp<l;temp++)
                        if(i&(1<<temp))
                            bits++;
                    ans=min(ans,bits);
                    //fprintf(fo,"Case #%d: %d\n",y,ans);
                }



            }

            if(ans==1e9)
             fprintf(fo,"Case #%d: NOT POSSIBLE\n",y);

            else
                fprintf(fo,"Case #%d: %d\n",y,ans);






 }

    fclose(fp);
    fclose(fo);
    return 0;
}
