#ifndef PLAYER_H
#define PLAYER_H

#pragma once
#include "libs.hpp"

const int NUM_WEEK = 19;

class Player
{
public:
    Player(string name_,
           string post_,
           bool red_card_,
           int yellow_card_,
           vector<float> scores_,
           vector<bool> injured_, int price_,
           vector<int> num_goals_,
           vector<int> num_assists_);
    bool isAvailable(int week);
    bool isInjured(int week);
    void set_injured(int index_week) { injured[index_week] = true; }

    void inc_yellow_card(int week) { yellow_card[week] = true; }

    int calc_yellow();

    void get_red_card(int week) { red_card[week] = true; }

    void set_score(int index_week, float score) { scores[index_week] = score; }

    string get_player_post() { return post; }

    string get_player_name() { return name; }
    void set_week(int week) { selected_week = week; }
    float get_score() { return scores[selected_week]; }
    string get_post() { return post; }
    float avg_score();
    float totalScore();
    void increase_goal(int week) { num_goals[week]++; }
    void decrease_goal(int week) { num_own_goals[week]++; }
    int get_price() { return price; }
    float convertRawScore(int raw_score);
    void increase_assist(int week) { num_assists[week]++; }
    void set_week_is_playing(int week) { is_playing[week] = true; }
    void set_post(string post_) { post = post_; }
    void set_location(string location_) { location = location_; }
    bool is_player_playing(int num_week) { return is_playing[num_week]; }
    int get_num_goal(int num_week) { return num_goals[num_week]; }
    int get_num_own_goal(int num_week) { return num_own_goals[num_week]; }
    int get_num_assist(int num_week) { return num_assists[num_week]; }
    float cal_player_score_base_match(int num_week, int GF, int GA);

private:
    int price;
    string name;
    string post;
    string location;
    vector<bool> red_card;
    vector<bool> yellow_card;
    vector<float> scores;
    vector<bool> injured;
    vector<int> num_goals;
    vector<int> num_own_goals;
    vector<int> num_assists;
    vector<bool> is_playing;
    int selected_week;

    int GoalkeeperScore(int GA, int score) const;

    int defenderScore(int num_week, int GA, int score);

    int midfielderScore(int num_week, int GA, int score);

    int forwardScore(int num_week, int GF, int score);
};

#endif