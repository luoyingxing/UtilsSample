package com.lyx.utils;

/**
 * CWUtils
 * <p>
 * <p/>
 * Created by luoyingxing on 2018/11/13.
 */
public class CWUtils {

    static {
        try {
            System.loadLibrary("cwsdk");
        } catch (Throwable e) {
            e.printStackTrace();
        }
    }

    public static native String eidConstructor(String tid);
}