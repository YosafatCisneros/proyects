/* Programa para imprimir nombre, apellido y telefono */
#include <stdio.h>

main()
{
    char nombre[21], dept[21], calle[21],ciudad[16],
            estado[4], codpos[6], tel[13];
    void obtcaden(), impcaden();
    /* Almacena las entradas como arreglos llamando a obtcaden() */
    printf("Introduce el nombre: ");
    obtcaden(nombre,21);
    printf("\ndepartamento: ");
    obtcaden(dept,21);
    printf("\ncalle y numero: ");
    obtcaden(calle,21);
    printf("\nciudad: ");
    obtcaden(ciudad,16);
    printf("\nestado: ");
    obtcaden(estado,4);
    printf("\ncodigo postal: ");
    obtcaden(codpos,6);
    printf("\nnumero telefonico: ");
    obtcaden(tel,13);
    printf("\n");

    /* pasa arreglos a impcaden */
    impcaden(nombre);
    impcaden(dept);
    impcaden(calle);
    impcaden(ciudad);
    impcaden(estado);
    impcaden(codpos);
    impcaden(tel);
}

/* acepta la entrada del usuario y la almacena en un arreglo */
void obtcaden(apunacaden,n)
char *apunacaden;
int n;
{
    int i = 0;
    while ((*apunacaden++ = getchar()) != '\n' && i++ < n)
            ;
    *(--apunacaden) = '\0';
}

/* funcion para imprimir las cadenas de caracteres */
void impcaden(apunacaden)
char *apunacaden;
{
    printf("\n       %s",apunacaden);
}
