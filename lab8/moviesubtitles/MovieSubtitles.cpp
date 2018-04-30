//
// Created by kamila on 30.04.18.
//

#include "MovieSubtitles.h"

std::stringstream moviesubs::MicroDvdSubtitles::ShiftAllSubtitlesBy(int mili, int framerate, std::stringstream *in,
                                                                    std::stringstream *out) {
    int rate_shift = mili/(1000/framerate);

    //regex
    //throw invalid format
    //throw end before start

    //shift

    //throw negative frame after shift

    //return out

}
