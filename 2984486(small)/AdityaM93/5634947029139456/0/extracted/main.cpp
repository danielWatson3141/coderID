#include <iostream>
#include<fstream>
using namespace std;

int flip[40];
int gn,gl;
int gsc[150][40],grc[150][40];
int bc;

int checkforsolved(){
    int lsc[gn][gl];
    for(int i=0;i<gn;i++){
        for(int j=0;j<gl;j++){
            if(flip[j]==0){
                lsc[i][j]=gsc[i][j];
            } else {
                lsc[i][j]=1-gsc[i][j];
            }
        }
    }
    for(int x=0;x<gn;x++)
        for(int w=0;w<gn;w++)
        if(w!=x){
        int equ=1;
        for(int y=0;y<gl;y++){
            if(lsc[x][y]!=lsc[w][y]){
                equ=0;
                break;
            }
        }
        if(equ==1)
            return 0;
    }
    int sat=0;
    for(int x=0;x<gn;x++)
        for(int y=0;y<gn;y++){
        int ts=1;
        for(int z=0;z<gl;z++){
            if(grc[x][z]!=lsc[y][z]){
                ts=0;
                break;
            }
        }
        if(ts==1)
            sat++;
    }
    if(sat==gn){
        int c=0;
        for(int x=0;x<gl;x++){
            if(flip[x]==1)
                c++;
        }
        return c;
    } else {
        return -1;
    }
}
void bruteforce(int i,int l){
    if(i<l){
        flip[i]=0;
        bruteforce(i+1,l);
        flip[i]=1;
        bruteforce(i+1,l);
    } else {
        int cc=checkforsolved();
        if(bc==-1||(bc>cc&&cc!=-1))
            bc=cc;
    }
}
int main()
{
    ofstream outputFile;
    outputFile.open("program3data.txt");
    int tt;
    cin>>tt;
    int n[tt],l[tt];

    int r[150][40];
    int rc[tt][150][40];

    int s[150][40];
    int sc[tt][150][40];

    for(int t=0;t<tt;t++){

    cin>>n[t];
    cin>>l[t];
    for(int x=0;x<n[t];x++){
        cin>>s[t][x];
        for(int y=0;y<l[t];y++){
            sc[t][x][y]=s[t][x]%10;
            s[t][x]/=10;
        }
    }

    for(int x=0;x<n[t];x++){
        cin>>r[t][x];
        for(int y=0;y<l[t];y++){
            rc[t][x][y]=r[t][x]%10;
            r[t][x]/=10;
        }
    }
 //   }
 //   for(int t=0;t<tt;t++){
    gn=n[t];
    gl=l[t];
    for(int x=0;x<40;x++)
        flip[x]=0;
    bc=-1;
    for(int x=0;x<n[t];x++)
        for(int y=0;y<l[t];y++){
        gsc[x][y]=sc[t][x][y];
        grc[x][y]=rc[t][x][y];
    }
    bruteforce(0,l[t]);
    if(bc!=-1)
    outputFile<<"Case #"<<t+1<<": "<<bc<<endl;
    else
    outputFile<<"Case #"<<t+1<<": "<<"NOT POSSIBLE"<<endl;
    }
    return 0;
}
