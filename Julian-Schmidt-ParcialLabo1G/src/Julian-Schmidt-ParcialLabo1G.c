/*
 ============================================================================
 Name        : Julian-Schmidt-ParcialLabo1G.c
 Author      : Julián Schmidt
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "eNotebook.h"
#include "eMarca.h"
#include "eTipo.h"
#include "inputs.h"
#include "eServicio.h"
#define MAX_REINTENTOS 9999

int main(void) {
	setbuf(stdout, NULL);
	int opcion;
	eNotebook notebooks[MAX_CHARS_MODELO];
	eMarca marcas[MAX_MARCAS] = { { 1000, "Compaq" }, { 1001, "Asus" }, { 1002,
			"Acer" }, { 1003, "HP" }, };
	eTipo tipos[MAX_TIPOS] = { { 5000, "Gamer" }, { 5001, "Disenio" }, { 5002,
			"Ultrabook" }, { 5003, "Normalita" }, };
	eServicio servicios[MAX_SERVICIOS] = { { 20000, "Bateria", 2250 }, { 20001,
			"Display", 10300 }, { 20002, "Teclado", 4400 }, { 20003, "Fuente",
			5600 }, };

	int auxIdMarca;
	int auxIdTipo;

	eNotebook nuevaNotebook;
	int idNotebook;
	int confirmarSalida;

	if (!abm_inicializarNotebook(notebooks, MAX_NOTEBOOKS)) {
		puts("\n ----------- OCURRIO UN ERROR AL INICIALIZAR ------------");
	}

	do {
		opcion = menu_opciones("\n------ MENU PRINCIPAL -----",
				"\n1. ALTA NOTEBOOK \n"
						"2. MODIFICAR NOTEBOOK \n"
						"3. BAJA NOTEBOOK \n"
						"4. LISTAR NOTEBOOKS \n"
						"5. LISTAR MARCAS\n"
						"6. LISTAR TIPOS\n"
						"7. LISTAR SERVICIOS\n"
						"8. ALTA TRABAJO\n"
						"9. LISTAR TRABAJOS\n"
						"10. SALIR\n",
				"\nError. Opcion invalida, ingrese la opcion: ", 1, 10);
		switch (opcion) {
		case 1:
			utn_getString("\nIngrese el modelo: ",
					"\nModelo invalido, ingresalo de vuelta: ", MAX_REINTENTOS,
					MAX_CHARS_MODELO, nuevaNotebook.modelo);

			mostrarTodosMarca(marcas, MAX_MARCAS);
			utn_getNumero(&auxIdMarca, "\nIngrese el id de la marca: ",
					"\n ID de marca invalido", 1000, 9999, MAX_REINTENTOS);

			while (encontrarMarcaPorId(marcas, MAX_MARCAS, auxIdMarca) == -1) {
				puts("\nEL ID INGRESADO NO EXISTE");
				utn_getNumero(&auxIdMarca, "\nIngrese el id de la marca: ",
						"\n ID de marca invalido", 1000, 9999, MAX_REINTENTOS);
			}
			nuevaNotebook.idMarca = auxIdMarca;

			mostrarTodosTipo(tipos, MAX_TIPOS);
			utn_getNumero(&auxIdTipo, "\nIngrese el id del tipo: ",
					"\n ID de tipo invalido", 5000, 9999, MAX_REINTENTOS);

			while (encontrarTipoPorId(tipos, MAX_TIPOS, auxIdTipo) == -1) {
				puts("\nEL ID INGRESADO NO EXISTE");
				utn_getNumero(&auxIdTipo, "\nIngrese el id del tipo: ",
						"\n ID de tipo invalido", 5000, 9999, MAX_REINTENTOS);
			}
			nuevaNotebook.idTipo = auxIdTipo;

			utn_getNumeroDecimal(&nuevaNotebook.precio,
					"\nIngrese el precio de la notebook: ",
					"\nPrecio invalido, ingrese el precio de la notebook: ", 1,
					999999, MAX_REINTENTOS);

			idNotebook = abm_obtenerIdNotebook();
			if (abm_altaNotebook(notebooks, MAX_NOTEBOOKS, idNotebook,
					nuevaNotebook)) {
				puts("\n ALTA EXITOSA");
			} else {
				puts("\n\n ---- OCURRIO UN ERROR EN EL ALTA  ---- ");
			}
			break;
		case 2:
			abm_listadoModificacionNotebook(notebooks, MAX_NOTEBOOKS, marcas,
			MAX_MARCAS, tipos, MAX_TIPOS);
			break;
		case 3:
			abm_listadoBajaNotebook(notebooks, MAX_NOTEBOOKS, marcas,
			MAX_MARCAS, tipos, MAX_TIPOS);
			break;
		case 4:
			ordenarNotebooksMarcaPrecio(notebooks, MAX_NOTEBOOKS, marcas,
			MAX_MARCAS);
			abm_mostrarTodosNotebook(notebooks, MAX_NOTEBOOKS, marcas,
			MAX_MARCAS, tipos, MAX_TIPOS);
			break;
		case 5:
			mostrarTodosMarca(marcas, MAX_MARCAS);
			break;
		case 6:
			mostrarTodosTipo(tipos, MAX_TIPOS);
			break;
		case 7:
			mostrarTodosServicio(servicios, MAX_SERVICIOS);
			break;
		case 8:
			puts("\nAlta trabajo");
			break;
		case 9:
			puts("\nListar trabajos");
			break;
		case 10:
			utn_getNumero(&confirmarSalida,
					"\nEsta seguro que desea salir del programa? (1. SI | 0. NO) \nIngrese la opcion: ",
					"\nError. Opcion ingresada invalida. Intentelo nuevamente",
					0, 1, 9999);
			if (confirmarSalida) {
				puts("\n GRACIAS POR USAR EL SISTEMA.");
			} else {
				puts("\n Volviendo al menu principal ...");
			}
			break;
		}
	} while (opcion != 10 || !confirmarSalida);

	return EXIT_SUCCESS;
}
