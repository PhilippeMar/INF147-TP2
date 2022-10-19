#ifndef _MOD_CESAR_
#define _MOD_CESAR_

#include <ctype.h>			/* isalpha */

/*****************************************************************************************
*                                       CONSTANTES                                       *
*****************************************************************************************/

#define ASCII_a 97			/* Code ASCII de la lettre a         */
#define ASCII_z 122			/* Code ASCII de la lettre z         */
#define TAILLE_ALPHABET 26	/* Nombre de lettres dans l'alphabet */

/*****************************************************************************************
*                                  FONCTIONS PUBLIQUES                                   *
*****************************************************************************************/

/*
 (SP1) CESAR_GENERER_CLE

	Genere une cle pour un decalage donne.

 PARAMETRES :

	- cle      : La cle generee a partir du decalage (type: unsigned char*).
	- decalage : Decalage utilise pour generer la cle (type: unsigned int)

 VALEUR DE RETOUR :

	- Aucune.
*/
void CESAR_generer_cle(unsigned char* cle, 
                       const int decalage);

/*
 (SP3) CESAR_ENCRYPTER

	Encode une chaine de caracteres avec le code de Cesar.

 PARAMETRES :

	- message  : Message a encoder (type: unsigned char*).
	- taille   : Taille du message a encoder (type: unsigned int). 
	- decalage : Decalage utilise pour generer la cle d'encodage (type: int).

 VALEUR DE RETOUR :

	- Aucune.
*/
void CESAR_encrypter(unsigned char*     message, 
	                 const unsigned int taille, 
	                 const int          decalage);

/*
 (SP4) CESAR_DECRYPTER

	Decode une chaine de caracteres avec le code de Cesar.

 PARAMETRES :

	- message  : Message a decoder (type: unsigned char*).
	- taille   : Taille du message a decoder (type: unsigned int).
	- decalage : Oppose du decalage utilise pour generer la cle d'encodage (type: int).

 VALEUR DE RETOUR :

	- Aucune.
*/
void CESAR_decrypter(unsigned char*     message, 
	                 const unsigned int taille, 
	                 const int          decalage);

#endif