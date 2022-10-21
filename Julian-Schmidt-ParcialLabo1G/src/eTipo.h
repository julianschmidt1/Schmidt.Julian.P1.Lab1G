/*
 * eTipo.h
 *
 *  Created on: 21 Oct 2022
 *      Author: Julian
 */

#ifndef ETIPO_H_
#define ETIPO_H_

#define MAX_DESCRIPCION 20
#define MAX_TIPOS 4

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int id;
	char descripcion[MAX_DESCRIPCION];
} eTipo;

void mostrarUnTipo(eTipo tipo);

int mostrarTodosTipo(eTipo *lista, int tam);

int encontrarTipoPorId(eTipo *lista, int tam, int id);

#endif /* ETIPO_H_ */
