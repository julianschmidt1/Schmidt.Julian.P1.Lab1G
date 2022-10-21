/*
 * eNotebook.c
 *
 *  Created on: 21 Oct 2022
 *      Author: Julian
 */

#include "eNotebook.h"

int abm_obtenerIdNotebook(void) {
	// La variable idIncrementalNotebook es static para que preserve su valor incluso cuando este fuera de scope, logrando ser auto incremental
	static int idIncrementalNotebook = 1;
	return idIncrementalNotebook++;
}

int abm_inicializarNotebook(eNotebook *lista, int tam) {
	int i;
	int rtn = 0;

	if (lista != NULL && tam > 0) {
		rtn = 1;
		for (i = 0; i < tam; i++) {
			lista[i].isEmpty = LIBRE;
		}
	}

	return rtn;
}

int abm_obtenerIndiceLibreNotebook(eNotebook *lista, int tam) {
	int rtn = -1;

	if (lista != NULL && tam > 0) {
		for (int i = 0; i < tam; i++) {
			if (lista[i].isEmpty == LIBRE) {
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

int abm_encontrarNotebookPorId(eNotebook *lista, int tam, int id) {
	int rtn = -1;
	int i;

	if (lista != NULL && tam > 0) {
		for (i = 0; i < tam; i++) {
			if (lista[i].id == id && lista[i].isEmpty == OCUPADO) {
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

void abm_mostrarUnNotebook(eNotebook Notebook, eMarca *marcas, int tamMarcas,
		eTipo *tipos, int tamTipos) {
	char auxDescripcionMarca[MAX_DESCRIPCION];
	char auxDescripcionTipo[MAX_DESCRIPCION];

	for (int i = 0; i < tamMarcas; i++) {
		if (marcas[i].id == Notebook.idMarca) {
			strcpy(auxDescripcionMarca, marcas[i].descripcion);
		}
	}

	for (int i = 0; i < tamTipos; i++) {
		if (tipos[i].id == Notebook.idTipo) {
			strcpy(auxDescripcionTipo, tipos[i].descripcion);
		}
	}

	printf("\n|%2d  |   %-16s  | %-14s    |   %-14s |    %-4f |", Notebook.id,
			Notebook.modelo, auxDescripcionMarca, auxDescripcionTipo,
			Notebook.precio);
}

int abm_mostrarTodosNotebook(eNotebook *lista, int tam, eMarca *marcas,
		int tamMarcas, eTipo *tipos, int tamTipos) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	if (lista != NULL && tam > 0) {
		puts(
				"\n=========================================================================================");
		puts(
				"| ID |     MODELO          | MARCA            |  TIPO             |   PRECIO      |");
		puts(
				"------------------------------------------------------------------------------------------");
		for (i = 0; i < tam; i++) {
			if (lista[i].isEmpty == OCUPADO) {
				abm_mostrarUnNotebook(lista[i], marcas, tamMarcas, tipos,
						tamTipos);
				cantidad++;
			}
		}
		puts(
				"\n==========================================================================================");
	}

	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}

int abm_altaNotebook(eNotebook *lista, int tam, int id, eNotebook Notebook) {
	int rtn = 0;

	int index = abm_obtenerIndiceLibreNotebook(lista, tam);
	if (index != -1 && lista != NULL) {
		// Aca deberia recibir los datos ya cargados y asignarlos al id libre que recibo por params
		Notebook.id = id;
		Notebook.isEmpty = OCUPADO;
		lista[index] = Notebook;

		rtn = 1;
	}
	return rtn;
}

int abm_listadoBajaNotebook(eNotebook *lista, int tam, eMarca *marcas,
		int tamMarcas, eTipo *tipos, int tamTipos) {
	int rtn = 0;
	int idNotebook;
	int flag = 0;
	int confirmar = 0;

	ordenarJugadoresId(lista, tam);
	if (abm_mostrarTodosNotebook(lista, tam, marcas, tamMarcas, tipos,
			tamTipos)) {
		flag = 1;
	}

	if (flag) {
		utn_getNumero(&idNotebook, "\nIngrese ID a dar de baja",
				"Valor incorrecto", 0, tam, 9999);

		while (abm_encontrarNotebookPorId(lista, tam, idNotebook) == -1) {
			puts("\n --- ID INEXISTENTE ---");

			utn_getNumero(&idNotebook, "\nIngrese ID a dar de baja: ",
					"Valor incorrecto", 0, tam, 99999);
		}

		printf("\nUsuario a dar de baja: ");
		abm_mostrarUnNotebook(
				lista[abm_encontrarNotebookPorId(lista, tam, idNotebook)],
				marcas, tamMarcas, tipos, tamTipos);

		utn_getNumero(&confirmar,
				"\nEsta seguro que desea dar de baja? (1. SI - 0. NO): ",
				"Opcion incorrecta", 0, 1, 9999);
		if (confirmar) {
			abm_bajaNotebook(lista, tam, idNotebook);
			rtn = 1;
		}
	}

	return rtn;
}

int abm_bajaNotebook(eNotebook *lista, int tam, int id) {
	int rtn = 0;
	int index;

	index = abm_encontrarNotebookPorId(lista, tam, id);
	if (index != -1) {
		lista[index].isEmpty = BAJA;
		printf("\n ---- Usuario: %s dado de baja exitosamente ---- \n",
				lista[index].modelo);
		rtn = 1;
	}

	return rtn;
}

eNotebook abm_modificacionNotebook(eNotebook Notebook, eMarca *marcas,
		int tamMarcas, eTipo *tipos, int tamTipos) {
	eNotebook auxiliar = Notebook;
	int opcionSeleccionada;
	int auxIdTipo;

	do {
		opcionSeleccionada = menu_opciones(
				"\n ------- MODIFICACION -----------", "\n 1. MODIFICAR PRECIO"
						"\n 2. MODIFICAR TIPO"
						"\n 3. FINALIZAR MODIFICACIONES",
				"Error, la opcion seleccionada no es valida", 1, 3);

		switch (opcionSeleccionada) {
		case 1:
			utn_getNumeroDecimal(&auxiliar.precio,
					"\nIngrese el nombre de la notebook: ",
					"\nError. Reingrese el nombre de la notebook: ", 0, 999999,
					9999);
			break;
		case 2:
			mostrarTodosTipo(tipos, tamTipos);
			utn_getNumero(&auxIdTipo, "\nIngrese el id del tipo: ",
					"\nError. Tipo invalido: ", 5000, 9999, 9999);
			while (encontrarTipoPorId(tipos, tamTipos, auxIdTipo) == -1) {
				puts("\nEL ID INGRESADO NO EXISTE");
				utn_getNumero(&auxIdTipo, "\nIngrese el id del tipo: ",
						"\nError. Tipo invalido: ", 5000, 9999, 9999);
			}
			auxiliar.idTipo = auxIdTipo;
			break;
		case 3:
			puts("Volviendo al menu principal");
			break;
		}
	} while (opcionSeleccionada != 3);

	return auxiliar;
}

int abm_listadoModificacionNotebook(eNotebook *lista, int tam, eMarca *marcas,
		int tamMarcas, eTipo *tipos, int tamTipos) {
	int rtn = 0;
	int idNotebook;
	int index;
	int flag = 0;
	eNotebook auxiliar;
	int confirmar = 0;

	ordenarJugadoresId(lista, tam);
	if (abm_mostrarTodosNotebook(lista, tam, marcas, tamMarcas, tipos,
			tamTipos)) {
		flag = 1;
	}

	if (flag) {
		utn_getNumero(&idNotebook, "\nIngrese ID a modificar: ",
				"Valor incorrecto", 0, tam, 99999);

		while (abm_encontrarNotebookPorId(lista, tam, idNotebook) == -1) {
			puts("NO EXISTE ID.");

			utn_getNumero(&idNotebook, "\nIngrese ID a modificar: ",
					"Valor incorrecto", 0, tam, 99999);
		}

		index = abm_encontrarNotebookPorId(lista, tam, idNotebook);
		auxiliar = abm_modificacionNotebook(lista[index], marcas, tamMarcas,
				tipos, tamTipos);

		printf("\nUsuario a modificar: ");
		abm_mostrarUnNotebook(lista[index], marcas, tamMarcas, tipos, tamTipos);

		utn_getNumero(&confirmar,
				"\nEsta seguro que modificar el usuario? (1. SI - 0. NO): ",
				"Opcion incorrecta", 0, 1, 9999);
		if (confirmar) {
			lista[index] = auxiliar;
			rtn = 1;
		}
	}

	return rtn;
}

int validarIngresoOpciones(int contadorAltas, int contadorBajas) {
	int rtn = 0;
	if (contadorAltas != contadorBajas) {
		rtn = 1;
	}
	return rtn;
}

int ordenarNotebooksMarcaPrecio(eNotebook *notebooks, int tamNotebooks,
		eMarca *marcas, int tamMarcas) {
	int rtn = 0;
	int indiceActual;
	int indiceSiguiente;
	eNotebook auxiliar;

	for (int i = 0; i < tamNotebooks - 1; i++) {
		for (int j = i + 1; j < tamNotebooks; j++) {
			indiceActual = encontrarMarcaPorId(marcas, tamMarcas,
					notebooks[i].idMarca);
			indiceSiguiente = encontrarMarcaPorId(marcas, tamMarcas,
					notebooks[j].idMarca);
			if ((strcmp(marcas[indiceActual].descripcion,
					marcas[indiceSiguiente].descripcion) > 0)
					|| ((strcmp(marcas[indiceActual].descripcion,
							marcas[indiceSiguiente].descripcion) == 0)
							&& notebooks[i].precio > notebooks[j].precio)) {
				auxiliar = notebooks[i];
				notebooks[i] = notebooks[j];
				notebooks[j] = auxiliar;
			}
		}
	}

	return rtn;
}

int ordenarJugadoresId(eNotebook *lista, int tam) {
	int rtn = 0;
	eNotebook auxNotebook;

	if (lista != NULL && tam > 0) {
		for (int i = 0; i < tam - 1; i++) {
			for (int j = i + 1; j < tam; j++) {
				if (lista[i].id < lista[j].id) {
					auxNotebook = lista[i];
					lista[i] = lista[j];
					lista[j] = auxNotebook;
				}

			}
		}
		rtn = 1;
	}
	return rtn;
}
