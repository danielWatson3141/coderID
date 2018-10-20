//
//  main.cpp
//  Charging Chaos
//
//  Created by Dylan Stenico on 26/04/14.
//  Copyright (c) 2014 Dylan Stenico. All rights reserved.
//


#include <iostream>
#include<fstream>
#include<math.h>
void aumenta();
bool uguali(bool v1[], bool v2[]);
using namespace std;

bool flows[150][40];
bool VFlows[150][40];
bool required[150][40];
int num();
bool switches[40];

int n, l;
int main(int argc, const char * argv[])
{
    int cases;
    ifstream input("/Users/dylanstenico/Documents/School/InformationTechnology/2014/GoogleCodeJam/Charging Chaos/A-small-attempt0.in.txt");
    ofstream output("/Users/dylanstenico/Documents/School/InformationTechnology/2014/GoogleCodeJam/Charging Chaos/A-small-practice.ou.txt");
    input >> cases;
    
    for(int i = 0; i < cases; i++)
    {
        int quanti = 999;
        input >> n;
        input >> l;

        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < l; k++)
            {
                char tmp;
                input >> tmp;
                //cout << tmp;
                if(tmp == '1')
                {
                    flows[j][k] = true;
                    VFlows[j][k] = true;
                }
                else
                {
                    flows[j][k] = false;
                    VFlows[j][k] = false;
                }
            }
            //cout << endl;
        }
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < l; k++)
            {
                char tmp;
                input >> tmp;
                if(tmp == '1')
                {
                    required[j][k] = true;
                }
                else
                {
                    required[j][k] = false;
                }
            }
        }
        
        //-----------------------------------------------------------
        for(int r = 0; r < l; r++)
        {
            switches[r] = 0;
        }
        
        for(int t = 0; t < pow(2, l); t++)
        {
            int indici[n];
            int current = 0;
            for(int z = 0; z < n; z++)
            {
                bool esiste = false;
                
                for(int h = 0; h < n; h++)
                {
                    if(uguali(flows[z], required[h]))
                    {
                        esiste = true;
                        for(int p = 0; p < current; p++)
                        {
                            if(indici[p] == h)
                            {
                                esiste = false;
                            }
                        }
                        if(esiste)
                        {
                            indici[current++] = h;
                        }
                    }
                }
            }
            if(current == n)
            {
                if(num() < quanti)
                {
                    quanti = num();
                }
            }
            aumenta();
            
            for(int w = 0; w < l; w++)
            {
                if(switches[w])
                {
                    for(int f = 0; f < n; f++)
                    {
                        flows[f][w] = !VFlows[f][w];
                    }
                }
                else
                {
                    for(int f = 0; f < n; f++)
                    {
                        flows[f][w] = VFlows[f][w];
                    }
                }
            }
            
        }
        if(quanti < 999)
        {
            output << "Case #" << i + 1 <<": " << quanti<< endl;
        }
        else
        {
            output << "Case #" << i + 1 <<": NOT POSSIBLE"<< endl;
        }
        
    }
}

bool uguali(bool v1[], bool v2[])
{
    for(int i = 0; i < l; i ++)
    {
        if(v1[i] != v2[i])
        {
            return false;
        }
    }
    return true;
}

int num()
{
    int toRtn = 0;
    for(int i = 0; i < l; i++)
    {
        if(switches[i] == 1)
            toRtn++;
    }
    return toRtn;
}


void aumenta()
{
	bool riporto = 1;
	for(int i = 0; riporto; i++)
	{
		if(switches[i] == 1)
            switches[i] = 0;
		else
		{
			switches[i] = 1;
			riporto = 0;
		}
	}
}