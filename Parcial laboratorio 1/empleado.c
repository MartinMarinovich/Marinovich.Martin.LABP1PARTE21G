
#include "Localidad.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hardCodearLocalidades(eLocalidad listaDeLocalidades[], int tamLocalidades)
{
	int error = -1;
	int idLocalidad [8] = {100,101,102,103,104,105,106,107};
	char Localidad [8][51]= {
		"Avellaneda",
		"Gerli",
		"Lanus",
		"Wilde",
		"Don Bosco",
		"San telmo",
		"DockSud",
		"Villa Crespo"
	};


	for(int i = 0; i<tamLocalidades;i++)
	{
		strcpy(listaDeLocalidades[i].nombre,Localidad[i]);
		listaDeLocalidades[i].codigo = idLocalidad[i];
		listaDeLocalidades[i].sexo = sexos[i];

	}


	return error;
}

void mostrarLocalidad(eLocalidad unLocalidad)
{
    printf(" %d         %10s \n",unLocalidad.codigo,unLocalidad.nombre);
}

int listarLocalidades(eLocalidad listaDeLocalidades[], int tamanioLocalidades)
{
	int error = -1;

    if(listaDeLocalidades !=NULL && tamanioLocalidades>0)
	{
    	system("cls");
	    printf(" ****  LISTADO DE Localidades  ****\n");
	    printf("Id        Nombre\n");
    	printf("----------------------------------\n");

        for(int i = 0 ; i<tamanioLocalidades; i++)
	    {

	    	mostrarLocalidad(listaDeLocalidades[i]);
    	}
        error = 0;
	}
	return error;
}
