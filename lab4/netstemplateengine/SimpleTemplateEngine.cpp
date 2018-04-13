//
// Created by kamila on 23.03.18.
//

#include <iostream>
#include <string>
#include <unordered_map>
#include <regex>
#include "SimpleTemplateEngine.h"


nets::View::View(std::string str) {
 str_ = str;
}

std::string nets::View::Render(const std::unordered_map <std::string, std::string> &model) const {
    std::string str = str_;
    std::string repl;
    size_t found;
    for( const auto& n : model ) {
        repl = "{{"+n.first+"}}";

        while ((found = str.find(repl))!= std::string::npos){
            str.replace(found, repl.length(), n.second);
        }
    }

     std::regex pattern ("\\{\\{\\w*\\}\\}");

    str= std::regex_replace(str,pattern,"");


    return str;

}
