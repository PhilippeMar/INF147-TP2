/*****************************************************************************************
Auteurs :	Barry Lawson
			Philippe Marineau
			Jean-Philippe Portant
			Teano Rocha
Date : Novembre 2022

--Description
	Ce fichier permet d'encrypter et decrypter par substitution aleatoire

On y retrouve les sous-programmes suivants :
	- CRYPT_generer_alphabet
	- test_CRYPT_generer_alphabet
	- CRYPT_generer_cle
	- CRYPT_encrypter
	- CRYPT_decrypter
*****************************************************************************************/

#include "mod_crypt.h"

/*****************************************************************************************
*                                  FONCTIONS PUBLIQUES                                   *
*****************************************************************************************/

// Genere un tableau qui contient les codes ASCII de l'alphabet en minuscules.
void CRYPT_generer_alphabet(unsigned char* tab_alphabet)
{
	for (unsigned int i = 0; i < TAILLE_ALPHABET; i++)
	{
		tab_alphabet[i] = ASCII_a + i;
	}
}

// Procedure de test pour CRYPT_GENERER_ALPHABET.
void test_CRYPT_generer_alphabet(void)
{
	// Initialisation d'un tableau contenant l'alphabet
	unsigned char tab_alphabet[TAILLE_ALPHABET];
	CRYPT_generer_alphabet(tab_alphabet);

}

// Genere une cle aleatoire pour l'encodage.
void CRYPT_generer_cle(unsigned char* cle)
{
	CRYPT_generer_alphabet(cle);
	OUTILS_melanger(cle, TAILLE_ALPHABET);
}

// Encode un message a partir d'une cle recue.
void CRYPT_encrypter(unsigned char* message,
	const unsigned int taille,
	const unsigned char* cle)
{
	for (unsigned int i = 0; i < taille; i++)
	{
		// On encrypte seulement les charactere alphabetiques
		if (isalpha(message[i]))
		{
			// Lettre minuscule ou majuscule
			unsigned char offset_maj = message[i] >= ASCII_a ? 0 : 32;
			// Encryption du charactere
			message[i] = cle[message[i] - ASCII_a + offset_maj] - offset_maj;
		}
	}
}

// Decode un message a partir d'une cle recue.
void CRYPT_decrypter(unsigned char* message,
	const unsigned int taille,
	const unsigned char* cle)
{
	for (unsigned int i = 0; i < taille; i++)
	{
		// On encrypte seulement les charactere alphabetiques
		if (isalpha(message[i]))
		{
			// On cherche le charactere actuel dans la cle
			for (unsigned int j = 0; j < TAILLE_ALPHABET; j++)
			{
				// Lettre minuscule ou majuscule
				unsigned char offset_maj = message[i] >= ASCII_a ? 0 : 32;
				// Decryption du charactere
				if (cle[j] - offset_maj == message[i])
				{
					message[i] = ASCII_a + j - offset_maj;
					break;	// On sort de la recherche de charactere dans la cle
				}
			}

		}
	}
}
