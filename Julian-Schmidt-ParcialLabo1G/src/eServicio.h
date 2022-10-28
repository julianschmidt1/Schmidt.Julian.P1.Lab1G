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

/// \brief Funcion que muestra una estructura de tipo eServicio
///
/// \param estructura eServicio a mostrar
void mostrarUnServicio(eServicio servicio);

/// \brief Funcion que itera una lista de eServicio
///
/// \param lista array de eServicio
/// \param tam tamaño del array
/// \return retorna 1 si pudo mostrar exitosamente y 0 si hubo un error
int mostrarTodosServicio(eServicio *lista, int tam);

/// \brief Funcion que obtiene el indice del id a buscar en el array de eServicio
///
/// \param lista array de eServicio
/// \param tam tamaño del array
/// \param id a buscar
/// \return Retorna el indice obtenido en caso de exito y -1 si no se encuentra o error
int encontrarServicioPorId(eServicio *lista, int tam, int id);

#endif /* ESERVICIO_H_ */
