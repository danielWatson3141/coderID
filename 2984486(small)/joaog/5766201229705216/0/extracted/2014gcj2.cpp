        #include <fstream>
        #include <iostream>
        #include <string>
        #include <stdio.h>
        #include <math.h>
        
        
        using namespace std;
        
        int main()
        {
            ofstream fout ("2014gcj2out.txt");
            ifstream fin ("2014gcj2in.txt");
            
            
            int t;
            fin >> t;
            int n;
            int aux;
            int aux2;
            int res2;
            
            
                      
                      
            for(int i=0; i<t; i++)
            {
            res2 =0;
            fin >> n;
            int x[n-1];
            int y[n-1];
            
            int res[n*n];
            
            for(int j=0; j<n-1; j++)
            {
            fin >> x[j];
            fin >> y[j];
            }
            
            for(int j=0; j<n; j++)
            for(int l=0; l<n; l++)
            res[j+n*l]=1;
            
            for(int l=0; l<n; l++)
            for(int m=1; m<n+1; m++)
            for(int s=0; s<n-1; s++)
            {
            if(x[s] == m)
            aux = y[s];
            
            if(y[s] ==m)
            aux = x[s];
            
            if(x[s] == m || y[s]==m)
            for(int t=s+1; t<n-1; t++)
            {
            if(x[t]==m)
            aux2 = y[t];
            
            if(y[t]==m)
            aux2 = x[t];
            
            if(x[t]==m || y[t]==m)
            {
            for(int k=1; k<n+1; k++)
            if(res[m-1+n*(k-1)] < res[aux-1+n*(m-1)]+res[aux2-1+n*(m-1)]+1 && aux != k && aux2 != k )
            res[m-1+n*(k-1)] = res[aux-1+n*(m-1)]+res[aux2-1+n*(m-1)]+1;
            }
            }
            }
           
            
            for(int j=0; j<n*n; j++)
            if( res2 < res[j])
            res2 = res[j];
            
            fout << "Case #" << i+1 << ": " << n-res2 << endl;
            
            
            
            }            
                                   
            
            return 0;
            
        }
        
        
