#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#include "localidad.h"
#include "utn.h"
#include "cliente.h"



int hardcodearClientes(eCliente listaDeClientes[],int tamanioClientes, int *pIdCliente)
{

    int retorno = -1;


    char nombres[10][51]= {"Donato","German","Gunda","Carmen","Daniela","Maria","Alex","Damian","Gaston","Santiago"};
    char apellidos[10][51]= {"Perez","Morales","Lopez","Huber","Fraiese","Parodi","Ferraro","Taboada","Zermo","Contardi"};
    int idLocalidades[10] = {100,106,102,101,101,104,105,102,105,103};
    char telefonos[10][21]= {"4204-6286","11-2650-6432","15-2435-8963","4265-9842","4895-6542","11-2256-6845","15-4789-7263","11-3548-4632","4289-4563","4222-4555"};
    char sexos[10]= {'m','m','f','f','f','f','m','m','m','m'};

    if(listaDeClientes != NULL && tamanioClientes >0 && pIdCliente !=NULL)
    {
        for(int i = 0; i<10; i++)
        {

            listaDeClientes[i].codigo = *pIdCliente;
            (*pIdCliente)++;

            strcpy(listaDeClientes[i].nombre,nombres[i]);
            strcpy(listaDeClientes[i].apellido,apellidos[i]);
            listaDeClientes[i].idLocalidad = idLocalidades[i];
            strcpy(listaDeClientes[i].telefono,telefonos[i]);
            listaDeClientes[i].sexo = sexos[i];
            listaDeClientes[i].isEmpty = 0;

        }
        retorno = 0;

    }


    return retorno;

}

int inicializarClientes(eCliente listaDeClientes[],int tamanioClientes)
{
    int error = -1;

    if(listaDeClientes != NULL &&tamanioClientes>0)
    {
        error = 0;

        for (int i = 0; i < tamanioClientes; ++i)
        {
            listaDeClientes[i].isEmpty = 1;
        }
    }
    return error;
}


int buscarLibre(eCliente listaDeClientes[], int tamanioClientes)
{
    int indice = -1;

    for(int i = 0; i < tamanioClientes; i++)
    {
        if(listaDeClientes[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int buscarCliente(eCliente listaDeClientes[], int tamClientes,int idCliente)
{
    int indice=-1;

    if(listaDeClientes!=NULL && tamClientes>0)
    {

        for(int i=0; i<tamClientes; i++)
        {
            if(idCliente == listaDeClientes[i].codigo && !listaDeClientes[i].isEmpty)
            {
                indice=i;
                break;
            }
        }
    }

    return indice;
}



int altaCliente(eCliente listaDeClientes[],eLocalidad listaDeLocalidades[],int tamLocalidades, int tamanioClientes,int* pIdCliente)
{

    int retorno=-1;
    int indice;
    eCliente nuevoCliente;

    if(listaDeClientes!=NULL && pIdCliente != NULL && listaDeLocalidades != NULL && tamanioClientes >0 && tamLocalidades >0)
    {
        system("cls");
        printf("      Alta Cliente\n\n");
        indice = buscarLibre(listaDeClientes,tamanioClientes);
        if(indice!=-1)
        {

            if(utn_getCadena(nuevoCliente.nombre,51,"Ingrese nombre: ","Error re ingrese el nombre\n",5)&&
                    utn_getCadena(nuevoCliente.apellido,51,"Ingrese apellido: ","Error re ingrese el apellido \n",5)&&
                    utn_getCaracter(&nuevoCliente.sexo,"Ingrese sexo: ","Error re ingrese sexo\n",'f','m',5)&&
                    utn_getCadena(nuevoCliente.telefono,21,"Ingrese el telefono: ","Error telefono demasiado largo.\n",5)
              )

            {
                listarLocalidades(listaDeLocalidades,tamLocalidades);

                if(utn_getNumero(&nuevoCliente.idLocalidad,"Ingrese el ID de la localidad\n","Error, re ingrese ID",100,107,4))
                {
                    strcpy(listaDeClientes[indice].nombre,nuevoCliente.nombre);
                    strcpy(listaDeClientes[indice].apellido,nuevoCliente.apellido);
                    listaDeClientes[indice].sexo = nuevoCliente.sexo;
                    listaDeClientes[indice].isEmpty = 0;
                    listaDeClientes[indice].codigo = *pIdCliente;
                    listaDeClientes[indice].idLocalidad = nuevoCliente.idLocalidad;
                    strcpy( listaDeClientes[indice].telefono,nuevoCliente.telefono);
                    (*pIdCliente)++;
                    retorno = 1;

                }
                else
                {
                    printf("Error, no se pudo dar de alta el cliente.");
                }

            }
            else
            {
                printf("Error, no se pudo dar de alta el cliente.");
            }
        }
        else
        {
            printf("No hay lugar para cargar mas clientes.\n");
        }
    }
    return retorno;


}


int menu (int *opcionMenu)
{
    int error = -1;
    int opcion;

    if(opcionMenu != NULL)
    {


        printf("\n*** ABM Juegos ***\n\n");
        printf("1 Alta Cliente\n");
        printf("2 Modificar Cliente\n");
        printf("3 Baja Cliente\n");
        printf("4 Listar Clientes\n");
        printf("5 Alta Alquiler\n");
        printf("6 Listar Alquiler\n");
        printf("7 Mostrar Juegos de mesa\n");
        printf("8 Mostrar Alquileres por cliente\n");
        printf("9 Mostrar Acumulado por cliente\n");
        printf("10 Mostrar Clientes que no alquilaron juegos\n");
        printf("11 Mostrar Juegos sin alquiler\n");
        printf("12 Mostrar clientes por fecha de alquiler\n");
        printf("13 Mostrar clientes por localidad\n");
        printf("14 Contar clientes por localidad\n");
        printf("15 Salir\n");


        if(utn_getNumero(&opcion,"\nIngrese la opcion deseada\n","Error, opcion invalida\n",1,15,4))
        {
            *opcionMenu = opcion;
        }
        error = 0;

    }
    return error;
}

int obtenerDescripcionLocalidad(eLocalidad listaDeLocalidades[],eCliente unCliente,int tamLocalidades, char descripcionLocalidad[])
{
    int error = -1;
    //int indice;

    if(listaDeLocalidades != NULL && tamLocalidades >0 && descripcionLocalidad != NULL)
    {

        for(int i = 0; i<tamLocalidades; i++)
        {

            if(listaDeLocalidades[i].idLocalidad == unCliente.idLocalidad)
            {

                strcpy(descripcionLocalidad, listaDeLocalidades[i].descripcion);
                error = 1;
                break;
            }

        }

    }

    return error;
}

int listarClientes(eCliente listaDeClientes[],eLocalidad listaDeLocalidades [],int tamClientes,int tamLocalidades)
{

    int error = 1;
    int flag = 0;

    if( listaDeClientes != NULL && tamClientes > 0 )
    {
        system("cls");
        //ordenarNotebooks(listaDeClientes,tamNotebook);
        printf(" Codigo           Nombre             Apellido             Sexo           Telefono           Localidad\n");
        printf("---------------------------------------------------------------------------------------------------------\n");

        for(int i=0; i<tamClientes; i++)
        {
            if(!verificarExistenciaCliente(listaDeClientes,tamClientes)&& listaDeClientes[i].isEmpty == 0)
            {
                //  mostrarUnCliente(listaDeClientes[i]);
                mostrarUnCliente(listaDeClientes[i],listaDeLocalidades,tamLocalidades);
                flag = 1;
                error = 0;
            }
        }

        if( flag == 0)
        {
            printf("    No hay clientes en la lista\n");
        }

    }
    return error;

}




int mostrarUnCliente(eCliente unCliente,eLocalidad listaDeLocalidades [], int tamLocalidades)
{
    int error = -1;
    char Localidad [51];

    if(listaDeLocalidades != NULL && tamLocalidades >0 && obtenerDescripcionLocalidad(listaDeLocalidades,unCliente,tamLocalidades,Localidad))
    {
        error = 1;

        printf("%d             %10s           %10s              %c          %10s       %10s\n",unCliente.codigo,unCliente.nombre,unCliente.apellido,unCliente.sexo,unCliente.telefono,Localidad);
    }
    return error;
}


int verificarExistenciaCliente(eCliente listaDeClientes[], int tamClientes)
{
    int error= -1;

    if(listaDeClientes!=NULL && tamClientes > 0)
    {
        for(int i=0; i<tamClientes; i++)
        {
            if(listaDeClientes[i].isEmpty == 0)
            {
                error=0;
                break;
            }
        }
    }
    return error;
}

int modificarClientes(eCliente listaDeClientes[], eLocalidad listaDeLocalidades [],int tamClientes, int tamLocalidades)
{
    int retorno= -1;
    int flag = 0;
    int indice;
    int opcion;
    int idCliente;
    eCliente auxCliente;


    if(listaDeClientes!=NULL && listaDeLocalidades != NULL && tamClientes>0 && tamLocalidades) // CAMBIAR
    {

        listarClientes(listaDeClientes,listaDeLocalidades,tamClientes,tamLocalidades);
        utn_getNumero(&idCliente,"ingrese la ID del cliente","Error, numero invalido",1,20,4);

        indice = buscarCliente(listaDeClientes,tamClientes,idCliente);

        if(indice==-1)
        {
            printf("No se encontro ningun cliente con ese codigo.\n");
        }
        else
        {

            printf(" Codigo           Nombre             Apellido             Sexo           Telefono       IdLocalidad      Localidad\n");
            printf("---------------------------------------------------------------------------------------------------------------------\n");

            mostrarUnCliente(listaDeClientes[indice],listaDeLocalidades,tamLocalidades);

            do
            {
                if(utn_getNumero(&opcion,"Ingrese la opcion para modificar\n1-Nombre\n2-Apellido\n3-Sexo\n4-Localidad\n5-Salir\n","Error, opcion no valida\n",1,5,4))
                {
                    switch(opcion)
                    {
                    case 1:
                        if(utn_getCadena(auxCliente.nombre,51,"Ingrese el nombre a reemplazar\n","Error\n",4))
                        {
                            strcpy(listaDeClientes[indice].nombre,auxCliente.nombre);
                            flag = 1;
                        }
                        break;

                    case 2:
                        if(utn_getCadena(auxCliente.apellido,51,"Ingrese el apellido a reemplazar\n","Error\n",4))
                        {
                            strcpy(listaDeClientes[indice].apellido,auxCliente.apellido);
                            flag = 1;
                        }
                        break;
                    case 3:
                        if(utn_getCaracter(&auxCliente.sexo,"Ingrese sexo\n","Error, parametro incorrecto\n",'f','m',4))
                        {
                            listaDeClientes[indice].sexo = auxCliente.sexo;
                            flag = 1;
                        }
                        break;

                    case 4:

                        listarLocalidades(listaDeLocalidades,tamLocalidades);

                        if(utn_getNumero(&auxCliente.idLocalidad,"Ingrese el Id del Localidad a modificar\n","Error, ID inexistente\n",100,107,5))
                        {
                            listaDeClientes[indice].idLocalidad = auxCliente.idLocalidad;
                            flag = 1;
                        }
                        break;
                    case 5:
                        if(flag)
                        {
                            retorno = 0;
                        }
                        else
                        {
                            retorno = 2;
                        }
                        break;

                    }
                }

            }
            while(opcion!=5);
        }
    }
    return retorno;
}


int bajaCliente(eCliente listaDeClientes[], eLocalidad listaDeLocalidades [],int tamClientes, int tamLocalidades,int *pIdCliente)
{
    int retorno= -1;
    int indice;
    int opcion;
    int idCliente;

    printf("*** Baja Cliente ***\n\n");
    if(listaDeClientes!=NULL && tamClientes >0)
    {
        listarClientes(listaDeClientes,listaDeLocalidades,tamClientes,tamLocalidades);
        utn_getNumero(&idCliente,"\ningrese la ID","Error, numero invalido",1,20,4);
        indice = buscarCliente(listaDeClientes, tamClientes,idCliente);
        *pIdCliente = idCliente;

        if(indice==-1)
        {
            printf("No se encontro ningun cliente con ese codigo.\n");
        }
        else
        {
            printf(" Codigo           Nombre             Apellido             Sexo\n");
            printf("-------------------------------------------------------------------------\n");
            mostrarUnCliente(listaDeClientes[indice],listaDeLocalidades,tamLocalidades);

            if(utn_getNumero(&opcion,"Desea dar de baja a este cliente?\n1-Si\2-No\n", "Error, numero incorrecto.\n",0,1,10))
            {
                if(opcion == 1)
                {
                    listaDeClientes[indice].isEmpty=1;

                    retorno = 0;
                }
                else
                {
                    printf("Baja cancelada.\n");
                    retorno = 1;
                }
            }

        }
    }

    return retorno;
}

int ordenarClientes(eCliente listaDeClientes [], int tamClientes)
{
    int retorno = -1;
    eCliente auxCliente;

    if(listaDeClientes != NULL && tamClientes >0)
    {
        for(int i = 0; i<tamClientes-1; i++)
        {
            for(int j = i +1; j<tamClientes; j++)
            {
                retorno = 1;
                if(strcmp(listaDeClientes[i].apellido,listaDeClientes[j].apellido)>0)
                {
                    auxCliente = listaDeClientes[i];
                    listaDeClientes[i] = listaDeClientes[j];
                    listaDeClientes[j] = auxCliente;
                }
                else
                {
                    if(strcmp(listaDeClientes[i].apellido,listaDeClientes[j].apellido) == 0)
                    {
                        if(strcmp(listaDeClientes[i].nombre,listaDeClientes[j].nombre)>0)
                        {
                            auxCliente = listaDeClientes[i];
                            listaDeClientes[i] = listaDeClientes[j];
                            listaDeClientes[j] = auxCliente;
                        }
                    }
                }
            }
        }

    }

    return retorno;
}
int listarClientesPorLocalidad(eCliente listaDeClientes [],eLocalidad listaDeLocalidades [],int tamLocalidad, int tamClientes)
{
    int retorno = -1;
    int idCliente;
    int idLocalidad;
    if(listaDeClientes!=NULL && listaDeLocalidades!=NULL && tamLocalidad >0 && tamClientes>0)
    {
        listarLocalidades(listaDeLocalidades,tamLocalidad));

        if(utn_getNumero(&idLocalidad,"Ingrese el id de la localidad\n","Error, id invalido\n",100,1074))
        {
            for(int i = 0; i<tamClientes;i++)
            {
                if(listaDeClientes[i].idLocalidad == idLocalidad)
                {
                    mostrarUnCliente(listaDeClientes[i],listaDeLocalidades,tamLocalidad);
                }
            }

            retorno = 1;
        }

    }

    return retorno;

}
int getIdCliente(eCliente listaDeClientes[],eLocalidad listaDeLocalidades[],int tamClientes,int tamLocalidades)
{
    int idCliente;

    listarClientes(listaDeClientes,listaDeLocalidades,tamClientes,tamLocalidades);

    utn_getNumero(&idCliente,"Ingrese la id del cliente\n","Error,id incorrecta",1,15,5);
    while(buscarCliente(listaDeClientes,tamClientes,idCliente)==-1)
    {
        utn_getNumero(&idCliente,"Ingrese la id del cliente\n","Error,id incorrecta",1,15,5);
    }

    printf("\n");

    return idCliente;
}

