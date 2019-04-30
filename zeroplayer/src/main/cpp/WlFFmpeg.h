//
// Created by clover on 19-4-30.
//

#ifndef ZEROMUSIC_WLFFMPEG_H
#define ZEROMUSIC_WLFFMPEG_H

#include <libavformat/avformat.h>
#include "WlCallJava.h"
#include "pthread.h"

class WlFFmpeg {

public:
    WlCallJava *callJava = NULL;
    const char *url = NULL;
    pthread_t decodeThread;
    AVFormatContext *pFormatCtx = NULL;

public:
    WlFFmpeg(WlCallJava *callJava, const char *url);
    ~WlFFmpeg();

    void parpared();
    void decodeFFmpegThread();
    void start();

};


#endif //ZEROMUSIC_WLFFMPEG_H
