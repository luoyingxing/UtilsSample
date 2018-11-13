//
// sipsdk.h
//
// Created by luoyingxing on 2018/11/1.
//

#ifndef SIPSAMPLE_SIPSKD_H
#define SIPSAMPLE_SIPSKD_H

#endif //SIPSAMPLE_SIPSKD_H

#include <string.h>
#include <jni.h>
#include <android/log.h>
#include <time.h>

#define LOG_TAG "cwsdk"

#define EID_LENGTH 20

#define LOGD(a) __android_log_write(ANDROID_LOG_DEBUG, LOG_TAG, a)
#define LOGI(a) __android_log_write(ANDROID_LOG_INFO, LOG_TAG, a)
#define LOGE(a) __android_log_write(ANDROID_LOG_ERROR, LOG_TAG, a)
#define LOGW(a) __android_log_write(ANDROID_LOG_WARN, LOG_TAG, a)

typedef struct cwsdk_context {
    JavaVM *javaVM;
    jclass jniHelperClz;
} CWSDKContext;

#define JNI_RES_CLASS "com/lyx/utils/CWUtils"

jclass g_res_class = NULL;
jmethodID g_method_onResponse = NULL;
JNIEnv *jniEnv;
CWSDKContext g_ctx;

time_t eid_time_last = 0;
uint16_t eid_seq = 0;

const char digi_64[] = "\\\
ABCDEFGHIJ\
KLMNOPQRST\
UVWXYZabcd\
efghijklmn\
opqrstuvwx\
yz01234567\
89+/";