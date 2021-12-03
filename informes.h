#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include "clientes.h"
#include "prestamo.h"
int menuInformes();
int informarClientesMasPrestamos(eCliente lista[], int tam,  ePrestamo prestamos[], int tamP);
int informarClientesMenosPrestamos(eCliente lista[], int tam,  ePrestamo prestamos[], int tamP);
int informarPrestamosSegunImporte(ePrestamo prestamos[],  int tamP,eCliente lista[], int tam);
int buscarPrestamosSegunImporte(float importe, ePrestamo prestamos[],  int tamP,eCliente lista[], int tam);

#endif // INFORMES_H_INCLUDED
