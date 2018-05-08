//
// Created by kamila on 30.04.18.
//

#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H

#include <iostream>
#include <regex>
#include <exception>
namespace moviesubs{


    class SubtitlesException: public std::invalid_argument{
        SubtitlesException (int line_numb, std::string content);

    };

    class NegativeFrameAfterShift: public SubtitlesException{
    public:

    };

    class SubtitleEndBeforeStart: public SubtitlesException{
    public:
        SubtitleEndBeforeStart (int line_numb, std::string content){
            line_numb_=line_numb;
        }
        int LineAt(){}

    private:
        int line_numb_;
        std::string content_;


    };

    class InvalidSubtitleLineFormat: public SubtitlesException{
    public:
        InvalidSubtitleLineFormat (int line_numb, std::string content);


    };

    class OutOfOrderFrames : public SubtitlesException{
    public:


    };
    class MissingTimeSpecification : public SubtitlesException{
    public:


    };




    class MovieSubtitles{
    public:
        virtual void ShiftAllSubtitlesBy (int mili, int framerate, std::stringstream *in, std::stringstream * out)=0;


    };

    class MicroDvdSubtitles: public MovieSubtitles{
    public:
        MicroDvdSubtitles()= default;

        virtual void ShiftAllSubtitlesBy (int mili, int framerate, std::stringstream *in, std::stringstream * out) override ;


    };

    class SubRipSubtitles: public MovieSubtitles{
    public:

        virtual void ShiftAllSubtitlesBy (int mili, int framerate, std::stringstream *in, std::stringstream * out) override ;
    };






}


#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
