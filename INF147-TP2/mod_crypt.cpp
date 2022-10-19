/*****************************************************************************************
Auteurs :	Barry Lawson
			Philippe Marineau
			Jean-Philippe Portant
			Teano Rocha
Date : Octobre 2022

--Description

On y retrouve les sous-programmes suivants :
	- 
*****************************************************************************************/

#include "mod_crypt.h"

/*****************************************************************************************
*                                  FONCTIONS PUBLIQUES                                   *
*****************************************************************************************/

// Genere un tableau qui contient les codes ASCII de l'alphabet en minuscules.
void CRYPT_generer_alphabet(unsigned char* tab_alphabet)
{
	// TODO
}

// Procedure de test pour CRYPT_GENERER_ALPHABET.
void test_CRYPT_generer_alphabet(void)
{

	unsigned char tab_alphabet[TAILLE_ALPHABET];
	CRYPT_generer_alphabet(tab_alphabet);

}

// Genere une cle aleatoire pour l'encodage.
void CRYPT_generer_cle(unsigned char* cle)
{
	// TODO
}

// Encode un message a partir d'une cle recue.
void CRYPT_encrypter(unsigned char* message,
					 const unsigned int taille,
					 const unsigned char* cle)
{
	// TODO
}

// Decode un message a partir d'une cle recue.
void CRYPT_decrypter(unsigned char* message,
	const unsigned int taille,
	const unsigned char* cle)
{
	//TODO
}