//
// Created by kamila on 16.05.18.
//

#ifndef JIMP_EXERCISES_ALGO_H
#define JIMP_EXERCISES_ALGO_H
#include <vector>
#include <algorithm>
#include <iterator>

namespace algo{
    void CopyInto(const std::vector<int> &v, int n_elements, std::vector<int> *out){//copy n elements from out to v
        std::copy_n(v.begin(),n_elements,std::back_inserter(*out));
    }
}


#endif //JIMP_EXERCISES_ALGO_H
