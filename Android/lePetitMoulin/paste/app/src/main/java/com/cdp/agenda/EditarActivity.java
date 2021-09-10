package com.cdp.agenda;

import android.annotation.SuppressLint;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

import com.cdp.agenda.bd.DbPastel;
import com.cdp.agenda.entidad.Pasteles;
import com.google.android.material.floatingactionbutton.FloatingActionButton;

public class EditarActivity extends AppCompatActivity {

    EditText txtNombre, txtFechap, txtFechac;
    Button btnGuarda;
    FloatingActionButton fabEditar, fabEliminar;
    boolean correcto = false;
    Pasteles contacto;
    int id = 0;

    @SuppressLint("RestrictedApi")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_read);

        txtNombre = findViewById(R.id.txtNombre);
        txtFechap = findViewById(R.id.txtFechap);
        txtFechac = findViewById(R.id.txtFechac);
        btnGuarda = findViewById(R.id.btnGuarda);
        fabEditar = findViewById(R.id.fabEditar);
        fabEditar.setVisibility(View.INVISIBLE);
        fabEliminar = findViewById(R.id.fabEliminar);
        fabEliminar.setVisibility(View.INVISIBLE);

        if (savedInstanceState == null) {
            Bundle extras = getIntent().getExtras();
            if (extras == null) {
                id = Integer.parseInt(null);
            } else {
                id = extras.getInt("ID");
            }
        } else {
            id = (int) savedInstanceState.getSerializable("ID");
        }

        final DbPastel dbPastel = new DbPastel(EditarActivity.this);
        contacto = dbPastel.verPastel(id);

        if (contacto != null) {
            txtNombre.setText(contacto.getNombre());
            txtFechap.setText(contacto.getFechap());
            txtFechac.setText(contacto.getFechac());
        }

        btnGuarda.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (!txtNombre.getText().toString().equals("") && !txtFechap.getText().toString().equals("")) {
                    correcto = dbPastel.editarPastel(id, txtNombre.getText().toString(), txtFechap.getText().toString(), txtFechac.getText().toString());

                    if(correcto){
                        Toast.makeText(EditarActivity.this, "REGISTRO MODIFICADO", Toast.LENGTH_LONG).show();
                        verRegistro();
                    } else {
                        Toast.makeText(EditarActivity.this, "ERROR AL MODIFICAR REGISTRO", Toast.LENGTH_LONG).show();
                    }
                } else {
                    Toast.makeText(EditarActivity.this, "DEBE LLENAR LOS CAMPOS OBLIGATORIOS", Toast.LENGTH_LONG).show();
                }
            }
        });
    }

    private void verRegistro(){
        Intent intent = new Intent(this, VerActivity.class);
        intent.putExtra("ID", id);
        startActivity(intent);
    }
}