package com.example.exapra_cisneros_87;
import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class NuevoActivity extends AppCompatActivity{
    EditText txtCurp, txtDias, txtPrecio;
    Button btnGuarda;
    double d, p, t;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_create_update);

        txtCurp = findViewById(R.id.txtCurp);
        txtDias = findViewById(R.id.txtDias);
        txtPrecio = findViewById(R.id.txtPrecio);
        btnGuarda = findViewById(R.id.btnGuarda);

        btnGuarda.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
              /*  d=Double.parseDouble(txtDias.getText().toString());
                p=Double.parseDouble(txtPrecio.getText().toString());
                t=d*p;
                if(d>5)
                {
                    t*=.9;
                }*/
                if(!txtCurp.getText().toString().equals("") && !txtDias.getText().toString().equals("")) {

                    DB dbPastel = new DB(NuevoActivity.this);
                    long id = dbPastel.insertarPasiente(txtCurp.getText().toString(), txtDias.getText().toString(), txtPrecio.getText().toString());

                    if (id > 0) {
                        Toast.makeText(NuevoActivity.this, "Registro Exitoso", Toast.LENGTH_LONG).show();
                        limpiar();
                    } else {
                        Toast.makeText(NuevoActivity.this, "ERROR AL GUARDAR HELADO", Toast.LENGTH_LONG).show();
                    }
                } else {
                    Toast.makeText(NuevoActivity.this, "DEBE LLENAR TODOS LOS CAMPOS", Toast.LENGTH_LONG).show();
                }
            }
        });
    }
    private void limpiar() {
        txtCurp.setText("");
        txtDias.setText("");
        txtPrecio.setText("");
    }
}
