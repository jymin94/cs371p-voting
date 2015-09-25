#ifndef Voting_h
#define Voting_h

#include <iostream> // istream, ostream
#include <sstream>
#include <string>   // string
#include <utility>  // pair
#include <vector>   //vector
#include <cassert>
#include <map>
#include <set>
#include <math.h>
#include <climits>
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

void show_all_winners (int max, map<int, Candidate>  winners, ostream& out); 
 
void eliminate_losers (set<int>losers, map<int,Candidate>& candidates);

void compute_winner (int total_votes, map<int,Candidate> candidates, int num_cands, ostream& out); 


 
#endif
// ----------------------------
// Voting.c++ 
// Jiyoung Min
// CS ID: jymin94
// UT EID: jm68529

// James Sweetman
// CS ID: sweetman
// UT EID: jts2939
// ----------------------------

// --------
// includes
// --------


/*
    reads in the input and maps the candidates to their votes 
*/
void voting_start (istream& in, ostream& out) {
    string s;
    int num_candidates;
    getline(in, s);
    istringstream sin(s);
    sin >> num_candidates;
    map<int, Candidate> candidates;
    int i = 1;

    int total_votes = 0;
    while (getline(in,s) && !s.empty()) {
        if (i <= num_candidates) {
            Candidate c(s);
            candidates.insert( pair<int,Candidate> (i, c) );
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
            total_votes++;
            if (cand_idx != -1)
                candidates.at(cand_idx).add_ballot(v);
        }
    }
    compute_winner(total_votes, candidates,num_candidates, out);
}

/*
    prints out all the winners (for perfect tie)
*/
void show_all_winners (int max, map<int,Candidate> candidates, ostream& out) {
   for (map<int,Candidate>::iterator c = candidates.begin(); c != candidates.end(); ++c) {
       if (c->second.get_num_ballots() == max)
         out << c->second.get_name() << endl;
   } 
}

/*
    takes the votes of the losers and reallocates them to corresponding valid candidates' list of ballots
*/
void eliminate_losers (set<int>losers, map<int,Candidate>& candidates) {
    for (set<int>::iterator loser = losers.begin(); loser != losers.end(); ++loser) {
        vector< vector<int> > ballots = candidates.at(*loser).get_all_ballots();
        for (vector< vector<int> >::iterator b = ballots.begin(); b != ballots.end(); ++b) {
            vector<int> votes = *b;
            for (vector<int>::iterator v = votes.begin(); v != votes.end(); ++v) {
                if (losers.find(*v) == losers.end() && candidates.find(*v) != candidates.end()) {
                    candidates.at(*v).add_ballot(votes);
                    break;
                }
            }
        }
        //delete the loser from the candidates map
        candidates.erase(*loser);
    }
}

/* 
    finds the winner from the given ballots
*/
void compute_winner (int total_votes, map<int,Candidate> candidates, int num_cands, ostream& out) {
    set<int> losers;
    int max_votes = 0;
    int min_votes = INT_MAX;
    bool tie_possible = true; 
    int max_idx = -1;
    int tie_votes = 0;

    for (map<int, Candidate>::iterator it = candidates.begin(); it != candidates.end(); ++it) {
       int votes = it->second.get_num_ballots();
       if (votes >= max_votes) {
            max_votes = votes;
            max_idx = it->first;
        }
        if (votes < min_votes) {
            min_votes = votes;
            losers.clear();
            losers.insert(it->first);
        }
        else if (votes == min_votes)
            losers.insert(it->first);
     
        // Checking for possible perfect tie   
       if (tie_votes == 0) {
            tie_votes = votes;
        }
        else if (votes != 0 && votes != tie_votes) {
            tie_possible = false;
        }
    }

    // If outright winner exists
    if (max_idx != -1 && max_votes > ceil(total_votes / 2)) {
        out << candidates.at(max_idx).get_name() << endl;
        return;
    }
 
    // If perfect tie exists
    if (tie_possible) {
        show_all_winners(max_votes, candidates, out);
        return;
    }

    // Need to reallocate losers set and recall this method
    if (!losers.empty()) {
        eliminate_losers(losers, candidates);
        compute_winner(total_votes, candidates, num_cands, out);
    }
    return;
}

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
