/*
 * eTrabajo.h
 *
 *  Created on: 21 Oct 2022
 *      Author: Julian
 */

#ifndef ETRABAJO_H_
#define ETRABAJO_H_
#include "eFecha.h"

#define MAX_DESCRIPCION 20

typedef struct {
	int id;
	int idNotebook;
	int idServicio;
	eFecha fecha;
} eTrabajo;

int abm_altaNotebook(eNotebook *lista, int tam, int id, eNotebook Notebook);

#endif /* ETRABAJO_H_ */
