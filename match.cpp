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
    week=week_;
}
void match::update_teams()
{
    if (goal_team_1 > goal_team_2)
    {
        team_1->updateData(goal_team_1, goal_team_2, 3, week);
        team_1->updatePlayersScores(WINNER);
        team_2->updateData(goal_team_2, goal_team_1, 0, week);
        team_2->updatePlayersScores(LOSER);
    }
    else if (goal_team_1 < goal_team_2)
    {
        team_1->updateData(goal_team_1, goal_team_2, 0, week);
        team_1->updatePlayersScores(LOSER);
        team_2->updateData(goal_team_2, goal_team_1, 3, week);
        team_2->updatePlayersScores(WINNER);
    }
    else
    {
        team_1->updateData(goal_team_1, goal_team_2, 1, week);
        team_2->updateData(goal_team_2, goal_team_1, 1, week);
        team_1->updatePlayersScores(EQUAL);
        team_2->updatePlayersScores(EQUAL);
    }

}
