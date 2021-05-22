#ifndef CATEGORIA_H_INCLUDED
#define CATEGORIA_H_INCLUDED

typedef struct{

	int idCategoria;
	char descripcion[51];

}eCategoria;

#endif // CATEGORIA_H_INCLUDED

int hardCodearCategorias(eCategoria listaDeCategorias[], int tamCategorias);
void mostrarCategoria(eCategoria unCategoria);
int listarCategorias(eCategoria listaDeCategorias[], int tamanioCategorias);
