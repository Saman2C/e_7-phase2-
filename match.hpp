#ifndef MATCH_H
#define MATCH_H

#pragma once

#include "libs.hpp"
#include "team.hpp"

const int WINNER=5;
const int LOSER=-1;
const int EQUAL=1;

class match
{
public:
    match(team *team_1_,
          team *team_2_,
          int goal_team_1_,
          int goal_team_2_,
          int week);
    string get_team1_name(){return team_1->get_name();}
    string get_team2_name(){return team_2->get_name();}
    int get_team1_goal(){return goal_team_1;}
    int get_team2_goal(){return goal_team_2;}
    void update_teams(int num_week);
    void calculate_total_score_is_lost_team(int num_week);
    void update_lost_score_right_team1(int num_week);
    void update_lost_score_left_team1(int num_week);
    void update_lost_score_center_team1(int num_week);
    void update_lost_score_midfielder_team1(int num_week);
    void update_lost_score_right_team2(int num_week);
    void update_lost_score_left_team2(int num_week);
    void update_lost_score_center_team2(int num_week);
    void update_lost_score_midfielder_team2(int num_week);
    

private:
    team *team_1;
    team *team_2;
    int goal_team_1;
    int goal_team_2;
    int week;
};

#endif