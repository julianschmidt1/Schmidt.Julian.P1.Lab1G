/*
 * menu.c
 *
 *  Created on: 21 Oct 2022
 *      Author: Julian
 */

#include "menu.h"

int menu_opciones(char *titulo, char *opciones, char *mensajeError, int min,
		int max) {
	int rtn = 0;
	int opcion;

	if (titulo != NULL && opciones != NULL && min > 0 && min < max) {
		printf("%s", titulo);
		printf("%s", opciones);

		if (utn_getNumero(&opcion, "\nIngrese la opcion: ", mensajeError, min,
				max, 1)) {
			rtn = opcion;
		}
	}

	return rtn;
}

