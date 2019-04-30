//
// Created by clover on 19-4-30.
//

#ifndef ZEROMUSIC_WLAUDIO_H
#define ZEROMUSIC_WLAUDIO_H


extern "C"
{
#include "libavcodec/avcodec.h"
};

class WlAudio {

public:
    int streamIndex = -1;
    AVCodecContext *avCodecContext = NULL;
    AVCodecParameters *codecpar = NULL;


public:
    WlAudio();
    ~WlAudio();

};



#endif //ZEROMUSIC_WLAUDIO_H
