/* This program should be run with its input piped from the input file and its output piped to the output file. */

#include <iostream>
#include <string>

using namespace std;

int iNumOutlets;
int iNumSwitches;

int  getNumSwitchesNeeded(string* pOutlets, string* pDevices, bool* piSwitchesUsed, int iDepth = 0, int iNextSwitch = 0);
bool testForMatch(string* pOutlets, string* pDevices);

int main() {
    int iNumTests;
    string* pOutlets;
    string* pDevices;
    bool*   pbSwitchesUsed;
    
    cin >> iNumTests;
    
    for (int test = 1; test <= iNumTests; ++test) {
        cin >> iNumOutlets >> iNumSwitches;
        
        pOutlets = new string[iNumOutlets];
        pDevices = new string[iNumOutlets];
        pbSwitchesUsed = new bool[iNumSwitches];
        
        for (int i = 0; i < iNumOutlets; ++i) {
            cin >> pOutlets[i];
        }
        
        for (int i = 0; i < iNumOutlets; ++i) {
            cin >> pDevices[i];
        }
        
        for (int i = 0; i < iNumSwitches; ++i) {
            pbSwitchesUsed[i] = false;
        }
        
        int iNumSwitchesNeeded = getNumSwitchesNeeded(pOutlets, pDevices, pbSwitchesUsed);
        
        cout << "Case #" << test << ": ";
        if (iNumSwitchesNeeded >= iNumSwitches + 1) {
            cout << "NOT POSSIBLE" << endl;
        } else {
            cout << iNumSwitchesNeeded << endl;
        }
        
        delete[] pOutlets;
        delete[] pDevices;
        delete[] pbSwitchesUsed;
    }
    
    return 0;
}

int getNumSwitchesNeeded(string* pOutlets, string* pDevices, bool* pbSwitchesUsed, int iDepth, int iNextSwitch) {
    if (testForMatch(pOutlets, pDevices)) {
        return iDepth;
    }
    
    ++iDepth;
    
    int iBest = 1000000;
    int iResult;
    
    for (int i = iNextSwitch; i < iNumSwitches; ++i) {
        if (!pbSwitchesUsed[i]) {
            pbSwitchesUsed[i] = true;
            for (int k = 0; k < iNumOutlets; ++k) {
                pOutlets[k][i] = pOutlets[k][i] == '0' ? '1' : '0';
            }
            
            iResult = getNumSwitchesNeeded(pOutlets, pDevices, pbSwitchesUsed, iDepth, iNextSwitch + 1);
            
            pbSwitchesUsed[i] = false;
            for (int k = 0; k < iNumOutlets; ++k) {
                pOutlets[k][i] = pOutlets[k][i] == '0' ? '1' : '0';
            }
            
            if (iResult < iBest) {
                iBest = iResult;
            }
        }
    }
    
    return iBest;
}

bool testForMatch(string* pOutlets, string* pDevices) {
    bool* pbDevicesUsed = new bool[iNumOutlets];
    int j;
    
    for (int i = 0; i < iNumOutlets; ++i) {
        pbDevicesUsed[i] = false;
    }
    
    for (int i = 0; i < iNumOutlets; ++i) {
        for (j = 0; j < iNumOutlets; ++j) {
            if (!(pbDevicesUsed[j]) && pOutlets[i].compare(pDevices[j]) == 0) {
                pbDevicesUsed[j] = true;
                break;
            }
        }
        
        if (j == iNumOutlets) {
            delete[] pbDevicesUsed;
            return false;
        }
    }
    
    delete[] pbDevicesUsed;
    return true;
}
