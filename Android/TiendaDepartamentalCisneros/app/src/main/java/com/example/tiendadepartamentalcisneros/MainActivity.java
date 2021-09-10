package com.example.tiendadepartamentalcisneros;

import androidx.appcompat.app.AppCompatActivity;
import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentManager;
import androidx.fragment.app.FragmentTransaction;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class MainActivity extends AppCompatActivity {

    Button alta, baja, actualiza, consulta;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        alta=findViewById(R.id.btnAlta);
        alta.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                replaceFragment(new Altas());
            }
        });

        baja=findViewById(R.id.btnBaja);
        baja.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                replaceFragment(new Bajas());
            }
        });

        actualiza=findViewById(R.id.btnActualiza);
        actualiza.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                replaceFragment(new Actualizaciones());
            }
        });

        consulta=findViewById(R.id.btnConsulta);
        consulta.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                replaceFragment(new Consultas());
            }
        });

    }
    private void replaceFragment(Fragment fragment){
        FragmentManager fragmentManager=getSupportFragmentManager();
        FragmentTransaction fragmentTransaction= fragmentManager.beginTransaction();
        fragmentTransaction.replace(R.id.frame,fragment);
        fragmentTransaction.commit();
    }
}
