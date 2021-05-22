#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

typedef struct{

	int codigo;
	char nombre[51];
	char sexo;

}eEmpleado;

#endif // EMPLEADO_H_INCLUDED


int hardCodearEmpleados(eEmpleado listaDeEmpleados[], int tamEmpleados);

void mostrarEmpleado(eEmpleado unEmpleado);

int listarEmpleados(eEmpleado listaDeEmpleados[], int tamanioEmpleados);


