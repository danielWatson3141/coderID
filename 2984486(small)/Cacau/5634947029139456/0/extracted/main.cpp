#include "main.h"

//Apologies for the poor code structure quality

int main(int argc, char* argv[]){
	if (argc < 2)
		cout << "Don't forget to pass the name of the input file (with extension) as a parameter!" << endl;

	string filename = argv[1];
	vector<input> inputs;

	readInputs(filename, inputs);
	writeSolution(inputs);
	return 0;
}

string solve(input &inElem){
	stringstream ss;
	
	int sol = checkForSolution(inElem.devices, inElem.outlets);
	if (sol == -1)
		ss << 0;
	else{
		hash_set<string> attemptedStates;
		int finalNumChanges = inElem.devices[0].size()+2;
		int numChanges = inElem.devices[0].size()+1;
		bool solFound = false;
		for (int i = 0; i < inElem.outlets.size(); i++){
			if (inElem.outlets[i] == inElem.devices[sol])
				break;

			if (attemptedStates.find(inElem.outlets[i]) == attemptedStates.end() && diffStr(inElem.outlets[i], inElem.devices[sol]) < finalNumChanges){
				numChanges = 0;
				attemptedStates.insert(inElem.outlets[i]);
				vector<string> attemptedStates(inElem.outlets);
				for (int j = 0; j < inElem.devices[sol].length(); j++){
					if (inElem.devices[sol][j] != inElem.outlets[i][j]){
						numChanges++;
						for (int x = 0; x < inElem.outlets.size(); x++){
							if (attemptedStates[x][j] == '0')
								attemptedStates[x][j] = '1';
							else
								attemptedStates[x][j] = '0';
						}
					}
				}

				if (checkForSolution(inElem.devices, attemptedStates) == -1){
					solFound = true;
					if (numChanges < finalNumChanges){
						finalNumChanges = numChanges;
					}
				}
				else
					numChanges = 0;
			}
		}
		if (solFound)
			ss << finalNumChanges;
		else
			ss << "NOT POSSIBLE";
	}
	return ss.str();
}

int checkForSolution(vector<string> &devices, vector<string> &outlets){
	hash_set<int> selectedDevices;
	for (int i = 0; i < devices.size(); i++){
		bool found = false;
		for (int j = 0; j < outlets.size() && !found; j++){
			if (devices[i] == outlets[j] && selectedDevices.find(j) == selectedDevices.end()){
				selectedDevices.insert(j);
				found = true;
			}
		}
		if (!found){
			return i;
		}
	}
	return -1;
}

int diffStr(string &str1, string &str2){
	int diff = 0;
	for (int i = 0; i < str1.length(); i++)
		if (str1[i] != str2[i])
			diff++;
	return diff;
}

void writeSolution(vector<input> &inputs){
	fstream ofile("test.ou", fstream::out);

	for (unsigned int i = 0; i < inputs.size(); i++){
		ofile << "Case #" << i+1 << ": " << solve(inputs[i]) << endl;
	}

	ofile.close();
}

void readInputs(string inputfile, vector<input> &inputs){
	fstream ifile(inputfile, fstream::in);
	if (!ifile.is_open()){
		cout << "Could not open file " << inputfile << "." << endl;
		exit(-1);
	}

	string line = "";
	do{
		getline(ifile, line);
	} while (line.length() <= 0);

	int numInputs = atoi(line.c_str());

	while (numInputs > 0){
		numInputs--;
		input curIn;

		getline(ifile, line);
		stringstream m1_ss(line);
		m1_ss >> curIn.numOutlets;
		m1_ss >> curIn.flowLength;

		string curValue;
		getline(ifile, line);
		m1_ss.clear(); m1_ss.str(line);
		for (int i = 0; i < curIn.numOutlets; i++){
			m1_ss >> curValue;
			curIn.outlets.push_back(curValue);
		}

		getline(ifile, line);
		m1_ss.clear(); m1_ss.str(line);
		for (int i = 0; i < curIn.numOutlets; i++){
			m1_ss >> curValue;
			curIn.devices.push_back(curValue);
		}

		
		inputs.push_back(curIn);
	}

	ifile.close();
}