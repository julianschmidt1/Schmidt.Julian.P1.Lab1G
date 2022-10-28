/*
 * eNotebook.h
 *
 *  Created on: 21 Oct 2022
 *      Author: Julian
 */

#ifndef ENOTEBOOK_H_
#define ENOTEBOOK_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Inputs.h"
#include "menu.h"
#include "eMarca.h"
#include "eTipo.h"

#define MAX_CHARS_MODELO 20
#define LIBRE 0
#define BAJA 1
#define OCUPADO -1
#define MAX_NOTEBOOKS 5

typedef struct {
	int id;
	char modelo[MAX_CHARS_MODELO];
	int idMarca;
	int idTipo;
	float precio;

	int isEmpty;
} eNotebook;

// ALTA -----------------------------------------
/// \brief Funcion que permite la adicion de una entidad de tipo eNotebook a un array
///
/// \param lista array de eNotebook
/// \param tam tamaño del array de eNotebook
/// \param id identificar univoco que sera asignado al eNotebook dado de alta
/// \param Notebook eNotebook previamente cargado
/// \return retorna 1 en caso de exito y 0 en caso de error
int abm_altaNotebook(eNotebook *lista, int tam, int id, eNotebook Notebook);

/// \brief Recorre un array de eNotebook, inicializando su propiedad isEmpty
///
/// \param lista array de eNotebook
/// \param tam tamaño del array de eNotebook
/// \return retorna 1 en caso de exito y cero en caso de error
int abm_inicializarNotebook(eNotebook *lista, int tam);

/// \brief Funcion que retorna un identificar univoco autoincremental
///
/// \return Valor utilizado como identificador
int abm_obtenerIdNotebook(void);
/// \brief Funcion que itera un array de eNotebook y busca un indice considero libre
///
/// \param lista array de eNotebook
/// \param tam tamaño del array de eNotebook
/// \return retorna el indice en caso de encontrarlo y -1 en caso de no encontrarlo o error
int abm_obtenerIndiceLibreNotebook(eNotebook *lista, int tam);
// ENCONTRAR INDICE -----------------------------------------
/// \brief Funcion que itera un array de eNotebook, y busca el indice especificado
///
/// \param lista array de eNotebook
/// \param tam tamaño del array de eNotebook
/// \param id valor univoco que representa cada eNotebook y permite la busqueda
/// \return Retorna el indice encontrado en caso de exito, o -1 en caso de error
int abm_encontrarNotebookPorId(eNotebook *lista, int tam, int id);
// MODIFICACION -----------------------------------------
/// \brief Funcion utilizada como para mostrar el menu y realizar modificaciones
///
/// \param Notebook estructura sobre la cual aplicar modificaciones
/// \return Retorna estructura con modificaciones aplicadas
eNotebook abm_modificacionNotebook(eNotebook Notebook, eMarca *marcas,
		int tamMarcas, eTipo *tipos, int tamTipos);
/// \brief Funcion que lista los usuarios y permite la seleccion de un indice para su modificacion
///
/// \param lista array de eNotebook
/// \param tam tamaño del array de eNotebook
/// \return Retorna 1 en caso de que las modificaciones sean aceptadas y 0 en caso de que se rechace o error
int abm_listadoModificacionNotebook(eNotebook lista[], int tam, eMarca *marcas,
		int tamMarcas, eTipo *tipos, int tamTipos);
// BAJA -----------------------------------------
/// \brief Funcion que lista los usuarios y permite la seleccion de un indice para su baja
///
/// \param lista array de eNotebook
/// \param tam tamaño del array de eNotebook
/// \return Retorna 1 en caso de que las bajas sean aceptadas y 0 en caso de que se rechace o error
int abm_listadoBajaNotebook(eNotebook *lista, int tam, eMarca *marcas,
		int tamMarcas, eTipo *tipos, int tamTipos);
/// \brief Funcion utilizada para aplicar una baja
///
/// \param lista array de eNotebook
/// \param tam tamaño del array de eNotebook
/// \param id de el eNotebook a dar de baja
/// \return Retorna 1 en caso de que la baja sea exitosa y 0 en caso de error
int abm_bajaNotebook(eNotebook *lista, int tam, int id);
// INFORMES -----------------------------------------
// TODO: HACER DOCS DE ORDEN MARCA PRECIO
int ordenarNotebooksMarcaPrecio(eNotebook *notebooks, int tamNotebooks,
		eMarca *marcas, int tamMarcas);
/// \brief Funcion que muestra los campos de un eNotebook
///
/// \param Notebook estructura a mostrar
void abm_mostrarUnNotebook(eNotebook Notebook, eMarca *marcas, int tamMarcas,
		eTipo *tipos, int tamTipos);
/// \brief Funcion que muestra un listado de eNotebook
///
/// \param lista array de eNotebook
/// \param tam tamaño del array de eNotebook
/// \return Retorna 1 en caso de exito y 0 en caso de error
int abm_mostrarTodosNotebook(eNotebook *lista, int tam, eMarca *marcas,
		int tamMarcas, eTipo *tipos, int tamTipos);
// VALIDACION -----------------------------------------
/// \brief Funcion que compara un contador de altas y bajas para comprobar si existen usuarios cargados hasta el momento
///
/// \param contadorAltas variable contador numerica
/// \param contadorBajas variable contador numerica
/// \return Retorna 1 si difiere la cantidad de altas con bajas y 0 si son iguales
int validarIngresoOpciones(int contadorAltas, int contadorBajas);
// ORDENAMIENTO
/// \brief Funcion que ordena eNotebook por ID
///
/// \param lista array de eNotebook
/// \param tam tamaño del array de eNotebook
/// \return retorna 1 en caso de exito y 0 en caso de error
int ordenarJugadoresId(eNotebook *lista, int tam);

#endif /* ENOTEBOOK_H_ */
