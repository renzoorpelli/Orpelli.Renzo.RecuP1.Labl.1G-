#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
typedef struct
{
    int id;
    char nombre[20];
    char apellido[20];
    int cuil;
    int isEmpty;

}eCliente;

int menu();
int inicializarClientes(eCliente lista[], int tam);
int buscarLibre(eCliente lista[], int tam);

int altaCliente(eCliente lista[], int tam, int* pId);
int bajaCliente(eCliente lista[], int tam);
int mostrarClientes(eCliente lista[], int tam);
int buscarCliente( eCliente lista[], int tam, int Id );

int modificarCliente(eCliente lista[], int tam);
int menuModificar( eCliente lista[], int tam, int indice);

int cargarNombreCliente(eCliente lista[], int tam, int idCliente, char nombre[]);
int cargarApellidoCliente(eCliente lista[], int tam, int idCliente, char apellido[]);

#endif // CLIENTES_H_INCLUDED
