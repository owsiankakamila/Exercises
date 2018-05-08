//
// Created by kamila on 25.04.18.
//

#ifndef JIMP_EXERCISES_PESEL_H
#define JIMP_EXERCISES_PESEL_H

#include <iostream>
#include <exception>
#include <regex>

namespace academia{
    class AcademiaDataValidationError:public std::invalid_argument{

    };

    class InvalidPeselChecksum{
        InvalidPeselChecksum(std::string);

    };
    class InvalidPeselLength{

    };
    class InvalidPeselCharacter{

    };


    class Pesel {
    public:
        Pesel(std::string pesel){
            try{
                validatePESEL(pesel);
            }catch{
                InvalidPeselChecksum();
            }
            catch{

            }




        }

        void validatePESEL(std::string pesel) const {

            if (pesel.size() != 11){
                throw InvalidPeselLength();
            }

            int checksum = 1*pesel[0] + 3*pesel[1] + 7*pesel[2] + 9*pesel[3] + 1*pesel[4] + 3*pesel[5] + 7*pesel[6] + 9*pesel[7] + 1*pesel[8] + 3*pesel[9] + 1*pesel[10];

            if ((checksum%10)!=0){
                throw InvalidPeselChecksum(pesel);
            }

            std::regex pattern (R"(\d{11})");

            if(!std::regex_match(pesel,pattern)){
                throw InvalidPeselCharacter();
            }




        }

    private:
        std::string pesel_;
    };


}



#endif //JIMP_EXERCISES_PESEL_H
