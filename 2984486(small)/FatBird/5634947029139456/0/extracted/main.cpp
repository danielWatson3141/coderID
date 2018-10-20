#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

#define SIZE 15
char supply[SIZE][SIZE];
char need[SIZE][SIZE];
char copy_of_supply[SIZE][SIZE];

int num_of_1_in_supply[SIZE];
int num_of_1_in_need[SIZE];

void as_sort(char target[SIZE][SIZE], int num, int size)
{
    char *buf = (char *)malloc(sizeof(char) * (size + 1));
    for (int i=0; i<num; i++)
    {
        for (int j=i+1; j<num; j++)
        {
            if (strcmp(target[i], target[j]) < 0)
            {
                strcpy(buf, target[i]);
                strcpy(target[i], target[j]);
                strcpy(target[j], buf);
            }
        }
    }
    free(buf);
}

int main()
{
    int num_of_cases = -1;
    cin >> num_of_cases;

    for (int i=0; i<num_of_cases; i++)
    {
        int N = -1;
        int L = -1;
        cin >> N;
        cin >> L;

        for (int j=0; j<N; j++)
            cin >> supply[j];

        for (int j=0; j<N; j++)
            cin >> need[j];

        as_sort(need, N, L);
/*
        cout << "debug : " << endl;
        for (int j=0; j<N; j++)
            cout << supply[j] << " ";
        cout << endl;

        for (int j=0; j<N; j++)
            cout << need[j] << " ";
        cout << endl;
*/
        // calculating the number of 1s
        memset(num_of_1_in_supply, 0, sizeof(num_of_1_in_supply));
        memset(num_of_1_in_need, 0, sizeof(num_of_1_in_need));
        for (int j=0; j<L; j++)
        {
            for (int k=0; k<N; k++)
            {
                if (supply[k][j] == '1')
                    num_of_1_in_supply[j]++;
                if (need[k][j] == '1')
                    num_of_1_in_need[j]++;
            }
        }

        // check impossible
        //bool possible = true;
        //for (int j=0; j<L; j++)
        //{
        //    if ((num_of_1_in_need[j] - num_of_1_in_supply[j]) % 2 == 1)
        //        possible = false;
        //}
/*        int step = 0;
        for (int j=0; j<L; j++)
        {
            if (num_of_1_in_need[j] == num_of_1_in_supply[j])
                continue;
            if (num_of_1_in_need[j] + num_of_1_in_supply[j] == N)
            {
                step++;
                continue;
            }

            possible = false;
            break;
        }
*/
        bool possible_with_initial_false = false;
        int step = 1024;
        for (int j=0; j<N; j++)
        {
            memcpy(copy_of_supply, supply, sizeof(supply));

            int diff = 0;
            for (int k=0; k<L; k++)
            {
                if (copy_of_supply[j][k] != need[0][k])
                {
                    for (int l=0; l<N; l++)
                    {
                        copy_of_supply[l][k] = copy_of_supply[l][k] == '1' ? '0' : '1';
                    }
                    diff++;
                }
            }

            // check possible
            as_sort(copy_of_supply, N, L);
            bool the_same = true;
            for (int k=0; k<N; k++)
            {
                if (strcmp(copy_of_supply[k], need[k]) != 0)
                {
                    the_same = false;
                    break;
                }
            }
            if (the_same)
            {
                possible_with_initial_false = true;
                step = step < diff? step : diff;
            }
        }

        if (!possible_with_initial_false)
        {
            printf("Case #%d: NOT POSSIBLE\n", i+1);
        }
        else
        {
            printf("Case #%d: %d\n", i+1, step);
        }

    }
    return 0;
}
