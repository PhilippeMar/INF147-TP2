/*****************************************************************************************
Auteurs :	Barry Lawson
			Philippe Marineau
			Jean-Philippe Portant
			Teano Rocha
Date : Novembre 2022

--Description
	Ce fichier permet d'encypter et decrypter des message selon le code de Cesar

On y retrouve les sous-programmes suivants :
	- CESAR_generer_cle
	- CESAR_encrypter
	- CESAR_decrypter
*****************************************************************************************/

#include "mod_cesar.h"

/*****************************************************************************************
*                                  FONCTIONS PUBLIQUES                                   *
*****************************************************************************************/

// Genere une cle pour un decalage donne.
void CESAR_generer_cle(unsigned char* cle, const int decalage)
{
	// On tronque le decalage
	int n = decalage % TAILLE_ALPHABET;
	// On veux un decalage positif (-2 => 24)
	if (n < 0) n += TAILLE_ALPHABET;
	// Genere la cle
	for (int i = 0; i < TAILLE_ALPHABET; i++)
	{
		cle[i] = ASCII_a + ((i + n) % TAILLE_ALPHABET);
	}
}

// Encode une chaine de caracteres avec le code de Cesar.
void CESAR_encrypter(unsigned char* message,
	const unsigned int taille,
	const int decalage)
{
	// On initialise la cl� d'encryptage
	unsigned char cle[TAILLE_ALPHABET];
	CESAR_generer_cle(cle, decalage);

	// On encrypte chaque charactere(a-z) du message
	for (unsigned int i = 0; i < taille; i++)
	{
		if (isalpha(message[i])) // On assume qu'il n'y a pas de majuscule
			message[i] = cle[message[i] - ASCII_a];
	}
}

// Decode une chaine de caracteres avec le code de Cesar.
void CESAR_decrypter(unsigned char* message,
	const unsigned int taille,
	const int decalage)
{
	// On rappel la fonction pour encrypter mais avec un decalage dans le sens inverse
	CESAR_encrypter(message, taille, -decalage);
}
