#ifndef LOCALIDAD_H_INCLUDED
#define LOCALIDAD_H_INCLUDED


typedef struct{

	int idLocalidad;
	char descripcion[51];


}eLocalidad;

#endif // LOCALIDAD_H_INCLUDED
int hardCodearLocalidades(eLocalidad listaDeLocalidades[], int tamLocal);

void mostrarLocalidades(eLocalidad unaLocalidad);

int listarLocalidades(eLocalidad listaDeLocalidades[], int tamanioLocalidades);


