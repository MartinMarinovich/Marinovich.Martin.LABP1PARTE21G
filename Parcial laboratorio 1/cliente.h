#include "localidad.h"

#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct{

	int codigo;
	int idLocalidad;
	char nombre[51];
	char apellido[51];
	char sexo;
	char telefono [21];
	int isEmpty;

}eCliente;


#endif // CLIENTE_H_INCLUDED


/*Brief Para incicar que todas las posiciones en el array estan vacias
 * esta funcion recorre el array y pone el flag"isEmpty" en 1,retorna 0 si se ejecuto correctamente
 * 1 si no se pudo realizara
 *
 * param llistaDeClientes
 * param tamanioClientes del array que pasamos por referencia
 * return 0 si esta ok o 1 si salio mal
 */

int inicializarClientes(eCliente listaDeClientes[],int tamanioClientes);


/*Brief La funcion buscarLibre recorre el array en busca de la primer posicion libre y la retorna si la encontro

 * param listaDeClientes
 * param tamanioClientes del array que pasamos por referencia
 * return la posicion libre en el array
 */

int buscarLibre(eCliente listaDeClientes[], int tamanioClientes);

/*Brief La funcion ordenar clientes recibe la lista de clientes y su tamanio y los oredena por apellido y nombre
 * param llistaDeClientes
 * param tamanioClientes del array que pasamos por referencia
 * return 1 si pudo ordenarlos 0 si salio mal
 */
int ordenarClientes(eCliente listaDeClientes [], int tamClientes);

/*Brief La funcion altaCliente solicita al usuario que ingrese los datos que va a llevar el cliente que ingresemos al sistema a traves de los vectores
 * estructura "listaDeClientes,listaDeLocalidades, y sus respectivos tamanios, para luego una vez que asigno los datos
 * le asgian un ID autoincremental
 *
 * param  listaDeClientes vector estructura de clientes
 * param  listaDeLocalidades vector estructura de Localidads
 * param  tamLocalidades  vector estructura de Localidads
 * param  tamanioClientes vector estructura de clientes
 * param  pIdCliente puntero a la variable id autoincremental
 *
 * return 0 si esta ok o 1 si salio mal
 */


int altaCliente(eCliente listaDeClientes[],eLocalidad listaDeLocalidades[],int tamLocalidades, int tamanioClientes,int* pIdCliente);

/*Brief la funcion Menu despliega el menu de la aplicacion y recibe el puntero a la direccion de memoria donde se encuetra la vatiable opcionMenu
 *param popcion menu puntero a la variable opcion
 *
 * return 0 si esta ok o 1 si salio mal
 */
int menu (int *opcionMenu);

/*Brief la funcion listarClientes recibe los listados de Clientes y tamanio del listado
 * para mostrarlos en pantalla
 *
 * param listaDeClientes vector de estructura de clientes
 * param tamClientes tamanio del vector

 *return 0 si salio bien 1 si salio mal
 */

//int listarClientes(eCliente listaDeClientes[],int tamClientes);
int listarClientes(eCliente listaDeClientes[],eLocalidad listaDeLocalidades [],int tamClientes,int tamLocalidades);

int verificarExistenciaCliente(eCliente listaDeClientes[], int tamClientes);

/*Brief la funcion mostarUnCliente recibe una estrcuctura de tipo cliente
 *
 * param UnCliente proveniente de la posicion que se desea mostrar

 */

//void mostrarUnCliente(eCliente unCliente);

int mostrarUnCliente(eCliente unCliente,eLocalidad listaDeLocalidades [], int tamLocalidades);

/*Brief la funcion modificarClientes recibe el vector listaDeclientes, el tamanio del vector
 * recorre el array de Clientes en busca del ID que coincida con el que buscamos para modificar los campos qeu se desee
 *
 * param listaDeclientes vector de estructura de cleintes
 * param tamClientes tamanio del vector
 *
 * return 1 si salio bien 0 si salio mal
 */

//int modificarClientes(eCliente listaDeClientes[], int tamClientes);
int modificarClientes(eCliente listaDeClientes[], eLocalidad listaDeLocalidades [],int tamClientes, int tamLocalidades);

/*Brief la funcion buscarCliente recibe el vector listaDeClientes, el tamanio del vector y la ID del cliente buscado,
 * recorre el array de clientes en busca del ID que coincida con el que buscamos
 *
 * param listaDeClientes vector de estructura de clientes
 * param tamClientes tamanio del vector
 * param idCliente ID de la cliente que deseamos buscar
 * return 1 si salio bien 0 si salio mal
 */

int buscarCliente(eCliente listaDeClientes[], int tamClientes,int idCliente);

/*Brief la funcion BajaCliente realiza la baja logica del cliente buscado poniendo el flag IsEmpty en 1 segun
    recibe la lista de clientes y su tamanio
 *
 * param listaDeClientes,vector lista de clientes
 * param tamClientes tamnaio del vector
 *
 *return 1 si se ejecuto correctamente 0 si no se pudo realizar
 */

//int bajaCliente(eCliente listaDeClientes[], int tamClientes);

int bajaCliente(eCliente listaDeClientes[], eLocalidad listaDeLocalidades [],int tamClientes, int tamLocalidades,int *pIdCliente);


int hardcodearClientes(eCliente listaDeClientes[],int tamanioClientes, int *pIdCliente);

/*Brief la funcion getIdCliente recibe la lista de clientes y su tamanio para buscar el id que deseamos
 *
 * param listaDeClientes,vector lista de clientes
 * param tamClientes tamnaio del vector
 *
 *return devuelve el id
 */

int getIdCliente(eCliente listaDeClientes[],eLocalidad listaDeLocalidades[],int tamClientes,int tamLocalidades);

int obtenerDescripcionLocalidad(eLocalidad listaDeLocalidades[],eCliente unCliente,int tamLocalidades, char descripcionLocalidad[]);


