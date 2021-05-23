#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#include "alquileres.h"
#include "categoria.h"
#include "cliente.h"

#include "juego.h"
#include "utn.h"

int hardcodearAlquileres(eAlquileres listaDeAlquileres[],int tamanioAlquileres, int *pIdAlquiler)
{
    int retorno = -1;

    int codigoJuego[10] = {1007,1003,1002,1002,1004,1002,1007,1007,1001,1003};
    int dias [10] = {4,4,8,8,30,30,11,22,22,4};
    int meses [10] = {12,12,1,1,4,4,5,6,6,4};
    int anios [10] = {1996,1996,2020,2020,2004,2004,2001,2004,2019,2020};
    int idCliente[10] = {4,4,1,1,2,5,3,7,2,6};
    if(listaDeAlquileres != NULL && tamanioAlquileres >0 && pIdAlquiler !=NULL)
    {
        for(int i = 0; i<10; i++)
        {
            listaDeAlquileres[i].codigoAlquiler = *pIdAlquiler;
            (*pIdAlquiler)++;
            listaDeAlquileres[i].fechaAlquiler.dia = dias[i];
            listaDeAlquileres[i].fechaAlquiler.mes = meses[i];
            listaDeAlquileres[i].fechaAlquiler.anio = anios[i];
            listaDeAlquileres[i].codigoJuego = codigoJuego[i];
            listaDeAlquileres[i].codigoCliente = idCliente[i];
            listaDeAlquileres[i].isEmpty = 0;

        }
        retorno = 0;

    }


    return retorno;

}

int inicializarAlquilers(eAlquileres listaDeAlquileres[],int tamanioAlquileres)
{
    int error = -1;

    if(listaDeAlquileres != NULL &&tamanioAlquileres>0)
    {
        error = 0;

        for (int i = 0; i < tamanioAlquileres; ++i)
        {
            listaDeAlquileres[i].isEmpty = 1;
        }
    }
    return error;
}



int buscarLibreAlquiler(eAlquileres listaDeAlquileres[], int tamanioAlquileres)
{
    int indice = -1;

    for(int i = 0; i < tamanioAlquileres; i++)
    {
        if(listaDeAlquileres[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int altaAlquiler(eAlquileres listaDeAlquileres[],eCliente listaDeClientes[],eLocalidad listaDeLocalidads[], int tamEmpleados, int tamClientes, int tamanioAlquileres,int* pIdAlquiler,eJuego listaDeJuegos[], int tamJuego)
{

    int retorno=-1;
    int indice;
    int aux;
    int idCliente;
    int idJuego;


    if(listaDeAlquileres!=NULL && pIdAlquiler != NULL && listaDeClientes != NULL && tamClientes>0 && tamanioAlquileres >0 )
    {
        system("cls");
        printf(" *** Alta Alquiler ***\n\n");

        indice = buscarLibreAlquiler(listaDeAlquileres,tamanioAlquileres);

        if(indice!=-1)
        {
            listarClientes(listaDeClientes,listaDeLocalidads,tamClientes,tamEmpleados);

            if(utn_getNumero(&idCliente,"Ingrese el numero del cliente:","Error numero invalido\n",1,20,10))
            {
                aux = buscarCliente(listaDeClientes,tamClientes,idCliente);

                if(aux != -1)
                {

                    listarJuegos(listaDeJuegos,tamJuego);

                    if(utn_getNumero(&idJuego,"Ingrese la id del juego\n","Error, ID invalido\n",1000,1007,5)
                            && utn_getNumero(&listaDeAlquileres[indice].fechaAlquiler.dia,"Ingrese el dia de alquiler\n","Error, ingrese dia  valida\n",1,30,5)
                            &&utn_getNumero(&listaDeAlquileres[indice].fechaAlquiler.mes,"Ingrese el mes de alquiler\n","Error, ingrese mes valida\n",1,12,5)
                            && utn_getNumero(&listaDeAlquileres[indice].fechaAlquiler.anio,"Ingrese el anio de alquiler\n","Error, ingrese anio valida\n",1900,2021,5))
                    {
                        listaDeAlquileres[indice].codigoJuego = idJuego;
                        listaDeAlquileres[indice].isEmpty = 0;
                        listaDeAlquileres[indice].codigoAlquiler = *pIdAlquiler;
                        (*pIdAlquiler)++;
                        listaDeAlquileres[indice].codigoCliente = idCliente;
                        retorno = 1;
                    }

                }
                else
                {
                    printf("Error, no exite un cliente con esa  ID\n");
                }
            }
            else
            {
                printf("Error, no se pudo dar de alta el alquiler.");
            }
        }
        else
        {
            printf("No hay lugar para cargar mas alquileres.\n");
        }
    }
    return retorno;


}
int bajaAlquiler(eAlquileres listaDeAlquileres[],int tamAlquileres,int idCliente)
{
    int retorno =  0;

    if(listaDeAlquileres != NULL && tamAlquileres >0 && idCliente >0)
    {
        for(int i = 0; i<tamAlquileres; i++)
        {
            if(listaDeAlquileres[i].codigoCliente == idCliente)
            {
                listaDeAlquileres[i].isEmpty = 1;
                retorno = 1;
            }
        }
    }


    return retorno;

}


int obtenerDescripcionCliente(eCliente listaDeClientes[], int tamanioClientes, int id, char nombreCliente[], char apellidoCliente[])
{
    int error = -1;

    if(listaDeClientes != NULL && tamanioClientes > 0 && nombreCliente != NULL && apellidoCliente != NULL)
    {
        for(int i = 0; i<tamanioClientes; i++)
        {
            if(listaDeClientes[i].codigo == id)
            {
                strcpy(nombreCliente, listaDeClientes[i].nombre);
                strcpy(apellidoCliente, listaDeClientes[i].apellido);
                error = 1;
                break;
            }
        }
    }
    return error;
}

int obtenerDescripcionJuego(eJuego listaDeJuegos[],int tamJuegos, int idJuego, char descripcionJuego[],float *precio)
{
    int error = -1;

    if(listaDeJuegos != NULL && descripcionJuego != NULL)
    {
        for(int i = 0; i<tamJuegos; i++)
        {
            if(listaDeJuegos[i].codigo == idJuego)
            {
                strcpy(descripcionJuego, listaDeJuegos[i].descripcion);
                *precio = listaDeJuegos[i].importe;
                error = 1;
                break;
            }
        }
    }

    return error;
}

int obtenerDescripcionCategoria(eCategoria listaDeCategorias[],eJuego listaDeJuegos[],int tamJuegos,int tamcategorias,int idJuego, char descripcionCategoria[])
{
    int error = -1;
    int indice;

    if(listaDeCategorias != NULL && descripcionCategoria != NULL && tamcategorias >0 && idJuego>0 && descripcionCategoria != NULL)
    {
        for(int i = 0; i<tamcategorias; i++)
        {
            indice = buscarJuego(listaDeJuegos,tamJuegos,idJuego);

            if(listaDeJuegos[indice].idCategoria == listaDeCategorias[i].idCategoria)
            {
                strcpy(descripcionCategoria, listaDeCategorias[i].descripcion);
                error = 1;
                break;
            }
        }
    }

    return error;
}

void mostrarUnAlquiler(eAlquileres unAlquiler,eJuego listaJuegos[],eCliente listaClientes[],eCategoria listaDeCategorias[],eLocalidad listaDeLocalidades[],int tamLocalidades,int tamcategorias,int tamJuego, int tamCliente)
{
    char juego [51];
    char nombreCliente [51];
    char apellidoCliente [51];
    char categoria [51];
    char localidad [51];
    float precio = 0;

    if(obtenerDescripcionJuego(listaJuegos,tamJuego,unAlquiler.codigoJuego,juego,&precio)&&
            obtenerDescripcionCliente(listaClientes,tamCliente,unAlquiler.codigoCliente,nombreCliente,apellidoCliente)&&
            obtenerDescripcionCategoria(listaDeCategorias,listaJuegos,tamJuego,tamcategorias,unAlquiler.codigoJuego,categoria)&&
            obtenerDescripcionLocalidadAlquiler(listaDeLocalidades,listaClientes,unAlquiler.codigoCliente,tamLocalidades,tamCliente,localidad))
    {

        printf("    %d             %10s        %10s                %d          %10s                %10s             %02d/%02d/%03d             %.4f   %10s\n",unAlquiler.codigoAlquiler,juego,categoria,unAlquiler.codigoCliente,nombreCliente,apellidoCliente,unAlquiler.fechaAlquiler.dia,unAlquiler.fechaAlquiler.mes,unAlquiler.fechaAlquiler.anio,precio,localidad);
    }


}

int obtenerDescripcionLocalidadAlquiler(eLocalidad listaDeLocalidades[],eCliente listaDeClientes [],int idCliente,int tamLocalidades,int tamClientes, char descripcionLocalidad[])
{
    int error = -1;
    int indice;

    if(listaDeLocalidades != NULL && tamLocalidades >0 && descripcionLocalidad != NULL && idCliente >0 )
    {

        for(int i = 0; i<tamLocalidades; i++)
        {
            indice = buscarCliente(listaDeClientes,tamClientes,idCliente);

            if(listaDeClientes[indice].idLocalidad == listaDeLocalidades[i].idLocalidad)
            {

                strcpy(descripcionLocalidad, listaDeLocalidades[i].descripcion);
                error = 1;
                break;
            }

        }

    }

    return error;
}

int listarAlquilers(eAlquileres listaDeAlquileres[],int tamAlquilers,eJuego listaJuegos[],eCliente listaClientes[],eCategoria listaDeCategorias[],eLocalidad listaDeLocalidades[],int tamcategorias,int tamJuego, int tamCliente,int tamLocalidades)
{

    int error = 1;
    int flag = 0;

    if( listaDeAlquileres != NULL && tamAlquilers > 0 )
    {
        system("cls");

        printf(" Codigo Alquiler           Juego          Categoria      Codigo Cliente     Nombre Cliente      Apellido Cliente          Fecha de Alquiler          Precio       Localidad\n");
        printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

        for(int i=0; i<tamAlquilers; i++)
        {
            if(!verificarExistenciaAlquiler(listaDeAlquileres,tamAlquilers) && listaDeAlquileres[i].isEmpty == 0)
            {

                mostrarUnAlquiler(listaDeAlquileres[i],listaJuegos,listaClientes,listaDeCategorias,listaDeLocalidades,tamLocalidades,tamcategorias,tamJuego,tamCliente);
                flag = 1;
                error = 0;
            }
        }
        printf("\n");
        if( flag == 0)
        {
            printf("    No hay Alquilers en la lista\n");
        }

    }
    return error;

}

int verificarExistenciaAlquiler(eAlquileres listarAlquileres[], int tamAlquileres)
{
    int error= -1;

    if(listarAlquileres!=NULL && tamAlquileres > 0)
    {
        for(int i=0; i<tamAlquileres; i++)
        {
            if(listarAlquileres[i].isEmpty == 0)
            {
                error=0;
                break;
            }
        }
    }
    return error;
}


int mostrarClientesSinAlquileres(eCliente listaDeClientes [],eAlquileres listaDeALquileres [], int tamClientes, int tamAlquiler,eLocalidad listaDeLocalidades [], int tamLocalidades)
{
    int retorno = -1;
    int indices [tamClientes];
    int flag = 0;

    if(listaDeClientes != NULL && listaDeALquileres!= NULL && listaDeLocalidades != NULL  && tamClientes >0 && tamAlquiler >0 && tamLocalidades>0)
    {
        printf("*** CLIENTES SIN ALQUILERES ***\n\n");
        printf(" Codigo           Nombre             Apellido             Sexo           Telefono           Localidad\n");
        printf("---------------------------------------------------------------------------------------------------------\n");
        for(int i = 0; i<tamClientes; i++)
        {
            indices[i] = 0;
            for(int j = 0; j<tamAlquiler; j++)
            {
                if(listaDeClientes[i].codigo == listaDeALquileres[j].codigoCliente && listaDeALquileres[i].isEmpty == 0)
                {
                    indices[i] = 1;

                }
            }
        }

        for(int i = 0; i<tamClientes; i++)
        {

            if(indices[i] == 0 && listaDeClientes[i].isEmpty == 0)
            {
                mostrarUnCliente(listaDeClientes[i],listaDeLocalidades,tamLocalidades);
                flag = 1;
            }
        }
        if(!flag)
        {
            printf("No hay clientes sin alquileres\n");
        }
    }
    return retorno;

}

int mostrarJuegoSinAlquiler(eAlquileres listaDeAlquileres[],eJuego listaDeJuegos [], int tamAlquileres, int tamJuegos)
{
    int retorno = -1;
    int indices[tamJuegos];
    int flag = 0;

    if(listaDeAlquileres != NULL && listaDeJuegos !=NULL && tamAlquileres >0 && tamJuegos >0)
    {
        printf("*** JUEGOS SIN ALQUILER ***\n\n");
        retorno = 1;
        printf("Id              Descripcion\n");
        printf("--------------------------------\n");
        for(int i = 0; i<tamJuegos; i++)
        {
            indices[i] = 0;
            for(int j = 0; j <tamAlquileres; j++)
            {

                if(listaDeAlquileres[i].isEmpty ==0 && listaDeAlquileres[j].codigoJuego == listaDeJuegos[i].codigo)
                {
                    indices[i] = 1;
                }
            }
        }

        for(int i = 0; i<tamJuegos; i++)
        {
            if(indices[i] == 0)
            {
                mostrarJuego(listaDeJuegos[i]);
                flag = 1;
            }
        }

        if(!flag)
        {
            printf("No hay juegos sin alquiler\n");
        }
    }



    return retorno;
}




int mostrarAcumuladoPorCliente(eAlquileres listaDeAlquileres[],eJuego listaDeJuegos [],eCliente listaDeClientes[],int tamClientes,int tamAlquileres,int tamJuegos,eLocalidad listaDeLocalidads[],int tamEmpleados)
{
    int error = -1;
    int indice;
    int idCliente;
    float acumulador = 0;
    int flag = 0;

    if(listaDeAlquileres != NULL && listaDeJuegos != NULL && listaDeClientes != NULL && tamClientes > 0 && tamAlquileres > 0 && tamJuegos>0)
    {
        printf("*** DINERO A PAGAR POR CLIENTE ***\n\n");

        idCliente = getIdCliente(listaDeClientes,listaDeLocalidads,tamClientes,tamEmpleados);
        for(int i = 0; i<tamClientes; i++)
        {

            if(listaDeAlquileres[i].codigoCliente == idCliente && listaDeAlquileres[i].isEmpty == 0)
            {
                flag = 1;
                for(int j = 0; j<tamJuegos; j++)
                {
                    if(listaDeAlquileres[i].codigoJuego == listaDeJuegos[j].codigo)
                    {
                        acumulador += listaDeJuegos[j].importe;
                    }
                }
            }
        }

        if(!flag)
        {
            printf("\n No se obtuvo dinero de ese cliente\n");
        }
        else
        {
            indice = buscarCliente(listaDeClientes,tamClientes,idCliente);
            printf(" Codigo           Nombre             Apellido             Sexo           Telefono           Localidad\n");
            printf("---------------------------------------------------------------------------------------------------------\n");
            mostrarUnCliente(listaDeClientes[indice],listaDeLocalidads,tamEmpleados);
            printf("\nTotal acumulado %.2f\n",acumulador);
        }



    }

    return error;
}



int mostrarAlquileresPorCliente(eAlquileres listaDeAlquileres[],eJuego listaDeJuegos [],eCliente listaDeClientes[],eCategoria listaDeCategorias[],eLocalidad listaDeLocalidads[],int tamLocalidades,int tamCategorias,int tamClientes,int tamAlquileres,int tamJuegos)
{

    int error = -1;
    int flag = 0;
    int idCliente;


    if(listaDeAlquileres !=NULL && listaDeJuegos != NULL && listaDeClientes != NULL && tamClientes >0 && tamAlquileres>0 && tamJuegos >0)
    {



        idCliente = getIdCliente(listaDeClientes,listaDeLocalidads,tamClientes,tamLocalidades);
        printf("*** ALQUILERES  POR CLIENTE ***\n\n");
        printf(" Codigo Alquiler           Juego          Categoria      Codigo Cliente     Nombre Cliente      Apellido Cliente          Fecha de Alquiler          Precio       Localidad\n");
        printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

        for(int i = 0; i<tamClientes; i++)
        {

            if(listaDeAlquileres[i].codigoCliente == idCliente && listaDeAlquileres[i].isEmpty == 0)
            {
                flag = 1;
                mostrarUnAlquiler(listaDeAlquileres[i],listaDeJuegos,listaDeClientes,listaDeCategorias,listaDeLocalidads,tamLocalidades,tamCategorias,tamJuegos,tamClientes);
            }
        }

        if(!flag)
        {
            printf("No se encontaron alquileres con ese cliente\n");
        }

    }
    return error;
}



int mostrarTelefonoOClientesPorFecha(eAlquileres listaDeAlquileres[],eJuego listaJuegos[],eCliente listaClientes[],eCategoria listaDeCategorias[],eLocalidad listaDeLocalidades[],int tamLocalidades,int tamAlquileres,int tamcategorias,int tamJuego, int tamCliente)
{
    int retorno=-1;
    int indice;
    eFecha fecha;
    int flag=0;

    if(listaJuegos != NULL && listaClientes != NULL && listaDeCategorias != NULL && tamcategorias >0  && tamJuego >0 && tamCliente>0)
    {
        system("cls");
        printf(" *** TELEFONOS  O CLIENTE POR FECHA ***\n\n");

        if(utn_getNumero(&fecha.dia,"Ingrese el dia del alquiler\n","Error, ingrese un dai valido\n",1,31,4) &&
                utn_getNumero(&fecha.mes,"Ingrese el mes del alquiler\n","Error, ingrese un mes valido\n",1,12,4) &&
                utn_getNumero(&fecha.anio,"Ingrese el anio del alquiler\n","Error, ingrese un anio valido\n",1900,2021,4))
        {

            printf("\nCliente que hizo alquiler o alquileres en la fecha: %02d/%02d/%4d\n\n",fecha.dia,fecha.mes,fecha.anio);
            printf(" Codigo           Nombre             Apellido             Sexo           Telefono           Localidad\n");
            printf("---------------------------------------------------------------------------------------------------------\n");
            for(int i=0; i<tamAlquileres; i++)
            {
                if(listaDeAlquileres[i].fechaAlquiler.dia==fecha.dia &&
                        listaDeAlquileres[i].fechaAlquiler.mes==fecha.mes &&
                        listaDeAlquileres[i].fechaAlquiler.anio==fecha.anio&&listaDeAlquileres[i].isEmpty==0)

                {

                    indice = buscarCliente(listaClientes,tamCliente,listaDeAlquileres[i].codigoCliente);
                    mostrarUnCliente(listaClientes[indice],listaDeLocalidades,tamLocalidades);
                    flag=1;
                }
            }

            if(!flag)
            {
                printf("No hay trabajos cargados ese dia\n");
            }
        }
        else
        {
            printf("Error, al ingresar la fecha\n");
        }



        retorno=0;
    }

    return retorno;
}

int mostrarClientesPorJuego(eCliente listaDeClientes[],eJuego listaDeJuegos[],eLocalidad listaDeLocalidades[],eAlquileres listaDeAlquileres[], int tamAlquileres, int tamClientes,int tamJuegos,int tamLocalidades)
{
    int retorno =-1;
    int idJuego;
    int flag = 0;

    if(listaDeClientes != NULL && listaDeJuegos != NULL && listaDeLocalidades !=NULL && tamClientes >0 && tamLocalidades >0 && tamJuegos>0)
    {
        printf("*** CLIENTES POR JUEGO\n\n");

        listarJuegos(listaDeJuegos,tamJuegos);
        if(utn_getNumero(&idJuego,"Ingrese el ID del juego del cual desea ver los clientes\n","Error, ID juego invalido\n",1000,1007,5))
        {
            printf(" Codigo           Nombre             Apellido             Sexo           Telefono           Localidad\n");
            printf("---------------------------------------------------------------------------------------------------------\n");


            for(int i = 0; i<tamAlquileres; i++)
            {
                if(idJuego == listaDeAlquileres[i].codigoJuego && listaDeAlquileres[i].isEmpty == 0)
                {
                    for(int j = 0; j<tamClientes; j++)
                    {
                        if(listaDeAlquileres[i].codigoCliente == listaDeClientes[j].codigo && listaDeClientes[j].isEmpty == 0)
                        {
                            mostrarUnCliente(listaDeClientes[j],listaDeLocalidades,tamLocalidades);
                            flag =1;
                        }
                    }
                }
            }
            if(!flag)
            {
                printf("Ese juego no ha sido alquilado\n");
            }
        }

    }

    return retorno;
}

int listarJuegosAlquiladosPorMujeres(eCliente listaClientes [], eLocalidad listaLocalidad[], eAlquileres listaAlquileres[], eJuego listaJuegos[], int tamAlqui,int tamCliente,int tamLocalidad, int tamJuegos)
{
    int retorno = -1;
    int contadores[tamJuegos];
    int flag = 0;

    if(listaClientes != NULL && listaLocalidad != NULL && listaAlquileres != NULL && listaJuegos != NULL && tamAlqui >0 && tamCliente >0 && tamLocalidad >0 &&tamJuegos >0)
    {
        retorno =0;


        printf(" ***  JUEGOS ALQUILADOS POR MUJERES *** \n\n");
        printf("Id              Descripcion\n");
        printf("--------------------------------\n");
        for(int i = 0; i<tamJuegos; i++)
        {
            contadores[i] = 0;
            for(int j =0; j<tamAlqui; j++)
            {
                if(listaJuegos[i].codigo == listaAlquileres[j].codigoJuego && listaAlquileres[j].isEmpty == 0)
                {
                    for(int k = 0; k<tamCliente; k++)
                    {
                        if(listaAlquileres[j].codigoCliente == listaClientes[k].codigo && listaClientes[k].sexo == 'f' && listaClientes[k].isEmpty == 0)
                        {
                            contadores[i] = 1;
                            flag = 1;
                        }
                    }
                }
            }
        }

        for(int i = 0; i<tamJuegos; i++)
        {
            if(contadores[i] == 1)
            {
                mostrarJuego(listaJuegos[i]);
            }
        }

        if(!flag)
        {
            printf("No hay juegos alquilados por mujeres\n");
        }
    }


    return retorno;
}

int juegoPreferidoDeHombres(eCliente listaDeClientes[],eLocalidad listaDeLocalidades [], eJuego ListaDeJuegos[],eAlquileres listaDeAlquileres[], int tamAlquileres,int tamClientes,int tamLocalidad,int tamJuegos)
{
    int retorno = -1;
    int indices[tamClientes];
    int mayor;
    int flag = 0;

    if(listaDeClientes != NULL && listaDeLocalidades != NULL && listaDeClientes != NULL && ListaDeJuegos != NULL && listaDeAlquileres != NULL && tamClientes >0 && tamAlquileres >0 && tamLocalidad >0 && tamJuegos >0)
    {

        printf("*** JUEGOS PREFERIDOS POR LOS HOMBRES *** \n\n");
        retorno = 1;
        printf("Id              Descripcion\n");
        printf("--------------------------------\n");

        for(int i = 0; i<tamJuegos; i++)
        {
            indices[i] = 0;

            for(int j = 0; j<tamAlquileres; j++)
            {
                if(listaDeAlquileres[j].isEmpty == 0 && ListaDeJuegos[i].codigo == listaDeAlquileres[j].codigoJuego)
                {
                    for(int k = 0; k<tamClientes; k++)
                    {
                        if(listaDeAlquileres[j].codigoCliente == listaDeClientes[k].codigo && listaDeClientes[k].sexo == 'm')
                        {
                            indices[i]++;
                            flag = 1;
                        }
                    }
                }
            }
        }

        mayor = indices[0];

        for(int i = 0; i<tamJuegos; i++)
        {

            if(indices[i] > mayor)
            {
                mayor = indices[i];
            }
        }

        for(int i = 0; i<tamJuegos; i++)
        {
            if(indices[i] == mayor)
            {
                mostrarJuego(ListaDeJuegos[i]);
            }
        }

        if(!flag)
        {
            printf("No hay juegos elegidos por hombres\n");
        }

    }



    return retorno;

}

int mostrarAcumuladoPorFecha(eAlquileres listaDeAlquileres[],eJuego listaJuegos[],eCliente listaClientes[],eLocalidad listaDeLocalidades[],int tamLocalidades,int tamAlquileres,int tamJuego, int tamCliente)
{
    int retorno = -1;
    eFecha fecha;
    float acumulador = 0;
    int flag = 0;
    if(listaDeAlquileres != NULL && listaClientes != NULL && listaJuegos != NULL && listaDeLocalidades != NULL && tamCliente >0 && tamLocalidades>0 && tamAlquileres >0 && tamJuego>0)
    {

        system("cls");
        printf(" *** ACUMULADO DE DINERO POR FECHA ***\n\n");

        if(utn_getNumero(&fecha.dia,"Ingrese el dia del alquiler\n","Error, ingrese un dai valido\n",1,31,4) &&
                utn_getNumero(&fecha.mes,"Ingrese el mes del alquiler\n","Error, ingrese un mes valido\n",1,12,4) &&
                utn_getNumero(&fecha.anio,"Ingrese el anio del alquiler\n","Error, ingrese un anio valido\n",1900,2021,4))
        {

            printf("\nFecha seleccionada: %02d/%02d/%4d\n",fecha.dia,fecha.mes,fecha.anio);


            for(int i=0; i<tamAlquileres; i++)
            {
                for(int j = 0; j<tamJuego; j++)
                {
                    if(listaDeAlquileres[i].fechaAlquiler.dia==fecha.dia &&
                            listaDeAlquileres[i].fechaAlquiler.mes==fecha.mes &&
                            listaDeAlquileres[i].fechaAlquiler.anio==fecha.anio&&
                            listaDeAlquileres[i].isEmpty == 0&&
                            listaDeAlquileres[i].codigoJuego == listaJuegos[j].codigo)

                    {

                        acumulador = acumulador + listaJuegos[j].importe;
                        flag = 1;

                    }
                }
            }
            printf("Acumulado %.4f\n",acumulador);

            if(!flag)
            {
                printf("No hay trabajos cargados ese dia\n");
            }
        }
        else
        {
            printf("Error, al ingresar la fecha\n");
        }

    }



    return retorno;
}
