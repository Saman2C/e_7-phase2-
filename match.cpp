#include "match.hpp"

match ::match(team *team_1_,
              team *team_2_,
              int goal_team_1_,
              int goal_team_2_,
              int week_)
{
    team_1 = team_1_;
    team_2 = team_2_;
    goal_team_1 = goal_team_1_;
    goal_team_2 = goal_team_2_;
    week = week_;
}

void match::update_lost_score_right_team1(int num_week)
{
    vector<int> num_goals = team_1->get_goals_right();
    if (num_goals[num_week] > 0)
    {
        for (auto player : team_2->get_team_players())
        {
            if (player->get_player_post() == "deafender" && player->get_location() == "left")
            {
                player->update_score(-num_goals[num_week], num_week);
            }
        }
    }
}

void match::update_lost_score_left_team1(int num_week)
{
    vector<int> num_goals = team_1->get_goals_left();
    if (num_goals[num_week] > 0)
    {
        for (auto player : team_2->get_team_players())
        {
            if (player->get_player_post() == "deafender" && player->get_location() == "right")
            {
                player->update_score(-num_goals[num_week], num_week);
            }
        }
    }
}

void match::update_lost_score_center_team1(int num_week)
{
    vector<int> num_goals = team_1->get_goals_center();
    if (num_goals[num_week] > 0)
    {
        for (auto player : team_2->get_team_players())
        {
            if (player->get_player_post() == "deafender" && player->get_location() == "middle")
            {
                player->update_score(-num_goals[num_week], num_week);
            }
        }
    }
}

void match::update_lost_score_midfielder_team1(int num_week)
{
    vector<int> num_goals = team_1->get_goals_midfielder();
    if (num_goals[num_week] > 0)
    {
        for (auto player : team_2->get_team_players())
        {
            if (player->get_player_post() == "midfielder")
            {
                player->update_score(-num_goals[num_week], num_week);
            }
        }
    }
}

void match::update_lost_score_right_team2(int num_week)
{
    vector<int> num_goals = team_2->get_goals_right();
    if (num_goals[num_week] > 0)
    {
        for (auto player : team_1->get_team_players())
        {
            if (player->get_player_post() == "deafender" && player->get_location() == "left")
            {
                player->update_score(-num_goals[num_week], num_week);
            }
        }
    }
}

void match::update_lost_score_left_team2(int num_week)
{
    vector<int> num_goals = team_2->get_goals_left();
    if (num_goals[num_week] > 0)
    {
        for (auto player : team_1->get_team_players())
        {
            if (player->get_player_post() == "deafender" && player->get_location() == "right")
            {
                player->update_score(-num_goals[num_week], num_week);
            }
        }
    }
}

void match::update_lost_score_center_team2(int num_week)
{
    vector<int> num_goals = team_2->get_goals_center();
    if (num_goals[num_week] > 0)
    {
        for (auto player : team_1->get_team_players())
        {
            if (player->get_player_post() == "deafender" && player->get_location() == "middle")
            {
                player->update_score(-num_goals[num_week], num_week);
            }
        }
    }
}

void match::update_lost_score_midfielder_team2(int num_week)
{
    vector<int> num_goals = team_2->get_goals_midfielder();
    if (num_goals[num_week] > 0)
    {
        for (auto player : team_1->get_team_players())
        {
            if (player->get_player_post() == "midfielder")
            {
                player->update_score(-num_goals[num_week], num_week);
            }
        }
    }
}


void match::calculate_total_score_is_lost_team(int num_week)
{
    team_1->update_total_num_goal(num_week);
    team_2->update_total_num_goal(num_week);
    update_lost_score_right_team1(num_week);
    update_lost_score_left_team1(num_week);
    update_lost_score_center_team1(num_week);
    update_lost_score_midfielder_team1(num_week);
    update_lost_score_right_team2(num_week);
    update_lost_score_left_team2(num_week);
    update_lost_score_center_team2(num_week);
    update_lost_score_midfielder_team2(num_week);
    
}

void match::update_teams(int num_week)
{
    num_week--;
    calculate_total_score_is_lost_team(num_week);
    if (goal_team_1 > goal_team_2)
    {
        team_1->updateData(goal_team_1, goal_team_2, 3, week);
        team_1->updatePlayersScores(WINNER, week);
        team_2->updateData(goal_team_2, goal_team_1, 0, week);
        team_2->updatePlayersScores(LOSER, week);

    }
    else if (goal_team_1 < goal_team_2)
    {
        team_1->updateData(goal_team_1, goal_team_2, 0, week);
        team_1->updatePlayersScores(LOSER, week);
        team_2->updateData(goal_team_2, goal_team_1, 3, week);
        team_2->updatePlayersScores(WINNER, week);
    }
    else
    {
        team_1->updateData(goal_team_1, goal_team_2, 1, week);
        team_2->updateData(goal_team_2, goal_team_1, 1, week);
        team_1->updatePlayersScores(EQUAL, week);
        team_2->updatePlayersScores(EQUAL, week);
    }
}
