#ifndef Voting_h
#define Voting_h

#include <iostream> // istream, ostream
#include <string>   // string
#include <utility>  // pair
#include <vector>   //vector
#include <cassert>
#include <map>
#include <set>

using namespace std;

class Candidate {
    string name; vector< vector<int> > ballots;
    
    public:
        Candidate (string s) {
            name = s;
        }

        int get_num_ballots (void) {
            return ballots.size();
        }
        
        vector< vector<int> > get_all_ballots () {
            return ballots;
        }

        string get_name (void) {
            return name;
        }

        void add_ballot (vector<int> b) {
            ballots.push_back(b);
            assert(!ballots.empty());
        }
};

void voting_start(istream& in, ostream& out);

void show_all_winners (int max, vector<Candidate> winners, ostream& out); 
 
void eliminate_losers (set<int>losers, map<int,Candidate>& candidates);

void compute_winner (int total_votes, map<int,Candidate> candidates, int num_cands, ostream& out); 


 
#endif
