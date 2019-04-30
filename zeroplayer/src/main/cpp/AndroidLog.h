//
// Created by clover on 19-4-30.
//

#ifndef ZEROMUSIC_ANDROIDLOG_H
#define ZEROMUSIC_ANDROIDLOG_H

#endif //ZEROMUSIC_ANDROIDLOG_H

#include <android/log.h>


#define LOG_DEBUG true

#define LOGI(FORMAT, ...) __android_log_print(ANDROID_LOG_INFO,"clover",FORMAT,##__VA_ARGS__);
#define LOGD(FORMAT, ...) __android_log_print(ANDROID_LOG_DEBUG,"clover",FORMAT,##__VA_ARGS__);
#define LOGE(FORMAT, ...) __android_log_print(ANDROID_LOG_ERROR,"clover",FORMAT,##__VA_ARGS__);
