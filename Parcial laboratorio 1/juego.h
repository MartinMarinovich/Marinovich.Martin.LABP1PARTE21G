#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

typedef struct{

	int codigo;
	char descripcion[20];
	float importe;
	int idCategoria;
	int isEmpty;

}eJuego;


#endif // JUEGO_H_INCLUDED

int hardCodearJuegos(eJuego listaDeJuegos[], int tamJuegos);
int listarJuegos(eJuego listaDeJuegos[], int tamanioJuegos);
void mostrarJuego(eJuego unJuego);
int buscarJuego(eJuego listaDeJuegos[], int tamJuegos,int idJuego);
int mostrarJuegosDeMesa(eJuego listaDeJuegos[],int tamJuegos);
