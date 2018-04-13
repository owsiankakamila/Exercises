//
// Created by kamila on 10.04.18.
//

#ifndef JIMP_EXERCISES_USEFUL_H
#define JIMP_EXERCISES_USEFUL_H


#include <algorithm>
#include <vector>
#include <set>

template <typename Type>
void remove_duplicate(std::vector<Type> vec) {
    std::sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
}

template <typename Type>
void remove_duplicate2(std::vector<Type> vec) {
    std::set<Type> s(vec.begin(), vec.end());
    vec.assign(s.begin(), s.end());
}

# See more at: http://stackoverflow.com/questions/1041620/most-efficient-way-to-erase-duplicates-and-sort-a-c-vector

void check() {
        // check if str is in pool_
        auto pos= std::find(std::begin(pool_), std::end(pool_), str);

        if (pos != std::end(pool_)) {
            auto index = std::distance(std::begin(pool_), pos);
            return pool_[index];
        }
};


#endif //JIMP_EXERCISES_USEFUL_H
