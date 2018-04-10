//
// Created by kamila on 10.04.18.
//
#include <algorithm>
#include "TextPool.h"

using ::std::swap;

//move constructor - move(y)
pool::TextPool::TextPool(TextPool &&textPool)noexcept {
    pool_.clear();

    swap(pool_,textPool.pool_);

}

//move assignment operator - x=move(y)
pool::TextPool &pool::TextPool::operator=(pool::TextPool &&textPool)noexcept {
    //x=move(x)
    if (this == &textPool){
        return textPool;
    }

    //x=move(y)
    pool_.clear();
    pool_;

    swap(pool_,textPool.pool_);
    return *this;

}

//destructor
pool::TextPool::~TextPool() {


}

std::experimental::string_view pool::TextPool::Intern(const std::string &str) {

    // check if str is in pool_
    auto pos= std::find(std::begin(pool_), std::end(pool_), str);

    if (pos != std::end(pool_)) {
        auto index = std::distance(std::begin(pool_), pos);
        return pool_[index];
    }
        // if not:
    else
    {
        //string to string_view
        std::experimental::string_view str_v(str);
        //str_v to pool_
        pool_.push_back(str_v);
        return pool_[pool_.size()-1];


    }



    return std::experimental::string_view();
}

size_t pool::TextPool::StoredStringCount() const {

    if (pool_.empty()){
        return 0;
    }

    else{
        size_t count =0;
        for(auto n : pool_) {
            count++;
        }

        return count;

    }

}


