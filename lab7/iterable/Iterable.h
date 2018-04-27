//
// Created by kamila on 19.04.18.
//

#ifndef JIMP_EXERCISES_ITERABLE_H
#define JIMP_EXERCISES_ITERABLE_H

#include <vector>
#include <iostream>
#include <memory>

namespace utility{


    class IterableIterator {
    public:
        virtual std::pair<int, std::string> Dereference() const=0;
        //=*it

        virtual IterableIterator &Next()=0;
        //++it

        virtual bool NotEquals(const std::unique_ptr<IterableIterator> &other) const=0;

        ~IterableIterator ()= default;

    private:

    };

    class ZipperIterator: public IterableIterator{
    public:
        explicit ZipperIterator(std::vector<int>::const_iterator left_begin,
                                std::vector<std::string>::const_iterator right_begin,
                                std::vector<int>::const_iterator left_end,
                                std::vector<std::string>::const_iterator right_end);

        virtual std::pair<int, std::string> Dereference() const override ;

        virtual IterableIterator &Next() override ;

        virtual bool NotEquals(const std::unique_ptr<IterableIterator> &other)const override ;

        ~ZipperIterator()= default;


    private:
        std::vector<int>::const_iterator left_begin_;
        std::vector<std::string>::const_iterator right_begin_;
        std::vector<int>::const_iterator left_end_;
        std::vector<std::string>::const_iterator right_end_;
    };


    class IterableIteratorWrapper{//opakowuje
    public:

        IterableIteratorWrapper(std::unique_ptr<IterableIterator> iterator);
        bool operator!=(const IterableIteratorWrapper &other)const;

        std::pair<int, std::string> operator*() const;
        IterableIteratorWrapper &operator++();

        std::unique_ptr<utility::IterableIterator> iterator_;
    };







    class Zipper{
    public:


    private:
    };


    class Enumerate {
        Enumerate(){}

    };
}



#endif //JIMP_EXERCISES_ITERABLE_H
