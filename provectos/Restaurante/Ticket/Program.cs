using System;

namespace Ticket
{
    class Program
    {
        public static void Main(string[] args)
        {
            string idticket="000001";
            int numMesero=3, numMesa=2;
            double efectivo=1000;
            Ticket miticket = new Ticket();
            miticket.IdTicket = idticket;
            miticket.NumDeMesero = numMesero;
            miticket.NumDeMesa = numMesa;
            miticket.Efectivo = efectivo;
            Console.WriteLine("Llenar la orden introduciendo el nombre del platillo y posteriormente el precio:\n\n");
            miticket.generarTotal();
            miticket.crearTicket();
            miticket.exportarTicket();
            miticket.enviarTicket();
        }
    }
}
