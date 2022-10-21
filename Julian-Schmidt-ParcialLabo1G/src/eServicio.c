/*
 * eServicio.c
 *
 *  Created on: 21 Oct 2022
 *      Author: Julian
 */

#include "eServicio.h"

void mostrarUnServicio(eServicio servicio) {
	// Modificar esto para que muestre data generica siempre
	printf("\n|%2d  |   %-16s  |    %-12.2f  |", servicio.id,
			servicio.descripcion, servicio.precio);
}

int mostrarTodosServicio(eServicio *lista, int tam) {
	int i;
	int rtn = 0;

	if (lista != NULL && tam > 0) {
		rtn = 1;
		puts("\n==================================================");
		puts("| ID |     DESCRIPCION         |       PRECIO   |");
		puts("-------------------------------------------------");
		for (i = 0; i < tam; i++) {
			mostrarUnServicio(lista[i]);
		}
		puts("\n==================================================");
	}

	return rtn;
}

