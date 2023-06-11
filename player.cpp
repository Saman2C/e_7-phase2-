#include "player.hpp"

Player::Player(string name_, string post_, bool red_card_, int yellow_card_, vector<float> scores_,
               vector<bool> injured_, int price_, vector<int> num_goals_,
               vector<int> num_assists_)
{
    {
        name = name_;
        post = post_;
        vector<bool> red(NUM_WEEK, false);
        red_card = red;
        vector<bool> yellow(NUM_WEEK, false);
        yellow_card = yellow;
        is_playing = yellow;
        scores = scores_;
        injured = injured_;
        selected_week = 0;
        price = price_;
        // num_assists = num_assists_;
        // num_goals = num_goals_;
        vector<int> goals(NUM_WEEK, 0);
        vector<int> assist(NUM_WEEK, 0);
        num_goals = goals;
        num_assists = assist;
    }
}

bool Player::isAvailable(int week)
{
    if (week >= 2)
        if (red_card[week - 2] || (calc_yellow() != 0 && calc_yellow() % 3 == 0) || isInjured(week))
        {
            for (int i = 0; i < week; ++i)
            {
                yellow_card[i] = false;
            }
            return false;
        }
    return true;
}

bool Player::isInjured(int week)
{
    if (week < 4)
        return false;
    return (injured[week - 2] && injured[week - 3] && injured[week - 4]);
}

float Player::avg_score()
{
    float total = 0;
    float num = 0;
    for (auto score : scores)
    {
        total += score;
        if (score != 0)
            num++;
    }
    if (num != 0)
        return total / num;
    return 0.0;
}

float Player::totalScore()
{
    float total = 0;
    for (auto score : scores)
        total += score;
    return total;
}

int Player::calc_yellow()
{
    int yellows = 0;
    for (auto yellow : yellow_card)
        if (yellow)
            yellows++;
    return yellows;
}

/*set base scores in constructor*/

int Player::cal_player_score_base_match(int num_week, int GF, int GA)
{
    int score = 0;
    if (num_own_goals[num_week] > 0)
    {
        score -= 3;
    }
    if (post == "goal_keeper")
    {
        if (GA == 0)
        {
            score += 5;
        }
        else
        {
            score -= (GA * 1);
        }
    }
    else if (post == "deafender")
    {
        if (GA == 0)
        {
            score += 2;
        }
        score += (num_goals[num_week] * 4);
        score += (num_assists[num_week] * 3);
    }
    else if (post == "midfielder")
    {
        if (GA == 0)
        {
            score += 1;
        }
        score += (num_goals[num_week] * 3);
        score += (num_assists[num_week] * 2);
    }
    else if (post == "forward")
    {
        if (GF == 0)
        {
            score += -1;
        }
        score += (num_goals[num_week] * 3);
        score += (num_assists[num_week] * 1);
    }
    return score;
}

/*It has to be fixed*/
int Player::calcScore()
{
    if (post == "goal_keeper")
    {
    }
    else if (post == "deafender")
    {
    }
    else if (post == "midfielder")
    {
    }
    else if (post == "forward")
    {
    }
    return 0;
}
