package com.example.cisnerossadecv;

import androidx.appcompat.app.AppCompatActivity;

import android.media.MediaPlayer;
import android.net.Uri;
import android.os.Bundle;
import android.widget.MediaController;
import android.widget.VideoView;

public class MainActivity2 extends AppCompatActivity {
    public MediaPlayer rp;
    public VideoView vp;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);

        vp=findViewById(R.id.videoView2);
        Uri path= Uri.parse("android.resource://"+getPackageName()+"/"+R.raw.vcovid);
        MediaController mc =new MediaController(this);
        vp.setMediaController(mc);
        vp.setVideoURI(path);
        vp.setMediaController(new MediaController(this));
        vp.start();
    }
}