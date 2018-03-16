//
// Created by kamila on 16.03.18.
//
#include <iostream>
#include <vector>
#include <regex>
#include "MinimalTimeDifference.h"


std::regex pattern {"(\\d{1,2}):(\\d{2})"};

unsigned int minimaltimedifference::ToMinutes(std::string time_HH_MM){

}
unsigned int minimaltimedifference::MinimalTimeDifference(std::vector<std::string> times){

    std::smatch matches;
    int hour1,hour2,hour_result;
    int minute1,minute2,minute_result;


    if (std::regex_match(times[0], matches, pattern)) {

        hour1=std::stoi(matches[1]);
        minute1=std::stoi(matches[2]);


    }
    if (std::regex_match(times[1], matches, pattern)) {
        hour2=std::stoi(matches[1]);;
        minute2=std::stoi(matches[2]);

    }

    //what hour is later






}