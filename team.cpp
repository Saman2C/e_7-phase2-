#include "team.hpp"

team ::team(string team_name_,
            vector<Player *> players_,
            vector<int> GF_,
            vector<int> GA_,
            vector<int> scores_)
{
    team_name = team_name_;
    players = players_;
    GA = GA_;
    GF = GF_;
    scores = scores_;
    score=0;
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
    int score_=0;
    for (int i = 0; i <= week; i++)
    {
        score_ += scores[i];
    }
    score=score_;
}

void team::show_players(string post) {
    vector<Player *> &Players = players;
    sort(Players.begin(),players.end(), sortName);
    print_players(post,Players);
}

void team::print_players(const string &post,vector<Player *> &Players) {
    cout << "list of players:\n";
    int i=1;
    for (auto player : Players) {
        if (post=="" || player->get_post()==post){
            cout<<i<<". name: "<<player->get_player_name()<<" | role: "<<player->get_post()<<" | score: "<<player->get_score()<<endl;
            i++;
        }
    }
}

void team::show_sorted_players(string post) {
    vector<Player *> &Players = players;
    sort(Players.begin(),Players.end(), sortScore);
    print_players(post,Players);
}

bool team::sortScore(Player *a, Player *b)
{
    return a->get_score() < b->get_score();
}

bool team::sortName(Player *a, Player *b) {
    return a->get_player_name() < b->get_player_name();
}

void team::updatePlayersScores(int result,int week) {
    for (auto player:players) {
        float score=result;
        score+=player->calcScore();
        player->set_score(week,score)
    }
}
