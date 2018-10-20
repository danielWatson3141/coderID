#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>

#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

//#include <conio.h>
//#include <stdlib.h>
//#include <stdio.h>
#include <string>
#include <time.h>

using namespace std;

int main()
{
    //redirect stdin and stdout
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);

    int rounds;
    cin >> rounds;
    string *have, *reqd;
    for (int rr = 0; rr< rounds; rr++)
    {

        int devices;
        cin >> devices;
        int switches;
        cin >> switches;

        have = new string[devices];
        reqd = new string[devices];

        for (int i=0; i < devices; i++)
            cin >> have[i];
        for (int i=0; i < devices; i++)
            cin >> reqd[i];
        sort(have, have + devices);
        sort(reqd, reqd + devices);

        /*printf("\n");
        for (int i=0; i < devices; i++)
        {
            printf("%s\n", have[i].c_str());
        }
        for (int i=0; i < devices; i++)
        {
            printf("%s\n", reqd[i].c_str());
        }*/

        sort(have, have + devices);
        sort(reqd, reqd + devices);

        // if not all match

        bool match = true;

        for (int i=0; i < devices; i++)
        {
            if (have[i] != reqd[i])
                match =false;
        }

        bool thing[switches];
        for (int i=0; i < switches; i++)
        {
            thing[i]=0;
        }
        int counter = 0;
        int flips = 0;
        while (!match && counter!= -1)
        {
            counter++;
            bool carry =false;
            for (int i=switches-1; i >= 0; i--)
            {

                if (carry || i == switches-1)
                {
                    thing[i] = !thing[i];

                    if (thing[i] ==0)
                        carry=true;
                    else
                        carry = false;
                }
            }
            for (int i=0; i < switches; i++)
            {
                if (thing[i])
                    for (int j=0; j < devices; j++)
                    {
                        have[j].replace(i, 1, have[j].at(i) == '0' ? "1": "0");
                    }
                //printf("%d", thing[i]);
            }
            //cout<<endl;

            sort(have, have + devices);
            sort(reqd, reqd + devices);

            /*printf("\n");
            for (int i=0; i < devices; i++)
            {
                printf("%s\n", have[i].c_str());
            }
            for (int i=0; i < devices; i++)
            {
                printf("%s\n", reqd[i].c_str());
            }
*/


            match =true;
            for (int i=0; i < devices; i++)
            {
                if (have[i] != reqd[i])
                    match=false;
            }
            if (match ==true)
            flips = 0;
            for (int i=0; i < switches; i++)
            {
                if (thing[i])
                    flips++;
            }

            for (int i=0; i < switches; i++)
            {
                if (thing[i])
                    for (int j=0; j < devices; j++)
                    {
                        have[j].replace(i, 1, have[j].at(i) == '0' ? "1": "0");
                    }
                //printf("%d", thing[i]);
            }


            int temp = 1;
            for (int i = 0; i< switches; i++)
            {
                temp *=2;
            }
            if (counter == temp-1)
                counter = -1;
        }

        //cout<<"Case #"<<
        if (counter ==-1)
            printf("Case #%d: NOT POSSIBLE\n", rr+1);
        else
            printf("Case #%d: %d\n", rr+1, flips);

        delete [] have;
        delete [] reqd;
    }





    return 0; //finish
}
