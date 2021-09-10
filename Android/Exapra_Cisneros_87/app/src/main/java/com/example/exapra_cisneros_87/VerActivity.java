package com.example.exapra_cisneros_87;
import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;

import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.text.InputType;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import com.google.android.material.floatingactionbutton.FloatingActionButton;

public class VerActivity extends AppCompatActivity {

    EditText txtCurp, txtDias, txtPrecio;
    Button btnGuarda;
    FloatingActionButton fabEditar, fabEliminar;

    Pasiente contacto;
    int id = 0;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_read);

        txtCurp = findViewById(R.id.txtCurp);
        txtDias = findViewById(R.id.txtDias);
        txtPrecio = findViewById(R.id.txtPrecio);
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

        final DB db = new DB(VerActivity.this);
        contacto = db.verPasiente(id);

        if(contacto != null){
            txtCurp.setText(contacto.getCurp());
            txtDias.setText(contacto.getDias());
            txtPrecio.setText(contacto.getPrecio());
            btnGuarda.setVisibility(View.INVISIBLE);
            txtCurp.setInputType(InputType.TYPE_NULL);
            txtDias.setInputType(InputType.TYPE_NULL);
            txtPrecio.setInputType(InputType.TYPE_NULL);
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
                builder.setMessage("¿Desea eliminar este helado?")
                        .setPositiveButton("SI", new DialogInterface.OnClickListener() {
                            @Override
                            public void onClick(DialogInterface dialogInterface, int i) {

                                if(db.eliminarPasiente(id)){
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