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
    candidates.insert(pair<int, Candidate>(1,c));
    int max_votes = 0;
    ostringstream w;
    show_all_winners(max_votes, candidates, w);
    ASSERT_EQ(w.str(), "James\n");
}

TEST(VotingFixture, show_all_winners_2) {
    map<int, Candidate> candidates;
    Candidate c("t1");
    candidates.insert(pair<int, Candidate>(1,c));
    int max_votes = 0;
    ostringstream w;
    show_all_winners(max_votes, candidates, w);
    ASSERT_EQ(w.str(), "t1\n");
}

TEST(VotingFixture, show_all_winners_3) {
    map<int, Candidate> candidates;
    Candidate c("t2");
    candidates.insert(pair<int, Candidate>(1,c));
    int max_votes = 0;
    ostringstream w;
    show_all_winners(max_votes, candidates, w);
    ASSERT_EQ(w.str(), "t2\n");
}


TEST(VotingFixture, show_all_winners_4) {
    map<int, Candidate> candidates;
    Candidate c("t3");
    candidates.insert(pair<int, Candidate>(1,c));
    int max_votes = 0;
    ostringstream w;
    show_all_winners(max_votes, candidates, w);
    ASSERT_EQ(w.str(), "t3\n");
}

TEST(VotingFixture, show_all_winners_5) {
    map<int, Candidate> candidates;
    Candidate c("t4");
    candidates.insert(pair<int, Candidate>(1,c));
    int max_votes = 0;
    ostringstream w;
    show_all_winners(max_votes, candidates, w);
    ASSERT_EQ(w.str(), "t4\n");
}

TEST(VotingFixture, show_all_winners_6) {
    map<int, Candidate> candidates;
    Candidate c("t5");
    candidates.insert(pair<int, Candidate>(1,c));
    int max_votes = 0;
    ostringstream w;
    show_all_winners(max_votes, candidates, w);
    ASSERT_EQ(w.str(), "t5\n");
}

TEST(VotingFixture, show_all_winners_7) {
    map<int, Candidate> candidates;
    Candidate c("t6");
    candidates.insert(pair<int, Candidate>(1,c));
    int max_votes = 0;
    ostringstream w;
    show_all_winners(max_votes, candidates, w);
    ASSERT_EQ(w.str(), "t6\n");
}

TEST(VotingFixture, show_all_winners_8) {
    map<int, Candidate> candidates;
    Candidate c("t7");
    candidates.insert(pair<int, Candidate>(1,c));
    int max_votes = 0;
    ostringstream w;
    show_all_winners(max_votes, candidates, w);
    ASSERT_EQ(w.str(), "t7\n");
}

TEST(VotingFixture, show_all_winners_9) {
    map<int, Candidate> candidates;
    Candidate c("t8");
    candidates.insert(pair<int, Candidate>(1,c));
    int max_votes = 0;
    ostringstream w;
    show_all_winners(max_votes, candidates, w);
    ASSERT_EQ(w.str(), "t8\n");
}

TEST(VotingFixture, show_all_winners_10) {
    map<int, Candidate> candidates;
    Candidate c("t9");
    candidates.insert(pair<int, Candidate>(1,c));
    int max_votes = 0;
    ostringstream w;
    show_all_winners(max_votes, candidates, w);
    ASSERT_EQ(w.str(), "t9\n");
}

TEST(VotingFixture, show_all_winners_11) {
    map<int, Candidate> candidates;
    Candidate c("t10");
    candidates.insert(pair<int, Candidate>(1,c));
    int max_votes = 0;
    ostringstream w;
    show_all_winners(max_votes, candidates, w);
    ASSERT_EQ(w.str(), "t10\n");
}

TEST(VotingFixture, show_all_winners_12) {
    map<int, Candidate> candidates;
    Candidate c("t11");
    candidates.insert(pair<int, Candidate>(1,c));
    int max_votes = 0;
    ostringstream w;
    show_all_winners(max_votes, candidates, w);
    ASSERT_EQ(w.str(), "t11\n");
}

TEST(VotingFixture, show_all_winners_13) {
    map<int, Candidate> candidates;
    Candidate c("t12");
    candidates.insert(pair<int, Candidate>(1,c));
    int max_votes = 0;
    ostringstream w;
    show_all_winners(max_votes, candidates, w);
    ASSERT_EQ(w.str(), "t12\n");
}

TEST(VotingFixture, show_all_winners_14) {
    map<int, Candidate> candidates;
    Candidate c("t13");
    candidates.insert(pair<int, Candidate>(1,c));
    int max_votes = 0;
    ostringstream w;
    show_all_winners(max_votes, candidates, w);
    ASSERT_EQ(w.str(), "t13\n");
}

TEST(VotingFixture, show_all_winners_15) {
    map<int, Candidate> candidates;
    Candidate c("t14");
    candidates.insert(pair<int, Candidate>(1,c));
    int max_votes = 0;
    ostringstream w;
    show_all_winners(max_votes, candidates, w);
    ASSERT_EQ(w.str(), "t14\n");
}

TEST(VotingFixture, show_all_winners_16) {
    map<int, Candidate> candidates;
    Candidate c("t15");
    candidates.insert(pair<int, Candidate>(1,c));
    int max_votes = 0;
    ostringstream w;
    show_all_winners(max_votes, candidates, w);
    ASSERT_EQ(w.str(), "t15\n");
}

TEST(VotingFixture, show_all_winners_17) {
    map<int, Candidate> candidates;
    Candidate c("t16");
    candidates.insert(pair<int, Candidate>(1,c));
    int max_votes = 0;
    ostringstream w;
    show_all_winners(max_votes, candidates, w);
    ASSERT_EQ(w.str(), "t16\n");
}

TEST(VotingFixture, show_all_winners_18) {
    map<int, Candidate> candidates;
    Candidate c("t17");
    candidates.insert(pair<int, Candidate>(1,c));
    int max_votes = 0;
    ostringstream w;
    show_all_winners(max_votes, candidates, w);
    ASSERT_EQ(w.str(), "t17\n");
}

TEST(VotingFixture, show_all_winners_19) {
    map<int, Candidate> candidates;
    Candidate c("t18");
    candidates.insert(pair<int, Candidate>(1,c));
    int max_votes = 0;
    ostringstream w;
    show_all_winners(max_votes, candidates, w);
    ASSERT_EQ(w.str(), "t18\n");
}

TEST(VotingFixture, show_all_winners_20) {
    map<int, Candidate> candidates;
    Candidate c("t19");
    candidates.insert(pair<int, Candidate>(1,c));
    int max_votes = 0;
    ostringstream w;
    show_all_winners(max_votes, candidates, w);
    ASSERT_EQ(w.str(), "t19\n");
}

TEST(VotingFixture, show_all_winners_21) {
    map<int, Candidate> candidates;
    Candidate c("t20");
    candidates.insert(pair<int, Candidate>(1,c));
    int max_votes = 0;
    ostringstream w;
    show_all_winners(max_votes, candidates, w);
    ASSERT_EQ(w.str(), "t20\n");
}

TEST(VotingFixture, show_all_winners_22) {
    map<int, Candidate> candidates;
    Candidate c("t21");
    candidates.insert(pair<int, Candidate>(1,c));
    int max_votes = 0;
    ostringstream w;
    show_all_winners(max_votes, candidates, w);
    ASSERT_EQ(w.str(), "t21\n");
}

TEST(VotingFixture, show_all_winners_23) {
    map<int, Candidate> candidates;
    Candidate c("t22");
    candidates.insert(pair<int, Candidate>(1,c));
    int max_votes = 0;
    ostringstream w;
    show_all_winners(max_votes, candidates, w);
    ASSERT_EQ(w.str(), "t22\n");
}

TEST(VotingFixture, show_all_winners_24) {
    map<int, Candidate> candidates;
    Candidate c("t23");
    candidates.insert(pair<int, Candidate>(1,c));
    int max_votes = 0;
    ostringstream w;
    show_all_winners(max_votes, candidates, w);
    ASSERT_EQ(w.str(), "t23\n");
}