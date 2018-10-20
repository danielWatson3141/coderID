/* https://code.google.com/codejam/contest/2974486/dashboard#s=p1
 * Problem B. Cookie Clicker Alpha
 */
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
        {
            double C,F,X,time=0.0000000,rate=2.0000000,cookies=0;
            scanf("%lf %lf %lf",&C,&F,&X);
           while(X/rate>X/(rate+F)+C/rate)
                    {
                    time+=C/rate;
                    rate+=F;
                    }
                printf("Case #%d: %.7lf\n",i,(double)time+(X/rate));
//            cout<<"Case #"<<i<<": ";
//            cout<<setprecision(7);
//            cout<<time+(X/r)<<endl;

        }
    return 0;
}
