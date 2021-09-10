package com.example.sesion36cisnerospdm_toast;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.os.Bundle;
import android.view.Gravity;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    Button btnToast1, btnToast2, btnToast3;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        btnToast1=findViewById(R.id.btnToast1);
        btnToast2=findViewById(R.id.btnToast2);
        btnToast3=findViewById(R.id.btnToast3);
    }

    public void toast1Personalizado(View view){
        Context context=getApplicationContext();
        CharSequence mensaje="Mensaje\n\nToast\n\nCisneros";
        int duration= Toast.LENGTH_LONG;

        Toast toast1Personalizado=Toast.makeText(context,mensaje,duration);

        toast1Personalizado.setGravity(Gravity.CENTER_HORIZONTAL,0,0);
        toast1Personalizado.show();
    }

    public void toast2Personalizado(View view){
        LayoutInflater inflater = getLayoutInflater();
        View layout = inflater.inflate(R.layout.toast2, null);

        Toast toast= new Toast(getApplicationContext());
        toast.setGravity(Gravity.CENTER_HORIZONTAL,0,0);
        toast.setDuration(Toast.LENGTH_LONG);

        toast.setView(layout);
        toast.show();
    }

    public void toast3Personalizado(View view){
        LayoutInflater inflater = getLayoutInflater();
        View layout = inflater.inflate(R.layout.toast2, null);

        Toast toast= new Toast(getApplicationContext());
        toast.setGravity(Gravity.CENTER_HORIZONTAL,0,0);
        toast.setDuration(Toast.LENGTH_LONG);

        toast.setView(layout);
        toast.show();
    }

}