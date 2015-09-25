#include <iostream>
#include <sstream>
#include "Voting.h"
#include <map>

int main () {
    using namespace std;
    
    int tests;
    string s;
    getline(cin, s);
    istringstream sin(s);
    sin >> tests;
   
    getline(cin, s); 

    for (int i = 0; i < tests; i++) {
        voting_start(cin, cout);
        if (i != tests - 1)
            cout << endl;
    }
    return 0;
}
