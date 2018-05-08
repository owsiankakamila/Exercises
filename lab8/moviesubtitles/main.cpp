//
// Created by kamila on 30.04.18.
//

#include <iostream>
#include <regex>

int main(){

    //problem to new line bo string od razu cyta \n jako newline i trzeba zmusic aby w regexie go przeczytal
    std::regex whole_pattern(R"((\{(\d+)\}\{(\d+)\}.*\n?)+)");
    std::regex line_pattern(R"(\{(\d+)\}\{(\d+)\}.*\n?)");

    if (std::regex_match ("{0}{100}{y:b}bold text\n{144}{299}{s:12}12 Font used\n{280}{350}{c:$0000FF}Hello!\n{1000}{1050}Multi|Line|Text\n", whole_pattern ))
        std::cout << "ORIGIN matched\n";
    if (std::regex_match ("{0}{250}TEXT\n", line_patterd ))
        std::cout << "string literal matched\n";

    return 0;
}