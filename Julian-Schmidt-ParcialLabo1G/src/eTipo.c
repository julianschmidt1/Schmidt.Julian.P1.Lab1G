/*
 * eTipo.c
 *
 *  Created on: 21 Oct 2022
 *      Author: Julian
 */

#include "eTipo.h"

void mostrarUnTipo(eTipo tipo) {
	// Modificar esto para que muestre data generica siempre
	printf("\n|%2d  |   %-16s  |", tipo.id, tipo.descripcion);
}

int mostrarTodosTipo(eTipo *lista, int tam) {
	int i;
	int rtn = 0;

	if (lista != NULL && tam > 0) {
		rtn = 1;
		puts("\n===========================");
		puts("| ID |     DESCRIPCION         |");
		puts("------------------------------");
		for (i = 0; i < tam; i++) {
			mostrarUnTipo(lista[i]);
		}
		puts("\n============================");
	}

	return rtn;
}

int encontrarTipoPorId(eTipo *lista, int tam, int id) {
	int rtn = -1;
	int i;

	if (lista != NULL && tam > 0) {
		for (i = 0; i < tam; i++) {
			if (lista[i].id == id) {
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}
