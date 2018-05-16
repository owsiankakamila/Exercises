//
// Created by kamila on 16.05.18.
//

#include "Algo.h"

#include <vector>
#include <utility>


void algo::CopyInto(const std::vector<int> &v, int n_elements, std::vector<int> *out){
    std::copy_n(v.begin(),n_elements,std::back_inserter(*out));
}

struct EqualTo
{
    const int d;
    EqualTo(int d) : d(d) {}
    bool operator()(int n) const { return n==d; }
};

bool algo::Contains(const std::vector<int> &v, int element){
    return std::any_of(v.begin(),v.end(),EqualTo(element));

}


