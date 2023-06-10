#include "libs.hpp"
#include "football_fantasy.hpp"
#include "league.hpp"
#include "match.hpp"
#include "handling.hpp"

float set_player_price(string name)
{
    int index_colon = name.find(':');
    float score = stof(name.substr(index_colon + 1, name.length() - 1));
    return score;
}

void seprate_names(string names, string post, vector<Player *> &players)
{
    stringstream ss(names);
    string word;
    vector<float> scores(NUM_WEEK,0);
    vector<bool> injured(NUM_WEEK,false);
    vector<int> num_goals_(NUM_WEEK,0);
    vector<int> num_assists_(NUM_WEEK,0);
    while (getline(ss, word, ';'))
    {
        int price = set_player_price(word);
        word=word.substr(0,word.find(':'));
        players.push_back(new Player(word, post, false, 0, scores, injured, price, num_goals_, num_assists_));
    }
}

    vector<team *> read_input_league_files(string directory_location)
{
    string file_location = directory_location + "/premier_league.csv";
    ifstream file(file_location);
    string line, field;
    getline(file, line);
    vector<team *> teams;
    vector<Player *> total_players;
    vector<int> GF;
    vector<int> GA;
    vector<int> scores;
    while (getline(file, line))
    {
        stringstream ss(line);
        vector<Player *> players;
        getline(ss, field, ',');
        string Team_name = field;
        getline(ss, field, ',');
        string Goal_keeper = field;
        seprate_names(Goal_keeper, "goal_keeper", players);
        getline(ss, field, ',');
        string Deafender = field;
        seprate_names(Deafender, "deafender", players);
        getline(ss, field, ',');
        string Midfielder = field;
        seprate_names(Midfielder, "midfielder", players);
        getline(ss, field);
        string Forwards = field;
        seprate_names(Forwards, "forward", players);

        teams.push_back(new team(Team_name, players, GF, GA, scores));
    }
    file.close();
    return teams;
}

vector<week *> read_weeks_files(string folderPath, vector<team *> teams_, Handling *pFantasy)
{
    int num_week = 0;
    vector<week *> weeks;
    vector<string> csv_files = pFantasy->get_csv_files_in_folder(folderPath);
    for (const auto &csv_file : csv_files)
    {
        ifstream file(folderPath + "/" + csv_file);
        string line, field;
        vector<match *> matches;
        getline(file, line);
        while (getline(file, line))
        {
            stringstream ss(line);
            team *team1;
            team *team2;
            int goal_team_1;
            int goal_team_2;
            getline(ss, field, ',');
            string matchh = field;
            vector<team *> adr = pFantasy->seperate_name_of_teams(matchh, teams_);
            team1 = adr[0];
            team2 = adr[1];
            getline(ss, field, ',');
            string result = field;
            pFantasy->sepreate_goals(result, goal_team_1, goal_team_2);
            getline(ss, field, ',');
            string injured = field;
            pFantasy->find_injured_players(injured, team1, team2, num_week);
            getline(ss, field, ',');
            string yellow_cards = field;
            pFantasy->find_yellow_card_players(yellow_cards, team1, team2, num_week);
            getline(ss, field, ',');
            string red_cards = field;
            pFantasy->find_red_car_players(red_cards, team1, team2, num_week);
            getline(ss, field, ',');
            string assist = field;
            pFantasy->assist_handler(assist, teams_, num_week);
            getline(ss, field, ',');
            string player_team1 = field;
            pFantasy->find_players_playing(player_team1, teams_, num_week);
            getline(ss, field, ',');
            string player_team2 = field;
            pFantasy->find_players_playing(player_team2, teams_, num_week);

            matches.push_back(new match(team1, team2, goal_team_1, goal_team_2, num_week));
        }
        weeks.push_back(new week(matches));
        num_week++;
        file.close();
    }
    return weeks;
}

int main()
{
    vector<team *> teams_;
    vector<week *> weeks_;
    string assets_folder = "data";
    string path_folder = "data/weeks_stats";
    Handling handle2;
    teams_ = read_input_league_files(assets_folder);
    weeks_ = read_weeks_files(path_folder, teams_, &handle2);
    league league1(teams_, weeks_);
    Football_Fantasy football_fantasy(league1);
    football_fantasy.fill_the_players();
    football_fantasy.updateScores();
    Handling handle(&(football_fantasy));
    handle.signup_admin();
    while (true)
    {
        handle.get_input();
    }
    return 0;
}