#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "clientes.h"
#include "bibilotecaPersonal.h"


int menu()
{
    int opcion = 0;
    system("cls");
    printf("------------------------------\n");
    printf("    ***FINANCIERA***   \n");
    printf("------------------------------\n");
    printf("1- ALTA CLIENTE\n");
    printf("2- MODIFICAR CLIENTE\n");
    printf("3- BAJA CLIENTE\n");
    printf("4- ALTA PRESTAMO\n");
    printf("5- SALDAR PRESTAMO\n");
    printf("6. REANUDAR PRESTAMO\n");
    printf("7- IMPRIMIR CLIENTES\n");
    printf("8- IMPRIMIR PRESTAMOS\n");
    printf("9- MOSTRAR INFORMES\n");
    printf("10- SALIR\n");
    fflush(stdin);
    validarEntero(&opcion,"Ingrese opcion: \n", "***ERROR***", 1, 10, 20 );
    return opcion;
}



int inicializarClientes(eCliente lista[], int tam)
{
    int todoOk = 0;
    if (lista != NULL && tam > 0)
    {
        todoOk = 1;
        for (int i = 0; i < tam; i++)
        {
            lista[i].isEmpty = 1;
        }
    }
    return todoOk;
}


int buscarLibre(eCliente lista[], int tam)
{
    int indice = -1;
    for (int i = 0; i < tam; i++)
    {
        if (lista[i].isEmpty)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int altaCliente(eCliente lista[], int tam, int* pId)
{
    int todoOk = 0;
    int indice;
    eCliente auxCliente;
    char auxNombre[20];
    char auxApellido[20];


    if(lista != NULL && tam > 0 && pId != NULL)
    {
        system("cls");
        printf("            ***ALTA CLIENTES***     \n\n");
        printf("------------------------------------\n");
        indice = buscarLibre(lista, tam);
        if (indice == -1)
        {
            printf("No hay lugar\n");
        }
        else
        {
            auxCliente.id = *pId;
            (*pId)++;

            pedirCadena(auxNombre, "Ingrese nombre cliente:\n", 20);
            strcpy(auxCliente.nombre, auxNombre);
            pedirCadena(auxApellido, "Ingrese nombre cliente:\n", 20);
            strcpy(auxCliente.apellido, auxApellido);
            validarEntero(&auxCliente.cuil, "Ingrese cuil cliente: recuerde que el cuil es  xxxxxxxxxxx\n", "***ERROR****", 1000000, 50000000, 20);

            auxCliente.isEmpty = 0;
            lista[indice] = auxCliente;
            todoOk = 1;
        }
    }

    return todoOk;
}



void mostrarCliente( eCliente lista, int tam)// MODIFICADO
{
    //char nombre[20];
    // charapellido[20];

        printf("  %d          %10s      %10s       %d\n",
               lista.id,
               lista.nombre,
               lista.apellido,
               lista.cuil);
}

int mostrarClientes(eCliente lista[], int tam)
{
    int todoOk = 0;
    int flag = 1;

    if(lista != NULL && tam > 0 )
    {
        system("cls");
        printf("               **** LISTA DE CLIENTES****     \n");
        printf("-----------------------------------------------------------\n");
        printf(" ID             NOMBRE           APELLIDO              CUIL\n");
        printf("-----------------------------------------------------------\n");

        for (int i = 0; i < tam; i++)
        {
            if (!lista[i].isEmpty)
            {
                mostrarCliente(lista[i], tam);
                flag = 0;
            }
        }

        if (flag)
        {
            printf("No hay clientes para mostrar.\n");

        }
        todoOk = 1;
    }
    return todoOk;
}

int bajaCliente(eCliente lista[], int tam)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirmaBaja;

    if(lista != NULL && tam > 0)
    {
        system("cls");
        printf("   *** BAJA DE CLIENTES *** \n\n");
        mostrarClientes(lista, tam);
        printf("------------------------------------------------------------\n");
        printf("Ingrese id cliente: \n");
        scanf("%d", &id);

        indice = buscarCliente(lista, tam, id);

        if (indice == -1)
        {
            printf("El id: %d no esta registrado en el sistema\n", id);
        }
        else
        {
            mostrarCliente(lista[indice], tam);
            printf("Confirma baja del sistema? S o N: \n");
            fflush(stdin);
            scanf("%c", &confirmaBaja);
            confirmaBaja = tolower(confirmaBaja);
            if (confirmaBaja == 's')
            {
                lista[indice].isEmpty = 1;
                todoOk = 1;
            }
            else
            {
                printf("Baja cancelada por el usuario.\n");
            }

        }
    }
    return todoOk;
}


int buscarCliente( eCliente lista[], int tam, int Id )
{
    int indice = -1;
    for (int i = 0; i < tam; i++)
    {
        if (lista[i].id == Id && lista[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int modificarCliente(eCliente lista[], int tam)// MODIFICADO
{
    int todoOk = 0;
    int indice;
    int id;
    char confirmaCambio = 's';
    char seguir = 's';
    char salir;
    eCliente auxCliente;
    char auxNombre[20];
    char auxApellido[20];
    if(lista != NULL && tam > 0)
    {
        system("cls");
        printf("   *** MODIFICACION DE CLIENTES DEL SISTEMA *** \n\n");
        mostrarClientes(lista, tam);
        printf("------------------------------------------------------------\n");
        printf("Ingrese id del cliente: ");
        scanf("%d", &id);

        indice = buscarCliente(lista, tam, id);

        if (indice == -1)
        {
            printf("El id: %d no esta registrado en el sistema\n", id);
        }
        else
        {
            do
            {
                switch(menuModificar(lista,tam, indice))
                {
                case 1:
                    printf("*** MODIFICAR NOMBRE CLIENTE ***: \n");
                    pedirCadena(auxNombre, "Ingrese nombre cliente:\n", 20);
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
                        strcpy(lista[indice].nombre, auxNombre);
                    }
                    else
                    {
                        printf("mofificacion cancelada por el usuario\n");
                    }
                    break;
                case 2:
                    printf("*** MODIFICAR APELLIDO CLIENTE ***: \n");
                    pedirCadena(auxApellido, "Ingrese apellido cliente:\n", 20);
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
                        strcpy(lista[indice].apellido, auxApellido);
                    }
                    else
                    {
                        printf("mofificacion cancelada por el usuario\n");
                    }
                    break;
                case 3:
                    printf("*** MODIFICAR CUIL CLIENTE ***: \n");
                    validarEntero(&auxCliente.cuil, "Ingrese cuil cliente: recuerde que el cuil es  xxxxxxxxxxx\n", "***ERROR****", 1000000, 50000000, 20);
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
                        lista[indice].cuil = auxCliente.cuil;
                    }
                    else
                    {
                        printf("mofificacion cancelada por el usuario\n");
                    }
                    break;
                case 4:
                    printf("Usted eligio salir\n");
                    printf("Esta seguro que desea salir? S o N\n");
                    fflush(stdin);
                    scanf("%c", &salir);
                    salir = tolower(salir);
                    while ( salir != 's' && salir != 'n')
                    {
                        printf("Esta seguro que desea salir? S o N\n");
                        fflush(stdin);
                        scanf("%c", &salir);
                        salir = tolower(salir);
                    }
                    if (salir == 's')
                    {
                        seguir = 'n';
                    }
                    break;
                default:
                    printf("OPCION INVALIDA\n");
                    break;
                }

            }
            while(seguir == 's');
            todoOk = 1;
        }
    }

    return todoOk;
}


int menuModificar( eCliente lista[], int tam, int indice)
{
    int opcion = 0;
    system("cls");
    printf("-------------------------------------------------------------------------------------------\n");
    mostrarCliente(lista[indice], tam);
    printf("-------------------------------------------------------------------------------------------\n");
    printf("1- Editar nombre\n");
    printf("2- Editar apellido\n");
    printf("3- Editar CUIL\n");
    printf("4- Salir\n");
    fflush(stdin);
    validarEntero(&opcion, "Ingrese opcion: \n", "***ERROR*** ", 1,4,20);
    return opcion;
}

/*
int buscarClienteInformacion(int idCliente, eCliente lista[], int tam)
{
    int todoOk =-1;
    if(lista != NULL && tam>0)
    {
        for (int i =0; i <  tam; i++)
        {
            if (lista[i].id == idCliente)
            {
                *idTipo = lista[i].idTipo;
                *idChofer = lista[i].idChofer;
                *idEstructura = lista[i].idTipoViaje;
                todoOk = 1;
            }
        }
        todoOk =0;
    }

    return todoOk;
}*/


int cargarNombreCliente(eCliente lista[], int tam, int idCliente, char nombre[])
{
    int todoOk = 0;
    int flag = 1;
    if (lista != NULL && tam > 0 && nombre != NULL)
    {
        todoOk = 1;
        for (int i = 0; i < tam; i++)
        {
            if (lista[i].id == idCliente)
            {
                strcpy(nombre, lista[i].nombre);
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            todoOk = -1;
        }
    }
    return todoOk;
}
int cargarApellidoCliente(eCliente lista[], int tam, int idCliente, char apellido[])
{
    int todoOk = 0;
    int flag = 1;
    if (lista != NULL && tam > 0 && apellido != NULL)
    {
        todoOk = 1;
        for (int i = 0; i < tam; i++)
        {
            if (lista[i].id == idCliente)
            {
                strcpy(apellido, lista[i].apellido);
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            todoOk = -1;
        }
    }
    return todoOk;
}
