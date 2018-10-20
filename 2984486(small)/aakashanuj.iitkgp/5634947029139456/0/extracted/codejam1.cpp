#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
        int T;
        cin>>T;
        int t;
        ll ans=0;
        int i,j;
        for(t=1;t<=T;t++)
        {
                ll N,L;
                cin>>N>>L;
                string init[N];
                string req[N];
                for(i=0;i<N;i++)
                {
                        cin>>init[i];
                }    
                for(i=0;i<N;i++)
                {
                        cin>>req[i];
                }
                int flag=0;
                ll ans=0;
                for(i=0;i<L;i++)
                {
 
                        
                       ll s1=0,s2=0;
                       for(j=0;j<N;j++)
                       {
                                if(init[j][i]=='1')
                                        s1++;  
                                if(req[j][i]=='1')
                                        s2++;      
                       }
                       if(s1!=s2 && s1!=(N-s2))
                       {
                                flag=1;
                                break;
                       }
                       else if (s1!=s2)
                        ans++;
                       
                }
                if(flag==1)
                        printf("Case #%d: %s\n",t,"NOT POSSIBLE");
                        else
                        printf("Case #%d: %lld\n",t,ans);
                    
                    
        
        }
        
        return 0;
}

