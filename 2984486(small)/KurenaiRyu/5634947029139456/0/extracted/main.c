#include <stdio.h>
#include <stdlib.h>
FILE *f,*o; // file handlers
int T; //test count
int N,L; //numero de devices y switches
long int OUTS[150];
long int DEVS[150];
long int parseBin(char *b){
    long int res=0;
    int i;
    for (i=0;i<L;i++){
        res<<=1;
        if (b[i]=='1') res+=1;
    }
    return res;
}

long int DIFS[150][2]; //store there
int difs_cnt=0;
void clear_difs(void){
    int i;
    for(i=0;i<N;i++){
        DIFS[i][0]=0;
        DIFS[i][1]=0;
    }
    difs_cnt=0;
}
void push_difs(long int d){
    int i;
    for(i=0;i<difs_cnt;i++){
        if(DIFS[i][0]==d){
            DIFS[i][1]++;
            return;
        }
    }
    DIFS[difs_cnt][0]=d;
    DIFS[difs_cnt][1]=1;
    difs_cnt++;
}
int bitsize(long int d){ //size of bit
    int i;
    long int b=1;
    int r=0;
    for(i=0;i<L;i++){
        if (d & b) r++;
        b<<=1;
    }
    return r;
}
int search_difs(){
    int worst=50;
    int dif;
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            dif=bitsize(OUTS[i]^DEVS[j]);
            printf ("diferencia entre %i %i = %i \n",OUTS[i],DEVS[j],dif);
            push_difs(OUTS[i]^DEVS[j]);
        }
    }

    for(i=0;i<difs_cnt;i++){
        printf("diferencia %i : %i \n",DIFS[i][0],DIFS[i][1]);
        if (DIFS[i][1]>=N){//posible solucion
            dif=bitsize(DIFS[i][0]);
            if (dif<worst) worst=dif;
        }
    }
    return worst;
}


int main(int argc, char *argv[]){
    int Tcnt;
    int i;
    char buff[255];
    int res;
    if (argc!=2){
        printf("Invalid Argument!");
        return 1;
    }
    f=fopen(argv[1],"r");
    o=stdout;
    o=fopen("output.txt","w"); //hardcode for llz
    if (!f){
        printf("can't open input file!");
        return 1;
    }
    if(!o){
         printf("can't open output file!");
        return 1;
    }
    //get T
    fscanf(f,"%i\n",&T);
    for(Tcnt=0;Tcnt<T;Tcnt++){
        //read Data
        fscanf(f,"%i  %i\n",&N,&L);
        for (i=0;i<N;i++){
            fscanf(f,"%s ",buff); //
            OUTS[i]=parseBin(buff);
        }
        for (i=0;i<N;i++){
            fscanf(f,"%s ",buff); //
            DEVS[i]=parseBin(buff);
        }
        //debug print...
        //for (i=0;i<N;i++){printf ("o:%i : %li \n",i,OUTS[i]);        }
        //for (i=0;i<N;i++){            printf ("d:%i : %li \n",i,DEVS[i]);        }
        //ok....
        //buscar combinación de switches
        clear_difs();
        res=search_difs();
        if (res<50)
            fprintf (o,"Case #%i: %i\n",Tcnt+1,res);
        else
            fprintf (o,"Case #%i: NOT POSSIBLE\n",Tcnt+1);
    }


    return 0;
}
