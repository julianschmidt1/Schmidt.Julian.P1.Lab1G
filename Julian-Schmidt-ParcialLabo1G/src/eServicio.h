/*
 * eServicio.h
 *
 *  Created on: 21 Oct 2022
 *      Author: Julian
 */

#ifndef ESERVICIO_H_
#define ESERVICIO_H_
#include <stdio.h>
#include <stdlib.h>

#define MAX_DESCRIPCION_SERVICIO 25
#define MAX_SERVICIOS 4

typedef struct {
	int id;
	char descripcion[MAX_DESCRIPCION_SERVICIO];
	float precio;
} eServicio;

void mostrarUnServicio(eServicio servicio);
int mostrarTodosServicio(eServicio *lista, int tam);

#endif /* ESERVICIO_H_ */
