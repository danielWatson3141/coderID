#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<string>
using namespace std;

int toint(string s)
{
    int n=0;
    for (int i=0;i<s.size();i++)
       n = n*2+(s[i]-'0');
    return n;
}

int main()
{
    ifstream input("a.in");
    ofstream output("a.out");
    
    int t;
    string s;
    input>>t;
    for (int l=0;l<t;l++)
    {
        output<<"Case #"<<l+1<<": ";
        
        int a[1000]={0}, b[1000], n, l;
        
        input >> n >> l;
        
        for (int j=0;j<n;j++)
        {
            input >> s;
            a[j] = toint(s);
        }
        
        for (int j=0;j<n;j++)
        {
            input >> s;
            b[j] = toint(s);
        }
        
        for (int j=0;j<n-1;j++)
                for (int k=0;k<n-1;k++)
                    if (b[k]>b[k+1])
                    {
                        int temp = b[k];
                        b[k] = b[k+1];
                        b[k+1] = temp;
                    }
        
        int c[1000]={0},i=0,m=100000000;
        for (i=0;i<pow(2.0,double(l));i++)
        {
            for (int j=0;j<n;j++)
                c[j]=a[j]^i;
            for (int j=0;j<n-1;j++)
                for (int k=0;k<n-1;k++)
                    if (c[k]>c[k+1])
                    {
                        int temp = c[k];
                        c[k] = c[k+1];
                        c[k+1] = temp;
                    }
            
            int j;
            for (j=0;j<n;j++)
                if (c[j]!=b[j])
                   break;
            if (j==n)
            {
                int count=0,ii=i;
                while (ii>0)
                {
                      count+=ii%2;
                      ii/=2;
                }
                if (count<m)
                   m=count;  
            }
        }
        if (m==100000000)
           output <<"NOT POSSIBLE";
        else
        {
            output<<m;
        }
        output<<endl;
    }
    
    return 0;
}
