#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <map>

using namespace std;

long long int out[200];
map<long long int,bool> device;
queue<long long int> q;

int main()
{
    int N,c,n,len,i,j,num,ans;
    long long int d,x,cur;
    bool find;
    scanf("%d",&N);
    for(c=1;c<=N;c++){
        device.clear();
        memset(out,0,sizeof(out));
        find=false; num=0; ans=0;
        scanf("%d %d",&n,&len);
        for(i=0;i<n;i++){
            for(j=0;j<len;j++){
                scanf("%1d",&x);
                out[i]*=2;
                out[i]+=x;
            }
        }
        for(i=0;i<n;i++){
            d=0;
            for(j=0;j<len;j++){
                scanf("%1d",&x);
                d*=2;
                d+=x;
            }
            device[d]=true;
        }
        q.push(0);
        while(!q.empty() && !find){
            cur=q.front(); q.pop(); num++;
            //printf("cur=%d\n",cur);
            for(i=0;i<n;i++){
                x=out[i]^cur;
                if(!device[x]){
                    x=1;
                    for(i=0;i<len;i++){
                        if((cur&x)!=x){
                            q.push(cur|x);
                            //printf("q.push(%d)\n",cur|x);
                        }
                        else break;
                        x=x*2;
                    }
                    break;
                }
                else if(i==n-1){
                    find=true;
                    break;
                }
            }
        }
        x=1;
        //printf("cur=%d\n",cur);
        for(i=0;i<len;i++){
            if((cur&x)==x){
                ans++;
            }
            x*=2;
        }

        printf("Case #%d: ",c);
        if(find)printf("%d\n",ans);
        else printf("NOT POSSIBLE\n");
        while(!q.empty()){q.pop();}
    }
    return 0;
}
