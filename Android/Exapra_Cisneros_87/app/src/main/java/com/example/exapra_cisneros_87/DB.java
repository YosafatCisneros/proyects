package com.example.exapra_cisneros_87;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;

import androidx.annotation.Nullable;
import com.example.exapra_cisneros_87.Pasiente;

import java.util.ArrayList;

public class DB extends DBHelper{
    Context context;

    public DB(@Nullable Context context) {
        super(context);
        this.context = context;
    }

    public long insertarPasiente(String curp, String dias, String precio) {

        long id = 0;

        try {
            DBHelper dbCrear = new DBHelper(context);
            SQLiteDatabase db = dbCrear.getWritableDatabase();

            ContentValues values = new ContentValues();
            values.put("curp", curp);
            values.put("dias", dias);
            values.put("precio", precio);

            id = db.insert(TABLE_PASIENTE, null, values);
        } catch (Exception ex) {
            ex.toString();
        }

        return id;
    }

    public ArrayList<Pasiente> mostrarPasiente() {

        DBHelper dbHelper = new DBHelper(context);
        SQLiteDatabase db = dbHelper.getWritableDatabase();

        ArrayList<Pasiente> listaPasiente = new ArrayList<>();
        Pasiente pasiente;
        Cursor cursorContactos;

        cursorContactos = db.rawQuery("SELECT * FROM " + TABLE_PASIENTE, null);

        if (cursorContactos.moveToFirst()) {
            do {
                pasiente = new Pasiente();
                pasiente.setId(cursorContactos.getInt(0));
                pasiente.setCurp(cursorContactos.getString(1));
                pasiente.setDias(cursorContactos.getString(2));
                pasiente.setPrecio(cursorContactos.getString(3));
                listaPasiente.add(pasiente);
            } while (cursorContactos.moveToNext());
        }

        cursorContactos.close();

        return listaPasiente;
    }

    public Pasiente verPasiente(int id) {

        DBHelper dbCrear = new DBHelper(context);
        SQLiteDatabase db = dbCrear.getWritableDatabase();

        Pasiente pasiente = null;
        Cursor cursorContactos;

        cursorContactos = db.rawQuery("SELECT * FROM " + TABLE_PASIENTE + " WHERE id = " + id + " LIMIT 1", null);

        if (cursorContactos.moveToFirst()) {
            pasiente = new Pasiente();
            pasiente.setId(cursorContactos.getInt(0));
            pasiente.setCurp(cursorContactos.getString(1));
            pasiente.setDias(cursorContactos.getString(2));
            pasiente.setPrecio(cursorContactos.getString(3));
        }

        cursorContactos.close();

        return pasiente;
    }

    public boolean editarPasiente(int id, String curp, String dias, String precio) {

        boolean correcto = false;

        DBHelper dbCrear = new DBHelper(context);
        SQLiteDatabase db = dbCrear.getWritableDatabase();

        try {
            db.execSQL("UPDATE " + TABLE_PASIENTE + " SET curp = '" + curp + "', dias = '" + dias + "', precio = '" + precio + "' WHERE id='" + id + "' ");
            correcto = true;
        } catch (Exception ex) {
            ex.toString();
            correcto = false;
        } finally {
            db.close();
        }

        return correcto;
    }

    public boolean eliminarPasiente(int id) {

        boolean correcto = false;

        DBHelper dbCrear = new DBHelper(context);
        SQLiteDatabase db = dbCrear.getWritableDatabase();

        try {
            db.execSQL("DELETE FROM " + TABLE_PASIENTE + " WHERE id = '" + id + "'");
            correcto = true;
        } catch (Exception ex) {
            ex.toString();
            correcto = false;
        } finally {
            db.close();
        }

        return correcto;
    }
}
