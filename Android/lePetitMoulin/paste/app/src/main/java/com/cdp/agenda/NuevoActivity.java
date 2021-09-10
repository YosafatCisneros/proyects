package com.cdp.agenda;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import com.cdp.agenda.bd.DbPastel;

public class NuevoActivity extends AppCompatActivity {

    EditText txtNombre, txtFechap, txtFechac;
    Button btnGuarda;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_create_update);

        txtNombre = findViewById(R.id.txtNombre);
        txtFechap = findViewById(R.id.txtFechap);
        txtFechac = findViewById(R.id.txtFechac);
        btnGuarda = findViewById(R.id.btnGuarda);

        btnGuarda.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                if(!txtNombre.getText().toString().equals("") && !txtFechap.getText().toString().equals("")) {

                    DbPastel dbPastel = new DbPastel(NuevoActivity.this);
                    long id = dbPastel.insertarPastel(txtNombre.getText().toString(), txtFechap.getText().toString(), txtFechac.getText().toString());

                    if (id > 0) {
                        Toast.makeText(NuevoActivity.this, "PASTEL GUARDADO", Toast.LENGTH_LONG).show();
                        limpiar();
                    } else {
                        Toast.makeText(NuevoActivity.this, "ERROR AL GUARDAR PASTEL", Toast.LENGTH_LONG).show();
                    }
                } else {
                    Toast.makeText(NuevoActivity.this, "DEBE LLENAR TODOS LOS CAMPOS", Toast.LENGTH_LONG).show();
                }
            }
        });
    }

    private void limpiar() {
        txtNombre.setText("");
        txtFechap.setText("");
        txtFechac.setText("");
    }
}