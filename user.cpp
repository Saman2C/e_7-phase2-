#include "user.hpp"

bool User::is_post_free(string post) {


    if (post == "goal_keeper" && num_goalkeepers == 0) {
        num_goalkeepers++;
        return true;
    } else {
        if (post == "deafender" && num_defenders < NUM_OF_DEFENDER) {
            num_defenders++;
            return true;
        } else if (post == "midfielder" && num_midfielder == 0) {
            num_midfielder++;
            return true;
        } else if (post == "forward" && num_forwards == 0) {
            num_forwards++;
            return true;
        } else
            return false;
    }
}

void User::increas_num_post(string post) {
    if (post == "goalkeeper") {
        num_goalkeepers++;
    } else if (post == "defender") {
        num_defenders++;
    } else if (post == "midfielder") {
        num_midfielder++;
    } else if (post == "forward") {
        num_forwards++;
    }
}

void User::decrease_num_post(string post) {
    if (post == "goal_keeper") {
        num_goalkeepers--;
    } else if (post == "deafender") {
        num_defenders--;
    } else if (post == "midfielder") {
        num_midfielder--;
    } else if (post == "forward") {
        num_forwards--;
    }
}

void User::add_player(Player *player) {
    if (!is_team_completed()) {
        players.push_back(player);
        increas_num_post(player->get_player_post());
        if(players.size()==5)
            is_completed_team=true;
        cout << "OK"<<endl;
    }
}

Player *User::find_player_of_user(string name_of_player) {
    for (auto player: players) {
        if (player->get_player_name() == name_of_player) {
            return player;
        }
    }
    return nullptr;
}

void User::delete_player(Player *player) {
    auto it = find(players.begin(), players.end(), player);
    players.erase(it);
    is_completed_team=false;
}

string User::get_name_of_player_base_post(string post, vector<Player *> &players_) {
    for (auto player: players_) {
        if (player->get_post() == post) {
            auto it = find(players_.begin(), players_.end(), player);
            players_.erase(it);
            return player->get_player_name();
        }
    }
    return "";
}

float User::calculate_team_score() {
    float total_score = 0;
    for (auto player: players) {
        total_score += player->get_score();
    }
    return total_score;
}

bool User::compare_my_class_ptr(Player *a, Player *b) {
    return a->get_player_name() < b->get_player_name();
}

void User::print_team_information() {
    vector<Player *> players_ = players;
    std::sort(players_.begin(), players_.end(), compare_my_class_ptr);
    cout << "fantasy_name: " << name_team << endl;
    cout << "Goalkeeper: " << get_name_of_player_base_post("goal_keeper", players_) << endl;
    cout << "Defender1: " << get_name_of_player_base_post("deafender", players_) << endl;
    cout << "Defender2: " << get_name_of_player_base_post("deafender", players_) << endl;
    cout << "Midfielder: " << get_name_of_player_base_post("midfielder", players_) << endl;
    cout << "Forward: " << get_name_of_player_base_post("forward", players_) << endl;
    cout << "Total Points: " << calculate_team_score() << endl;
}

float User::totalPoint() {
    float total_point = 0;
    for (auto player: players)
        total_point += player->totalScore();
    return total_point;
}

