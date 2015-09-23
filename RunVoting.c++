#include <iostream>
#include <sstream>
#include "Voting.h"

int main () {
    using namespace std;
    
    int tests;
    string s;
    getline(cin, s);
    istringstream sin(s);
    sin >> tests;
   
    getline(cin, s); 
    voting_read(cin, cout);
   

    /* optimized  
    for (int i = 0; i < tests; i++) {
        voting_read(cin);
    }
    */
    return 0;
}
