//
// Created by kamila on 17.04.18.
//

#ifndef JIMP_EXERCISES_ARRAYFILL_H
#define JIMP_EXERCISES_ARRAYFILL_H

#include <iostream>
#include <vector>
#include <random>

namespace arrays{

    //-------------------------------------------------------
    class ArrayFill {
    public:
        virtual int Value(int index) const =0;
    };

    void FillArray(size_t size, const ArrayFill &filler, std::vector<int> *v) {
        v->clear();
        v->reserve(size);
        for (size_t i = 0; i < size; i++) {
            v->emplace_back(filler.Value(i));
        }
    }

    //----------------------
    class UniformFill : public ArrayFill {
    public:
        UniformFill(int value = 0) : value_{value} {}
        virtual int Value(int index) const override;
    private:
        int value_;
    };



    int UniformFill::Value(int index) const {
        return value_;
    }
    //--------------------------------


    class IncrementalFill : public ArrayFill {
    public:
        IncrementalFill(int start, int step = 1) : start_{start}, step_{step} {}
        virtual int Value(int index) const override;
    private:
        int start_;
        int step_;
    };


    int IncrementalFill::Value(int index) const {
        return (start_+(index*step_));
    }

    //----------------------------


    class RandomFill : public ArrayFill {
    public:
        RandomFill() {}
        virtual int Value(int index) const override;
    private:
        int value_;
    };
// generator, distribiution????


    int RandomFill::Value(int index) const {

    }
    //--------------------------------

    class SquaredFill : public ArrayFill {
    public:
        SquaredFill(int value = 0) : value_{value} {}
        virtual int Value(int index) const override;
    private:
        int value_;
    };



    int SquaredFill::Value(int index) const {
        return value_;
    }
    //--------------------------------



}















#endif //JIMP_EXERCISES_ARRAYFILL_H
