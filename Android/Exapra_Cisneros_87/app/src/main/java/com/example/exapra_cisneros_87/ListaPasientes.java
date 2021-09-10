package com.example.exapra_cisneros_87;
import android.content.Context;
import android.content.Intent;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;
import com.example.exapra_cisneros_87.VerActivity;

import java.util.ArrayList;

public class ListaPasientes extends RecyclerView.Adapter<ListaPasientes.ContactoViewHolder>{
    ArrayList<Pasiente> listaPasientes;

    public ListaPasientes(ArrayList<Pasiente> listaPasientes){
        this.listaPasientes = listaPasientes;
    }

    @NonNull
    @Override
    public ContactoViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View view = LayoutInflater.from(parent.getContext()).inflate(R.layout.lista_recycle, null, false);
        return new ContactoViewHolder(view);
    }

    @Override
    public void onBindViewHolder(@NonNull ContactoViewHolder holder, int position) {
        holder.viewCurp.setText(listaPasientes.get(position).getCurp());
        holder.viewDias.setText(listaPasientes.get(position).getDias());
        holder.viewPrecio.setText(listaPasientes.get(position).getPrecio());
    }

    @Override
    public int getItemCount() {
        return listaPasientes.size();
    }

    public class ContactoViewHolder extends RecyclerView.ViewHolder {

        TextView viewCurp, viewDias, viewPrecio;

        public ContactoViewHolder(@NonNull View itemView) {
            super(itemView);

            viewCurp = itemView.findViewById(R.id.viewCurp);
            viewDias = itemView.findViewById(R.id.viewDias);
            viewPrecio = itemView.findViewById(R.id.viewPrecio);

            itemView.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View view) {
                    Context context = view.getContext();
                    Intent intent = new Intent(context, VerActivity.class);
                    intent.putExtra("ID", listaPasientes.get(getAdapterPosition()).getId());
                    context.startActivity(intent);
                }
            });
        }
    }
}
