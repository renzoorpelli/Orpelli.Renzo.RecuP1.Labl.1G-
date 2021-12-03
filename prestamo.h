#ifndef PRESTAMO_H_INCLUDED
#define PRESTAMO_H_INCLUDED
typedef struct
{
    int id;
    int idCliente;
    float importe;
    int cantidadCuotas;
    int estadoPrestamo;
    int isEmpty;

}ePrestamo;

int inicializarPrestamo(ePrestamo prestamos[], int tam);
int buscarLibrePrestamo(ePrestamo prestamos[], int tam);
int altaPrestamo(ePrestamo prestamos[], int tamP,eCliente lista[], int tam, int* pIdPrestamo);
void mostrarPrestamo( ePrestamo unPrestamo, int idCliente ,eCliente lista[], int tam);
int mostrarPrestamos( ePrestamo prestamos[], int idCliente ,eCliente lista[], int tam);
void mostrarEncabezadoPrestamos(char aux[50]);
int saldarPrestamo(ePrestamo prestamos[],  int tamP,eCliente lista[], int tam);
int reanudarPrestamo(ePrestamo prestamos[],  int tamP,eCliente lista[], int tam);
int buscarPrestamos( ePrestamo prestamos[], int tamP, int Id );

#endif // PRESTAMO_H_INCLUDED
