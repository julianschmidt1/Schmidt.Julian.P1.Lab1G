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

/// \brief Funcion que muestra una estructura de tipo eMarca
///
/// \param marca estructura eMarca a mostrar
void mostrarUnMarca(eMarca marca);

/// \brief Funcion que itera una lista de eMarca
///
/// \param lista array de eMarca
/// \param tam tamaño del array
/// \return retorna 1 si pudo mostrar exitosamente y 0 si hubo un error
int mostrarTodosMarca(eMarca *lista, int tam);

/// \brief Funcion que obtiene el indice del id a buscar en el array de eMarca
///
/// \param lista array de eMarca
/// \param tam tamaño del array
/// \param id a buscar
/// \return Retorna el indice obtenido en caso de exito y -1 si no se encuentra o error
int encontrarMarcaPorId(eMarca *lista, int tam, int id);

#endif /* EMARCA_H_ */
