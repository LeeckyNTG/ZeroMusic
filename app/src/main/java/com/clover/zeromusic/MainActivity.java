package com.clover.zeromusic;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;

import com.clover.zeroplayer.player.WlPlay;

public class MainActivity extends AppCompatActivity {

    WlPlay wlPlay;

    private static final String TAG = "MainActivity";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        wlPlay = new WlPlay();

    }

    public void click(View view) {
        switch (view.getId()) {
            case R.id.btn_begin:
                wlPlay.setSource("");
                wlPlay.parpared();
                break;
        }
    }
}
