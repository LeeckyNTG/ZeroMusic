//
// Created by clover on 19-4-30.
//

#ifndef ZEROMUSIC_JAVALISTENER_H
#define ZEROMUSIC_JAVALISTENER_H


#include <cwchar>
#include "jni.h"
#include "AndroidLog.h"
#include <linux/stddef.h>

#define MAIN_THREAD 0
#define CHILD_THREAD 1

class WlCallJava {

public:
    _JavaVM *javaVM = NULL;
    JNIEnv *jniEnv = NULL;
    jobject jobj;

    jmethodID jmid_parpared;
public:
    WlCallJava(_JavaVM *javaVM, JNIEnv *env, jobject *obj);

    ~WlCallJava();

    /**
     * 1:主线程
     * 0：子线程
     * @param type
     * @param code
     * @param msg
     */
    void onCallParpared(int type);
};


#endif //ZEROMUSIC_JAVALISTENER_H
