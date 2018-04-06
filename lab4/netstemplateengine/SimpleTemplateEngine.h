//
// Created by kamila on 23.03.18.
//

#ifndef JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#define JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H

#include <unordered_map>>


namespace nets {
    class View{
    public:
        View(std::string str);

        View();

        std::string Render(const std::unordered_map <std::string, std::string> &model) const;
    private:
        std::string str_;


    };
}

#endif //JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
