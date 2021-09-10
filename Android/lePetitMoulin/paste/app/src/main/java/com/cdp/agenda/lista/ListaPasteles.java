package com.cdp.agenda.lista;

import android.content.Context;
import android.content.Intent;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import com.cdp.agenda.R;
import com.cdp.agenda.VerActivity;
import com.cdp.agenda.entidad.Pasteles;

import java.util.ArrayList;

public class ListaPasteles extends RecyclerView.Adapter<ListaPasteles.ContactoViewHolder> {

    ArrayList<Pasteles> listaPastel;

    public ListaPasteles(ArrayList<Pasteles> listaPastel){
        this.listaPastel = listaPastel;
    }

    @NonNull
    @Override
    public ContactoViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View view = LayoutInflater.from(parent.getContext()).inflate(R.layout.lista_recycle, null, false);
        return new ContactoViewHolder(view);
    }

    @Override
    public void onBindViewHolder(@NonNull ContactoViewHolder holder, int position) {
        holder.viewNombre.setText(listaPastel.get(position).getNombre());
        holder.viewFechap.setText(listaPastel.get(position).getFechap());
        holder.viewFechac.setText(listaPastel.get(position).getFechac());
    }

    @Override
    public int getItemCount() {
        return listaPastel.size();
    }

    public class ContactoViewHolder extends RecyclerView.ViewHolder {

        TextView viewNombre, viewFechap, viewFechac;

        public ContactoViewHolder(@NonNull View itemView) {
            super(itemView);

            viewNombre = itemView.findViewById(R.id.viewNombre);
            viewFechap = itemView.findViewById(R.id.viewFechap);
            viewFechac = itemView.findViewById(R.id.viewFechac);

            itemView.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View view) {
                    Context context = view.getContext();
                    Intent intent = new Intent(context, VerActivity.class);
                    intent.putExtra("ID", listaPastel.get(getAdapterPosition()).getId());
                    context.startActivity(intent);
                }
            });
        }
    }
}
