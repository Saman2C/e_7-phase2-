#ifndef FOOTBALL_FANTACY
#define FOOTBALL_FANTACY

#pragma once

#include "libs.hpp"
#include "user.hpp"
#include "player.hpp"
#include "league.hpp"

class Football_Fantasy
{
public:
    Football_Fantasy(league league1_) : league1(league1_)
    {
        can_sell_player = false;
        current_week = 1;
        current_user= nullptr;
    }

    bool is_team_used_before(string user_team_name);
    void make_new_user(string username, string password);
    void make_admin(string username, string password);
    bool enter_user(string username, string password);
    void logout();
    Player *find_player(string name);
    bool can_sell() { return can_sell_player; }
    User *find_user_by_name(string name);
    void show_ranked_team_players(string name,string post);
    void show_team_players(string name,string post);
    void show_table(){league1.showTable(current_week-1);}
    User *current_user;
    bool can_sell_player;
    static bool sortUser(User *a, User *b);
    vector<Player> sortByScore(int week);
    vector<Player> sortGKByScore(int week);
    vector<Player> sortDFByScore(int week);
    vector<Player> sortMDByScore(int week);
    vector<Player> sortFWByScore(int week);
    void close_transfer_window();
    void open_transfer_window();
    void increase_num_week();
    int get_week() { return current_week; }
    void show_users();
    void fill_the_players();
    void show_match_week(int week);
    void updateScores();


private:
    int current_week;
    vector<User *> users;
    vector<Player *> players;
    league league1;

    vector<Player> findingPost(int week, const string &post);

    static bool sortScore(User *a, User *b);
};

#endif