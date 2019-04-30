package com.clover.zeroplayer.player;

import android.text.TextUtils;

import com.clover.zeroplayer.listener.WlOnParparedListener;

/**
 * Created by clover on 19-4-30.
 */

public class WlPlay {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
        System.loadLibrary("avcodec-57");
        System.loadLibrary("avdevice-57");
        System.loadLibrary("avfilter-6");
        System.loadLibrary("avformat-57");
        System.loadLibrary("avutil-55");
        System.loadLibrary("postproc-54");
        System.loadLibrary("swresample-2");
        System.loadLibrary("swscale-4");
    }

    private String source;

    private WlOnParparedListener onParparedListener;

    public WlPlay() {

    }

    public void setOnParparedListener(WlOnParparedListener onParparedListener) {
        this.onParparedListener = onParparedListener;
    }

    public void setSource(String source) {
        this.source = source;
    }

    public void parpared() {
        if (TextUtils.isEmpty(source)) {
            return;
        }

        new Thread(new Runnable() {
            @Override
            public void run() {
                n_parpared(source);
            }
        }).start();
    }


    public void onCallParpared() {
        if (onParparedListener != null) {
            onParparedListener.onParpared();
        }
    }

    public native void n_parpared(String source);

}
