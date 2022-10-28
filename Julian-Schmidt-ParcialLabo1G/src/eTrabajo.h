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

/// \brief Funcion que da de alta un trabajo en el array
///
/// \param lista array de eTrabajo
/// \param tam tamaño del array de eTrabajo
/// \param id identificador autoincremental de la estructura
/// \param trabajo auxiliar en donde se cargo la informacion del trabajo
/// \return retorna 1 en caso de exito  y 0 en caso de error
int abm_altaTrabajo(eTrabajo *lista, int tam, int id, eTrabajo trabajo);

/// \brief Recorre un array de eTrabajo, inicializando su propiedad isEmpty
///
/// \param lista array de eServicio
/// \param tam tamaño del array de eServicio
/// \return retorna 1 en caso de exito y cero en caso de error
int abm_inicializarTrabajo(eTrabajo *lista, int tam);

/// \brief Funcion que retorna un identificar univoco autoincremental
///
/// \return Valor utilizado como identificador
int abm_obtenerIdTrabajo(void);

/// \brief Funcion que itera un array de eServicio y busca un indice considero libre
///
/// \param lista array de eServicio
/// \param tam tamaño del array de eServicio
/// \return retorna el indice en caso de encontrarlo y -1 en caso de no encontrarlo o error
int abm_obtenerIndiceLibreTrabajo(eTrabajo *lista, int tam);

/// \brief Funcion utilizada para mostrar una estructura de tipo eTrabajo, incluyendo sus relaciones con otras estructuras
///
/// \param Trabajo estructura eTrabajo a mostrar
/// \param notebooks array de estructura eNotebook
/// \param tamNotebooks tamaño del array de notebooks
/// \param servicios array de estructura eServicio
/// \param tamServicios tamaño del array de servicios
void abm_mostrarUnTrabajo(eTrabajo Trabajo, eNotebook *notebooks,
		int tamNotebooks, eServicio *servicios, int tamServicios);

/// \brief Funcion utilizada para mostrar un listado de estructuras de tipo eTrabajo
///
/// \param lista array de eTrabajo
/// \param tam tamaño del array de estructura eTrabajo
/// \param notebooks array de estructura eNotebook
/// \param tamNotebooks tamaño del array de estructura eNotebook
/// \param servicios array de estructura eServicio
/// \param tamServicios tamaño del array de estructura eServicio
/// \return Retorna 1 en caso de exito y 0 en caso de error
int abm_mostrarTodosTrabajo(eTrabajo *lista, int tam, eNotebook *notebooks,
		int tamNotebooks, eServicio *servicios, int tamServicios);

#endif /* ETRABAJO_H_ */
