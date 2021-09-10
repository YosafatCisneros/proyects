package com.example.sesion6CisnerosVisor;
//View OnclickListener, realiza evento de accion o boton automatica

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {
         public ImageView imageView1;
         public Button btnAudioVideo;
    @Override
    protected void onCreate(Bundle savedInstanceState) {//inicia metodo onCreate
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        btnAudioVideo=findViewById(R.id.btnAudioVideo);

        imageView1 = findViewById(R.id.ivVisor);

        ImageView imageView2 = (ImageView)findViewById(R.id.ivImg2);
        ImageView imageView3 = (ImageView)findViewById(R.id.ivImg3);
        ImageView imageView4 = (ImageView)findViewById(R.id.ivImg4);
        ImageView imageView5 = (ImageView)findViewById(R.id.ivImg5);

        imageView2.setOnClickListener(this);
        imageView3.setOnClickListener(this);
        imageView4.setOnClickListener(this);
        imageView5.setOnClickListener(this);

        btnAudioVideo.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent1=new Intent(MainActivity.this,AudioVideo.class);
                startActivity(intent1);
            }
        });

    }//termina metdo onCreate

    @Override
    public void onClick(View view) {//inicia metodo

        //estructura de control selectiva que ejecuta casos
        switch (view.getId()){
            case R.id.ivImg2:
                imageView1.setImageResource(R.drawable.img2);
                break;
            case R.id.ivImg3:
                imageView1.setImageResource(R.drawable.img3);
                break;
            case R.id.ivImg4:
                imageView1.setImageResource(R.drawable.img4);
                break;
                case R.id.ivImg5:
                imageView1.setImageResource(R.drawable.img5);
                break;

        }
    }//termina metodo
}