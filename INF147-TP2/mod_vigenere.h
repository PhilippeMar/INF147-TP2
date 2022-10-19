#ifndef _MOD_VIGENERE_
#define _MOD_VIGENERE_

#include <stdio.h>
#include <ctype.h>

/*****************************************************************************************
*                                       CONSTANTES                                       *
*****************************************************************************************/

#define TAILLE_TABLE_VIGENERE 26	/* Dimension de la tabula recta		*/
#define ASCII_a 97					/* Code ASCII du a pour decalage	*/
#define ASCII_z 122					/* Code ASCII du z pour decalage	*/

/*****************************************************************************************
*                                  FONCTIONS PUBLIQUES                                   *
*****************************************************************************************/

/*
 (SP18) VIGENERE_REMPLIR_TABLE_VIGENERE

	Insere les valeurs de la table de vigenere dans un tableau 26 x 26 recu en parametres.

 PARAMETRES :

	- table_vigenere : La table a remplir (type: unsigned char[26][26])

 VALEUR DE RETOUR :

	- Aucune.
*/
void VIGENERE_remplir_table_vigenere(unsigned char[TAILLE_TABLE_VIGENERE][TAILLE_TABLE_VIGENERE]);

/* Procedure de test pour VIGENERE_remplir_table_vigenere. */
void test_VIGENERE_remplir_table_vigenere(void);

/*
 (SP19) VIGENERE_ENCRYPTER

	Encode un message avec le chiffre de Vigenere a partir d'une cle donnee.

 PARAMETRES :

	- message	      : Message a encoder (type: unsigned char*).
	- taille_message : Taille du message a encoder (type: unsigned int).
	- cle			  : Cle pour l'encodage (type: unsigned char*).
	- taille_cle	  : Taille de la cle (type: unsigned int).

 VALEUR DE RETOUR :

	- Aucune.
*/
void VIGENERE_encrypter(unsigned char*     message, 
	                    const unsigned int taille_message, 
	                    unsigned char*     cle, 
	                    const unsigned int taille_cle);

/*
 (SP20) VIGENERE_DECRYPTER

	Decode un message encode avec le chiffre de Vigenere a partir de sa cle.

 PARAMETRES :

	- message	      : Message a encoder (type: unsigned char*).
	- taille_message : Taille du message a encoder (type: unsigned int).
	- cle			  : Cle pour l'encodage (type: unsigned char*).
	- taille_cle	  : Taille de la cle (type: unsigned int).

 VALEUR DE RETOUR :

	- Aucune.
*/
void VIGENERE_decrypter(unsigned char*     message,
						const unsigned int taille_messsage,
						unsigned char*     cle,
						const unsigned int taille_cle);

#endif