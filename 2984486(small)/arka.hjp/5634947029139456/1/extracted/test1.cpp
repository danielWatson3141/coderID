#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string.h>
using namespace std;
int N,L;
int flipStatus[40];
        string outlets[150];
        string devices[150];
        int bitCountOfDevices[40];
        int bitCountOfOutlets[40];
int numOfflip;
bool matches(string flip){
    string flipedOutlet[150];
    for(int i=0;i<N;i++)
    {        flipedOutlet[i]=outlets[i];
        for(int j=0;j<L;j++)
        {
            if(flip[j]=='1')
            {
                if(flipedOutlet[i][j]=='1')
                    flipedOutlet[i][j]='0';
                else
                    flipedOutlet[i][j]='1';
            }
        }
        bool found=false;
        for(int k=0;k<N;k++)
        {
            if(!flipedOutlet[i].compare(devices[k]))
                {
                    found=true;
                    break;
                }

        }

        if(!found)
            return false;
    }
    return true;
}
string requiredFlip(string device,string outlet){
    //int numOfFlip;
    numOfflip=0;
    for(int i=0;i<L;i++)
    {
        if(device[i]==outlet[i])
            device[i]='0';
        else
        {
             device[i]='1';
             numOfflip++;
        }

    }
    return device;
}
int main(){
    int test_cases;
    freopen("g:/input.txt","r",stdin);
    freopen("g:/output.txt","w",stdout);

    cin>>test_cases;

  //  char grids[6][6];
    for(int caseNum=0;caseNum<test_cases;caseNum++){
        cin>>N;
        cin>>L;
        for(int k=0;k<L;k++)
        {
            bitCountOfDevices[k]=0;
            bitCountOfOutlets[k]=0;
        }
        for(int i=0;i<N;i++){
            cin>>devices[i];
            for(int j=0;j<L;j++)
            {
                if(devices[i][j]=='1')
                    bitCountOfDevices[j]++;
            }
        }
        for(int i=0;i<N;i++){
            cin>>outlets[i];
            for(int j=0;j<L;j++)
            {
                if(outlets[i][j]=='1')
                    bitCountOfOutlets[j]++;
            }
        }
        bool possible=false;
        int minFlip=L;
        for(int i=0;i<N;i++){
            string testDevice=devices[0];
            string flip=requiredFlip(testDevice,outlets[i]);
            if(!possible||minFlip>numOfflip)
            {
                if(matches(flip))
                {
                    possible=true;
                    minFlip=numOfflip;
                }
            }

        }

        if(!possible)
        cout<<"Case #"<<caseNum+1<<": NOT POSSIBLE"<<endl;
        else
        cout<<"Case #"<<caseNum+1<<": "<<minFlip<<endl;
  /*      int numOfflips=0;
        for(int i=0;i<L;i++){
            if(bitCountOfDevices[i]==bitCountOfOutlets[i]&&bitCountOfOutlets[i]+bitCountOfDevices[i]==N)
                flipStatus[i]=2;
            else if(bitCountOfDevices[i]==bitCountOfOutlets[i])
                flipStatus[i]=0;
            else if(bitCountOfOutlets[i]+bitCountOfDevices[i]==N)
            {
                numOfflips++;
                flipStatus[i]=1;
            }
            else
                possible=false;
        }
        for(int i=0;i<L;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(fl)
            }
        }

*/
    }
    return 0;
    }

