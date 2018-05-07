//
// Created by kamila on 30.04.18.
//

#include <string>
#include <regex>
#include "MovieSubtitles.h"


void moviesubs::MicroDvdSubtitles::ShiftAllSubtitlesBy(int mili, int framerate, std::stringstream *in,
                                                                    std::stringstream *out) {

    //set shift
    int rate_shift = mili / (1000 / framerate);
    std::regex whole_pattern{R"(((\{(\d+)\}\{(\d+)\}.+?(?=\\|$))(\\n)?)+)"};
    //WRONG REGEEEEEEEX

    std::string s= in->str();
    std::string output;
    std::smatch matched;
    int line =1;
    //not match
    if (!std::regex_match(s, whole_pattern)){
        throw InvalidSubtitleLineFormat();
    }
        //match

    else{
        while (std::regex_search (s,matched,line_pattern)) {
            //to int
            int start_time=std::stoi( matched.str(start));
            int stop_time=std::stoi( matched.str(stop));
            //set line

            // (2)<(1)?
            if(stop_time<start_time){
                throw SubtitleEndBeforeStart();//  (matched(0),line)
            }

            //make shift
            start_time+=rate_shift;
            stop_time+=rate_shift;

            //are negative??
            if(start_time<0||stop_time<0){
                throw NegativeFrameAfterShift();
            }
            else{//replace

                //int to string

                output += std::regex_replace (matched.str(0),std::regex(matched.str(start)),std::to_string(start_time));


            }
            s = matched.suffix().str();
            line++;
        }

    }



    //to stringstream
    out->str(output);



}