//
// Created by owsikami on 13.04.18.
//

#ifndef JIMP_EXERCISES_STUDENTREPOSITORY_H
#define JIMP_EXERCISES_STUDENTREPOSITORY_H

#include <iostream>

namespace academia{
    class Student {
    public:
        Student();
        Student( std::string id, std::string fn, std::string ln, std::string program, StudyYear year){
            this->id =id;
            first_name=fn;
            last_name=ln;
            this->program=program;
            
            
        }
                
        
        std::string Id(){
            return id;
        }
        std::string FirstName(){
            return first_name;
        }
        std::string LastName(){
            return last_name;
        }
        std::string Program(){
            return program;
        }
        std::ostream &operator<<(std::ostream &input, StudyYear &year);
        std::istream &operator>>(std::istream &input, StudyYear &year);

    private:
        std::string id;
        std::string first_name;
        std::string last_name;
        std::string program;
        StudyYear year;

    };
    
    class StudyYear{
    public:
        StudyYear ():year_(0){}
        StudyYear (int x):year_(x){}
        
        StudyYear &operator++(){
            year_+=1;
            return *this;
        }

        StudyYear &operator--(){
            year_-=1;
            return *this;
        }
        
        std::ostream &operator<<(std::ostream &input, StudyYear &year);
        std::istream &operator>>(std::istream &input, StudyYear &year);
        
        
    private:
        int year_;
    };
}



#endif //JIMP_EXERCISES_STUDENTREPOSITORY_H
