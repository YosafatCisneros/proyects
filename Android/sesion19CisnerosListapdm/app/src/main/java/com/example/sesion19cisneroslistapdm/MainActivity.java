package com.example.sesion19cisneroslistapdm;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    TextView tvPrecio;
    ListView lvProductos;

    private String productos[]={"Laptop","Bocinas","Mouse","Teclado","Monitor","Xbox","Celular"};
    private String precio[]={"10000","500","1000","600","1500","15000","2500"};
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        tvPrecio=(TextView)findViewById(R.id.tvPrecio);
        lvProductos=(ListView)findViewById(R.id.lvProductos);

        ArrayAdapter<String> adapter1=new ArrayAdapter<String>(this, android.R.layout.simple_list_item_1,productos);
            lvProductos.setAdapter(adapter1);
            lvProductos.setOnItemClickListener(new AdapterView.OnItemClickListener() {
                @Override
                public void onItemClick(AdapterView<?> parent, View view, int position, long id) {

                    tvPrecio.setText("Precio: "+precio[position]);
                    Toast.makeText(MainActivity.this,"Has pulsado: \n"+precio[position],Toast.LENGTH_LONG).show();

                }
            });
    }
}