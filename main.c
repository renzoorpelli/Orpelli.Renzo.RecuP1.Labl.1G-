#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "clientes.h"
#include "prestamo.h"
#include "informes.h"
#define TAM 20
#define TAMP 20
int main()
{
    char seguir = 's';
    char salir;
    eCliente lista[TAM];
    int defaultIdCliente = 10000;
    int defaultIdPrestamo = 20000;
    ePrestamo prestamos[TAMP];

    if ( !inicializarClientes(lista, TAM) )
    {
        printf("Error al iniciar clientes\n");
    }

    if(!inicializarPrestamo(prestamos, TAMP))
    {
        printf("Error al iniciar prestamos\n");
    }

    do
    {
        switch (menu())
        {
        case 1:
            if( !altaCliente(lista, TAM, &defaultIdCliente) )
            {
                printf("No se pudo realizar el alta con exito\n");
            }
            else
            {
                printf("Alta exitosa\n");
            }

            break;
        case 2:
            if(!modificarCliente(lista, TAM))
            {
                printf("No se pudo llevar a cabo la modificacion de datos\n");
            }
            break;
        case 3:
            if(!bajaCliente(lista, TAM))
            {
                printf("No se pudo realizar la baja\n");
            }
            break;
        case 4:
            system("cls");
            if ( !altaPrestamo(prestamos, TAMP, lista, TAM, &defaultIdPrestamo))
            {
                printf("No se pudo DAR DE ALTA EL RPESTAMO\n");
            }
            break;
        case 5:
            system("cls");
            if ( !saldarPrestamo(prestamos, TAMP, lista, TAM) )
            {
                printf("No se pudo SALDAR PRESTAO\n");
            }
            break;
        case 6:
            system("cls");

            if ( !reanudarPrestamo(prestamos, TAMP, lista, TAM) )
            {
                printf("No se pudo mostrar los destinos\n");
            }
            break;
        case 7:
            system("cls");
            if ( !mostrarClientes(lista, TAM) )
            {
                printf("No se pudo mostrar los clientes\n");
            }
            break;
        case 8:
            system("cls");
            if ( !mostrarPrestamos(prestamos, TAMP, lista, TAM) )
            {
                printf("No se pudo mostrar los clientes\n");
            }
            break;
        case 9:
            switch(menuInformes())
            {
            case 1:
                if( !informarClientesMasPrestamos(lista, TAM, prestamos, TAMP))
                {
                    printf("No se pudo informar\n");
                }
                break;
            case 2:
                if( !informarClientesMenosPrestamos(lista, TAM, prestamos, TAMP))
                {
                    printf("No se pudo informar\n");
                }
                break;
            case 3:
                if( !informarPrestamosSegunImporte(prestamos, TAMP, lista, TAM))
                {
                    printf("No se pudo informar\n");
                }
                break;
            }
            break;

        case 10:
            printf("Esta seguro que quiere salir? S o N \n");
            fflush(stdin);
            scanf("%c", &salir);
            salir = toupper(salir);
            if (salir == 'S')
            {
                seguir = 'n';
            }
            else
            {
                break;
            }
            break;
        default:
            printf("Opcion invalida\n");
        }
        system("pause");

    }
    while(seguir == 's');


    return 0;
}
