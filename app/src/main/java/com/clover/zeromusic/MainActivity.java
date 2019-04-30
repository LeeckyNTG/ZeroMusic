package com.clover.zeromusic;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;

import com.clover.zeroplayer.listener.WlOnParparedListener;
import com.clover.zeroplayer.log.MyLog;
import com.clover.zeroplayer.player.WlPlay;

public class MainActivity extends AppCompatActivity {

    WlPlay wlPlay;

    private static final String TAG = "MainActivity";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        wlPlay = new WlPlay();

        wlPlay.setOnParparedListener(new WlOnParparedListener() {
            @Override
            public void onParpared() {
                MyLog.d("准备好了，可以开始播放声音了");
                wlPlay.start();
            }
        });

    }

    public void click(View view) {
        switch (view.getId()) {
            case R.id.btn_begin:
                wlPlay.setSource("http://mpge.5nd.com/2015/2015-11-26/69708/1.mp3");
                wlPlay.parpared();
                break;
        }
    }
}
