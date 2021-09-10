package com.example.exapra_cisneros_87;

import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.content.Intent;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;

import com.example.exapra_cisneros_87.ListaPasientes;
import com.example.exapra_cisneros_87.DB;
import com.example.exapra_cisneros_87.Pasiente;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {

    RecyclerView listaContactos;
    ArrayList<Pasiente> listaArrayContactos;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        listaContactos = findViewById(R.id.listaContactos);
        listaContactos.setLayoutManager(new LinearLayoutManager(this));

        DB db = new DB(MainActivity.this);

        listaArrayContactos = new ArrayList<>();

        ListaPasientes adapter = new ListaPasientes(db.mostrarPasiente());
        listaContactos.setAdapter(adapter);
    }

    public boolean onCreateOptionsMenu(Menu menu){
        MenuInflater inflater = getMenuInflater();
        inflater.inflate(R.menu.menu_principal, menu);
        return true;
    }

    public boolean onOptionsItemSelected(MenuItem item){
        switch (item.getItemId()){
            case R.id.menuNuevo:
                nuevoRegistro();
                return true;



            default:
                return super.onOptionsItemSelected(item);
        }
    }

    private void nuevoRegistro(){
        Intent intent = new Intent(this, NuevoActivity.class);
        startActivity(intent);
    }



}