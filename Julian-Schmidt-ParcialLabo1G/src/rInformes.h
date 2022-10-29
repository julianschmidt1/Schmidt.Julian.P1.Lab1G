/*
 * rInformes.h
 *
 *  Created on: 28 Oct 2022
 *      Author: Julian
 */

#ifndef RINFORMES_H_
#define RINFORMES_H_

#include "eNotebook.h"
#include "eTipo.h"
#include "eMarca.h"
#include "eTrabajo.h"
#include <stdio.h>
#include <stdlib.h>

/// \brief Esta funcion muestra notebooks que coincidan con el id del tipo seleccionado
///
/// \param notebooks array de notebooks
/// \param tamNotebooks tamaño del array de notebooks
/// \param idTipoSeleccionado id del tipo seleccionado
/// \param marcas array de marcas
/// \param maxMarcas tamaño del array de marcas
/// \param tipos array de tipos
/// \param maxTipos tamaño del array de tipos
/// \return retorna 1 en caso de exito y 0 en caso de error
int informe_mostrarNotebooksDeTipoSeleccionado(eNotebook *notebooks,
		int tamNotebooks, int idTipoSeleccionado, eMarca *marcas, int maxMarcas,
		eTipo *tipos, int maxTipos);

/// \brief Esta funcion muestra notebooks que coincidan con el id de marca seleccionada
///
/// \param notebooks array de notebooks
/// \param tamNotebooks tamaño del array de notebooks
/// \param idTipoSeleccionado id del tipo seleccionado
/// \param marcas array de marcas
/// \param maxMarcas tamaño del array de marcas
/// \param tipos array de tipos
/// \param maxTipos tamaño del array de tipos
/// \return retorna 1 en caso de exito y 0 en caso de error
int informe_mostrarNotebooksDeMarcaSeleccionada(eNotebook *notebooks,
		int tamNotebooks, int idMarcaSeleccionada, eMarca *marcas,
		int maxMarcas, eTipo *tipos, int maxTipos);

/// \brief Esta funcion muestra notebooks y sus respectivas marcas
///
/// \param notebooks array de notebooks
/// \param tamNotebooks tamaño del array de notebooks
/// \param idTipoSeleccionado id del tipo seleccionado
/// \param marcas array de marcas
/// \param maxMarcas tamaño del array de marcas
/// \param tipos array de tipos
/// \param maxTipos tamaño del array de tipos
/// \return retorna 1 en caso de exito y 0 en caso de error
int informe_mostrarNotebooksPorMarca(eNotebook *notebooks, int tamNotebooks,
		eMarca *marcas, int maxMarcas, eTipo *tipos, int maxTipos);

/// \brief Funcion que muestra la marca mas elegida en las notebooks
///
/// \param notebooks array de notebooks
/// \param tamNotebooks tamaño del array de notebooks
/// \param marcas array de marcas
/// \param maxMarcas tamaño del array de marcas
/// \return retorna 1 en caso de exito y 0 en caso de error
int informe_mostrarMarcaMasElegida(eNotebook *notebooks, int tamNotebooks,
		eMarca *marcas, int maxMarcas);

int inicializarIntArray(int *array, int tam, int valor);

/// \brief Esta funcion muestra notebooks que coincidan con el id del tipo seleccionado
///
/// \param notebooks array de notebooks
/// \param tamNotebooks tamaño del array de notebooks
/// \param idMarcaSeleccionada id de marca seleccionada a buscar
/// \param idTipoSeleccionado id del tipo seleccionado a buscar
/// \param marcas array de marcas
/// \param maxMarcas tamaño del array de marcas
/// \param tipos array de tipos
/// \param maxTipos tamaño del array de tipos
/// \return retorna 1 en caso de exito y 0 en caso de error
int informe_mostrarNotebookPorMarcaYTipo(eNotebook *notebooks, int tamNotebooks,
		int idMarcaSeleccionada, int idTipoSeleccionado, eMarca *marcas,
		int maxMarcas, eTipo *tipos, int maxTipos);

/// \brief Funcion que muestra la/s notebooks mas baratas
///
/// \param notebooks array de notebooks
/// \param tamNotebooks tamaño del array de notebooks
/// \param tipos array de tipos
/// \param tamTipos array de marcas
/// \param marcas array de marcas
/// \param tamMarcas tamaño del array de marcas
/// \return
int informe_mostrarNotebooksMasBarata(eNotebook *notebooks, int tamNotebooks,
		eTipo *tipos, int tamTipos, eMarca *marcas, int tamMarcas);

int informe_mostrarTrabajosSobreNotebook(eTrabajo *trabajos, int tamTrabajos,
		eServicio *servicios, int tamServicios, int idNotebook,
		eNotebook *notebooks, int tamNotebooks);

int informe_sumaDeImportesServicios(eTrabajo *trabajos, int tamTrabajos,
		eServicio *servicios, int tamServicios, int idNotebook,
		eNotebook *notebooks, int tamNotebooks);

#endif /* RINFORMES_H_ */
