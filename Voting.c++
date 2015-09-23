// ----------------------------
// Voting.c++ 
// Jiyoung Min
// CS ID: jymin94
// UT EID: jm68529

// James Sweetman
// CS ID:
// UT EID:
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <sstream>  // istringstream
#include <string>   // getline, string
#include <vector>
#include <map>


#include "Voting.h"

using namespace std;

void voting_read (istream& r, ostream& out) {
    string s;
    int num_candidates;
    getline(r, s);
    istringstream sin(s);
    sin >> num_candidates;
    
    map<int, Candidate> candidates;
    int i = 1;
    while (getline(r,s) && !s.empty()) {
        if (i <= num_candidates) {
            Candidate c(s);
            candidates.insert( pair<int,Candidate> (i, c) );
            cout << c.get_name() << endl;
            ++i;
        }
        else {
            istringstream line_stream(s);
            int vote;
            vector<int> v;
            int cand_idx = -1;
            while (line_stream >> vote) {
                if (cand_idx == -1) {
                    cand_idx = vote;
                }
                v.push_back(vote);
            }
            candidates.at(cand_idx).add_ballot(v);
        }
    }

    /* TESTING 
    for (map<int, Candidate>::iterator it = candidates.begin(); it != candidates.end(); ++it) {
        cout << "candidate " << it->first << " ";
        cout.flush();
        it->second.print_ballots();
    } 
        */
}

