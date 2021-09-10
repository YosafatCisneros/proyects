using System;
using System.Collections.Generic;
using System.Reflection;
using System.Text;
using System.Net.Mail;
using System.Net;

namespace Ticket
{
    class Ticket
    {
        int  numDeMesero, numDeMesa;
        double totalDeAlimentos=0, iva=10, totalAPagar=0, efectivo, cambio, descuento=0;
        string[,] orden=new string[2,20];
        string[] ticket = new string[35];
        string idTicket, fecha;
        

        public string IdTicket { get => idTicket; set => idTicket = value; }
        public int NumDeMesero { get => numDeMesero; set => numDeMesero = value; }
        public int NumDeMesa { get => numDeMesa; set => numDeMesa = value; }
        public double Efectivo { get => efectivo; set => efectivo = value; }

        
        
        public void generarTotal()
        {
            for(int j, i=0;i<20 ;i++)
            {
                for (j=0;j<2;j++)
                {
                    if(j==0)
                    {
                        Console.WriteLine("Nombre del platillo: ");
                        orden[j, i]=Console.ReadLine();
                    }
                    else
                    {
                        Console.WriteLine("Precio: ");
                        orden[j, i] = Console.ReadLine();
                        totalDeAlimentos += double.Parse(orden[j, i]);                        
                    }
                }
                Console.WriteLine("Desea agregar otro producto (1=si, 0=no): ");
                string opciones;
                opciones = Console.ReadLine();
                if (opciones=="0")
                {
                    orden[0, i+1] =null;
                    i = 20;
                }
                    
            }
            totalAPagar = (totalDeAlimentos* (1-(descuento/ 100))) * ((iva/100)+1);
            cambio = efectivo - totalAPagar;
        }
        public void crearTicket()
        {
            ticket[0]="Cafeteria";
            ticket[1] = "ID: " + idTicket;
            DateTime localDate = DateTime.Now;
            fecha = localDate.ToString();
            ticket[2] = "Fecha: " + fecha;
            ticket[3] = "Mesero: "+numDeMesero.ToString();
            ticket[4] = "Mesa: " + numDeMesa.ToString();
            ticket[5] = "Producto/precio:";
            int n = 6;
            for(int j, i = 0; i < 20; i++,n++)
            {               
                for (j = 0; j < 2; j++)
                {
                    if (j == 0)
                        ticket[n] = orden[j, i] + "\t\t";

                    else
                        ticket[n] += "$"+orden[j, i];
                }
                if (orden[0, i + 1] == null)
                    i=20;
            }
            ticket[n] = "Total de alimentos: $"+totalDeAlimentos.ToString();
            n++;
            ticket[n] = "Descuento: "+descuento.ToString() + "%";
            n++;
            ticket[n] = "iva: "+iva.ToString() + "%";
            n++;
            ticket[n] = "Total a pagar: $"+ totalAPagar.ToString("#.##");
            n++;
            ticket[n] = "Efectivo: $"+efectivo.ToString();
            n++;
            ticket[n] = "cambio: $"+cambio.ToString();
        }
        public void exportarTicket()
        {
            System.IO.File.WriteAllLines(@/*aqui se agrega la ruta"C:\Users\yosaf\source\repos\Ticket\ticket.txt"*/, ticket);
        }
        public void enviarTicket()
        {
            try
            {
                //Cliente
                //gmail >> smtp server : smtp.gmail.com, port : 587 , ssl true
                //yahoo >> smtp server : smtp.mail.yahoo.com, port : 587 , ssl true
                string correo;
                Console.WriteLine("\n\nCorreo del cliente: ");
                correo = Console.ReadLine();
                SmtpClient clientDetails = new SmtpClient();
                clientDetails.Port = 587;
                clientDetails.Host = "smtp.gmail.com";
                clientDetails.EnableSsl = true;
                clientDetails.DeliveryMethod = SmtpDeliveryMethod.Network;
                clientDetails.UseDefaultCredentials = false;
                clientDetails.Credentials = new NetworkCredential("ticketpruebacaf@gmail.com", "ticketcaf");

                //mensaje
                MailMessage mailDetails = new MailMessage();
                mailDetails.From = new MailAddress("ticketpruebacaf@gmail.com");
                mailDetails.To.Add(correo);

                mailDetails.Subject = "Ticket";
                mailDetails.Body = "Ticket de su compra";


                //txt
                Attachment attachment = new Attachment(/*aqui se agrega la ruta "C:/Users/yosaf/source/repos/Ticket/ticket.txt"*/);
                mailDetails.Attachments.Add(attachment);

                clientDetails.Send(mailDetails);
                Console.WriteLine("\nSe ha enviado con exito el ticket a su correo");
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
        }
    }
}
