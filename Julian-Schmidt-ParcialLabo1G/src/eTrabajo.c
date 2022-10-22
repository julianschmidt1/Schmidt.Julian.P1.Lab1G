/*
 * eTrabajo.c
 *
 *  Created on: 21 Oct 2022
 *      Author: Julian
 */

#include "eTrabajo.h"

int abm_obtenerIdTrabajo(void) {
	static int idIncrementalTrabajo = 1;
	return idIncrementalTrabajo++;
}

int abm_obtenerIndiceLibreTrabajo(eTrabajo *lista, int tam) {
	int rtn = -1;

	if (lista != NULL && tam > 0) {
		for (int i = 0; i < tam; i++) {
			if (lista[i].isEmpty == LIBRE) {
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

int abm_altaTrabajo(eTrabajo *lista, int tam, int id, eTrabajo Notebook) {
	int rtn = 0;

	int index = abm_obtenerIndiceLibreTrabajo(lista, tam);
	if (index != -1 && lista != NULL) {
		// Aca deberia recibir los datos ya cargados y asignarlos al id libre que recibo por params
		Notebook.id = id;
		Notebook.isEmpty = OCUPADO;
		lista[index] = Notebook;

		rtn = 1;
	}
	return rtn;
}

int abm_inicializarTrabajo(eTrabajo *lista, int tam) {
	int i;
	int rtn = 0;

	if (lista != NULL && tam > 0) {
		rtn = 1;
		for (i = 0; i < tam; i++) {
			lista[i].isEmpty = LIBRE;
		}
	}

	return rtn;
}

void abm_mostrarUnTrabajo(eTrabajo Trabajo, eNotebook *notebooks,
		int tamNotebooks, eServicio *servicios, int tamServicios) {

	char modeloNotebook[20];
	char servicioDescripcion[25];

	for (int i = 0; i < tamNotebooks; i++) {
		if (notebooks[i].id == Trabajo.idNotebook) {
			strcpy(modeloNotebook, notebooks[i].modelo);
		}
	}
	for (int i = 0; i < tamServicios; i++) {
		if (servicios[i].id == Trabajo.idServicio) {
			strcpy(servicioDescripcion, servicios[i].descripcion);
		}
	}

	printf(
			"\n|%2d  |   %-6d     | %-14s      |   %-14s       |    %-2d/%-2d/%-4d      |",
			Trabajo.id, Trabajo.idNotebook, modeloNotebook, servicioDescripcion,
			Trabajo.fecha.dia, Trabajo.fecha.mes, Trabajo.fecha.anio);
}

int abm_mostrarTodosTrabajo(eTrabajo *lista, int tam, eNotebook *notebooks,
		int tamNotebooks, eServicio *servicios, int tamServicios) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	if (lista != NULL && tam > 0) {
		puts(
				"\n=========================================================================================");
		puts(
				"| ID |  ID NOTEBOOK  | MODELO NOTEBOOK   |  DESCRIPCION SERVICIO    |   FECHA      |");
		puts(
				"------------------------------------------------------------------------------------------");
		for (i = 0; i < tam; i++) {
			if (lista[i].isEmpty == OCUPADO) {
				abm_mostrarUnTrabajo(lista[i], notebooks, tamNotebooks,
						servicios, tamServicios);
				cantidad++;
			}
		}
		puts(
				"\n==========================================================================================");
	}

	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}
