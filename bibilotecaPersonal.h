#ifndef BIBILOTECAPERSONAL_H_INCLUDED
#define BIBILOTECAPERSONAL_H_INCLUDED

/** BIBLIOTECA PERSONAL PARA VALIDACIONES Orpelli Renzo division 1g
 */


// Validaciones Numeros
int encontrarParidad(int numero);
int pedirEntero();
int pedirEnteroRango(int min, int max);
int validarDistintoDeCero(int numero);
int validarDecimales(float numero);
int getInt(int *pResultado);
int validarEntero(int *pResultado, char *mensaje, char *mensajeError,int minimo, int maximo, int reintentos);
int esNumerica(char *cadena);
int getFloat(float *pResultado);
int validarFloat(float *pResultado, char *mensaje, char *mensajeError, float minimo, float maximo, int reintentos);
int esNumericoFlotante(char cadena[]);
// Validaciones Cadenas
int miStrlen(char vect[]);
int validarCadena(char vect[]);
int pedirCadena(char cadena[], char mensaje[], int limite);
int setMayus(char cadena[]);
int myGets(char *cadena, int longitud);

#endif // BIBILOTECAPERSONAL_H_INCLUDED
