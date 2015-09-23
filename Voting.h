#ifndef Voting_h
#define Voting_h

#include <iostream> // istream, ostream
#include <string>   // string
#include <utility>  // pair
#include <vector>   //vector
#include <cassert>
using namespace std;

class Candidate {
    string name; vector< vector<int> > ballots;
    
    public:
        Candidate (string s) {
            name = s;
        }

        int get_votes (void) {
            return ballots.size();
        }

        string get_name (void) {
            return name;
        }

        void add_ballot (vector<int> b) {
            ballots.push_back(b);
            assert(!ballots.empty());
            for (vector<int>::iterator it=b.begin(); it != b.end(); ++it) {
                cout << *it << ' ';
            }
            cout << endl;
            cout << "added ballot into " << name << endl;
        }

        void print_ballots() {
            cout << name << endl; 
            if (ballots.empty()) {
                cout << "empty k bye" << endl;
                return;
            } 
            string output = "";

            for (vector< vector<int> >::iterator i = ballots.begin(); 
                i != ballots.end(); ++i) {
                vector<int> v = *i;
                assert(!v.empty());
                for (vector<int>::iterator  j = v.begin(); j != v.end(); ++j) {
                    cout << *j << ' ';
                    cout.flush();
                }
             }
             cout << endl;
        }
};
void voting_read(istream& r, ostream& out);

#endif
