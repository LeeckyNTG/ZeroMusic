//
// Created by clover on 19-4-30.
//

#include "WlFFmpeg.h"

WlFFmpeg::WlFFmpeg(WlCallJava *callJava, const char *url) {

    this->callJava = callJava;
    this->url = url;
}


void *decodeFFmpeg(void *data)
{
    WlFFmpeg *wlFFmpeg = (WlFFmpeg *) data;
    wlFFmpeg->decodeFFmpegThread();
    pthread_exit(&wlFFmpeg->decodeThread);
}


void WlFFmpeg::parpared() {
    pthread_create(&decodeThread,NULL,decodeFFmpeg,this);
}

void WlFFmpeg::decodeFFmpegThread() {

    av_register_all();
    avformat_network_init();
    pFormatCtx = avformat_alloc_context();



}
