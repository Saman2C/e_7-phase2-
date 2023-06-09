//
// Created by 98902 on 6/8/2023.
//

#ifndef CA7_HANDLING_HPP
#define CA7_HANDLING_HPP
#include "libs.hpp"
#include "football_fantasy.hpp"
#include "league.hpp"
#include "match.hpp"

const int FIRST_LEN=19;
const string ADMIN_USER="admin";
const string ADMIN_PASSWORD="123456";

class Handling{
private:
    Football_Fantasy *pFantasy;
public:
    Handling(Football_Fantasy *pFantasy_);

    team *find_team(vector<team *> teams, string name);

    void seprate_names(string names, string post, vector<Player *> &players);

    void find_injured_players(string injured, team *team1, team *team2, int index_of_week);

    void showBestTeam();

    void show_team(Player &GK, vector<Player> &DF, Player &MD, Player &FW);

    void logout_user();

    void show_players();

    string &setPost(string &post);

    void show_match_week();

    void getHandling( string &word);

    void postHandling( string &word);

    vector<team *> seperate_name_of_teams(string name, vector<team *> teams);
    void sepreate_goals(string goals, int &team1_score, int &team2_score);

    void find_yellow_card_players(string yellow_card_players, team *team1, team *team2,int week);

    void set_players_scores(string player_scores, team *team1, team *team2, int index_week);

    void find_red_car_players(string red_card_players, team *team1, team *team2,int week);
    bool compareByLatter(string a,string b){
        return a<b;
    }

    vector<string> get_csv_files_in_folder(const string &folder_path);

    vector<week *> read_weeks_files(string folderPath, vector<team *> teams_);

    void signup_user();

    void signup_admin();

    void login_user();

    void sell_player( int num_week, User *current_user);

    void buy_player();

    void get_squad_information();

    void get_input();

    Handling();
};
#endif //CA7_HANDLING_HPP
