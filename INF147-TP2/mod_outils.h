#ifndef _MOD_OUTILS_
#define _MOD_OUTILS_

#include <stdlib.h>
#include <stdio.h>

/*****************************************************************************************
*                                       CONSTANTES                                       *
*****************************************************************************************/

#define TAILLE_ALPHABET 26	/* Nombre de lettres dans l'alphabet */

/* Macro-fonction qui permute deux entiers. */
#define SWAP_INT(x,y) { int temp = x; \
                        x = y;        \
                        y = temp; }

/* Macro-fonction qui permute deux rationnels. */
#define SWAP_DBL(x,y) { double temp = x; \
                        x = y;           \
                        y = temp; }

/* Macro-fonction qui genere un nombre aleatoire entre a et b inclusivement. */
#define RANDBETWEEN(a, b) {(unsigned int) (a + rand() % (b - a + 1)) }

/*****************************************************************************************
*                                  FONCTIONS PUBLIQUES                                   *
*****************************************************************************************/

/*
 (SP2) OUTILS_AFFICHER_TABLEAU_1D_UCHAR

    Affiche un talbeau 1D de caracteres.

 PARAMETRES :

    - tableau        : Tableau de caracteres (type: unsigned char*).
    - taille_tableau : Nombre de caracteres du tableau (type: unsigned int).

 VALEUR DE RETOUR :

    - Aucune.
*/
void OUTILS_afficher_tableau_1D_uchar(unsigned char*     tableau, 
                                      const unsigned int taille_tableau);

/*
 (SP6) OUTILS_OBTENIR_POSITION_MAX_DBL

    Trouve l'indice de la plus grande valeur dans un tableau de rationnels.

 PARAMETRES :

    - tableau        : Tableau de rationnels (type: double*).
    - taille_tableau : Taille du tableau de rationnels (type: unsigned int).

 VALEUR DE RETOUR :

    - i_max           : Position de la valeur maximale du tableau (type: unsigned int).
*/
unsigned int OUTILS_obtenir_position_max_dbl(const double*      tableau, 
                                             const unsigned int taille);

/* Procedure de test pour OUTILS_obtenir_position_max_dbl.  */
void test_OUTILS_obtenir_position_max_dbl(void);

/*
 (SP9) OUTILS_MELANGER

    Cree une permutation aleatoire d'un tableau 1D avec l'algorithme de Fisher-Yates.

 PARAMETRES :

    - tableau     : Reference vers un tableau de caracteres a melanger (type: unsigned char*).
    - taille_tableau : Taille du tableau a melanger (type: unsigned int). 

 VALEUR DE RETOUR :

    - Aucune.
*/
void OUTILS_melanger(unsigned char*     tableau, 
                     const unsigned int taille);

/*
 (SP14) OUTILS_TRI_DECROISSANT_ETENDU_DBL_UCHAR

    Trie deux tableaux en etendant le tri du premier aux elements du deuxieme.

 PARAMETRES :

    - tableau_principal  : Tableau de reference (type: double*).
    - tableau_secondaire : Tableau auquel le tri est etendu (type: unsigned char*).
    - taille_tableaux    : Taille des deux tableaux (type: unsigned int).

 VALEUR DE RETOUR :

    - Aucune.
*/
void OUTILS_tri_decroissant_etendu_dbl_uchar(double*            tableau_principal, 
                                             unsigned char*     tableau_secondaire, 
                                             const unsigned int taille_tableaux);

/* Procedure de test pour OUTILS_tri_decroissant_etendu_dbl_uchar. */
void test_OUTILS_tri_decroissant_etendu_dbl_uchar(void);

#endif
