package com.example.exapra_cisneros_87;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

//import com.google.firebase.auth.FirebaseAuth;

public class InventResActivity extends AppCompatActivity {

    /*FirebaseAuth auth;*/

    private Button login;
    private Button regsitrar;
    private Button cerrarSesion;
    private Button inventario;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_invent_res);

        login = findViewById(R.id.btnIniciar);
        regsitrar = findViewById(R.id.btnRegistrar);
        cerrarSesion = findViewById(R.id.btnCerrarSesion);
        inventario=findViewById(R.id.btnInventario);

        /*auth = FirebaseAuth.getInstance();
        if(auth.getCurrentUser()!= null){
            login.setVisibility(View.GONE);
            regsitrar.setVisibility(View.GONE);
            cerrarSesion.setVisibility(View.VISIBLE);
        }*/
    }

    public void permiso(View view) {
        Intent ini = new Intent(this, MainActivity.class);
        startActivity(ini);
    }

    public void  iniRecetas(View view) {
        Intent ini = new Intent(this, RecetasActivity.class);
        startActivity(ini);
    }

    /*public void iniSesion(View view) {
        Intent ini = new Intent(this, MainActivity.class);
        startActivity(ini);
    }

    public void iniRegsitrar(View view) {
        Intent ini = new Intent(this, RegistrarActivity.class);
        startActivity(ini);
    }

    public void iniRecetas(View view) {

        if(auth.getCurrentUser()!=null){
            Intent ini = new Intent(this, Recetas.class);
            startActivity(ini);
        }else{
            AlertDialog.Builder builder = new AlertDialog.Builder(MenuSesion.this);
            builder.setMessage("Debes registrarte o iniciar sesion para acceder");
            builder.setCancelable(true);
            builder.setPositiveButton(
                    "ok",
                    (dialog, id) ->{dialog.cancel();} );
            AlertDialog alert = builder.create();
            alert.show();

        }
    }*/



    /*public void cerrarSesion(View view){
        auth.signOut();
        if(auth.getCurrentUser()==null){
            login.setVisibility(View.VISIBLE);
            regsitrar.setVisibility(View.VISIBLE);
            cerrarSesion.setVisibility(View.GONE);
        }
    }

    public void permiso(View view){
        if(auth.getCurrentUser()!=null){
            Intent i= new Intent(this,CodigoQr.class);
            startActivity(i);
        }else{
            AlertDialog.Builder builder = new AlertDialog.Builder(MenuSesion.this);
            builder.setMessage("Debes registrarte o iniciar sesion para acceder");
            builder.setCancelable(true);
            builder.setPositiveButton(
                    "ok",
                    (dialog, id) ->{dialog.cancel();} );
            AlertDialog alert = builder.create();
            alert.show();

        }
    }*/



}