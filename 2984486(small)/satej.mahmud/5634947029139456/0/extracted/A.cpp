#include<iostream>
using namespace std;


int T;
int N,L;
char in[50];
int A[50];
int B[50];

int get(){
    cin>>in;
    int ret = 0;
    for(int i=0;i<L;++i){
        ret*=2;
        ret=ret+in[i]-'0';
    }
    return ret;
}

int bitCount(int i){
    return i==0?0:bitCount(i/2)+i%2;
}


int main(){
    int i,j;
    freopen("A-small-attempt1.in","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>T;
    for(int cas=1;cas<=T;++cas){
        cin>>N>>L;
        for(i=0;i<N;++i) A[i] = get();
        for(i=0;i<N;++i) B[i] = get();
        sort(B,B+N);
        int res = 100;
        do{
            int first = A[0]^B[0];
            int t1 = bitCount(first);
            if(t1>=res) continue;
            for(i=1;i<N;++i){
                int cur = A[i]^B[i];
                if(cur!=first) break;
            }
            if(i==N){
                res=t1;
            }
        }while(next_permutation(B,B+N));
        cout<<"Case #"<<cas<<": ";
        if(res==100){
            cout<<"NOT POSSIBLE\n";
        }
        else{
            cout<<res<<endl;
        }
    }
    return 0;
}
