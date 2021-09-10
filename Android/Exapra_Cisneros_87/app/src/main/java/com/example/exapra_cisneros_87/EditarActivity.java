package com.example.exapra_cisneros_87;

import android.annotation.SuppressLint;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

import com.google.android.material.floatingactionbutton.FloatingActionButton;

public class EditarActivity extends AppCompatActivity {

    EditText txtCurp, txtDias, txtPrecio;
    Button btnGuarda;
    FloatingActionButton fabEditar, fabEliminar;
    boolean correcto = false;
    Pasiente contacto;
    int id = 0;

    @SuppressLint("RestrictedApi")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_read);

        txtCurp = findViewById(R.id.txtCurp);
        txtDias = findViewById(R.id.txtDias);
        txtPrecio = findViewById(R.id.txtPrecio);
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

        final DB db = new DB(EditarActivity.this);
        contacto = db.verPasiente(id);

        if (contacto != null) {
            txtCurp.setText(contacto.getCurp());
            txtDias.setText(contacto.getDias());
            txtPrecio.setText(contacto.getPrecio());
        }

        btnGuarda.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (!txtCurp.getText().toString().equals("") && !txtDias.getText().toString().equals("")) {
                    correcto = db.editarPasiente(id, txtCurp.getText().toString(), txtDias.getText().toString(), txtPrecio.getText().toString());

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