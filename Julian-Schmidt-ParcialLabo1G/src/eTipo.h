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

/// \brief Funcion que muestra una estructura de tipo eTipo
///
/// \param marca estructura eTipo a mostrar
void mostrarUnTipo(eTipo tipo);

/// \brief Funcion que itera una lista de eTipo
///
/// \param lista array de eTipo
/// \param tam tamaño del array
/// \return retorna 1 si pudo mostrar exitosamente y 0 si hubo un error
int mostrarTodosTipo(eTipo *lista, int tam);

/// \brief Funcion que obtiene el indice del id a buscar en el array de eTipo
///
/// \param lista array de eTipo
/// \param tam tamaño del array
/// \param id a buscar
/// \return Retorna el indice obtenido en caso de exito y -1 si no se encuentra o error
int encontrarTipoPorId(eTipo *lista, int tam, int id);

#endif /* ETIPO_H_ */
