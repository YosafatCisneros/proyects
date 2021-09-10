package com.cdp.agenda.bd;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;

import androidx.annotation.Nullable;

import com.cdp.agenda.entidad.Pasteles;

import java.util.ArrayList;

public class DbPastel extends DbCrear {

    Context context;

    public DbPastel(@Nullable Context context) {
        super(context);
        this.context = context;
    }

    public long insertarPastel(String nombre, String fechap, String fechac) {

        long id = 0;

        try {
            DbCrear dbCrear = new DbCrear(context);
            SQLiteDatabase db = dbCrear.getWritableDatabase();

            ContentValues values = new ContentValues();
            values.put("nombre", nombre);
            values.put("fechap", fechap);
            values.put("fechac", fechac);

            id = db.insert(TABLE_PASTEL, null, values);
        } catch (Exception ex) {
            ex.toString();
        }

        return id;
    }

    public ArrayList<Pasteles> mostrarPastel() {

        DbCrear dbCrear = new DbCrear(context);
        SQLiteDatabase db = dbCrear.getWritableDatabase();

        ArrayList<Pasteles> listaPastel = new ArrayList<>();
        Pasteles pastel;
        Cursor cursorContactos;

        cursorContactos = db.rawQuery("SELECT * FROM " + TABLE_PASTEL, null);

        if (cursorContactos.moveToFirst()) {
            do {
                pastel = new Pasteles();
                pastel.setId(cursorContactos.getInt(0));
                pastel.setNombre(cursorContactos.getString(1));
                pastel.setFechap(cursorContactos.getString(2));
                pastel.setFechac(cursorContactos.getString(3));
                listaPastel.add(pastel);
            } while (cursorContactos.moveToNext());
        }

        cursorContactos.close();

        return listaPastel;
    }

    public Pasteles verPastel(int id) {

        DbCrear dbCrear = new DbCrear(context);
        SQLiteDatabase db = dbCrear.getWritableDatabase();

        Pasteles pastel = null;
        Cursor cursorContactos;

        cursorContactos = db.rawQuery("SELECT * FROM " + TABLE_PASTEL + " WHERE id = " + id + " LIMIT 1", null);

        if (cursorContactos.moveToFirst()) {
            pastel = new Pasteles();
            pastel.setId(cursorContactos.getInt(0));
            pastel.setNombre(cursorContactos.getString(1));
            pastel.setFechap(cursorContactos.getString(2));
            pastel.setFechac(cursorContactos.getString(3));
        }

        cursorContactos.close();

        return pastel;
    }

    public boolean editarPastel(int id, String nombre, String fechap, String fechac) {

        boolean correcto = false;

        DbCrear dbCrear = new DbCrear(context);
        SQLiteDatabase db = dbCrear.getWritableDatabase();

        try {
            db.execSQL("UPDATE " + TABLE_PASTEL + " SET nombre = '" + nombre + "', fechap = '" + fechap + "', fechac = '" + fechac + "' WHERE id='" + id + "' ");
            correcto = true;
        } catch (Exception ex) {
            ex.toString();
            correcto = false;
        } finally {
            db.close();
        }

        return correcto;
    }

    public boolean eliminarPastel(int id) {

        boolean correcto = false;

        DbCrear dbCrear = new DbCrear(context);
        SQLiteDatabase db = dbCrear.getWritableDatabase();

        try {
            db.execSQL("DELETE FROM " + TABLE_PASTEL + " WHERE id = '" + id + "'");
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
