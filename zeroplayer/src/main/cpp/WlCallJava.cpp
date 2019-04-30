//
// Created by clover on 19-4-30.
//

#include "WlCallJava.h"

WlCallJava::WlCallJava(_JavaVM *javaVM, JNIEnv *env, jobject *obj) {

    this->javaVM = javaVM;
    this->jniEnv = env;
    this->jobj = *obj;
    this->jobj = env->NewGlobalRef(jobj);

    jclass clz = env->GetObjectClass(jobj);
    if (!clz) {
        if (LOG_DEBUG){
            LOGE("get jclass error!");
        }
        return;
    }
    jmid_parpared = env->GetMethodID(clz, "onCallParpared", "()V");
}

void WlCallJava::onCallParpared(int type) {
    if(type == MAIN_THREAD)
    {
        jniEnv->CallVoidMethod(jobj, jmid_parpared);
    }
    else if(type == CHILD_THREAD)
    {
        JNIEnv *jniEnv;
        if(javaVM->AttachCurrentThread(&jniEnv, 0) != JNI_OK)
        {
            if(LOG_DEBUG)
            {
                LOGE("get child thread jnienv worng");
            }
            return;
        }
        jniEnv->CallVoidMethod(jobj, jmid_parpared);
        javaVM->DetachCurrentThread();
    }
}


