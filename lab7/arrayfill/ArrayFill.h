//
// Created by kamila on 17.04.18.
//

#ifndef JIMP_EXERCISES_ARRAYFILL_H
#define JIMP_EXERCISES_ARRAYFILL_H

#include <iostream>
#include <vector>
#include <random>
#include <memory>

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
        RandomFill(std::unique_ptr<std::default_random_engine> generator, std::unique_ptr<std::uniform_int_distribution<int>> distribution):generator_{move(generator)}, distribution_{move(distribution)} {}
        virtual int Value(int index) const override;
    private:
        std::unique_ptr<std::default_random_engine> generator_;
        std::unique_ptr<std::uniform_int_distribution<int>> distribution_;

    };
// generator, distribiution????


    int RandomFill::Value(int index) const {
    return (*distribution_)(*generator_);
    }
    //--------------------------------

    class SquaredFill : public ArrayFill {
    public:
        SquaredFill(int a = 1, int b = 0) :a_{a}, b_{b} {}
        virtual int Value(int index) const override;
    private:
        int a_;
        int b_;
    };



    int SquaredFill::Value(int index) const {
        return (a_*(index*index)+b_);
    }
    //--------------------------------



}















#endif //JIMP_EXERCISES_ARRAYFILL_H
