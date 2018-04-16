//
// Created by kamila on 14.04.18.
//

#include "WordCounter.h"



datastructures::WordCounter::WordCounter(const std::initializer_list<datastructures::Word> &elements) {

    for (auto n: elements){
        if(not index_.empty()){
            auto search = index_.find(n);

            if (search != index_.end()) {
                ++search->second;
            }
            else{
                index_.insert ( std::pair<Word,Counts>(n,1));
            }
        }


        else{
            index_.insert ( std::pair<Word,Counts>(n,1));
        }
    }


}

datastructures::WordCounter datastructures::WordCounter::FromInputStream(std::istream &input) {
    return datastructures::WordCounter();
}

int datastructures::WordCounter::DistinctWords() const {
    //rozmiar kontenera
    return index_.size();
}

int datastructures::WordCounter::TotalWords() const {
    //przejdz po kolei po kontenerze i zlicze Counts
    int total=0;
    for (auto n:index_){
        total = total + n.second;
    }
    return total;
}

std::set<datastructures::Word> datastructures::WordCounter::Words() const {
    std::set<Word> words;
    for (auto n:index_){
        words.insert(n.first);
    }
    return words;
}



/*int &datastructures::WordCounter::operator[] (datastructures::Word word) {
    int x = 0;
    auto search = index_.find(word);


    if (search != index_.end()) {
        x = search->second;
    }

    return x;
}*/
datastructures::Counts &datastructures::WordCounter::operator[] (std::string word) {

    Counts x;
    auto search = index_.find(word);
    // index_ to std::map <Word,Counter>


    if (search != index_.end()) {
        return search->second;
    }
    return x;


}


std::ostream &datastructures::operator<<(std::ostream &output, const datastructures::WordCounter &counter) {
    std::map <Word,Counts> index = counter.index_;
    //sort

    //output

    return output;
}

