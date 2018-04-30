//
// Created by kamila on 30.04.18.
//

#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H

#include <iostream>
namespace moviesubs{
    class MicroDvdSubtitles{

        std::stringstream ShiftAllSubtitlesBy (int mili, int framerate, std::stringstream *in, std::stringstream * out);

    };
}


#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
