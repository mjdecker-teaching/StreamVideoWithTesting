/*
  Stream.hpp

  Include file for Stream class
*/

#ifndef STREAM_H
#define STREAM_H

#include "Video.hpp"

class Stream {
public:

    // constructor
    Stream(const Video& video, int occurrences);

    // number of times watched
    int viewings() const;

    // video rented
    Video video() const;

private:
    Video streamingVideo;
    int numViewed;
};

#endif
