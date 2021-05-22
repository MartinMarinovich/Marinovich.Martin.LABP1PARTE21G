#include <stdio.h>
#include <stdlib.h>

#include "alquileres.h"
#include "utn.h"
#include "juego.h"
#include "cliente.h"
#include "categoria.h"
#include "localidad.h"


#define TAM_CLIENTES 15
#define TAM_CATEGORIAS 5
#define TAM_JUEGOS 8
#define TAM_ALQUILERES 20
#define TAM_LOCALIDADES 8

int main()
{


    eJuego listaDeJuegos[TAM_JUEGOS];
    eCategoria listaDeCategorias[TAM_CATEGORIAS];
    eCliente listaDeClientes[TAM_CLIENTES];
    eAlquileres listaDeAlquileres[TAM_ALQUILERES];
    eLocalidad listaDeLocalidades[TAM_LOCALIDADES];

    int proximoIdAlquiler = 100;
    int proximoIdCliente = 1;
    int auxModificacion;
    int auxBaja;
    int auxIdCliente;
    int opcionMenu;

    if(!inicializarClientes(listaDeClientes,TAM_CLIENTES) && !inicializarAlquilers(listaDeAlquileres,TAM_ALQUILERES))
    {
        printf("Sistema inicializado con exito!\n\n");
    }
    else
    {
        printf("Problema para inicializar el sistema\n");
    }


    hardCodearJuegos(listaDeJuegos,TAM_JUEGOS);
    hardCodearCategorias(listaDeCategorias,TAM_CATEGORIAS);
    hardCodearLocalidades(listaDeLocalidades,TAM_LOCALIDADES);
    hardcodearClientes(listaDeClientes,TAM_CLIENTES,&proximoIdCliente);
    hardcodearAlquileres(listaDeAlquileres,TAM_ALQUILERES,&proximoIdAlquiler);

    do
    {
        menu(&opcionMenu);

        switch(opcionMenu)
        {
        case 1:
            if(altaCliente(listaDeClientes,listaDeLocalidades,TAM_LOCALIDADES,TAM_CLIENTES,&proximoIdCliente))
            {

                printf("ALTA EXITOSA!\n");
            }
            else
            {
                printf("Problema para realizar el alta\n");
            }

            break;
        case 2:
            if(verificarExistenciaCliente(listaDeClientes,TAM_CLIENTES)==0)
            {
                auxModificacion = modificarClientes(listaDeClientes,listaDeLocalidades,TAM_CLIENTES,TAM_LOCALIDADES);

                if( auxModificacion == 0)
                {
                    printf("Modificacion exitosa\n");
                }
                else if(auxModificacion == 2)
                {
                    printf("Ha salido de las modificaciones\n");
                }
                else
                {
                    printf("Se ha producido un error en la modificacion\n");
                }

            }
            else
            {
                printf("No hay clientes en el listado\n");
            }
            break;

        case 3:
            if(verificarExistenciaCliente(listaDeClientes,TAM_CLIENTES)==0)
            {
                auxBaja = bajaCliente(listaDeClientes,listaDeLocalidades,TAM_CLIENTES,TAM_LOCALIDADES,&auxIdCliente);

                if(!auxBaja)
                {
                    printf("Baja exitosa\n");
                    bajaAlquiler(listaDeAlquileres,TAM_ALQUILERES,auxIdCliente);
                }
                else
                {
                    if(auxBaja)
                    {
                        printf("La baja ha sido cancelada\n");
                    }
                }
            }
            else
            {
                printf("No hay clientes en el listado\n");
            }
            break;
        case 4:

            if(!verificarExistenciaCliente(listaDeClientes,TAM_CLIENTES))
            {
                ordenarClientes(listaDeClientes,TAM_CLIENTES),


             listarClientes(listaDeClientes,listaDeLocalidades,TAM_CLIENTES,TAM_LOCALIDADES);


            }
            else
            {
                printf("No hay clientes en la lista\n");
            }

            break;

        case 5:

            if(!verificarExistenciaCliente(listaDeClientes,TAM_CLIENTES))
            {

                if(altaAlquiler(listaDeAlquileres,listaDeClientes,listaDeLocalidades,TAM_LOCALIDADES,TAM_CLIENTES,TAM_ALQUILERES,&proximoIdAlquiler,listaDeJuegos,TAM_JUEGOS))
                {
                    printf("Alta alquiler exirosa!\n");
                }

            }
            else
            {
                printf("No hay clientes en la lista\n");
            }


            break;

        case 6:
            system("cls");
            if(!verificarExistenciaAlquiler(listaDeAlquileres,TAM_ALQUILERES))
            {

                listarAlquilers(listaDeAlquileres,TAM_ALQUILERES,listaDeJuegos,listaDeClientes,listaDeCategorias,listaDeLocalidades,TAM_CATEGORIAS,TAM_JUEGOS,TAM_CLIENTES,TAM_LOCALIDADES);


            }
            else
            {
                printf("No hay alquileres en la lista\n");
            }

            break;

        case 7:
            system("cls");


            mostrarJuegosDeMesa(listaDeJuegos,TAM_JUEGOS);

            break;

        case 8:
            if(!verificarExistenciaCliente(listaDeClientes,TAM_CLIENTES)&& !verificarExistenciaAlquiler(listaDeAlquileres,TAM_ALQUILERES))
            {
                mostrarAlquileresPorCliente(listaDeAlquileres,listaDeJuegos,listaDeClientes,listaDeCategorias,listaDeLocalidades,TAM_LOCALIDADES,TAM_CATEGORIAS,TAM_CLIENTES,TAM_ALQUILERES,TAM_JUEGOS);
            }
            else
            {
                printf("No hay alquileres en la lista\n");
            }
            break;

        case 9:
            if(!verificarExistenciaCliente(listaDeClientes,TAM_CLIENTES) && !verificarExistenciaAlquiler(listaDeAlquileres,TAM_ALQUILERES))
            {
                mostrarAcumuladoPorCliente(listaDeAlquileres,listaDeJuegos,listaDeClientes,TAM_CLIENTES,TAM_ALQUILERES,TAM_JUEGOS,listaDeLocalidades,TAM_LOCALIDADES);
            }
            else
            {
                printf("Error, no hay alquileres o clientes para listar\n");
            }
            break;

        case 10:/*
            if(!verificarExistenciaCliente(listaDeClientes,TAM_CLIENTES) && !verificarExistenciaAlquiler(listaDeAlquileres,TAM_ALQUILERES))
            {
                mostrarClientesSinAlquileres(listaDeClientes,listaDeAlquileres,TAM_CLIENTES,TAM_ALQUILERES,listaDeLocalidades,TAM_LOCALIDADES);

            }
            else
            {
                printf("Error, no hay alquileres o clientes para listar\n");
            }
            break;
*/
        case 11:
            if(!verificarExistenciaCliente(listaDeClientes,TAM_CLIENTES) && !verificarExistenciaAlquiler(listaDeAlquileres,TAM_ALQUILERES))
            {

                mostrarJuegoSinAlquiler(listaDeAlquileres,listaDeJuegos,TAM_ALQUILERES,TAM_JUEGOS);
            }
            else
            {
                printf("Error, no hay alquileres o clientes para listar\n");
            }
            break;

        case 12:
            if(!verificarExistenciaCliente(listaDeClientes,TAM_CLIENTES) && !verificarExistenciaAlquiler(listaDeAlquileres,TAM_ALQUILERES))
            {

                mostrarTelefonoOClientesPorFecha(listaDeAlquileres,listaDeJuegos,listaDeClientes,listaDeCategorias,listaDeLocalidades,TAM_LOCALIDADES,TAM_ALQUILERES,TAM_CATEGORIAS,TAM_JUEGOS,TAM_CLIENTES);
            }
            else
            {
                printf("Error, no hay alquileres o clientes para listar\n");
            }
            break;

        case 13:
            if(!verificarExistenciaCliente(listaDeClientes,TAM_CLIENTES) && !verificarExistenciaAlquiler(listaDeAlquileres,TAM_ALQUILERES))
            {

                listarClientesPorLocalidad(listaDeClientes,listaDeLocalidades,TAM_LOCALIDADES,TAM_CLIENTES);

            }
            else
            {
                printf("Error, no hay alquileres o clientes para listar\n");
            }
            break;

        }
    }
    while(opcionMenu != 15);

    return 0;
}

