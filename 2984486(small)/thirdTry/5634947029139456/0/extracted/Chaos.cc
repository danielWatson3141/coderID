#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Program to print all combination of size r in an array of size n
void combinationUtil(int arr[],int n,int r,int index,int data[],int i, vector <vector <int>>& combs);
 
// The main function that prints all combinations of size r
// in arr[] of size n. This function mainly uses combinationUtil()
void printCombination(int arr[], int n, int r,vector <vector <int>>& combs)
{
    // A temporary array to store all combination one by one
    int data[r];
 
    // Print all combination using temprary array 'data[]'
    combinationUtil(arr, n, r, 0, data, 0, combs);
}
 
/* arr[]  ---> Input Array
   n      ---> Size of input array
   r      ---> Size of a combination to be printed
   index  ---> Current index in data[]
   data[] ---> Temporary array to store current combination
   i      ---> index of current element in arr[]     */
void combinationUtil(int arr[], int n, int r, int index, int data[], int i, vector <vector <int>>& combs)
{
    // Current cobination is ready, print it
    if (index == r)
    {
		vector <int> temp;
        for (int j=0; j<r; j++)
        {
            //printf("%d ",data[j]);
            temp.push_back(data[j]);
		}
		combs.push_back(temp);
		temp.clear();
        //printf("\n");
        return;
    }
 
    // When no more elements are there to put in data[]
    if (i >= n)
        return;
 
    // current is included, put next at next location
    data[index] = arr[i];
    combinationUtil(arr, n, r, index+1, data, i+1,combs);
 
    // current is excluded, replace it with next (Note that
    // i+1 is passed, but index is not changed)
    combinationUtil(arr, n, r, index, data, i+1,combs);
}

vector <string> reverseBit(vector <string> input,int ind){
	for(int i=0;i<input.size();i++){
		if(input[i][ind] == '1')
			input[i][ind] = '0';
		else
			input[i][ind] = '1';
	}
	return input;
}

bool isArrayEqual(vector <string> array1,vector <string> array2){
	for(int i=0;i<array1.size();i++){
		if(array1[i]!=array2[i])
			return false;
	}
	return true;
}

bool isPossible(vector <string> input,vector <string> output,int numSwitches,int possible){
	sort(input.begin(), input.end());
	sort(output.begin(), output.end());
	if(isArrayEqual(input,output))
		return true;
	int arr[numSwitches];
	for(int i=0;i<numSwitches;i++){
		arr[i] = i;
	}
	vector <vector <int>> combs;
	printCombination(arr,numSwitches,possible,combs);
	//~ for(int i=0;i<combs.size();i++){
		//~ for(int j=0;j<combs[0].size();j++)
			//~ cout << combs[i][j]<<" ";
		//~ cout <<endl;
	//~ }
	for(int i=0;i<combs.size();i++){
		vector <string> temp;
		temp = input;
		for(int j=0;j<combs[0].size();j++){
			temp = reverseBit(temp,combs[i][j]);
		}
		sort(temp.begin(),temp.end());
		if(isArrayEqual(temp,output))
			return true;
	}
	return false;
}
// Driver program to test above functions
int main()
{
    
    vector <string> input;
    vector <string> output;
    int T,N,L,caseNum=1;
    cin >> T;
    while(caseNum<=T){
		cin >>N>>L;
		for(int i=0;i<N;i++){
			string temp;
			cin >> temp;
			input.push_back(temp);
		}
		for(int i=0;i<N;i++){
			string temp;
			cin >> temp;
			output.push_back(temp);
		}
		int check=0;
		for(int i=0;i<=L;i++){
			if(isPossible(input,output,L,i)){
				cout << "Case #"<<caseNum<<": " << i <<endl;
				check++;
				break;
			}
		}
		if(check==0)
			cout << "Case #"<<caseNum<<": NOT POSSIBLE" <<endl;
		input.clear();
		output.clear();
		caseNum++;
	}
    return 0;
}
