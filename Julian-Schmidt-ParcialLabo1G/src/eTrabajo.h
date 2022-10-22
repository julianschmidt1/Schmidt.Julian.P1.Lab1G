/*
 * eTrabajo.h
 *
 *  Created on: 21 Oct 2022
 *      Author: Julian
 */

#ifndef ETRABAJO_H_
#define ETRABAJO_H_
#include "eFecha.h"
#include <stdio.h>
#include <stdlib.h>
#include "eTipo.h"
#include "eNotebook.h"
#include "eServicio.h"
#define LIBRE 0
#define BAJA 1
#define OCUPADO -1
#define MAX_DESCRIPCION 20
#define MAX_TRABAJOS 50

typedef struct {
	int id;
	int idNotebook;
	int idServicio;
	eFecha fecha;
	int isEmpty;
} eTrabajo;

int abm_altaTrabajo(eTrabajo *lista, int tam, int id, eTrabajo Notebook);

int abm_inicializarTrabajo(eTrabajo *lista, int tam);

int abm_obtenerIdTrabajo(void);

int abm_obtenerIndiceLibreTrabajo(eTrabajo *lista, int tam);

void abm_mostrarUnTrabajo(eTrabajo Trabajo, eNotebook *notebooks,
		int tamNotebooks, eServicio *servicios, int tamServicios);

int abm_mostrarTodosTrabajo(eTrabajo *lista, int tam, eNotebook *notebooks,
		int tamNotebooks, eServicio *servicios, int tamServicios);

#endif /* ETRABAJO_H_ */
