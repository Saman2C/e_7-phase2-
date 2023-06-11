#include "league.hpp"
bool compareScore(const team &a, const team &b)
{
    if (a.score < b.score)
        return true;
    else if (a.score == b.score && a.GD_ < b.GD_)
        return true;
    else if (a.score == b.score && a.GF_ < b.GF_)
        return true;
    return false;
}
void league::showTable(int week)
{
    vector<team> sorted_teams;
    for (auto &team : teams)
    {
        team->calc_scores(week);
        team->calc_GD(week);
        sorted_teams.push_back(*team);
    }
    sort(sorted_teams.begin(), sorted_teams.end(), compareScore);
    for (int i = sorted_teams.size() - 1; i >= 0; i--)
    {
        cout << sorted_teams.size() - i << "." << sorted_teams[i].get_name()
             << ": score: " << sorted_teams[i].score << " | GF: " << sorted_teams[i].GF_
             << " | GA: " << sorted_teams[i].GF_ - sorted_teams[i].GD_ << endl;
    }
}

team *league::find_team(string name) {
    for(auto team :teams){
        if(team->get_name()==name)
            return team;
    }
    return nullptr;
}

void league::showWeek(int week_) {
    week *&this_week = weeks[week_ - 1];
    for (auto match:this_week->get_match()) {
        cout<<match->get_team1_name()<<" "<<match->get_team1_goal()<<" | "<<match->get_team2_name()<<" "<<match->get_team2_goal()<<endl;
    }
}

void league::set_score_teams(int num_week) {
    for (auto week : weeks){
        for (auto match : week->get_match()){
            match->update_teams(num_week);
        }
    }
}
