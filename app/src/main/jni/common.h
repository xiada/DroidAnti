//
// Created by pengk on 2016/5/10.
//

#ifndef DROIDANTI_COMMON_H
#define DROIDANTI_COMMON_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <jni.h>
#include <android/log.h>
#include <sys/wait.h>
#include <sys/ptrace.h>

#define TAG "DroidAnti"
#define LOGV(...) __android_log_print(ANDROID_LOG_VERBOSE, TAG, __VA_ARGS__)
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG , TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO , TAG, __VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN , TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR , TAG, __VA_ARGS__)

char *getCmdline(int pid);

pid_t getPidByName(const char *name);

#endif //DROIDANTI_COMMON_H
