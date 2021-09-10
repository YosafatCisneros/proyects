package com.example.exapra_cisneros_87;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;

public class InicioActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_inicio);
    }


    public void iniSesion(View view) {
        Intent ini = new Intent(this, InventResActivity.class);
        startActivity(ini);
    }

    public void iniQR(View view) {
        Intent ini = new Intent(this, NuevoActivity.class);
        startActivity(ini);
    }
}