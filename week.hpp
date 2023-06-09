#ifndef WEEK_H
#define WEEK_H

#pragma once

#include "libs.hpp"
#include "match.hpp"
// #include "league.h"

class week
{
public:
    week(vector<match *> matches_)
    {
        matches = matches_;
    }
    vector<match *> get_match(){return matches;}

private:
    vector<match *> matches;
};

#endif