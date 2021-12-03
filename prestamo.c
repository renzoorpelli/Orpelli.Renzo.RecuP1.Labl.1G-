#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "clientes.h"
#include "bibilotecaPersonal.h"
#include "prestamo.h"

int inicializarPrestamo(ePrestamo prestamos[], int tam)
{
    int checkStatus = -1;
    if (prestamos != NULL && tam > 0)
    {
        for (int i = 0; i < tam; i++)
        {
            prestamos[i].isEmpty = 1;
        }
        checkStatus = 0;
    }

    return checkStatus;
}

int buscarLibrePrestamo(ePrestamo prestamos[], int tam)
{
    int checkStatus = -1;
    for (int i = 0; i < tam; i++)
    {
        if (prestamos[i].isEmpty)
        {
            checkStatus = i;
            break;
        }
    }

    return checkStatus;
}


int altaPrestamo(ePrestamo prestamos[], int tamP,eCliente lista[], int tam, int* pIdPrestamo)
{
    int todoOk = 0;
    int indice;
    ePrestamo auxPrestamo;

    if( prestamos != NULL && tamP > 0 &&lista != NULL && tam > 0 && pIdPrestamo != NULL)
    {
        system("cls");
        printf("            ***ALTA PRESTAMOS***     \n");
        indice = buscarLibrePrestamo(prestamos, tamP);
        if (indice == -1)
        {
            printf("Errorr, no hay mas lugar\n");
        }
        else
        {
            auxPrestamo.id = *pIdPrestamo;
            (*pIdPrestamo)++;

            mostrarClientes(lista, tam);
            printf("Ingrese id CLIENTE:\n");
            scanf("%d", &auxPrestamo.idCliente);
            while(buscarCliente(lista, tam, auxPrestamo.idCliente) == -1)
            {
                printf("Error ingrese un id de cliente valido: \n");
                scanf("%d", &auxPrestamo.idCliente);
            }

            validarFloat(&auxPrestamo.importe,"Ingrese importe del prestamo: de 1000 a 1000000\n", "***ERRORR****", 1000, 100000, 20);
            validarEntero(&auxPrestamo.cantidadCuotas,"Ingrese la cantidad  cuotas: de 6- 150\n", "***ERRORR****", 6, 150, 20 );
            auxPrestamo.estadoPrestamo = 1;

            auxPrestamo.isEmpty = 0;
            prestamos[indice] = auxPrestamo;
            todoOk = 1;

        }

    }

    return todoOk;
}


void mostrarPrestamo( ePrestamo unPrestamo, int idCliente,eCliente lista[], int tam)
{
    char nombre[20];
    char apellido[20];

    if (cargarNombreCliente(lista, tam, idCliente, nombre) == 1 &&
            cargarApellidoCliente(lista, tam, idCliente, apellido) ==1
       )
    {
        printf(" %d                 %d                  %10s            %10s            %.2f            %d              %d\n",
               unPrestamo.id,
               unPrestamo.idCliente,
               nombre,
               apellido,
               unPrestamo.importe,
               unPrestamo.cantidadCuotas,
               unPrestamo.estadoPrestamo
              );
    }
}


int mostrarPrestamos( ePrestamo prestamos[],  int tamP,eCliente lista[], int tam)
{
    int checkStatus = 0;
    int flag = 1;

    if( prestamos != NULL && tamP > 0 &&lista != NULL && tam > 0)
    {
        mostrarEncabezadoPrestamos("PRESTAMOS");
        for (int i = 0; i < tam ; i++)
        {
            if(!prestamos[i].isEmpty)
            {
                mostrarPrestamo(prestamos[i],prestamos[i].idCliente, lista, tam);
                flag=0;
            }
        }
        if (flag)
        {
            printf("No hay prestamos para mostrar.\n");

        }
        checkStatus = 1;

    }
    return checkStatus;
}

void mostrarEncabezadoPrestamos(char aux[50])
{
    system("cls");
    printf("                                                                        **** LISTA %s****      \n", aux);
    printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    printf(" ID PRESTAMO    ID CLIENTE    NOMBRE CLIENTE    APELLIDO CLIENTE    CUIL CLLIENTE       IMPORTE CLIENTE     CANTIDAD CUOTAS CLIENTE         ESTADO PRESTAMO\n");
    printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
}



int saldarPrestamo(ePrestamo prestamos[],  int tamP,eCliente lista[], int tam)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirmaCambio = 's';
    if(prestamos != NULL &&  tamP > 0 && lista != NULL && tam > 0)
    {
        system("cls");
        printf("   *** SALDAR PRESTAMO DEL SISTEMA *** \n\n");
        mostrarPrestamos(prestamos, tamP, lista, tam);
        printf("------------------------------------------------------------\n");
        printf("Ingrese id del prestamo: ");
        scanf("%d", &id);

        indice = buscarPrestamos(prestamos, tamP, id);

        if (indice == -1)
        {
            printf("El id: %d no esta registrado en el sistema\n", id);
        }
        else
        {
            printf("Confirma el cambio? S o N \n");
            fflush(stdin);
            scanf("%c", &confirmaCambio);
            confirmaCambio = tolower(confirmaCambio);
            while(confirmaCambio != 's' && confirmaCambio !='n')
            {
                printf("Confirma el cambio? S o N \n");
                fflush(stdin);
                scanf("%c", &confirmaCambio);
                confirmaCambio = tolower(confirmaCambio);
            }
            if( confirmaCambio == 's')
            {
                printf("PRESTAMO SALDADO CORRECTAMENTE\n");
                prestamos[indice].estadoPrestamo = 0;
                todoOk = 1;
            }
            else
            {
                printf("mofificacion cancelada por el usuario\n");
            }

        }
    }
        return todoOk;
}


int reanudarPrestamo(ePrestamo prestamos[],  int tamP,eCliente lista[], int tam)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirmaCambio = 's';
    if(prestamos != NULL &&  tamP > 0 && lista != NULL && tam > 0)
    {
        system("cls");
        printf("   *** REANUDAR PRESTAMO DEL SISTEMA *** \n\n");
        mostrarPrestamos(prestamos, tamP, lista, tam);
        printf("------------------------------------------------------------\n");
        printf("Ingrese id del prestamo: ");
        scanf("%d", &id);

        indice = buscarPrestamos(prestamos, tamP, id);

        if (indice == -1)
        {
            printf("El id: %d no esta registrado en el sistema\n", id);
        }
        else
        {
            printf("Confirma el cambio? S o N \n");
            fflush(stdin);
            scanf("%c", &confirmaCambio);
            confirmaCambio = tolower(confirmaCambio);
            while(confirmaCambio != 's' && confirmaCambio !='n')
            {
                printf("Confirma el cambio? S o N \n");
                fflush(stdin);
                scanf("%c", &confirmaCambio);
                confirmaCambio = tolower(confirmaCambio);
            }
            if( confirmaCambio == 's')
            {
                printf("PRESTAMO REANUDADO CORRECTAMENTE\n");
                prestamos[indice].estadoPrestamo = 1;
                todoOk = 1;
            }
            else
            {
                printf("mofificacion cancelada por el usuario\n");
            }

        }
    }
        return todoOk;
}


int buscarPrestamos( ePrestamo prestamos[], int tamP, int Id )
{
    int indice = -1;
    for (int i = 0; i < tamP; i++)
    {
        if (prestamos[i].id == Id && prestamos[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}
