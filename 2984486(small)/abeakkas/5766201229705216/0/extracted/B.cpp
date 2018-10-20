/*
* abdurak - Abdurrahman Akkas
* Google CodeJam 2014 - Round 1A
* Problem A
* Hadi hayirlisi
*/
#include<iostream>
#include<iomanip>
#include<fstream>
#include<cmath>
#include<algorithm>
#define FORN(i,n) for(int (i)=0;(i)<(n);(i)++)
#define FORR(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define MAX(a,b) (((a)>(b))?(a):(b))
using namespace std;
// ilk elemanda node sayisi
int debug=0;
int **toCon=(int **)malloc(sizeof(int *)*1001);
//kendisi dahil
int numCon(int n,int from){
    int c=1;
    FORR(i,1,toCon[n][0]){
        if(toCon[n][i]!=from)
            c+=numCon(toCon[n][i],n);
    }
    return c;
}
int toKill(int n,int from){
    if(debug==62){ //cout<<n<<" "<<from<<endl; system("pause");
}
    if(from==0){
        if(toCon[n][0]==0){
            return 0;
        }
        if(toCon[n][0]==1){
            if(toCon[n][1]==from)
            return numCon(toCon[n][2],n);
            else
            return numCon(toCon[n][1],n);
        }
        if(toCon[n][0]==2){
            if(toCon[n][1]==from)
            return toKill(toCon[n][2],n)+toKill(toCon[n][3],n);
            else if(toCon[n][2]==from)
            return toKill(toCon[n][1],n)+toKill(toCon[n][3],n);
            else
            return toKill(toCon[n][1],n)+toKill(toCon[n][2],n);
        }
        int arr[toCon[n][0]];
        int mass=0;
        FORR(i,1,toCon[n][0]){
            mass+=numCon(toCon[n][i],n);
        }
        FORR(i,1,toCon[n][0]){
            arr[i]=toKill(toCon[n][i],n)-numCon(toCon[n][i],n);
        }
        sort(arr,arr+toCon[n][0]);
        if(arr[0]+arr[1]<0)
        return arr[0]+arr[1]+mass;
        else
        return mass;
    }
    if(toCon[n][0]==1){
        return 0;
    }
    if(toCon[n][0]==2){
        if(toCon[n][1]==from)
        return numCon(toCon[n][2],n);
        else
        return numCon(toCon[n][1],n);
    }
    if(toCon[n][0]==3){
        if(toCon[n][1]==from)
        return toKill(toCon[n][2],n)+toKill(toCon[n][3],n);
        else if(toCon[n][2]==from)
        return toKill(toCon[n][1],n)+toKill(toCon[n][3],n);
        else
        return toKill(toCon[n][1],n)+toKill(toCon[n][2],n);
    }
    int arr[toCon[n][0]];
    int k=0;
    int mass=0;
    FORR(i,1,toCon[n][0]){
        if(toCon[n][i]!=from)
            mass+=numCon(toCon[n][i],n);
    }
    FORR(i,1,toCon[n][0]){
        if(toCon[n][i]==from){
            k--;
            continue;
        }
        if(debug==62&&n==7){
            //cout<<i<<"-"<<toCon[n][i]<<endl;
            //system("pause");
        }
        arr[i+k]=toKill(toCon[n][i],n);
    }
    sort(arr,arr+toCon[n][0]+k);
    return arr[0]+arr[1]+mass;
}
int main(){
    FORN(i,1001){
        toCon[i]=(int *)malloc(1001*sizeof(int));
    }
    //fout<<setprecision(15);
    ifstream fin("B.in");
    ofstream fout("B.out");
    int T;
    fin>>T;
    FORR(iT,1,T){
        debug=iT;
        FORN(i,1001){
            toCon[i][0]=0;
        }
        int N;
        fin>>N;
        cout<<iT<<" "<<N<<endl;
        FORN(i,N-1){
            int a,b;
            fin>>a>>b;
            if(iT==62) cout<<a<<" "<<b<<endl;
            toCon[a][0]++;
            toCon[a][toCon[a][0]]=b;
            toCon[b][0]++;
            toCon[b][toCon[b][0]]=a;
        }
        FORR(i,1,N){
            FORR(j,1,toCon[i][0]){
                //cout<<toCon[i][j]<<" ";
            }
            //cout<<endl;
        }
        int min=10000;
        FORR(i,1,N){
            int x=-1;
            x=toKill(i,0);
            if(x<min) min=x;
        }
        //cout<<endl;
        fout<<"Case #"<<iT<<": "<<min;
        fout<<endl;
    }
    system("pause");
}
