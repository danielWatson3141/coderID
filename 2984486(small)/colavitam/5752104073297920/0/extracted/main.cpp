#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
#include <algorithm>
#define ABS(x) ((x) < 0 ? -(x) : (x))
using namespace std;
/*
int main2() {
    srand(4312);
    ofstream out("in.txt");
    out<<"1200\n";
    double cutoff = 0;
    for(int k=0;k<600;k++) {
        out<<"1000\n";
        //Randgen
        int nums[1000];
        for(int i=0;i<1000;i++)
            nums[i] = i;
        for(int i=0;i<1000;i++) {
            int r = (rand() % (1000));
            int tmp = nums[i];
            nums[i] = nums[r];
            nums[r] = tmp;
        }
        for(int i=0;i<1000;i++) {
            out<<nums[i]<<" ";
        }
        for(int i=0;i<1000;i++) {
            cutoff += pow(nums[i] - i,2) * pow(nums[i], 2);
        }
        out<<"\n";
    }
    for(int k=0;k<600;k++) {
        out<<"1000\n";
        //Randgen
        int nums[1000];
        for(int i=0;i<1000;i++)
            nums[i] = i;
        for(int i=0;i<1000;i++) {
            int r = (rand() % (1000 - i)) + i;
            int tmp = nums[i];
            nums[i] = nums[r];
            nums[r] = tmp;
        }
        for(int i=0;i<1000;i++) {
            out<<nums[i]<<" ";
        }
        for(int i=0;i<1000;i++) {
            cutoff += pow(nums[i] - i,2) * pow(nums[i], 2);
        }
        out<<"\n";
    }
    cout<<cutoff/1200<<"\n";
    out.close();
    return 0;
}*/

int main3() {
    ifstream in("in.txt");
    ofstream out("out.txt");
    int T;
    in>>T;
    //int wrongN = 0, wrongP = 0;
    for(int k=0;k<T;k++) {
        int N;
        in>>N;
        double dev = 0;
        for(int i=0;i<N;i++) {
            int tmp;
            in>>tmp;
            dev += pow(tmp - i,2) * pow(tmp, 2);
        }
        out<<"Case #"<<(k+1)<<": ";
        if(dev < 5.79317e+13) {
            //if(k >= 600)
            //    wrongN ++;
            out<<"BAD\n";
        }
        else {
            //if(k < 600)
             //   wrongP ++;
            out<<"GOOD\n";
        }
    }
    //cout<<wrongN<<" "<<wrongP<<"\n";
    return 0;
}

int main() {
    //main2();
    main3();
}
//Median good: 1.66695e+08
//Mean good: 1.66791e+08
//Median bad: 1.57206e+08
//Mean bad: 1.57251e+08
/*
 vector<double> devs;
 for(int k=0;k<10000;k++) {
 //Randgen
 int nums[1000];
 for(int i=0;i<1000;i++)
 nums[i] = i;
 for(int i=0;i<1000;i++) {
 int r = (rand() % (1000));
 int tmp = nums[i];
 nums[i] = nums[r];
 nums[r] = tmp;
 }
 double dev = 0;
 for(int i=0;i<1000;i++) {
 dev += pow(nums[i] - i,2);
 }
 devs.push_back(dev);
 }
 double tot = 0;
 for(int i=0;i<devs.size();i++)
 tot+=devs[i];
 cout<<tot/10000<<"\n";
*/