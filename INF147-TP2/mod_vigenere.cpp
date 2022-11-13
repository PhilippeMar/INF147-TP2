/*****************************************************************************************
Auteurs :	Barry Lawson
			Philippe Marineau
			Jean-Philippe Portant
			Teano Rocha
Date : Octobre 2022

--Description
	Ce fichier permet d'encrypter et decrypter par substitution polyalphabetique

On y retrouve les sous-programmes suivants :
	- VIGENERE_remplir_table_vigenere
	- test_VIGENERE_remplir_table_vigenere
	- VIGENERE_encrypter
	- VIGENERE_decrypter
*****************************************************************************************/

#include "mod_vigenere.h"

/*****************************************************************************************
*                                  FONCTIONS PUBLIQUES                                   *
*****************************************************************************************/

// Insere les valeurs de la table de vigenere dans un tableau 26 x 26 recu en parametres.
void VIGENERE_remplir_table_vigenere(unsigned char table[TAILLE_TABLE_VIGENERE][TAILLE_TABLE_VIGENERE])
{
	for (unsigned int i = 0; i < TAILLE_TABLE_VIGENERE; i++)
	{
		for (unsigned int j = 0; j < TAILLE_TABLE_VIGENERE; j++)
		{
			table[i][j] = ASCII_a + ((i + j) % 26);
		}
	}
}

// Procedure de test pour VIGENERE_remplir_table_vigenere.
void test_VIGENERE_remplir_table_vigenere(void)
{

	unsigned char table_vigenere[TAILLE_TABLE_VIGENERE][TAILLE_TABLE_VIGENERE];

	VIGENERE_remplir_table_vigenere(table_vigenere);

	for (int i = 0; i < TAILLE_TABLE_VIGENERE; i++)
	{
		for (int j = 0; j < TAILLE_TABLE_VIGENERE; j++)
		{
			printf("%-3u ", table_vigenere[i][j]);
		}
		printf("\n");
	}

}

// Encode un message avec le chiffre de Vigenere a partir d'une cle donnee.
void VIGENERE_encrypter(unsigned char* message,
						const unsigned int taille_message,
						unsigned char* cle,
						const unsigned int taille_cle)
{
	// Genere table de Vigenere
	unsigned char table_vigenere[TAILLE_TABLE_VIGENERE][TAILLE_TABLE_VIGENERE];
	VIGENERE_remplir_table_vigenere(table_vigenere);

	for (unsigned int i = 0; i < taille_message; i++)
	{
		// On encrypte seulement les charactere alphabetiques
		if (isalpha(message[i]))
		{
			// Lettre minuscule ou majuscule
			unsigned char offset_maj_x = message[i] >= ASCII_a ? 0 : 32;
			unsigned char offset_maj_y = cle[i % taille_cle] >= ASCII_a ? 0 : 32;
			// 
			unsigned int x = message[i] - ASCII_a + offset_maj_x;
			unsigned int y = cle[(i % taille_cle)] - ASCII_a + offset_maj_y;
			// Encryption du charactere
			message[i] = table_vigenere[x][y] - offset_maj_x;
		}
	}
}

// Decode un message encode avec le chiffre de Vigenere a partir de sa cle.
void VIGENERE_decrypter(unsigned char* message,
						const unsigned int taille_message,
						unsigned char* cle,
						const unsigned int taille_cle)
{
	// Genere table de Vigenere
	unsigned char table_vigenere[TAILLE_TABLE_VIGENERE][TAILLE_TABLE_VIGENERE];
	VIGENERE_remplir_table_vigenere(table_vigenere);
	
	for (unsigned int i = 0; i < taille_message; i++)
	{
		// On encrypte seulement les charactere alphabetiques
		if (isalpha(message[i]))
		{
			// Lettre minuscule ou majuscule
			unsigned char offset_maj_x = message[i] >= ASCII_a ? 0 : 32;
			unsigned char offset_maj_y = cle[i % taille_cle] >= ASCII_a ? 0 : 32;
			// 
			unsigned int x = message[i] - ASCII_a + offset_maj_x;
			unsigned int y = cle[(i % taille_cle)] - ASCII_a + offset_maj_y;

			// Decryption du charactere
			for (unsigned int j = 0; j < TAILLE_TABLE_VIGENERE; j++)
			{
				if (message[i] == table_vigenere[j][y] - offset_maj_x)
				{
					message[i] = ASCII_a + j - offset_maj_x;
					break; // On passe au prochain charactere
				}
			}
		}
	}
}