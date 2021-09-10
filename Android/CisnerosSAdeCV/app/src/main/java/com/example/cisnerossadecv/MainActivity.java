package com.example.cisnerossadecv;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    public EditText nombre, costo, dias;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        nombre=(EditText)findViewById(R.id.txtNombre);
        costo=(EditText)findViewById(R.id.txtCobro);
        dias=(EditText)findViewById(R.id.txtDias);
        String nom=nombre.getText().toString();
        String cos1=costo.getText().toString();
        String dia1=dias.getText().toString();

        final Button btnForm = findViewById(R.id.btnForm);
        final Button btnC = findViewById(R.id.btnC);
                btnC.setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View v) {
                        Intent intent1 = new Intent(MainActivity.this,MainActivity2.class);
                        startActivity(intent1);
                    }
                });
                btnForm.setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View v) {
                        Toast.makeText(MainActivity.this, "El total del pasiente " + ":\n", Toast.LENGTH_LONG).show();
                    }
                });


    }
}