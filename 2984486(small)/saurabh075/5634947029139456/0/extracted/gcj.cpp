#include<cstdio>
#include<iostream>

using namespace std;

inline void write(int a){
       register char c;
       char snum[20];
       int i=0;
       do{
          snum[i++]=a%10+48;
          a=a/10;
       }while(a!=0);
       i=i-1;
       while(i>=0)
           putchar(snum[i--]);
}

inline int readString() {
  register char c = getchar();
  while(c<'0' || c>'1') c = getchar();
  int ret = 0;
  while(c>='0' && c<='1') {
    ret = ret|(c - 48);
    ret<<=1;
    c = getchar();
  }
  ret>>=1;
  return ret;
}


inline long read() {
  register char c = getchar();
  while(c<'0' || c>'9') c = getchar();
  long ret = 0;
  while(c>='0' && c<='9') {
    ret = (ret<<3)+(ret<<1) + c - 48;
    c = getchar();
  }
  return ret;
}


void sort(long *arr,int size){
      int i, j;
      long tmp;
       for (i = 1; i < size; i++) {
            j = i;
              while (j > 0 && arr[j - 1] > arr[j]) {
                    tmp = arr[j];
                     arr[j] = arr[j - 1];
                      arr[j - 1] = tmp;
                       j--;
               }//end of while loop
       }//end of for loop
}

long orig[200];
long final[200];
int N,L,ans;

void printA(long* a){
     cout<<"[";
    for(int i=0;i<N;i++)
            cout<<a[i]<<", ";
    cout<<"]";
     
}
int compare(long* a,long* b){
//    printA(a);printA(b);cout<<endl;
    for(int i=0;i<N;i++)
            if(a[i] != b[i])
                    return 0;
    return 1;
}

void solve(long* arr, int bit,int flipCount){
//     cout<<endl;
//     cout<<"solve called with";
//     printA(arr);
//     cout<<"bit="<<bit<<",flipCount="<<flipCount<<endl;
    int temp[1000];
    sort(arr,N);
    if(compare(arr,final)){
         if(flipCount < ans) ans = flipCount;
//         cout<<"ans="<<ans<<",flipCount="<<flipCount<<endl;
    }
    if(flipCount >= ans) return;

    if(bit>=L) return;
    solve(arr,bit+1,flipCount);
    for(int i=0;i<N;i++) orig[i]^=(1<<bit);
    solve(arr,bit+1,flipCount+1);
    for(int i=0;i<N;i++) orig[i]^=(1<<bit);
}

int main(){
    int T,t;
    T = read();
    for(t=1;t<=T;t++){
               cout<<"Case #"<<t<<": ";
               N = read();
               L = read();
              for(int i=0;i<N;i++){
                    orig[i] = readString();
              } 
              for(int i=0;i<N;i++){
                    final[i] = readString();
              }
              sort(final,N);
              ans=1000;
              solve(orig,0,0);
              if(ans==1000) cout<<"NOT POSSIBLE"<<endl;
              else cout<<ans<<endl;
    }
//   while(1);
}
