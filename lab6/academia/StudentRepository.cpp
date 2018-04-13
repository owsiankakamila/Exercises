//
// Created by owsikami on 13.04.18.
//

#include "StudentRepository.h"

std::ostream &academia::StudyYear::operator<<(std::ostream &input, academia::StudyYear &year) {
    input<<year_;
    return input;
    
}

std::istream &academia::StudyYear::operator>>(std::istream &input, academia::StudyYear &year) {
    input>>year_;
    return input;
}
