#include <stdio.h>
#include <stdlib.h>
FILE *f,*o; // file handlers
int T; //test count
int N; //number of nodes
int XY[1000][2];
int delSubtree(int r, int b){
    //how many nodes?
    int i;
    int dels=0;
    int c=0;
    int cs[1000];
    printf("\n deleting branch %i - %i",r,b);
    for(i=0;i<(N-1);i++){
        if(b==XY[i][0]){
            if(r==XY[i][1]) continue;
            //not parent? then children
            //check possible branch
            cs[c]=XY[i][1];
            c++;
        }
        if(b==XY[i][1]){
            if(r==XY[i][0]) continue;
            cs[c]=XY[i][0];
            c++;
        }
    }
    for(i=0;i<c;i++){
        dels+=delSubtree(b,cs[i]);
    }
    printf ("deleting %i and %i child .",dels,c);
    return c+dels;
}
int branchOk(int r, int b){
    int i;
    int dels=0;
    int c=0;
    int cs[1000];
    printf("\n testing branch %i - %i:",r,b);
    //first check appropiated number of childrens
    for(i=0;i<(N-1);i++){
        if(b==XY[i][0]){
            if(r==XY[i][1]) continue;
            //not parent? then children
            //check possible branch
            cs[c]=XY[i][1];
            c++;
        }
        if(b==XY[i][1]){
            if(r==XY[i][0]) continue;
            cs[c]=XY[i][0];
            c++;
        }
    }
    if (c==0) printf(" ok ! ");
    if (c==0) return 0; //do not need to delete children
    if (c==2){ //check childrens
        for(i=0;i<c;i++){
            dels+=branchOk(b,cs[i]);
        }
        printf(" ok with %i ",dels);
        return dels; // how much to be optimun
    }
    //si sobra 1 o  3
    printf(" %i childs ... ",c);
    for(i=0;i<c;i++){
        dels+=delSubtree(b,cs[i]);
    }
    printf(" deleting with %i ",dels+1);
    return dels+1; // how much to be optimun
}

int possibleRoot(int n){

    int i;
    int r=0;
    for(i=0;i<(N-1);i++){
        if(XY[i][0]==n) r++;
        if(XY[i][1]==n) r++;
    }
    return (r==2);
}
int delstobtree(int r){
    //from root r analice branches
    int i;
    int td=0;
    for(i=0;i<(N-1);i++){
        if(r==XY[i][0]) td+=branchOk(r,XY[i][1]);
        if(r==XY[i][1]) td+=branchOk(r,XY[i][0]);
    }
    return td;
}
int tree(void){
    //analise tree
    //tree need a root (with 2 branches
    //branches need 2 branches or none
    //single nodes should be deleted..
    //how many are deleted?
    int i;
    int mind=N;
    int d=0;
    for(i=0;i<N;i++){ //look por possible root
        if(possibleRoot(i)){
            d=delstobtree(i);
            printf("\nposible root: %i, dels: %i", i,d);
            if (d<mind) mind=d;
        }
    }
    return mind;
}

int main(int argc, char *argv[]){
    int Tcnt;
    int i;
    int best;
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

        //get data
        fscanf(f,"%i\n",&N); //numero de nodos
        for(i=0;i<(N-1);i++){
            fscanf(f,"%i  %i\n",&XY[i][0],&XY[i][1]);
        }
        best=tree();
        fprintf (o,"Case #%i: %i\n",Tcnt+1,best);
    }


    return 0;
}
