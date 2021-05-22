
#include "categoria.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hardCodearCategorias(eCategoria listaDeCategorias[], int tamCategorias)
{
	int error = -1;
	int idCategoria [5] = { 1,2,3,4,5};
	char descripcion [5][51]= {
		"Mesa","Azar","Estrategia","Salon","Magia"
	};
	for(int i = 0; i<tamCategorias;i++)
	{
		strcpy(listaDeCategorias[i].descripcion,descripcion[i]);
		listaDeCategorias[i].idCategoria = idCategoria[i];
		error = 0;
	}


	return error;
}

void mostrarCategoria(eCategoria unCategoria)
{
    printf(" %d         %10s \n",unCategoria.idCategoria,unCategoria.descripcion);
}

int listarCategorias(eCategoria listaDeCategorias[], int tamanioCategorias)
{
	int error = -1;

    if(listaDeCategorias !=NULL && tamanioCategorias>0)
	{
    	system("cls");
	    printf(" ****  LISTADO DE CATEGORIAS  ****\n");
	    printf("Id        Descripcion\n");
    	printf("----------------------------------\n");

        for(int i = 0 ; i<tamanioCategorias; i++)
	    {
	    	mostrarCategoria(listaDeCategorias[i]);
    	}
        error = 0;
	}
	return error;
}
