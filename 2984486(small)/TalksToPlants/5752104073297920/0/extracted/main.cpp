#include <iostream>
#include <fstream>

using namespace std;

int arr[1000];
ofstream output;

bool bad(int on, int up, int down)
{
    //cout << "At positon " << on << endl;
    //cout << "Value " << arr[on] << endl;
    if (arr[on] == 0) {
        //cout << "YAy" << endl;
        //output << up << endl;
        //output << down << endl;
        if (up > down) {
            return true;
        } else {
            return false;
        }
    } else {
        if (arr[on] > on) {
            return bad(arr[on], up + 1, down);
        } else {
            return bad(arr[on], up, down + 1);
        }
    }
}

int main()
{
    ifstream input;
    input.open("input.txt");
    output.open("output.txt");
    int t;
    input >> t;
    int n;
    int num;
    for (int i = 0; i < t; i++) {
        input >> n;
        int count = 0;
        for (int x = 0; x < n; x++) {
            input >> num;
            arr[x] = num;
        }
        if (bad(arr[0] , 0 , 0)) {
            output << "Case #" << i + 1 << ": BAD" << endl;
        } else {
            output << "Case #" << i + 1 << ": GOOD" << endl;
        }
    }
    return 0;
}
