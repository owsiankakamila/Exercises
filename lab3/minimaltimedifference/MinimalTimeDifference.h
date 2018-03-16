//
// Created by kamila on 16.03.18.
//

#ifndef JIMP_EXERCISES_MINIMALTIMEDIFFERENCE_H
#define JIMP_EXERCISES_MINIMALTIMEDIFFERENCE_H

#include <string>
#include <vector>

namespace minimaltimedifference {

    using ::std::string;
    unsigned int ToMinutes(std::string time_HH_MM);
    unsigned int MinimalTimeDifference(std::vector<std::string> times);
}


#endif //JIMP_EXERCISES_MINIMALTIMEDIFFERENCE_H
