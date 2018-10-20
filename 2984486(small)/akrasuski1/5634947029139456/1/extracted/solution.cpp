//Author: Adam Krasuski
//Solution to Google Code Jam 2014's Round !A's task 1.

#include <cstdio>
#include <algorithm>

using namespace std;

char buff[200];

int main(){

    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int n,l;
        scanf("%d %d",&n,&l);
        long long int outlets[n];
        long long int devices[n];

        for(int j=0;j<n;j++){
            scanf("%s",buff);
            long long int temp=0;
            for(int k=0;k<l;k++){
                temp*=2;
                temp+=buff[k]-'0';
            }
            outlets[j]=temp;
        }
        sort(outlets,outlets+n);

        for(int j=0;j<n;j++){
            scanf("%s",buff);
            long long int temp=0;
            for(int k=0;k<l;k++){
                temp*=2;
                temp+=buff[k]-'0';
            }
            devices[j]=temp;
        }
        sort(devices,devices+n);

        //end of loading data
        int min=1e9;
        for(int j=0;j<n;j++){
            //for every position of first device
            long long int pattern=devices[0]^outlets[j];

            long long int new_outlets[n];
            for(int k=0;k<n;k++){
                new_outlets[k]=outlets[k]^pattern;
            }
            sort(new_outlets,new_outlets+n);

            //now, for every device calculate if its outlet is correct
            int ok=1;
            for(int k=0;k<n;k++){
                if(new_outlets[k]!=devices[k]){
                    ok=0;
                }
            }
            if(ok){
                int amount_of_switches=0;
                while(pattern){
                    amount_of_switches+=pattern%2;
                    pattern/=2;
                }
                if(amount_of_switches<min){
                    min=amount_of_switches;
                }

            }

        }
        if(min>1000){
            printf("Case #%d: NOT POSSIBLE\n",i+1);
        }
        else{
            printf("Case #%d: %d\n",i+1,min);
        }


    }





}
