
#include "handling.hpp"
#include "libs.hpp"
#include "football_fantasy.hpp"
#include "league.hpp"
#include "match.hpp"

void Handling::find_injured_players(string injured, team *team1, team *team2, int index_of_week)
{
    stringstream ss(injured);
    string word;
    while (getline(ss, word, ';'))
    {
        for (auto team_player : team1->get_team_players())
        {
            if (team_player->get_player_name() == word)
            {
                team_player->set_injured(index_of_week);
            }
        }
        for (auto team_player : team2->get_team_players())
        {
            if (team_player->get_player_name() == word)
            {
                team_player->set_injured(index_of_week);
            }
        }
    }
}

void Handling::logout_user()
{
    pFantasy->logout();
}

void Handling::show_team(Player &GK, vector<Player> &DF, Player &MD, Player &FW)
{
    cout << "team of the week:" << endl;
    cout << "GoalKeeper: " << GK.get_player_name() << " | score: " << GK.get_score() << endl;
    cout << "Defenders1: " << DF[0].get_player_name() << " | score: " << DF[0].get_score() << endl;
    cout << "Defenders2: " << DF[1].get_player_name() << " | score: " << DF[1].get_score() << endl;
    cout << "Midfielder: " << MD.get_player_name() << " | score: " << MD.get_score() << endl;
    cout << "Forward: " << FW.get_player_name() << " | score: " << FW.get_score() << endl;
}

void Handling::signup_admin()
{
    string username = ADMIN_USER;
    string password = ADMIN_PASSWORD;
    pFantasy->make_admin(username, password);
}

void Handling::sell_player(int num_week, User *current_user)
{
    string name;
    Player *player;
    cin >> name >> name;
    getline(cin, name);
    name = name.substr(1);
    player = pFantasy->current_user->find_player_of_user(name);
    if (player == NULL)
    {
        cout << "Not Found" << endl;
    }
    else if (!(pFantasy->can_sell()) ||
             current_user->get_num_of_sell_in_week(num_week) >= 2)
    {
        cout << "Premission Denied" << endl;
    }
    else
    {
        current_user->delete_player(player);
        current_user->decrease_num_post(player->get_post());
        cout << "OK" << endl;
    }
}

void Handling::showBestTeam()
{
    int week = pFantasy->get_week();
    string trash, numb;
    getline(cin, trash);
    stringstream ss(trash);
    ss >> trash >> trash;
    if (!(ss >> numb))
        week = pFantasy->get_week();
    else
        week = stoi(numb);

    week--;
    if (week > NUM_WEEK || week < 0)
    {
        cout << "Bad Request" << endl;
        return;
    }
    Player GK = pFantasy->sortGKByScore(week)[0];
    vector<Player> DF = pFantasy->sortDFByScore(week);
    Player MD = pFantasy->sortMDByScore(week)[0];
    Player FW = pFantasy->sortFWByScore(week)[0];
    show_team(GK, DF, MD, FW);
}

void Handling::postHandling(string &word)
{
    cin >> word;
    if (word == "signup")
    {
        signup_user();
    }
    else if (word == "login")
    {
        login_user();
    }
    else if (word == "register_admin") /*what is diffrent between admin and other user*/
    {
        login_user();
    }
    else if (word == "logout")
    {
        logout_user();
    }
    else if (word == "sell_player")
    {
        sell_player(pFantasy->get_week(), pFantasy->current_user);
    }
    else if (word == "buy_player")
    {
        buy_player();
    }
    else if (word == "close_transfer_window")
    {
        pFantasy->close_transfer_window();
    }
    else if (word == "open_transfer_window")
    {
        pFantasy->open_transfer_window();
    }
    else if (word == "pass_week")
    {
        pFantasy->increase_num_week();
        cout << "OK" << endl;
    }
}

void Handling::sepreate_goals(string goals, int &team1_score, int &team2_score)
{
    int colon_index;
    string team1_score_st;
    string team2_score_st;
    colon_index = goals.find(':');
    team1_score_st = goals.substr(0, colon_index);
    team1_score = stoi(team1_score_st);
    team2_score_st = goals.substr(colon_index + 1);
    team2_score = stoi(team2_score_st);
}

team *Handling::find_team(vector<team *> teams, string name)
{
    for (team *teamm : teams)
    {
        if (teamm->get_team_name() == name)
        {
            return teamm;
        }
    }
    return NULL;
}

void Handling::find_yellow_card_players(string yellow_card_players, team *team1, team *team2, int week)
{
    stringstream ss(yellow_card_players);
    string word;
    while (getline(ss, word, ';'))
    {
        for (auto team_player : team1->get_team_players())
        {
            if (team_player->get_player_name() == word)
            {
                team_player->inc_yellow_card(week);
            }
        }
        for (auto team_player : team2->get_team_players())
        {
            if (team_player->get_player_name() == word)
            {
                team_player->inc_yellow_card(week);
            }
        }
    }
}

void Handling::set_players_scores(string player_scores, team *team1, team *team2, int index_week)
{
    stringstream ss(player_scores);
    string word;
    while (getline(ss, word, ';'))
    {
        int index_colon = word.find(':');
        float score = stof(word.substr(index_colon + 1));
        word = word.substr(0, index_colon);

        for (auto team_player : team1->get_team_players())
        {
            if (team_player->get_player_name() == word)
            {
                team_player->set_score(index_week, score);
            }
        }
        for (auto team_player : team2->get_team_players())
        {
            if (team_player->get_player_name() == word)
            {
                team_player->set_score(index_week, score);
            }
        }
    }
}

void Handling::find_red_car_players(string red_card_players, team *team1, team *team2, int week)
{
    stringstream ss(red_card_players);
    string word;
    vector<int> scores;
    while (getline(ss, word, ';'))
    {
        for (auto team_player : team1->get_team_players())
        {
            if (team_player->get_player_name() == word)
            {
                team_player->get_red_card(week);
            }
        }
        for (auto team_player : team2->get_team_players())
        {
            if (team_player->get_player_name() == word)
            {
                team_player->get_red_card(week);
            }
        }
    }
}

void Handling::signup_user()
{
    string user_team_name, password, trash;
    cin >> trash >> trash >> user_team_name >> trash >> password;
    if (pFantasy->is_team_used_before(user_team_name))
    {
        cout << "Bad Request" << endl;
    }
    else
    {
        pFantasy->make_new_user(user_team_name, password);
    }
}

void Handling::login_user()
{
    string user_team_name, entered_password, trash;
    cin >> trash >> trash >> user_team_name >> trash >> entered_password;
    pFantasy->enter_user(user_team_name, entered_password);
}

vector<string> Handling::get_csv_files_in_folder(const string &folder_path)
{
    vector<string> file_name;
    for (int i = 1; i <= NUM_WEEK; ++i)
    {
        string path = "week_" + to_string(i) + ".csv";
        file_name.push_back(path);
    }
    return file_name;
}

void Handling::getHandling(string &word)
{
    cin >> word;
    if (word == "team_of_the_week")
    {
        showBestTeam();
    }
    else if (word == "squad")
    {
        get_squad_information();
    }
    else if (word == "players")
    {
        show_players();
    }
    else if (word == "league_standings")
    {
        pFantasy->show_table();
    }
    else if (word == "league_standings")
    {
        pFantasy->show_users();
    }
    else if (word == "matches_result_league")
    {
        show_match_week();
    }
    else if (word == "users_ranking")
    {
        pFantasy->show_users();
    }
}

void Handling::buy_player()
{
    string trash, player_name;
    cin >> trash >> trash;
    getline(cin, player_name);
    player_name = player_name.substr(1);
    Player *player = pFantasy->find_player(player_name);
    if (player != NULL)
    {
        if (pFantasy->can_sell_player)
        {
            if (player->isAvailable(pFantasy->get_week()))
            {
                if (pFantasy->current_user->is_post_free(player->get_player_post()))
                {
                    pFantasy->current_user->add_player(player);
                }
                else
                {
                    cout << "Bad Request" << endl;
                }
            }
            else
            {
                cout << "The player is not available for next week" << endl;
            }
        }
        else
        {
            cout << "Premission Denied" << endl;
        }
    }
    else
    {
        cout << "Not Found" << endl;
    }
}

void Handling::get_squad_information()
{
    string trash, name_of_team;
    User *user;
    cin >> trash;
    getline(cin, name_of_team);
    if (name_of_team == "")
    {
        if (pFantasy->current_user->is_team_completed())
        {
            pFantasy->current_user->print_team_information();
        }
        else
        {
            cout << "Empty" << endl;
        }
    }
    else
    {
        name_of_team = name_of_team.substr(FIRST_LEN);
        user = pFantasy->find_user_by_name(name_of_team);
        if (user == NULL)
        {
            cout << "Not Found" << endl;
        }
        else
        {
            if (user->is_team_completed())
            {
                user->print_team_information();
            }
            else
            {
                cout << "Empty" << endl;
            }
        }
    }
}

void Handling::get_input()
{
    string input, word;
    cin >> input;
    if (input == "POST")
    {
        postHandling(word);
    }
    else if (input == "GET")
    {
        getHandling(word);
    }
    else if (input == "PUT")
    {
    }
    else if (input == "DELETE")
    {
    }
    else
    {
        cout << "Bad Request" << endl;
    }
}

void Handling::show_players()
{
    string team_name, post, rank, trash, line;
    bool hasPost, hasRank;
    getline(cin, line);
    stringstream ss(line);
    ss >> trash >> trash >> team_name;
    if (ss >> post)
    {
        hasPost = true;
        post = setPost(post);
    }
    if (ss >> rank)
        hasRank = true;
    if (hasRank)
        pFantasy->show_ranked_team_players(team_name, post);
    else
        pFantasy->show_team_players(team_name, post);
}

string &Handling::setPost(string &post)
{
    if (post == "gk")
        post = "goal_keeper";
    if (post == "df")
        post = "deafender";
    if (post == "md")
        post = "midfielder";
    if (post == "fw")
        post = "forward";
    return post;
}

void Handling::show_match_week()
{
    int week;
    string line, num, trash;
    getline(cin, line);
    stringstream ss(line);
    ss >> trash >> trash;
    if (!(ss >> num))
        week = pFantasy->get_week();
    else
        week = stoi(num);
    pFantasy->show_match_week(week);
}

vector<team *> Handling::seperate_name_of_teams(string name, vector<team *> teams)
{
    int colon_index;
    vector<team *> teams_adr(2);
    string team1_name;
    string team2_name;
    colon_index = name.find(':');
    team1_name = name.substr(0, colon_index);
    team2_name = name.substr(colon_index + 1);
    teams_adr[0] = (find_team(teams, team1_name));
    teams_adr[1] = (find_team(teams, team2_name));
    return teams_adr;
}

Handling::Handling(Football_Fantasy *pFantasy_)
{
    pFantasy = pFantasy_;
}

Handling::Handling() {}
