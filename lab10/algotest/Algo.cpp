//
// Created by kamila on 16.05.18.
//

#include "Algo.h"

#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <sstream>

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

    std::fill((*v).begin(), (*v).end(), initial_value);


}

std::vector<int> algo::InitializedVectorOfLength(int length, int initial_value){
    std::vector<int> x(length,initial_value);
    return x;

}
std::vector<std::string> algo::MapToString(const std::vector<double> &v){
    std::vector<std::string> x;
    std::transform(v.begin(), v.end(), std::back_inserter(x), //iterator kotry robi push na koniec
                   [](double c) -> std::string { return std::to_string(c); });
                    //[](int current {return to_string}
    // [] grupa przechwytajaca
    // [v] (int x, int y){return x*y*z)
    //jesli v przez referencje to mozna modyfikowac przy zew kontekscie
    return x;
}


//TEST 4
std::set<std::string> algo::Keys(const std::map<std::string, int> &m){
    std::set<std::string> x;//do lambdy tefai para string int; set nie ma pushback wiec backinsertern nie dziala ale dziala inserter(set,iterator do poczatku)
    std::transform(m.begin(), m.end(), std::inserter(x,x.begin()),
                   [](auto s) { return s.first;});
    return x;

}


//TEST 5
std::vector<int> algo::DivisableBy(const std::vector<int> &m,int divisor){
    std::vector<int> divisabled;
    std::copy_if(m.begin(), m.begin(), std::back_inserter(divisabled), [divisor](auto i) {return i%divisor ==0;});
    return divisabled;
}


//OTHERS
std::string algo::Join(const std::string &joiner, const std::vector<double> &v){
    std::stringstream x;
    std::copy(v.begin(), v.begin(), std::ostream_iterator<double>(x,joiner.c_str()));
    return x.str();
}


int algo::Sum(const std::vector<int> &v){
    return  std::accumulate(v.begin(), v.end(), 0);
}
int algo::Product(const std::vector<int> &v){
    return std::accumulate(v.begin(), v.end(), 1, std::multiplies<int>());
}

std::vector<std::string> algo::RemoveDuplicates(const std::vector<std::string> &v){
    std::vector<std::string> x=v;

    std::sort(x.begin(), x.end());

    auto last=std::unique(x.begin(), x.end());
    x.erase(last, x.end());
    return x;
}

void algo::RemoveDuplicatesInPlace(std::vector<std::string> *v){
    std::sort((*v).begin(), (*v).end());
    auto last=std::unique((*v).begin(), (*v).end());
    (*v).erase(last, (*v).end());
}


