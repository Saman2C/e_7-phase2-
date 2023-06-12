//
// Created by 98902 on 5/29/2023.
//
#include "football_fantasy.hpp"

// User *find_user(string username, string password)
// {
// }

bool Football_Fantasy::is_team_used_before(string user_team_name)
{
    for (auto user : users)
    {
        if (user->say_name() == user_team_name)
        {
            return true;
        }
    }
    return false;
}

void Football_Fantasy::make_new_user(string username, string password)
{
    current_user = new User(username, password);
    users.push_back(current_user);
    cout << "OK" << endl;
}

void Football_Fantasy::make_admin(string username, string password)
{
    User *admin = new User(username, password);
    admin->set_admin();
    users.push_back(admin);
}

bool Football_Fantasy::enter_user(string username, string password)
{
    for (auto user : users)
    {
        if (user->say_name() == username)
        {
            if (user->get_password() == password)
            {
                cout << "OK"<<endl;
                current_user = user;
                return true;
            }
            else
            {
                cout << "Permission Denied";
                return false;
            }
        }
    }
    cout << "Not Found";
    return false;
}

Player *Football_Fantasy::find_player(string name)
{
    for (auto player : players)
    {
        if (player->get_player_name() == name)
        {
            return player;
        }
    }
    return NULL;
}

void Football_Fantasy::logout()
{
    current_user = nullptr;
    cout << "OK" << endl;
}

bool compareByScore(Player a, Player b)
{
    return a.get_score() > b.get_score();
}

vector<Player> Football_Fantasy::sortByScore(int week)
{
    vector<Player> sorted_players;
    for (auto player : players)
    {
        player->set_week(week);
        sorted_players.push_back(*player);
    }
//    for (auto player : sorted_players)
//    {
//        player.set_week(week);
//    }
    sort(sorted_players.begin(), sorted_players.end(), compareByScore);
    return sorted_players;
}

vector<Player> Football_Fantasy::findingPost(int week, const string &post)
{
    vector<Player> selected_post;
    vector<Player> all_players;
    all_players = sortByScore(week);
    for (auto player : all_players)
    {
        if (post == player.get_post())
            selected_post.push_back(player);
    }
    return selected_post;
}

vector<Player> Football_Fantasy::sortGKByScore(int week)
{
    string post = "goal_keeper";
    return findingPost(week, post);
}

vector<Player> Football_Fantasy::sortDFByScore(int week)
{
    string post = "deafender";
    return findingPost(week, post);
}

vector<Player> Football_Fantasy::sortMDByScore(int week)
{
    string post = "midfielder";
    return findingPost(week, post);
}

vector<Player> Football_Fantasy::sortFWByScore(int week)
{
    string post = "forward";
    return findingPost(week, post);
}

void Football_Fantasy::close_transfer_window()
{
    if (current_user->isAdmin())
    {
        can_sell_player = false;
    }
}

void Football_Fantasy::open_transfer_window()
{
    if (current_user == NULL)
        return;
    if (current_user->isAdmin())
    {
        can_sell_player = true;
        cout<<"OK"<<endl;
    }
}

User *Football_Fantasy::find_user_by_name(string name)
{
    for (auto user : users)
    {
        if (user->say_name() == name)
        {
            return user;
        }
    }
    return NULL;
}

void Football_Fantasy::show_ranked_team_players(string name, string post,int week)
{
    auto team = league1.find_team(name);
    team->show_sorted_players(post,week);
}

void Football_Fantasy::show_team_players(string name, string post,int week)
{
    auto team = league1.find_team(name);
    team->show_players(post,week);
}
void Football_Fantasy::fill_the_players()
{
    vector<Player *> total_players;
    vector<team *> teams = league1.get_teams();
    for (auto team : teams)
    {
        for (auto player : team->get_team_players())
        {
            total_players.push_back(player);
        }
    }
    players = total_players;
}

void Football_Fantasy::show_users()
{
    vector<User *> &users_ = users;
    sort(users_.begin(), users_.end(), sortScore);
    int i=1;
    for (auto user : users_)
    {
        if(!user->isAdmin()){
            cout << i<<". team_name: " << user->get_name() << " | point: " << user->totalPoint() << endl;
            i++;
        }


    }
}

bool Football_Fantasy::sortScore(User *a, User *b)
{
    return a->totalPoint() > b->totalPoint();
}

void Football_Fantasy::show_match_week(int week)
{
    league1.showWeek(week);
}

void Football_Fantasy::updateScores() {
    league1.set_score_teams(current_week);

}

void Football_Fantasy::increase_num_week() {
    current_week++;
    for(auto player :players)
        player->set_week(current_week);
}

/*void Football_Fantasy::updatePlayerScores() {
    for(auto player :players){
        player->calcScore();
    }
}*/


