/*
 * menu.h
 *
 *  Created on: 21 Oct 2022
 *      Author: Julian
 */

#ifndef MENU_H_
#define MENU_H_

#include <stdio.h>
#include <stdlib.h>
#include "Inputs.h"

/// \brief Funcion que muestra la interfaz de un menu
///
/// \param titulo Cabecera a mostrar
/// \param opciones opciones enumeradas a seleccionar
/// \param mensajeError mensaje a mostrar en caso de error
/// \param min valor minimo aceptado como opcion
/// \param max valor maximo aceptado como opcion
/// \return Retorna la opcion seleccionada en caso de exito y 0 en caso de error
int menu_opciones(char *titulo, char *opciones, char *mensajeError, int min,
		int max);

#endif /* MENU_H_ */
