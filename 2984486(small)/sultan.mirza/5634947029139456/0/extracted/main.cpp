#include <iostream>
#include<string>
#include<math.h>
using namespace std;
int binary_decimal(int n)

{
    int decimal=0, i=0, rem;
    while (n!=0)
    {
        rem = n%10;
        n/=10;
        decimal += rem*pow(2,i);
        ++i;
    }
    return decimal;
}
int decimal_binary(int n)  /* Function to convert decimal to binary.*/
{
    int rem, i=1, binary=0;
    while (n!=0)
    {
        rem=n%2;
        n/=2;
        binary+=rem*i;
        i*=10;
    }
    return binary;
}
int main()
{
    int t,k;
    cin>>t;
    k=t;
    while(t--)
    {
        int n,l;
        cin>>n>>l;
        int aux[2048]={0};
        int a[n],b[n];
            for(int i=0;i<n;i++)
            {
                cin>>a[i];
                a[i]=binary_decimal(a[i]);
            }
        for(int i=0;i<n;i++)
            {
                cin>>b[i];
                b[i]=binary_decimal(b[i]);
            }
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    aux[a[i]^b[j]]++;
                }
        }
        int var,count=0,i;
        cout<<"Case #"<<k-t<<": ";
   for( i=0;i<2048;i++)
   {
       if(aux[i]==n)
       {
           var=decimal_binary(i);
           while(var>0)
           {
              int rem=var%10;
              if(rem==1)
              {
                  count++;
              }
              var=var/10;
           }
           cout<<count<<"\n";
           break;
       }
   }
   if(i==2048)
   {
       cout<<"NOT POSSIBLE"<<"\n";
   }
    }
    return 0;
}
