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
           // cout << "getting all the ballots " << endl;
           // print_ballots();
            return ballots;
        }

        string get_name (void) {
            return name;
        }

        void add_ballot (vector<int> b) {
            ballots.push_back(b);
            assert(!ballots.empty());
          /*
            for (vector<int>::iterator it=b.begin(); it != b.end(); ++it) {
                cout << *it << ' ';
            }
            cout << endl;
            cout << "added ballot into " << name << endl;
         */
        }

        void print_ballots() {
            if (ballots.empty()) {
                cout << "empty k bye" << endl;
                return;
            } 
            string output = "";
            cout << "[ ";
            cout.flush();
            for (vector< vector<int> >::iterator i = ballots.begin(); 
                i != ballots.end(); ++i) {
                vector<int> v = *i;
                assert(!v.empty());
                cout << "< ";
                cout.flush();
                for (vector<int>::iterator  j = v.begin(); j != v.end(); ++j) {
                    cout << *j << ' ';
                    cout.flush();
                }
                cout << "> " ;
                cout.flush();
             }
             cout << "]" << endl;
        }
};

void voting_start(istream& in, ostream& out);

void show_all_winners (vector<Candidate> winners, ostream& out); 
 
bool winner_exists (map<int, Candidate> candidates, int idx, int votes_to_exceed);

void eliminate_losers (set<int>losers, map<int,Candidate>& candidates);

void compute_winner (int total_votes, map<int,Candidate> candidates, int num_cands, ostream& out); 


 
#endif
