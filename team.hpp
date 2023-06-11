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
    void updatePlayersScores(int result, int week);
    void update_num_goal_base_post(int num_week);
    void update_total_num_goal(int num_week);
    void decrease_score_for_location(int num_week, string post, int decreasing_score);
    void update_num_goal_left(int num_week, Player *player);
    void update_num_goal_midfielder(int num_week, Player *player);
    void update_num_goal_right(int num_week, Player *player);
    void update_num_goal_center(int num_week, Player *player);
    vector<int> get_goals_left() { return num_goals_left; }
    vector<int> get_goals_right() { return num_goals_right; }
    vector<int> get_goals_center() { return num_goals_center; }
    vector<int> get_goals_midfielder() { return num_goals_midfielder; } /*73632*/

private:
    string team_name;
    vector<Player *> players;
    vector<int> GF;
    vector<int> GA;
    vector<int> scores;
    vector<int> num_goals_left;
    vector<int> num_goals_right;
    vector<int> num_goals_center;
    vector<int> num_goals_midfielder;
    void print_players(const string &post, vector<Player *> &Players);
};

#endif