//
// Created by kamila on 16.05.18.
//

#ifndef JIMP_EXERCISES_ALGO_H
#define JIMP_EXERCISES_ALGO_H
#include <vector>
#include <set>
#include <map>

namespace algo{
    //TEST 1
    void CopyInto(const std::vector<int> &v, int n_elements, std::vector<int> *out);//copy n elements from out to v

    //TEST 2
    bool Contains(const std::vector<int> &v, int element); //check if it contains element

    //TEST 3
    void InitializeWith(int initial_value, std::vector<int> *v); // replace every element in v with initial_value
    std::vector<int> InitializedVectorOfLength(int length, int initial_value); //create vector of length with initial_value
    std::vector<std::string> MapToString(const std::vector<double> &v); //change double to string

    //TEST 4
    bool ContainsKey(const std::map<std::string, int> &v, const std::string &key);
    bool ContainsValue(const std::map<std::string, int> &v, int value);
    std::set<std::string> Keys(const std::map<std::string, int> &m);
    std::vector<int> Values(const std::map<std::string, int> &m);

    //TEST 5
    std::map<std::string, int> DivisableBy(const std::map<std::string, int> &m,int divisor);

    //*******OTHER*******
    void SortInPlace(std::vector<int> *v);
    std::vector<int> Sort(const std::vector<int> &v);
    void SortByFirstInPlace(std::vector<std::pair<int,int>> *v);
    void SortBySecondInPlace(std::vector<std::pair<int,int>> *v);
    void SortByThirdInPlace(std::vector<std::tuple<int,int,int>> *v);

    std::string Join(const std::string &joiner, const std::vector<double> &v);
    int Sum(const std::vector<int> &v);
    int Product(const std::vector<int> &v);

    std::vector<std::string> RemoveDuplicates(const std::vector<std::string> &v);
    void RemoveDuplicatesInPlace(std::vector<std::string> *v);

    int HowManyShortStrings(const std::vector<std::string> &v, int inclusive_short_length);
}




#endif //JIMP_EXERCISES_ALGO_H
