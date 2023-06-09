#ifndef TEAM_H
#define TEAM_H

#pragma once

#include "libs.hpp"
#include "player.hpp"
// #include "league.h"

class team
{
public:
    team(string team_name_,
         vector<Player *> players_,
         vector<int> GF_,
         vector<int> GA_,
         vector<int> scores_);
    string get_name() { return team_name; }
    string get_team_name() { return team_name; }
    vector<Player *> get_team_players() { return players; }

    void updateData(int GF_, int GA_, int score_, int week)
    {
        GF.push_back(GF_);
        GA.push_back(GA_);
        scores.push_back(score_);
    }
    
    void calc_scores(int week);
    int calc_GD(int week);
    void show_players(string post);
    void show_sorted_players(string post);
    static bool sortScore(Player *a, Player *b);
    static bool sortName(Player *a, Player *b);
    
    int score;
    int GA_;
    int GF_;
    int GD_;

private:
    string team_name;
    vector<Player *> players;
    vector<int> GF;
    vector<int> GA;
    vector<int> scores;

    void print_players(const string &post,vector<Player *> &Players);
};

#endif