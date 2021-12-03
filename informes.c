#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "informes.h"
#include "bibilotecaPersonal.h"

#define PRESTAMO_SALDADO 0
#define PRESTAMO_ACTIVO 1

int menuInformes()
{
    int opcion = 0;
    system("cls");
    printf("------------------------------\n");
    printf("    ***INFORMES FINANCIERA***   \n");
    printf("------------------------------\n");
    printf("1- INFORMAR CLIENTES CON MAS PRESTAMOS ACTIVOS\n");
    printf("2- INFORMAR CLIENTES CON MAS PRESTAMOS SALDADOS\n");
    printf("3- INFORME CANTIDAD DE PRESTAMOS SEGUN IMPORTES\n");
    fflush(stdin);
    validarEntero(&opcion, "Ingrese opcion: ", "***ERROR***", 1, 3, 20);
    return opcion;
}


int informarClientesMasPrestamos(eCliente lista[], int tam,  ePrestamo prestamos[], int tamP)
{
    int todoOk = 0;
    int contadores[tamP];
    int mayor= 0;
    int flag =1;
    //inicializo contadores
    for(int i = 0; i < tamP; i++)
    {
        contadores[i] = 0;
    }
    if(prestamos != NULL &&  tamP > 0 && lista != NULL && tam > 0)
    {
        system("cls");
        printf("                   **** PERSONA MAS PRESTAMOS ACTIVOS****     \n");


        for (int i = 0; i < tam; i++)
        {
            for (int j = 0; j < tamP; j++)
            {
                if ( !lista[i].isEmpty && lista[i].id == prestamos[j].idCliente && prestamos[j].estadoPrestamo == PRESTAMO_ACTIVO)
                {
                    contadores[j]++;
                }
            }
        }

        for (int i = 0; i<tamP; i++)
        {
            if (flag|| contadores[i] > mayor)
            {
                mayor = contadores[i];
                flag = 0;
            }
        }

        for (int i = 0; i<tamP; i++)
        {
            if (contadores[i] == mayor)
            {
                printf("La persona con mas prestamos es  %s\n", lista[i].nombre);
            }
        }
        printf("con la cantidad de %d prestamos.\n", mayor);
        todoOk = 1;
    }
    return todoOk;
}


int informarClientesMenosPrestamos(eCliente lista[], int tam,  ePrestamo prestamos[], int tamP)
{
    int todoOk = 0;
    int contadores[tamP];
    int mayor= 0;
    int flag =1;
    //inicializo contadores
    for(int i = 0; i < tamP; i++)
    {
        contadores[i] = 0;
    }
    if(prestamos != NULL &&  tamP > 0 && lista != NULL && tam > 0)
    {
        system("cls");
        printf("                   **** PERSONA MAS PRESTAMOS SALDADOS****     \n");


        for (int i = 0; i < tam; i++)
        {
            for (int j = 0; j < tamP; j++)
            {
                if ( !lista[i].isEmpty && lista[i].id == prestamos[j].idCliente && prestamos[j].estadoPrestamo == PRESTAMO_SALDADO)
                {
                    contadores[j]++;
                }
            }
        }

        for (int i = 0; i<tamP; i++)
        {
            if (flag|| contadores[i] > mayor)
            {
                mayor = contadores[i];
                flag = 0;
            }
        }

        for (int i = 0; i<tamP; i++)
        {
            if (contadores[i] == mayor)
            {
                printf("La persona con mas prestamos saldados es  %s\n", lista[i].nombre);
            }
        }
        printf("con la cantidad de %d prestamos.\n", mayor);
        todoOk = 1;
    }
    return todoOk;
}


int informarPrestamosSegunImporte(ePrestamo prestamos[],  int tamP,eCliente lista[], int tam)
{
    float importe;
    int todoOk = 0;
    if(prestamos != NULL &&  tamP > 0 && lista != NULL && tam > 0)
    {
        system("cls");
        printf("               ***  INFORMAR PRESTAMO SEGUN IMPORTE  ***\n");
        printf("------------------------------------------------------------\n");
        validarFloat(&importe, "Ingrese IMPORTE PRESTAMO: \n", "***ERROR****", 1000, 100000, 20 );
        buscarPrestamosSegunImporte(importe, prestamos, tamP,lista, tam);
        todoOk = 1;
    }
    return todoOk;
}

int buscarPrestamosSegunImporte(float importe, ePrestamo prestamos[],  int tamP,eCliente lista[], int tam)
{
    int todoOk = 0;
    int flag = 1;
    if(prestamos != NULL &&  tamP > 0 && lista != NULL && tam > 0)
    {
        for (int i = 0; i < tamP ; i++)
        {
            if(!prestamos[i].isEmpty && prestamos[i].importe == importe)
            {
                mostrarEncabezadoPrestamos("PRESTAMOS");
                mostrarPrestamo(prestamos[i], prestamos[i].idCliente,lista, tam);
                flag = 0;
            }

        }
        if(flag)
        {
            printf("No hay IMPORTES DECLARADOS POR EL VALOR\n");
        }
        todoOk = 1;
    }
    return todoOk;
}
