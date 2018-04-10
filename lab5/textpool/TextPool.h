//
// Created by kamila on 10.04.18.
//

#ifndef JIMP_EXERCISES_TEXTPOOL_H
#define JIMP_EXERCISES_TEXTPOOL_H
#include <initializer_list>
#include <string>
#include <experimental/string_view>
#include <set>
#include <vector>


namespace pool {
    class TextPool {
    public:
        //default constructor
        TextPool() {
                pool_;
        };


        //--- RULE OF FIVE ---

        //copy constructor
        TextPool(const TextPool &textPool)= delete;

        //copy assignment operator
        TextPool &operator=(const TextPool &textPool) = delete;

        //move constructor
        TextPool(TextPool &&textPool) noexcept ;

        //move assignment operator
        TextPool &operator=(TextPool &&textPool) noexcept ;

        //destructor
        ~TextPool();

        //----------------------

        // constructor list initialization
        //in vector?? sth with new?? to deallocate
        TextPool(const std::initializer_list<std::experimental::string_view> &elements) : pool_{elements} {

                // if there are many duplicates - leave only one
                std::set<std::experimental::string_view> s(pool_.begin(), pool_.end());
                pool_.assign(s.begin(), s.end());

        }

        std::experimental::string_view Intern(const std::string &str);

        size_t StoredStringCount() const;

    private:
        std::vector <std::experimental::string_view> pool_;

    };
}


#endif //JIMP_EXERCISES_TEXTPOOL_H
