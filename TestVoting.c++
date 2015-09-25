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

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // string
#include <utility>  // pair

#include "gtest/gtest.h"

#include "Voting.h"

using namespace std;

// -----------
// TestCollatz
// -----------

// ----
// read
// ----

TEST(VotingFixture, show_all_winners_1) {
    map<int, Candidate> candidates;
    Candidate c("James");
    candidates.insert(pair<int, Candidate>(1,c))
    int max_votes = 0;
    ostringstream w;
    show_all_winners(max_votes, candidates, w);
    cout << w.str() << endl;
}

// TEST(VotingFixture, show_all_winners_2) {

// }
// TEST(VotingFixture, show_all_winners_3) {

// }
// TEST(VotingFixture, show_all_winners_4) {

// }
// TEST(VotingFixture, show_all_winners_5) {

// }
// TEST(VotingFixture, show_all_winners_6) {

// }
// TEST(VotingFixture, show_all_winners_7) {

// }
// TEST(VotingFixture, show_all_winners_8) {

// }
// TEST(VotingFixture, show_all_winners_9) {

// }
// TEST(VotingFixture, show_all_winners_10) {

// }
// TEST(VotingFixture, show_all_winners_11) {

// }
// TEST(VotingFixture, show_all_winners_12) {

// }
