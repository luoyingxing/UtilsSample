

#include "cwsdk.h"

char *u64_t_to_code64(time_t t, char *buf, int len, int digits) {
    if (digits > len - 1) { digits = len - 1; };
    memset(buf, 0, len);
    int index = digits - 1;
    if (t == 0) {
        buf[index] = digi_64[0];
        index--;
        if (digits > 0) { digits--; };
    } else {
        while (t > 0) {
            int n = t % 64;
            buf[index] = digi_64[n];
            index--;
            if (digits > 0) { digits--; };
            t = t >> 6;
        }
    }
    while (digits > 0) {
        buf[index] = digi_64[0];
        digits--;
        index--;
    }
    return buf;
}

char *new_eid(char *tid, char eid[EID_LENGTH]) {
    time_t t;
    time(&t);
    if (eid_time_last != t) {
        eid_seq = 0;
        eid_time_last = t;
    };
    char s_time[10];
    u64_t_to_code64(t, s_time, sizeof(s_time), 6);
    char s_seq[10];
    u64_t_to_code64(eid_seq, s_seq, sizeof(s_seq), 1);
    char s_tid[10] = {0};
    strncpy(s_tid, tid + 5, 3);
    strncpy(s_tid + 3, tid + 9, 2);
    strncpy(s_tid + 5, tid + 12, 3);
    eid[0] = 0;
    strcat(eid, s_tid);
    strcat(eid, s_time);
    strcat(eid, s_seq);
    eid_seq++;
    return eid;
};

JNIEXPORT jstring JNICALL
Java_com_lyx_utils_CWUtils_eidConstructor(JNIEnv *env, jobject instance, jstring tid) {
    const char *_tid = (*env)->GetStringUTFChars(env, tid, 0);

    char eid[EID_LENGTH];
    new_eid(_tid, eid);
    (*env)->ReleaseStringUTFChars(env, tid, _tid);

    return (*env)->NewStringUTF(env, eid);
}

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *env;

//    LOGW("JNI_OnLoad");

    memset(&g_ctx, 0, sizeof(g_ctx));

    g_ctx.javaVM = vm;
    if ((*vm)->GetEnv(vm, (void **) &env, JNI_VERSION_1_6) != JNI_OK) {
        return JNI_ERR; // JNI version not supported.
    }

    jniEnv = env;

    jclass tmp = (*env)->FindClass(env, JNI_RES_CLASS);
    g_res_class = (jclass) ((*env)->NewGlobalRef(env, tmp));

    return JNI_VERSION_1_6;
}