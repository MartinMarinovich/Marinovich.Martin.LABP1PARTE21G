#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"


static int myGets(char* cadena, int tamanio);

static int esNumerica(char* cadena);
static int getInt(int* pResultado);


static int getFloat(float* pResultado);
static int esFlotante(char* cadena);


/** \brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena un maximo de 'longitud - 1' caracteres.
 *
 * \param cadena char* puntero al espacio en memoria donde se copiara la cadena obtenida
 * \param longitud int tamaño de la cadena
 * \return int retorna 0 si se obtiene una cadena y -1 si no
 *
 */

static int myGets(char* cadena, int longitud)
{
    int retorno = -1;
    char bufferString[4096];
    if(cadena!=NULL && longitud>0)
    {
        fflush(stdin);
        if(fgets(bufferString,sizeof(bufferString),stdin) != NULL && bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
        {
            bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
        }
        if(strnlen(bufferString,sizeof(bufferString))<= longitud)
        {
            strncpy(cadena,bufferString,longitud);
            retorno=0;
        }
    }

    return retorno;
}

/** \brief verifica si la cadena ingresada es numerica
 *
 * \param cadena char* cadena de caracteres a ser analizada
 * \param limite int tamaño de la cadena a analizar
 * \return int Retorna 1 (verdadero) si la cadena es numerica, 0 (falso) si no lo es o -1 en caso de error
 *
 */
static int esNumerica(char* cadena)
{
	int retorno = 1; // devuelve true or false solamente
	int i = 0;

	if(cadena != NULL && strlen(cadena)>0)
	{
		if(cadena[0]=='-')
		{
				i = 1;
		}

		for(; cadena[i] != '\0';i++)
		{
			if(cadena[i]>'9'|| cadena[i]<'0')
			{
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}
static int getInt(int* pResultado)
{
	int retorno = -1;
	char buffer[4096];
	if(pResultado != NULL)
	{
		if(myGets(buffer,sizeof(buffer)) == 0 && esNumerica(buffer))
		{
			retorno = 0;
			*pResultado = atoi(buffer);
		}
	}
	return retorno;
}



int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int buffer;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);

			if(getInt(&buffer)== 0 &&buffer >= minimo && buffer <= maximo)
			{
				*pResultado = buffer;
				retorno = 1;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}


int utn_getCaracter(char* pResultado, char* mensaje,char* mensajeError, char minimo,char maximo,int reintentos)
{
	int retorno = -1;
	char buffer;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			scanf("%c",&buffer);
			if(buffer >= minimo && buffer <= maximo)
			{
				*pResultado = buffer;
				retorno = 1;
				break;
			}
			printf("%s",mensajeError);
			reintentos--;
		}while(reintentos>=0);

	}
	return retorno;
}

/** \brief verifica si la cadena ingresada es numerica
 *
 * \param cadena char* cadena de caracteres a ser analizada
 * \param limite int tamaño de la cadena a analizar
 * \return int Retorna 1 (verdadero) si la cadena es numerica, 0 (falso) si no lo es o -1 en caso de error
 *
 */


static int esFlotante(char* cadena)
{
	int retorno = 1; // devuelve true or false solamente
	int i = 0;
	int contadorPuntos = 0;

	if(cadena != NULL && strlen(cadena)>0)
	{
		for(; cadena[i] != '\0';i++)
		{
			if(i == 0 && (cadena[i]=='-' || cadena[i] == '+'))
			{
				continue;
			}

			if(cadena[i] < '0'|| cadena[i] >'9')
			{
				if(cadena[i] == '.' && contadorPuntos == 0)
				{
					contadorPuntos++;
				}else
				{
				  retorno = 0;
				  break;
				}
			}
		}
	}

	return retorno;
}

/** \brief pide al usuario ingresar un numero limita el tamaño de lo que se ingresa y si verifica que es un numero flotante, convierte la cadena en flotante y almacena el valor por referencia
 *
 * \param pResultado int* puntero al espacio en memoria donde se guardara el entero obtenido
 * \return int retorna 0 si se guardo el entero o -1 si no
 *
 */

static int getFloat(float* pResultado)
{
	int retorno = -1;
	char buffer[4096];

	if(pResultado != NULL)
	{
		if(myGets(buffer,sizeof(buffer)) == 0 && esFlotante(buffer))
		{
			retorno = 0;
			*pResultado = atof(buffer);
		}
	}
	return retorno;
}



int utn_getNumeroFloat(float* pResultado,char* mensaje,char* mensajeError,int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	float buffer;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos > 0)
	{
		do{
			printf("%s", mensaje);
			fflush(stdin);
			if(getFloat(&buffer) == 0 &&
					buffer >= minimo &&
					buffer <= maximo)
			{
				*pResultado = buffer;
				retorno = 1;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos >=0);
	}
	return retorno;
}

int utn_getCadena(char* pResultado,int len,char* mensaje,char* mensajeError,int reintentos)
{

	int retorno = -1;
	char buffer[4096];

	if(pResultado != NULL && len>0 && mensaje != NULL && mensajeError != NULL && reintentos > 0)
	{
		do{
			printf("%s",mensaje);

			if(myGets(buffer,sizeof(buffer))==0 && strlen(buffer) < len)
			{
				strncpy(pResultado,buffer,len-1);
				retorno = 1;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}

/** \brief verifica si la cadena ingresada es un nombre
 *
 * \param cadena char* cadena de caracteres a ser analizada
 * \param limite int tamaño de la cadena a analizar
 * \return int Retorna 1 (verdadero) si la cadena es un nombre, 0 (falso) si no lo es o -1 en caso de error
 *
 */


int esNombreValido(char* cadena, int len)
{
	int retorno = 1;

	if( cadena!= NULL && len > 0)
	{
		for(int i=0; i<=len && cadena[i] != '\0';i++)
		{
			if(	(cadena[i] < 'A' || cadena[i] > 'Z') &&
				(cadena[i] < 'a' || cadena[i] > 'z') &&
				cadena[i] != ' ' && cadena[i] != '-')
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
