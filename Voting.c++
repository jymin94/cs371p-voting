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
#include <set>
#include <climits>
#include <math.h>
#include "Voting.h"

using namespace std;

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

void print_map (map<int,Candidate> candidates) {
    for (map<int, Candidate>::iterator it = candidates.begin(); it != candidates.end(); ++it) {
        cout << "candidate " << it->first << " ";
        cout.flush();
        it->second.print_ballots();
    } 
}


void show_all_winners (int max, map<int,Candidate> candidates, ostream& out) {
   for (map<int,Candidate>::iterator c = candidates.begin(); c != candidates.end(); ++c) {
       if (c->second.get_num_ballots() == max)
         out << c->second.get_name() << endl;
   } 
}

bool winner_exists (map<int, Candidate> candidates, int idx, int votes_to_exceed) {
    return candidates.at(idx).get_num_ballots() > votes_to_exceed;
}

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

    
