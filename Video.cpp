/*
  Video.cpp

  Definition file for Video class
*/

#include "Video.hpp"

// constructor
Video::Video(const std::string& title, int type, int hours, int minutes, int episodes)
    : videoTitle(title), videoType(type), lengthHours(hours), lengthMinutes(minutes), numEpisodes(episodes)
{ }

// video title
std::string Video::title() const {

    return videoTitle;
}

// video type
int Video::type() const {

    return videoType;
}

// video length in hours
int Video::hours() const {

    return lengthHours;
}

// video length in minutes
int Video::Minutes() const {

    return lengthMinutes;
}

// number of episodes
int Video::episodes() const {

    // special case as movies do not have episodes
    if (videoType == Video::MOVIE)
        return 0;

    return numEpisodes;
}

// set video length
void Video::setLength(int hours, int minutes) {

    this->lengthHours = hours;
    this->lengthMinutes = minutes;
}
