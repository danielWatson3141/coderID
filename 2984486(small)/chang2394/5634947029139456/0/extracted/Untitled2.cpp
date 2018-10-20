#include <bits/stdc++.h>
#include <climits>
#include <fstream>

using namespace std;
int main()
{freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    
    int t;
    cin>>t;
    for(int I=1;I<=t;I++)
    {
            int n,l,res=INT_MAX;
            cin>>n>>l;
            vector<string>s1,s2;
            for(int i=0;i<n;i++)
            {
                    string ss;
                    cin>>ss;
                    s1.push_back(ss);
            }
            for(int i=0;i<n;i++)
            {
                    string ss;
                    cin>>ss;
                    s2.push_back(ss);
            }
            for(int i=0;i<n;i++)
            {
                    int r=0,mrk=0,f=0;
                    vector<int>A(100);
                    vector<int>v(200);
                    v[i]=1;
                    for(int j=0;j<l;j++)
                    {
                            if(s1[i][j]!=s2[0][j])
                            {
                                                  r++;
                                                  A[j]=1;
                            }
                    }
                    for(int j=1;j<n;j++)
                    {
                            f=0;
                            string st="";
                            for(int k=0;k<l;k++)
                            {
                                    int pp=(s2[j][k]-48);
                                    if(A[k]==1) pp=(pp+1)%2;
                                    st.push_back((char)(pp+48));
                            }
                            for(int k=0;k<n;k++)
                            {
                                    if(v[k]==1) continue;
                                    if(st==s1[k])
                                    {
                                                 f=1;
                                                 v[k]=1;
                                    }
                            }
                            if(f==0)
                            {
                                    mrk=1;
                                    break;
                            }
                    }
                    if(mrk==1) continue;
                    if(r<res) res=r;
            }
            cout<<"Case #"<<I<<": ";
            if(res==INT_MAX) cout<<"NOT POSSIBLE"<<"\n";
            else cout<<res<<"\n";
    }
    return 0;
}
                                    
                                                 
                            
                            
                    
                    
                    
                    
            
            
