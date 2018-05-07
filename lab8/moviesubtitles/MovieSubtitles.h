//
// Created by kamila on 30.04.18.
//

#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H

#include <iostream>
#include <regex>
namespace moviesubs{



    class NegativeFrameAfterShift{
    public:

    };

    class SubtitleEndBeforeStart{
    public:
    };

    class InvalidSubtitleLineFormat {
    public:


    };




    class MovieSubtitles{
    public:
        virtual void ShiftAllSubtitlesBy (int mili, int framerate, std::stringstream *in, std::stringstream * out)=0;


    private:
        std::regex whole_pattern;
        std::regex line_pattern;
        int start;
        int stop;

    };

    class MicroDvdSubtitles: public MovieSubtitles{
    public:
        MicroDvdSubtitles(): whole_pattern{R"(((\{(\d+)\}\{(\d+)\}.+?(?=\\|$))(\\n)?)+)"}, line_pattern{R"(\{(\d+)\}\{(\d+)\}.+?(?=\\|$))"}, start(1), stop(2){}

        virtual void ShiftAllSubtitlesBy (int mili, int framerate, std::stringstream *in, std::stringstream * out) override ;

    private:
        std::regex whole_pattern;
        std::regex line_pattern;
        int start;
        int stop;

    };

    class SubRipSubtitles: public MovieSubtitles{
    public:

        virtual void ShiftAllSubtitlesBy (int mili, int framerate, std::stringstream *in, std::stringstream * out) override ;
    };






}


#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
