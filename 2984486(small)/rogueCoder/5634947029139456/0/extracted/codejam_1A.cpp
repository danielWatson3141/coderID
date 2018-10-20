#include <fstream>
#include <string.h>
#include <math.h>

using namespace std;
unsigned int N,L;


int flip_bits(char DATA[][41],int pos)
{
    int i;
    for(i=0; i<N; i++)
    {
        if(DATA[i][pos] == '0')
           DATA[i][pos] = '1';

        else if(DATA[i][pos] == '1')
           DATA[i][pos] = '0';

    }
}

int avail(char DATA[][41], char REQ[][41])
{
    int i,j;
    int matches = 0;

    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
    {
        if(strcmp(DATA[i],REQ[j]) == 0)
        {
            matches++;
            break;
        }
    }
    }
    if (matches == N)   return 1;
    else return 0;
}

int check(char DATA[][41], char REQ[][41])
{
    int i,j;
    unsigned int min_switches = 999;
    unsigned int flips_done;
    for(i=0; i < pow(2,L); i++)
    {
        flips_done = 0;
        for(j=0; j<L; j++)
        {
            if(i>>j & 1)
            {
                flip_bits(DATA,L-j-1);
                flips_done++;

            }

        }
        if(avail(DATA,REQ) && flips_done<min_switches) min_switches = flips_done;
        if(flips_done > 0)
        {
        for(j=0; j<L; j++)
        {
            if(i>>j & 1)
            {
                flip_bits(DATA,L-j-1);
            }
        }
        }
    }
    if(min_switches == 999)
    return -1;
    else return min_switches;
}


int main()
{
    ifstream readFile("A-small-attempt3.in");
    ofstream outFile("output.in");
    unsigned int test_cases;

    int i;
    char data[150][41];
    char req[150][41];

    readFile>>test_cases;
    int temp = test_cases;

    while(temp--)
    {
        readFile>>N;
        readFile>>L;

        for(i=0; i<N; i++)
          readFile>>data[i];         // present switch configurations
        for(i=0; i<N; i++)
          readFile>>req[i];          // required switch configurations

        outFile<<"Case #"<<test_cases-temp<<": ";

        int x = check(data,req);

        if(x >= 0) outFile<<x;

        if(x == -1) outFile<<"NOT POSSIBLE";

        outFile<<endl;

    }

    readFile.close();
    outFile.close();
    return 0;
}
