//
// Created by kamila on 16.05.18.
//

#include "Algo.h"

#include <vector>
#include <algorithm>
#include <iterator>
#include <string>

//TEST 1
void algo::CopyInto(const std::vector<int> &v, int n_elements, std::vector<int> *out){
    std::copy_n(v.begin(),n_elements,std::back_inserter(*out));
}


//TEST 2
struct EqualTo
{
    const int d;
    EqualTo(int d) : d(d) {}
    bool operator()(int n) const { return n==d; }
};

bool algo::Contains(const std::vector<int> &v, int element){
    return std::any_of(v.begin(),v.end(),EqualTo(element));

}
//TEST 3

void algo::InitializeWith(int initial_value, std::vector<int> *v){
    std::for_each((*v).begin(), (*v).end(), [initial_value](int &n){ n=initial_value; });
    //równie dobrze fill

}

std::vector<int> algo::InitializedVectorOfLength(int length, int initial_value){
    std::vector<int> x(length,initial_value);
    return x;

}
std::vector<std::string> algo::MapToString(const std::vector<double> &v){
    std::vector<std::string> x;
    std::transform(v.begin(), v.end(), std::back_inserter(x),
                   [](double c) -> std::string { return std::to_string(c); });
    return x;
}





//TEST 4