//
// Created by kamila on 19.04.18.
//

#include "Iterable.h"

utility::ZipperIterator::ZipperIterator(std::vector<int>::const_iterator left_begin,
                                        std::vector<std::string>::const_iterator right_begin,
                                        std::vector<int>::const_iterator left_end,
                                        std::vector<std::string>::const_iterator right_end) {
    left_begin_=left_begin;
    right_begin_ = right_begin;
    left_end_=left_end;
    right_end_=right_end;

}

std::pair<int, std::string> utility::ZipperIterator::Dereference() const {

    return {*left_begin_,*right_begin_};
}

utility::IterableIterator &utility::ZipperIterator::Next() {
    ++left_begin_;
    ++right_begin_;
    return *this;
}

bool utility::ZipperIterator::NotEquals(const std::unique_ptr<utility::IterableIterator> &other)const {
    //niekoniecznie ale test ok
    return Dereference()!=other->Dereference();



}


utility::IterableIteratorWrapper::IterableIteratorWrapper(std::unique_ptr<utility::IterableIterator> iterator) {
    iterator_=move(iterator);

}

bool utility::IterableIteratorWrapper::operator!=(const utility::IterableIteratorWrapper &other) const {
    return iterator_->NotEquals(other.iterator_);
}

std::pair<int, std::string> utility::IterableIteratorWrapper::operator*() const {
    return iterator_->Dereference();
}

utility::IterableIteratorWrapper &utility::IterableIteratorWrapper::operator++() {
    iterator_->Next();
    return *this;
}
