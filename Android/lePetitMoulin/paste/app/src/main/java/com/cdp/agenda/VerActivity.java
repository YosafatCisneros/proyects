package com.cdp.agenda;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;

import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.text.InputType;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

import com.cdp.agenda.bd.DbPastel;
import com.cdp.agenda.entidad.Pasteles;
import com.google.android.material.floatingactionbutton.FloatingActionButton;

public class VerActivity extends AppCompatActivity {

    EditText txtNombre, txtFechap, txtFechac;
    Button btnGuarda;
    FloatingActionButton fabEditar, fabEliminar;

    Pasteles contacto;
    int id = 0;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_read);

        txtNombre = findViewById(R.id.txtNombre);
        txtFechap = findViewById(R.id.txtFechap);
        txtFechac = findViewById(R.id.txtFechac);
        btnGuarda = findViewById(R.id.btnGuarda);
        fabEditar = findViewById(R.id.fabEditar);
        fabEliminar = findViewById(R.id.fabEliminar);

        if(savedInstanceState == null){
            Bundle extras = getIntent().getExtras();
            if(extras == null){
                id = Integer.parseInt(null);
            } else {
                id = extras.getInt("ID");
            }
        } else {
            id = (int) savedInstanceState.getSerializable("ID");
        }

        final DbPastel dbPastel = new DbPastel(VerActivity.this);
        contacto = dbPastel.verPastel(id);

        if(contacto != null){
            txtNombre.setText(contacto.getNombre());
            txtFechap.setText(contacto.getFechap());
            txtFechac.setText(contacto.getFechac());
            btnGuarda.setVisibility(View.INVISIBLE);
            txtNombre.setInputType(InputType.TYPE_NULL);
            txtFechap.setInputType(InputType.TYPE_NULL);
            txtFechac.setInputType(InputType.TYPE_NULL);
        }

        fabEditar.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent = new Intent(VerActivity.this, EditarActivity.class);
                intent.putExtra("ID", id);
                startActivity(intent);
            }
        });

        fabEliminar.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                AlertDialog.Builder builder = new AlertDialog.Builder(VerActivity.this);
                builder.setMessage("¿Desea eliminar este pastel?")
                        .setPositiveButton("SI", new DialogInterface.OnClickListener() {
                            @Override
                            public void onClick(DialogInterface dialogInterface, int i) {

                                if(dbPastel.eliminarPastel(id)){
                                    lista();
                                }
                            }
                        })
                        .setNegativeButton("NO", new DialogInterface.OnClickListener() {
                            @Override
                            public void onClick(DialogInterface dialogInterface, int i) {

                            }
                        }).show();
            }
        });
    }

    private void lista(){
        Intent intent = new Intent(this, MainActivity.class);
        startActivity(intent);
    }
}