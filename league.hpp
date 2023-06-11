#ifndef LEAGUE_H
#define LEAGUE_H

#pragma once

#include "libs.hpp"
#include "team.hpp"
#include "week.hpp"
// #include "football_fantasy.h"

class league
{
public:
    league(vector<team *> teams_,
           vector<week *> weeks_)
    {
        teams = teams_;
        weeks = weeks_;
    }
    vector<week *> get_weeks() { return weeks; }
    vector<team *> get_teams() { return teams; }
    void showTable(int week);
    team *find_team(string name);
    void showWeek(int week_);
    void set_score_teams(int num_week);

private:
    vector<team *> teams;
    vector<week *> weeks;
};

#endif