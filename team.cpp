#include "team.hpp"

team ::team(string team_name_,
            vector<struct Player *> players_,
            vector<int> GF_,
            vector<int> GA_,
            vector<int> scores_)
{
    team_name = team_name_;
    players = players_;
    GA = GA_;
    GF = GF_;
    scores = scores_;
    score = 0;
    num_goals_center=vector<int> (NUM_WEEK,0);
    num_goals_left=vector<int> (NUM_WEEK,0);
    num_goals_right=vector<int> (NUM_WEEK,0);
    num_goals_midfielder=vector<int> (NUM_WEEK,0);


}

int team ::calc_GD(int week)
{
    GD_ = 0;
    GA_ = 0;
    GF_ = 0;
    for (int i = 0; i <= week; i++)
    {
        GA_ += GA[i];
        GF_ += GF[i];
    }
    GD_ = GF_ - GA_;
    return GD_;
}

void team ::calc_scores(int week)
{
    int score_ = 0;
    for (int i = 0; i <= week; i++)
    {
        score_ += scores[i];
    }
    score = score_;
}

void team::show_players(string post)
{
    vector<Player *> &Players = players;
    sort(Players.begin(), players.end(), sortName);
    print_players(post, Players);
}

void team::print_players(const string &post, vector<Player *> &Players)
{
    cout << "list of players:\n";
    int i = 1;
    for (auto player : Players)
    {
        if (post == "" || player->get_post() == post)
        {
            cout << i << ". name: " << player->get_player_name() << " | role: " << player->get_post() << " | score: " << player->get_score() << endl;
            i++;
        }
    }
}

void team::show_sorted_players(string post)
{
    vector<Player *> &Players = players;
    sort(Players.begin(), Players.end(), sortScore);
    print_players(post, Players);
}

bool team::sortScore(Player *a, Player *b)
{
    return a->get_score() < b->get_score();
}

bool team::sortName(Player *a, Player *b)
{
    return a->get_player_name() < b->get_player_name();
}

void team::update_total_num_goal(int num_week)
{
    for (auto player : players)
    {
        if(player->is_player_playing(num_week)){
            if (player->get_location() == "left")
            {
                num_goals_left[num_week]+=player->get_num_goal(num_week);
            }
            else if (player->get_location() == "right")
            {
                num_goals_right[num_week]+=player->get_num_goal(num_week);
            }
            else if (player->get_location() == "middle")
            {
                num_goals_center[num_week]+=player->get_num_goal(num_week);
            }
            else if (player->get_location() == "midfielder")
            {
                num_goals_midfielder[num_week]+=player->get_num_goal(num_week);
            }
        }
        }

}

void team::updatePlayersScores(int result, int week)
{
    //update_total_num_goal(week);
    for (auto player : players)
    {

        if (player->is_player_playing(week))
        {
            float score = float(result);
            score += player->cal_player_score_base_match(week, GF[week], GA[week]);
            player->update_score(score,week);
            player->set_week(week);
            float raw_score=player->get_score()+score;
            float score_=player->convertRawScore(raw_score);
            player->update_score(-player->get_score(),week);
            player->update_score(score_,week);
        }
    }
}

void team::decrease_score_for_location(int num_week, string post, int decreasing_score)
{
    for(auto player :players)
    {
        if(player->get_location() == post)
        {
            player->update_score(decreasing_score, num_week);
        }
    }
}

void team::update_num_goal_left(int num_week, Player *player)
{
    num_goals_left[num_week] += player->get_num_goal(num_week);
}

void team::update_num_goal_midfielder(int num_week, Player *player)
{
    num_goals_midfielder[num_week] += player->get_num_goal(num_week);
}

void team::update_num_goal_right(int num_week, Player *player)
{
    num_goals_right[num_week] += player->get_num_goal(num_week);
}

void team::update_num_goal_center(int num_week, Player *player)
{
    num_goals_center[num_week] += player->get_num_goal(num_week);
}

void team::update_num_goal_base_post(int num_week)
{
    for (auto player : players)
    {
        if (player->is_player_playing(num_week))
        {
            if (player->get_post() == "deafender")
            {

            }
        }
    }
}

