/*
 * eMarca.h
 *
 *  Created on: 21 Oct 2022
 *      Author: Julian
 */

#ifndef EMARCA_H_
#define EMARCA_H_

#define MAX_DESCRIPCION 20
#define MAX_MARCAS 4
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int id;
	char descripcion[MAX_DESCRIPCION];
} eMarca;

void mostrarUnMarca(eMarca marca);

int mostrarTodosMarca(eMarca *lista, int tam);

int encontrarMarcaPorId(eMarca *lista, int tam, int id);

#endif /* EMARCA_H_ */
