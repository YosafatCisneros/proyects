package com.example.sesion28cisnerosCRUD;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteDatabase.CursorFactory;
import android.database.sqlite.SQLiteOpenHelper;

import androidx.annotation.Nullable;

public class AdminSQL extends SQLiteOpenHelper{


    @Override
    public void onCreate(SQLiteDatabase db) {
        db.execSQL("create table Pacientes(cod integer primary key, Nombre text, Costo integer, Dias integer, descuento double, Total double)");

    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        db.execSQL(drop table if exist (paciente));
        db.execSQL("create table Pacientes(cod integer primary key, Nombre text, Costo integer, Dias integer, descuento double, Total double)")
    }
}
