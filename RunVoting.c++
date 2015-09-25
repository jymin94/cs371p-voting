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
    //voting_start(cin, cout);
     

    for (int i = 0; i < tests; i++) {
    //    cout << "calling test case " << i << endl;
        voting_start(cin, cout);
        cout << endl;
    }
    return 0;
}
