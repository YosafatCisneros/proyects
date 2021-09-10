package com.cdp.agenda;

import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.content.Intent;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;

import com.cdp.agenda.lista.ListaPasteles;
import com.cdp.agenda.bd.DbPastel;
import com.cdp.agenda.entidad.Pasteles;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {

    RecyclerView listaContactos;
    ArrayList<Pasteles> listaArrayContactos;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        listaContactos = findViewById(R.id.listaContactos);
        listaContactos.setLayoutManager(new LinearLayoutManager(this));

        DbPastel dbPastel = new DbPastel(MainActivity.this);

        listaArrayContactos = new ArrayList<>();

        ListaPasteles adapter = new ListaPasteles(dbPastel.mostrarPastel());
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

            case R.id.menuVenta:
                nuevaVenta();
                return true;
            default:
                return super.onOptionsItemSelected(item);
        }
    }

    private void nuevoRegistro(){
        Intent intent = new Intent(this, NuevoActivity.class);
        startActivity(intent);
    }
    private void nuevaVenta(){
        Intent intent = new Intent(this, VentaActivity.class);
        startActivity(intent);
    }
}