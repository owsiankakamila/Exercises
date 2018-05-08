//
// Created by kamila on 30.04.18.
//

#include <iostream>
#include <regex>

int main(){

    //problem to new line bo string od razu cyta \n jako newline i trzeba zmusic aby w regexie go przeczytal
    std::regex whole_pattern(R"((\{(\d+)\}\{(\d+)\}.*\n?)+)");
    std::regex line_pattern(R"(\{(\d+)\}\{(\d+)\}.*\n?)");

    if (std::regex_match ("{10}{250}TEXT\n{260}{300}NEWLINE\n", whole_pattern ))
        std::cout << "ORIGIN matched\n";


    return 0;
}