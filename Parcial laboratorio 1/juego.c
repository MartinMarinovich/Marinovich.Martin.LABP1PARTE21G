
#include "juego.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hardCodearJuegos(eJuego listaDeJuegos[], int tamJuegos)
{
	int error = -1;
	int idJuego [8] = {1000,1001,1002,1003,1004,1005,1006,1007};
	char juego [8][30]= {
		"Jenga",
		"TEG",
		"Monopoly",
		"Estanciero",
		"WarHammer",
		"Clue",
		"Scrabble",
		"LudoMatic"
	};

	float precios[8]={2000,1200,1100,1250,1300,6000,5423,7000};
    int idCategoria[8] = {2,1,1,2,5,3,5,4};


	for(int i = 0; i<tamJuegos;i++)
	{
		strcpy(listaDeJuegos[i].descripcion,juego[i]);
		listaDeJuegos[i].codigo = idJuego[i];
		listaDeJuegos[i].importe = precios[i];
		listaDeJuegos[i].idCategoria = idCategoria[i];
		listaDeJuegos[i].isEmpty = 0;
	}


	return error;
}

void mostrarJuego(eJuego unJuego)
{
    printf(" %d         %20s \n",unJuego.codigo,unJuego.descripcion);
}

int listarJuegos(eJuego listaDeJuegos[], int tamanioJuegos)
{
	int error = -1;

    if(listaDeJuegos !=NULL && tamanioJuegos>0)
	{
    	system("cls");
	    printf(" ****  LISTADO DE JUEGOS  ****\n");
	    printf("Id              Descripcion\n");
        printf("--------------------------------\n");

        for(int i = 0 ; i<tamanioJuegos; i++)
	    {
	    	mostrarJuego(listaDeJuegos[i]);
    	}
        error = 0;
	}
	return error;
}

int buscarJuego(eJuego listaDeJuegos[], int tamJuegos,int idJuego)
{
    int indice=-1;

    if(listaDeJuegos!=NULL && tamJuegos>0 && idJuego >0)
    {

        for(int i=0; i<tamJuegos; i++)
        {
            if(idJuego == listaDeJuegos[i].codigo)
            {
                indice = i;
                break;
            }
        }
    }

    return indice;
}


int mostrarJuegosDeMesa(eJuego listaDeJuegos[],int tamJuegos)
{
    int retorno = -1;


    if(listaDeJuegos != NULL && tamJuegos >0)
    {
        system("cls");
	    printf(" ****  LISTADO DE JUEGOS DE MESA ****\n");
	    printf("Id        Descripcion\n");
    	printf("----------------------------------\n");
        for(int i = 0;i<tamJuegos;i++)
        {
            if(listaDeJuegos[i].idCategoria == 1)
            {
                mostrarJuego(listaDeJuegos[i]);
            }
        }

    }


    return retorno;
}
