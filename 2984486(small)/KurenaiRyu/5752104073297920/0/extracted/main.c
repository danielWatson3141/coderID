#include <stdio.h>
#include <stdlib.h>
FILE *f,*o; // file handlers
int T; //test count
int N;
int PER[1000];

int test_per(){
    //probamos toda la pruena
    int i,j;
    int dif;
    long int dift=0;
    for(i=N/2;i<N;i++){
        dif=abs(i-PER[i]);
        dift+=dif;
    }
    printf("dift %li",dift);
    return dift;
}

int main(int argc, char *argv[]){
    int Tcnt;
    int i;
    if (argc!=2){
        printf("Invalid Argument!");
        return 1;
    }
    f=fopen(argv[1],"r");
    o=stdout;
    o=fopen("output.txt","w"); //hardcode for ll
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
        //read data
        fscanf(f,"%i\n",&N); //number of permutations... N=1000 :/
        for(i=0;i<N;i++){
            fscanf(f,"%i ",&PER[i]);
        }
        if(test_per()>160000)
            fprintf (o,"Case #%i: GOOD\n",Tcnt+1);
        else
            fprintf (o,"Case #%i: BAD\n",Tcnt+1);

    }


    return 0;
}
