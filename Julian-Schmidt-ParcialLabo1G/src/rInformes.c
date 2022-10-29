/*
 * rInformes.c
 *
 *  Created on: 28 Oct 2022
 *      Author: Julian
 */

#include "rInformes.h"

int informe_mostrarNotebooksDeTipoSeleccionado(eNotebook *notebooks,
		int tamNotebooks, int idTipoSeleccionado, eMarca *marcas, int tamMarcas,
		eTipo *tipos, int tamTipos) {
	int rtn = 0;

	if (notebooks != NULL && tamNotebooks > 0 && marcas != NULL && tamMarcas > 0
			&& tipos != NULL && tamTipos > 0) {
		for (int i = 0; i < tamNotebooks; i++) {
			if (notebooks[i].idTipo == idTipoSeleccionado) {
				abm_mostrarUnNotebook(*notebooks, marcas, tamMarcas, tipos,
						tamTipos);
			}
		}
		rtn = 1;
	}

	return rtn;
}

int informe_mostrarNotebooksDeMarcaSeleccionada(eNotebook *notebooks,
		int tamNotebooks, int idMarcaSeleccionada, eMarca *marcas,
		int tamMarcas, eTipo *tipos, int tamTipos) {
	int rtn = 0;

	if (notebooks != NULL && tamNotebooks > 0 && marcas != NULL && tamMarcas > 0
			&& tipos != NULL && tamTipos > 0) {
		for (int i = 0; i < tamNotebooks; i++) {
			if (notebooks[i].idMarca == idMarcaSeleccionada) {
				abm_mostrarUnNotebook(*notebooks, marcas, tamMarcas, tipos,
						tamTipos);
			}
		}
		rtn = 1;
	}

	return rtn;
}

int inicializarIntArray(int *array, int tam, int valor) {
	int rtn = 0;
	if (array != NULL && tam > 0) {
		for (int i = 0; i < tam; i++) {
			array[i] = valor;
		}
		rtn = 1;
	}
	return rtn;
}

int informe_mostrarMarcaMasElegida(eNotebook *notebooks, int tamNotebooks,
		eMarca *marcas, int maxMarcas) {
	int rtn = 0;
	int indiceMarca;
	int contadoresNotebooksDeTipos[maxMarcas];
	int indiceMarcaConMasNotebooks = -1;

	inicializarIntArray(contadoresNotebooksDeTipos, maxMarcas, 0);
	if (notebooks != NULL && marcas != NULL && tamNotebooks > 0
			&& maxMarcas > 0) {
		for (int i = 0; i < tamNotebooks; i++) {
			if (notebooks[i].isEmpty == OCUPADO) {
				indiceMarca = encontrarMarcaPorId(marcas, maxMarcas,
						notebooks[i].idMarca);
				contadoresNotebooksDeTipos[indiceMarca]++;
			}
		}

		for (int i = 0; i < maxMarcas; i++) {
			// Uso el indice como flag, si es el primer indice guardo el valor. Se espera que este ordenado el array de marcas con respecto al array de contadores
			if (i == 0
					|| contadoresNotebooksDeTipos[i]
							> contadoresNotebooksDeTipos[indiceMarcaConMasNotebooks]) {
				indiceMarcaConMasNotebooks = i;
			}
		}

		for (int i = 0; i < maxMarcas; i++) {
			if (contadoresNotebooksDeTipos[i]
					== contadoresNotebooksDeTipos[indiceMarcaConMasNotebooks]) {
				printf("\n\nMARCA/S CON MAYOR CANTIDAD DE NOTEBOOKS: %s \n",
						marcas[i].descripcion);
			}
		}

		printf("\nMarca con mas notebooks: %s: ",
				marcas[indiceMarcaConMasNotebooks].descripcion);
		rtn = 1;
	}

	return rtn;
}

int informe_mostrarNotebooksMasBarata(eNotebook *notebooks, int tamNotebooks,
		eTipo *tipos, int tamTipos, eMarca *marcas, int tamMarcas) {
	int rtn = 0;
	int idMasBarato = -1;
	int indiceNotebookBarata;

	if (notebooks != NULL && tamNotebooks > 0) {
		for (int i = 0; i < tamNotebooks; i++) {
			if (i == 0
					|| (notebooks[i].precio
							< notebooks[indiceNotebookBarata].precio)) {
				idMasBarato = notebooks[i].id;
				indiceNotebookBarata = i;
			}
		}

		indiceNotebookBarata = abm_encontrarNotebookPorId(notebooks,
				tamNotebooks, idMasBarato);

		puts("\n\n NOTEBOOK MAS BARATA: ");

		for (int i = 0; i < tamNotebooks; i++) {
			if (notebooks[i].precio == notebooks[indiceNotebookBarata].precio) {
				abm_mostrarUnNotebook(notebooks[i], marcas, tamMarcas, tipos,
						tamTipos);
			}
		}

		rtn = 1;
	}

	return rtn;
}

int informe_mostrarNotebookPorMarcaYTipo(eNotebook *notebooks, int tamNotebooks,
		int idMarcaSeleccionada, int idTipoSeleccionado, eMarca *marcas,
		int maxMarcas, eTipo *tipos, int maxTipos) {
	int rtn = 0;
	int contadorSeleccionado = 0;

	if (notebooks != NULL && tamNotebooks > 0 && marcas != NULL && maxMarcas > 0
			&& tipos != NULL && maxTipos > 0) {

		for (int i = 0; i < tamNotebooks; i++) {
			if (notebooks[i].idMarca == idMarcaSeleccionada
					&& notebooks[i].idTipo == idTipoSeleccionado) {
				contadorSeleccionado++;
			}
		}
		printf("\nNOTEBOOKS CON EL ID DE MARCA Y TIPO SELECCIONADOS: %d \n",
				contadorSeleccionado);

		rtn = 1;
	}

	return rtn;
}

int informe_mostrarNotebooksPorMarca(eNotebook *notebooks, int tamNotebooks,
		eMarca *marcas, int maxMarcas, eTipo *tipos, int maxTipos) {
	int rtn = 0;

	if (notebooks != NULL && tamNotebooks > 0 && marcas != NULL && maxMarcas > 0
			&& tipos != NULL && maxTipos > 0) {

		for (int i = 0; i < maxMarcas; i++) {
			puts("\n=======================================================");
			printf("|        %-36s         |", marcas[i].descripcion);
			puts("\n=======================================================");
			for (int j = 0; j < tamNotebooks; j++) {
				if (notebooks[j].idMarca == marcas[i].id) {
					printf("| %-24s | %-10f |\n", notebooks[j].modelo,
							notebooks[j].precio);
				}
			}
		}
		rtn = 1;
	}

	return rtn;
}

int informe_sumaDeImportesServicios(eTrabajo *trabajos, int tamTrabajos,
		eServicio *servicios, int tamServicios, int idNotebook,
		eNotebook *notebooks, int tamNotebooks) {
	int rtn = 0;
	int acumuladorPrecioServicios = 0;
	int indiceServicio;

	if (trabajos != NULL && servicios != NULL && tamTrabajos > 0
			&& tamServicios > 0) {
		for (int i = 0; i < tamTrabajos; i++) {
			if (trabajos[i].idNotebook == idNotebook) {
				indiceServicio = encontrarServicioPorId(servicios, tamServicios,
						trabajos[i].idServicio);
				acumuladorPrecioServicios = acumuladorPrecioServicios
						+ servicios[indiceServicio].precio;
			}
		}
		printf("\n VALOR TOTAL DE SERVICES: %d", acumuladorPrecioServicios);
	}

	return rtn;
}

int informe_mostrarTrabajosSobreNotebook(eTrabajo *trabajos, int tamTrabajos,
		eServicio *servicios, int tamServicios, int idNotebook,
		eNotebook *notebooks, int tamNotebooks) {
	int rtn = 0;
	int indiceNotebook;
	int indiceServicio;

	if (trabajos != NULL && servicios != NULL && tamTrabajos > 0
			&& tamServicios > 0) {
		for (int i = 0; i < tamTrabajos; i++) {
			if (trabajos[i].idNotebook == idNotebook) {
				indiceNotebook = abm_encontrarNotebookPorId(notebooks,
						tamNotebooks, idNotebook);
				indiceServicio = encontrarServicioPorId(servicios, tamServicios,
						trabajos[i].idServicio);
				printf("\n Modelo: %s\n Servicio: %s\n Precio servicio: %f\n",
						notebooks[indiceNotebook].modelo,
						servicios[indiceServicio].descripcion,
						servicios[indiceServicio].precio);
			}
		}
		rtn = 1;
	}

	return rtn;
}
