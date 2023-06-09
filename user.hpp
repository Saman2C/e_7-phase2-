#ifndef USER
#define USER

#pragma once

#include "libs.hpp"
#include "player.hpp"

const int NUM_OF_DEFENDER=2;

class User
{
public:
    User(string name_team_,
         string password_)
    {
        vector<int> num_sell(NUM_WEEK, 0);
        num_of_sell_in_each_week = num_sell;
        name_team = name_team_;
        password = password_;
        adminity = false;
        num_defenders=0;
        num_forwards=0;
        num_goalkeepers=0 ;
        num_midfielder=0;
        is_completed_team=false;
    }

    string say_name() { return name_team; }
    string get_password() { return password; }
    bool isAdmin() { return adminity; }
    void set_admin() { adminity = true; }
    bool is_team_completed() { return is_completed_team; }
    void add_player(Player *player);
    void increas_num_post(string post);
    void decrease_num_post(string post);
    bool is_post_free(string post);
    void delete_player(Player *player);
    Player *find_player_of_user(string name_of_player);
    void print_team_information();
    string get_name_of_player_base_post(string post, vector<Player *> &players_);
    string get_name(){return name_team;}
    static bool compare_my_class_ptr(Player *a, Player *b);
    float calculate_team_score();
    float totalPoint();
    int get_num_of_sell_in_week(int num_week)
    {
        return num_of_sell_in_each_week[num_week];
    }

private:
    vector<int> num_of_sell_in_each_week;
    vector<Player *> players;
    vector<int> weekly_scores;
    string name_team;
    string password;
    int num_goalkeepers, num_defenders, num_midfielder, num_forwards;
    bool is_completed_team;
    bool adminity;
};

#endif