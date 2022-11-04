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

#include "mod_cesar.h"

/*****************************************************************************************
*                                  FONCTIONS PUBLIQUES                                   *
*****************************************************************************************/

// Genere une cle pour un decalage donne.
void CESAR_generer_cle(unsigned char* cle, const int decalage)
{
	int n = fabs(decalage % TAILLE_ALPHABET);
	
	char temporaire[TAILLE_ALPHABET];

	for (int a = ASCII_a; a <= ASCII_z; a++)
	{
		temporaire[a - ASCII_a] = a;
	}

	for (int i = n; i < TAILLE_ALPHABET; i++)
	{
		cle[i - n] = temporaire[i];
	}

	for (int j = TAILLE_ALPHABET - n; j < TAILLE_ALPHABET; j++)
	{
		cle[j] = temporaire[j - (TAILLE_ALPHABET - n)];
	}
}

// Encode une chaine de caracteres avec le code de Cesar.
void CESAR_encrypter(unsigned char* message, const unsigned int taille, const int decalage)
{
	unsigned char cle_crypte[TAILLE_ALPHABET];

	CESAR_generer_cle(cle_crypte,decalage);

	int i = 0;
	while (i < taille)
	{
		if (isalpha(message[i]) != 0)
		{
			message[i] = cle_crypte[message[i] - ASCII_a];
		}
		i++;
	}

}

// Decode une chaine de caracteres avec le code de Cesar.
void CESAR_decrypter(unsigned char* message, const unsigned int taille, const int decalage)
{
	int oppose_decalage = decalage * -1;

	CESAR_encrypter(message, taille, oppose_decalage);

}
