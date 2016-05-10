//
// Created by pengk on 2016/5/10.
//

#include "DroidAnti.h"
#include "anti_debug.h"

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *jvm, void *reserved) {
    LOGI("enter JNI_OnLoad!\n");
    bool bDebug = anti_debug_antiTracePid();
    if (bDebug) {
        LOGD("detect debuggee!");
    } else {
        LOGD("no debuggee!");
    }
    anti_debug_antiPtrace();
    return JNI_VERSION_1_6;
}