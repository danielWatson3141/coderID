        #include <fstream>
        #include <iostream>
        #include <string>
        #include <stdio.h>
        #include <math.h>
        #include <limits>
        
        
        using namespace std;
        
        int main()
        {
            ofstream fout ("2014gcj1out.txt");
            ifstream fin ("2014gcj1in.txt");
            
            
            
            int t;
            int n, l;
            int res;
            int aux;
            int aux2;
            int res2;
            
            res2=100;
             
            
          
            fin >> t;
            
            for(int i=0; i<t; i++)
            {
                    
            res2=100;
            
            fin >> n;
            fin >> l;
            
            char flow[n*l];
            
            char device[n*l];
            char tempflow[n*l];    
                      
            for(int j=0; j<n*l; j++)
            fin >> flow[j];
            
            for(int j=0; j<n*l; j++)
            fin >> device[j];
            
            for(int j=0; j<n; j++)
            {
                    
            
            for(int k=0; k<n*l; k++)
            tempflow[k] = flow[k];
            
            res = 0;
            for(int k=0; k<l; k++)
            {
            if(tempflow[k] != device[k+j*l])
            {
            res++;
            for(int s=0; s<n; s++)
            {
            if(tempflow[k+s*l] == '0')
            tempflow[k+s*l]='1';
            else
            tempflow[k+s*l]='0';
            }          
            }
            }
            
            
            aux =0;
            
            for(int s=0; s<n; s++)
            {
            
            for(int t=0; t<n; t++)
            {
            aux2 =0;
            for(int u=0; u<l; u++)
            if(tempflow[u+s*l] != device[u+t*l])
            {
            aux2 = 1;
            break;
            }
            
            if(aux2 ==0)
            {
            aux++;
            break;
            }
            }
            
            if(aux == s)
            break;
            }
            
            
            
            if(aux == n && res < res2)
            res2 = res;  
            }
            
            if(res2 == 100)
            fout << "Case #" << i+1 << ": NOT POSSIBLE" << endl;
            else
            fout << "Case #" << i+1 << ": " << res2 << endl;
            
            }
            return 0;
            
        }
        
        
