/*****************************************************************************************
Auteurs :	Barry Lawson
			Philippe Marineau
			Jean-Philippe Portant
			Teano Rocha
Date : Octobre 2022

--Description
	Ce module contient des outils utiliser pour les divers types d'encryption

On y retrouve les sous-programmes suivants :
	- OUTILS_afficher_tableau_1D_uchar
	- OUTILS_obtenir_position_max_dbl
	- test_OUTILS_obtenir_position_max_dbl
	- OUTILS_melanger
	- OUTILS_tri_decroissant_etendu_dbl_uchar
	- test_OUTILS_tri_decroissant_etendu_dbl_uchar
*****************************************************************************************/

#include "mod_outils.h"

/*****************************************************************************************
*                                  FONCTIONS PUBLIQUES                                   *
*****************************************************************************************/

// Affiche un talbeau 1D de caracteres.
void OUTILS_afficher_tableau_1D_uchar(unsigned char* tableau,
	const unsigned int taille_tableau)
{
	for (unsigned int i = 0; i < taille_tableau; i++)
		printf("%c ", tableau[i]);
	printf("\n");
}

// Trouve l'indice de la plus grande valeur dans un tableau de rationnels.
unsigned int OUTILS_obtenir_position_max_dbl(const double* tableau,
											const unsigned int taille)
{
	unsigned int indice = 0;
	// Parcourir les valeur du tableau
	for (unsigned int i = 1; i < taille; i++)
	{
		// On change la valeur de l'indice si la valeur courante est plus grande
		if (tableau[i] > tableau[indice])
		{
			indice = i;
		}
	}
	return indice;
}

// Procedure de test pour OUTILS_obtenir_position_max_dbl.
void test_OUTILS_obtenir_position_max_dbl(void)
{

	printf("TEST_OUTILS_OBTENIR_POSITION_MAX_DBL :: [-1., 1., 10., 0.]\n\n");

	double tableau[] = { -1., 1., 10., 0. };
	unsigned int taille = sizeof(tableau) / sizeof(double);

	unsigned int valeur_attendue = 2;
	unsigned int valeur_obtenue = OUTILS_obtenir_position_max_dbl(tableau, taille);

	printf("\tValeur attendue : %u\n", valeur_attendue);
	printf("\tValeur obtenue  : %u\n", valeur_obtenue);

}

// Cree une permutation aleatoire d'un tableau 1D avec l'algorithme de Fisher-Yates.
void OUTILS_melanger(unsigned char* tableau, const unsigned int taille)
{
	for (unsigned int i = taille - 1; i >= 1; i--)
	{
		// Assignation d'une valeur aléatiore 
		unsigned int j = RANDBETWEEN(0, i);
		// Permutation entre la valeur courante et la valeur aléatoire
		SWAP_INT(tableau[i], tableau[j]);
	}
}

// Trie deux tableaux en etendant le tri du premier aux elements du deuxieme.
void OUTILS_tri_decroissant_etendu_dbl_uchar(double* tableau_principal,
	unsigned char* tableau_secondaire,
	const unsigned int taille_tableaux)
{
	for (unsigned int i = taille_tableaux; i >= 1; i--)
	{
		for (unsigned int j = 0; j < taille_tableaux - 1; j++)
		{
			if (tableau_principal[j + 1] > tableau_principal[j])
			{
				SWAP_DBL(tableau_principal[j], tableau_principal[j + 1]);
				SWAP_DBL(tableau_secondaire[j], tableau_secondaire[j + 1]);
			}
		}
	}
}

// Procedure de test pour OUTILS_tri_decroissant_etendu_dbl_uchar.
void test_OUTILS_tri_decroissant_etendu_dbl_uchar(void)
{

	printf("TEST_OUTILS_OBTENIR_POSITION_MAX_DBL :: [0.02848, 0.07278, 0.01582, 0.00000]\n");
	printf("                                        [97     , 98     , 99     , 100    ]\n\n");

	double tableau_principal[] = { 0.02848, 0.07278, 0.01582, 0.00000 };
	unsigned char tableau_secondaire[] = { 97, 98, 99, 100 };
	unsigned int taille_tableaux = sizeof(tableau_principal) / sizeof(double);

	OUTILS_tri_decroissant_etendu_dbl_uchar(tableau_principal,
		tableau_secondaire,
		taille_tableaux);

	printf("\tValeur attendue : [0.07278, 0.02848, 0.01582, 0.00000]\n");
	printf("\t                  [98     , 97     , 99     , 100    ]\n\n");

	printf("\tValeur obenue :   [%.5lf, %.5lf, %.5lf, %.5lf]\n",
		tableau_principal[0],
		tableau_principal[1],
		tableau_principal[2],
		tableau_principal[3]);

	printf("\t                  [%u     , %u     , %u     , %u    ]\n",
		tableau_secondaire[0],
		tableau_secondaire[1],
		tableau_secondaire[2],
		tableau_secondaire[3]);

}
